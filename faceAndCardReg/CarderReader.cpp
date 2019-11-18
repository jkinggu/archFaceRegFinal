#include "CarderReader.h"
typedef int(*_UCommand1)(unsigned char* pCmd, int* parg0, int* parg1, int* parg2);
typedef int(*_Ucommand2)(unsigned char* pCmd, int* parg0, int* parg1, char* parg2);
typedef int(*_GetAddr)(char* pbuf);
typedef int(*_GetBegin)(char* pbuf);
typedef int(*_GetName)(char* pbuf);
typedef int(__stdcall *_GetSex)(char* pbuf);
typedef int(__stdcall *_GetSexGB)(char* pbuf);
typedef int(__stdcall *_GetFolk)(char* pbuf);
typedef int(__stdcall *_GetFolkGB)(char* pbuf);
typedef int(__stdcall *_GetIDNum)(char* pbuf);
typedef int(__stdcall *_GetDep)(char* pbuf);
typedef int(__stdcall *_GetBirth)(char* pbuf);
typedef int(__stdcall *_GetEnd)(char* pbuf);
typedef int(__stdcall *_GetNewAddr)(char* pbuf);
typedef int(__stdcall *_GetSAMIDToStr)(char* id);
typedef int(__stdcall *_GetBmpPath)(char *buf);
typedef int(__stdcall *_UnicodeToGBK)(wchar_t *pwc, char *pc, int nsize);
_UCommand1				UCommand1;
_Ucommand2				UCommand2;
_GetAddr				GetAddr;
_GetBegin				GetBegin;
_GetName				GetName;
_GetSex					GetSex;
_GetSexGB				GetSexGB;
_GetFolk				GetFolk;
_GetFolkGB				GetFolkGB;
_GetIDNum				GetIDNum;
_GetDep					GetDep;
_GetBirth				GetBirth;
_GetEnd					GetEnd;
_GetNewAddr				GetNewAddr;
_GetBmpPath				GetBmpPath;
_GetSAMIDToStr			GetSAMIDToStr;
_UnicodeToGBK			UnicodeToGBK;
QString tmpCard = "";
CarderReader::CarderReader(QObject *parent):cinfo1(nullptr),cinfo2(nullptr){
	dllFlag = OnInitCard();
}



bool& CarderReader::getDllFlag() {
	return this->dllFlag;

}


void CarderReader::run() {
	if (dllFlag) {
		QTimer *timer = new QTimer(this);
		timer->start(800);
		connect(timer, SIGNAL(timeout()), this, SLOT(handlerCardTimeout()));
		QEventLoop loop;
		loop.exec();
		
	}
}



void CarderReader::handlerCardTimeout() {
	if (cinfo1 == nullptr&&cinfo2 == nullptr) {
		//qDebug() << "DOUBLE NULL";
		cinfo2 = hanlerCardTime();
		if (cinfo2 != NULL) {
			cinfo1 = new CardInfo(cinfo2->getCname(), cinfo2->getCsex(), cinfo2->getCardNum());
		}
	}
	else if (cinfo1 != nullptr&&cinfo2 != nullptr&&cinfo1->getCardNum() == cinfo2->getCardNum()) {
		//qDebug() << "DOUBLE NOT NULL";
		tmpCard = cinfo1->getCardNum();
		CardInfo *tmp = cinfo1;
		free(tmp);
		cinfo1 = nullptr;
		tmp = nullptr;


	}else if (cinfo1 == nullptr&&cinfo2 != nullptr) {

		CardInfo *tmp = cinfo2;
		free(tmp);
		tmp = nullptr;
		cinfo2 = hanlerCardTime();
		if (cinfo2 != nullptr) {
			if (tmpCard != cinfo2->getCardNum()) {
				cinfo1 = new CardInfo(cinfo2->getCname(), cinfo2->getCsex(), cinfo2->getCardNum());
				tmpCard = "";
			}
		}
	}else {
		if (cinfo1 !=nullptr) {
			qDebug() << "here is cinfo1 nullptr";
	   }
		if (cinfo2 !=nullptr) {
			qDebug() << "here is cinfo2 nullptr";
		}
	}



	if (cinfo1 != nullptr) {
		QString baseDir = QCoreApplication::applicationDirPath();
		QString fileDirPath = baseDir + "/faceImg/" + cinfo1->getCardNum();
		QDir fileDir(fileDirPath);
		if (!fileDir.exists()) {
			fileDir.mkdir(fileDirPath);
			QFile file1(baseDir + "/zp.bmp");
			QFile file2(baseDir + "/wx.txt");
			if (file1.exists())
				file1.copy(fileDirPath + "/" + cinfo1->getCardNum() + ".bmp");
			file2.copy(fileDirPath + "/" + "wx.txt");
			file1.close();
			file2.close();
		}
		emit cardChanged();
	}

	if (cinfo1 == nullptr&&cinfo2 == nullptr) {
		emit cardClean();
	}


}

CardInfo *&CarderReader::getCinfo1() {
	return this->cinfo1;
}

CardInfo * CarderReader::hanlerCardTime() {

	//连接设备
	unsigned char cmd = 0x41;
	int para0 = 0, para1 = 8811, para2 = 9986;
	int ret = UCommand1(&cmd, &para0, &para1, &para2);
	if (ret != 62171)
	{
		
		return nullptr;
	}
	//验证卡（寻卡）
	cmd = 0x43;
	ret = UCommand1(&cmd, &para0, &para1, &para2);

	//读卡
	cmd = 0x49;
	ret = UCommand1(&cmd, &para0, &para1, &para2);

	if (ret != 62171 && ret != 62172)
	{
		return nullptr;
	}

	char Name[250] = { 0 };
	char Gender[250] = { 0 };
	char Nation[250] = { 0 };
	char BirthDate[250] = { 0 };
	char Address[250] = { 0 };
	char IDNumber[250] = { 0 };
	char SignOrgan[250] = { 0 };
	char BeginTerm[250] = { 0 };
	char ValidTerm[250] = { 0 };
	char NewAddress[250] = { 0 };
	char BmpPath[250] = { 0 };
	char CardVersion[250] = { 0 };
	switch (ret) {
	case 62171://二代证
	{
		GetName(Name);
		TrimStr(Name);
		GetSexGB(Gender);
		GetFolkGB(Nation);
		GetBirth(BirthDate);
		GetAddr(Address);
		TrimStr(Address);
		GetIDNum(IDNumber);
		GetDep(SignOrgan);
		TrimStr(SignOrgan);
		GetBegin(BeginTerm);
		GetEnd(ValidTerm);
		GetNewAddr(NewAddress);
		TrimStr(NewAddress);
		GetBmpPath(BmpPath);
		break;
	}
	case 62172://二代证带指纹
	{
		GetName(Name);
		TrimStr(Name);
		GetSexGB(Gender);
		GetFolkGB(Nation);
		GetBirth(BirthDate);
		GetAddr(Address);
		TrimStr(Address);
		GetIDNum(IDNumber);
		GetDep(SignOrgan);
		TrimStr(SignOrgan);
		GetBegin(BeginTerm);
		GetEnd(ValidTerm);
		GetNewAddr(NewAddress);
		TrimStr(NewAddress);
		break;
	}
	}

	//关闭读卡器
	cmd = 0x42;
	UCommand1(&cmd, &para0, &para1, &para2);
	CardInfo *mycinfo = new CardInfo();
	//格式编码转换。浪费一些时间
	LPCSTR cname = (LPCSTR)Name;
	QString str1 = QString::fromLocal8Bit(cname);
	mycinfo->setCname(str1);

	LPCSTR csex = (LPCSTR)Gender;
	QString str2 = QString::fromLocal8Bit(csex);
	mycinfo->setCsex(str2);

	LPCSTR cardNum = (LPCSTR)IDNumber;
	QString str3 = QString::fromLocal8Bit(cardNum);
	mycinfo->setCardNum(str3);
	return mycinfo;


}

bool CarderReader::OnInitCard() {
	QString dllPath = QCoreApplication::applicationDirPath()+"/RdCard.dll";
	
	HINSTANCE dllLib = LoadLibraryA((LPCSTR)(dllPath.toStdString().c_str()));
	if (dllLib != NULL) {
		UCommand1 = (_UCommand1)GetProcAddress(dllLib, "UCommand1");
		UCommand2 = (_Ucommand2)GetProcAddress(dllLib, "UCommand1");

		GetAddr = (_GetAddr)GetProcAddress(dllLib, "GetAddr");
		GetBegin = (_GetBegin)GetProcAddress(dllLib, "GetBegin");
		GetName = (_GetName)GetProcAddress(dllLib, "GetName");
		GetSex = (_GetSex)GetProcAddress(dllLib, "GetSex");
		GetSexGB = (_GetSexGB)GetProcAddress(dllLib, "GetSexGB");
		GetFolk = (_GetFolk)GetProcAddress(dllLib, "GetFolk");
		GetFolkGB = (_GetFolkGB)GetProcAddress(dllLib, "GetFolkGB");
		GetIDNum = (_GetIDNum)GetProcAddress(dllLib, "GetIDNum");
		GetDep = (_GetDep)GetProcAddress(dllLib, "GetDep");
		GetBirth = (_GetBirth)GetProcAddress(dllLib, "GetBirth");
		GetEnd = (_GetEnd)GetProcAddress(dllLib, "GetEnd");
		GetNewAddr = (_GetNewAddr)GetProcAddress(dllLib, "GetNewAddr");
		GetBmpPath = (_GetBmpPath)GetProcAddress(dllLib, "GetBmpPath");
		GetSAMIDToStr = (_GetSAMIDToStr)GetProcAddress(dllLib, "GetSAMIDToStr");

		if (UCommand1 == NULL || UCommand2 == NULL || GetAddr == NULL || GetBegin == NULL || GetName == NULL || GetSex == NULL || GetSexGB == NULL || GetFolk == NULL || GetFolkGB == NULL || GetIDNum == NULL || GetDep == NULL || GetBirth == NULL || GetEnd == NULL || GetNewAddr == NULL || GetSAMIDToStr == NULL || GetBmpPath == NULL)
		{
			return false;
		}
		return true;
	}
	return false;
}




char*  CarderReader::TrimStr(char *str)
{
	char *head = str;
	while (*head == ' ')
	{
		++head;
	}

	char *end = head + strlen(head) - 1;
	while (*end == ' ')
	{
		--end;
	}
	*(end + 1) = 0;
	strcpy(str, head);
	return str;
	
}


CarderReader::~CarderReader()
{
	if (cinfo1 != nullptr) {
		delete cinfo1;
	}
	if (cinfo2 != nullptr) {
		delete cinfo2;
	}
	
}
