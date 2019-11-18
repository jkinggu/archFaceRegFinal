#include "CardObject.h"
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

CardObject::CardObject(QObject *parent) :dllLib(QCoreApplication::applicationDirPath() + "/RdCard.dll")
{
	dllFlag = false;
	exitFlag = false;
	if (dllLib.load()) {
		dllFlag = OnInitCard();
	}
	qRegisterMetaType<CardInfo>("CardInfo");

}

void CardObject::run() {
	if (dllFlag) {
		while (true)
		{
			if (readFlag) {
				CardInfo info = handlerCtlTask();
				if (!info.getCardNum().isEmpty()) {
					readFlag = false;
					emit emitCardInfo(info);
				}
			}
			if (exitFlag) {
				qDebug() << "OK break Thread.......";
				break;
			}
			this->msleep(600);
		}

	}

}

bool CardObject::getReadFlag() {
	return this->readFlag;
}
bool CardObject::getDllFlag() {
	return this->dllFlag;
}

void CardObject::setReadFlag(const bool &read) {
	this->readFlag = read;
}
void CardObject::setExitFlag(const bool &exit) {
	this->exitFlag = exit;
}
CardInfo CardObject::handlerCtlTask() {
	CardInfo mycinfo;
	mycinfo.setCardNum("");
	mycinfo.setCname("");
	mycinfo.setCsex("");
	//连接设备
	unsigned char cmd = 0x41;
	int para0 = 0, para1 = 8811, para2 = 9986;
	int ret = UCommand1(&cmd, &para0, &para1, &para2);
	if (ret != 62171)
	{
		dllFlag = false;
		return mycinfo;
	}
	//验证卡（寻卡）
	cmd = 0x43;
	ret = UCommand1(&cmd, &para0, &para1, &para2);

	//读卡
	cmd = 0x49;
	ret = UCommand1(&cmd, &para0, &para1, &para2);

	if (ret != 62171 && ret != 62172)
	{
		dllFlag = false;
		return mycinfo;
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

	//格式编码转换。浪费一些时间
	LPCSTR cname = (LPCSTR)Name;
	QString str1 = QString::fromLocal8Bit(cname);
	mycinfo.setCname(str1);

	LPCSTR csex = (LPCSTR)Gender;
	QString str2 = QString::fromLocal8Bit(csex);
	mycinfo.setCsex(str2);

	LPCSTR cardNum = (LPCSTR)IDNumber;
	QString str3 = QString::fromLocal8Bit(cardNum);
	mycinfo.setCardNum(str3);
	return mycinfo;

}
bool CardObject::OnInitCard() {
	UCommand1 = (_UCommand1)dllLib.resolve("UCommand1");
	UCommand2 = (_Ucommand2)dllLib.resolve("UCommand1");
	GetAddr = (_GetAddr)dllLib.resolve("GetAddr");
	GetBegin = (_GetBegin)dllLib.resolve("GetBegin");
	GetName = (_GetName)dllLib.resolve("GetName");
	GetSex = (_GetSex)dllLib.resolve("GetSex");
	GetSexGB = (_GetSexGB)dllLib.resolve("GetSexGB");
	GetFolk = (_GetFolk)dllLib.resolve("GetFolk");
	GetFolkGB = (_GetFolkGB)dllLib.resolve("GetFolkGB");
	GetIDNum = (_GetIDNum)dllLib.resolve("GetIDNum");
	GetDep = (_GetDep)dllLib.resolve("GetDep");
	GetBirth = (_GetBirth)dllLib.resolve("GetBirth");
	GetEnd = (_GetEnd)dllLib.resolve("GetEnd");
	GetNewAddr = (_GetNewAddr)dllLib.resolve("GetNewAddr");
	GetBmpPath = (_GetBmpPath)dllLib.resolve("GetBmpPath");
	GetSAMIDToStr = (_GetSAMIDToStr)dllLib.resolve("GetSAMIDToStr");

	if (UCommand1 == NULL || UCommand2 == NULL || GetAddr == NULL || GetBegin == NULL || GetName == NULL || GetSex == NULL || GetSexGB == NULL || GetFolk == NULL || GetFolkGB == NULL || GetIDNum == NULL || GetDep == NULL || GetBirth == NULL || GetEnd == NULL || GetNewAddr == NULL || GetSAMIDToStr == NULL || GetBmpPath == NULL)
	{
		return false;
	}
	return true;

}


char*  CardObject::TrimStr(char *str)
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
CardObject::~CardObject()
{
	readFlag = false;
	exitFlag = true;
}
