#include "Login.h"

Login::Login(QWidget *parent) :QDialog(parent), faceAdminService(nullptr), paramService(nullptr), mainWin(nullptr) {
	QRegExp regExp("[A-Za-z0-9]{1,8}");
	loginFont = new QFont("Microsoft YaHei", 12, QFont::Normal);

	ulabel = new QLabel("�û���:");
	ulabel->setFont(*loginFont);
	username = new QLineEdit;
	username->setFont(*loginFont);
	username->setAlignment(Qt::AlignLeft);
	username->setFixedSize(130, 25);
	username->setMaxLength(130);
	username->setValidator(new QRegExpValidator(regExp));
	//ulabel->setBuddy(username);

	plabel = new QLabel("��   ��:");
	plabel->setFont(*loginFont);
	password = new QLineEdit;
	password->setEchoMode(QLineEdit::Password);
	password->setFont(*loginFont);
	password->setFixedSize(130, 25);
	password->setMaxLength(130);
	password->setAlignment(Qt::AlignLeft);
	password->setValidator(new QRegExpValidator(regExp));
	// plabel->setBuddy(password);

	checkBtn = new QPushButton("��½");
	checkBtn->setFont(*loginFont);
	checkBtn->setFixedSize(95, 30);
	connect(checkBtn, SIGNAL(clicked()), this, SLOT(userLogin()));



	cancelBtn = new QPushButton("ȡ��");
	cancelBtn->setFont(*loginFont);
	cancelBtn->setFixedSize(95, 30);
	connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));


	//�ֶ�����
	QHBoxLayout *topLay = new QHBoxLayout();
	topLay->addWidget(ulabel);
	topLay->addWidget(username);
	topLay->setAlignment(username, Qt::AlignCenter);
	//topLay->setMargin(30);
	//topLay->setSpacing(7);
	QSpacerItem *topLayItem = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	topLay->addSpacerItem(topLayItem);

	QHBoxLayout *midLay = new QHBoxLayout();
	midLay->addWidget(plabel);
	midLay->addWidget(password);
	midLay->setAlignment(password, Qt::AlignCenter);
	//midLay->setMargin(30);
	QSpacerItem *midItem = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	midLay->addSpacerItem(midItem);


	QHBoxLayout *bottomLay = new QHBoxLayout();
	bottomLay->addWidget(checkBtn);
	bottomLay->addWidget(cancelBtn);
	//bottomLay->setMargin(45);
	QSpacerItem *botItem = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
	bottomLay->addSpacerItem(botItem);
	// bottomLay->addStretch();

	QVBoxLayout *mainLay = new QVBoxLayout();
	mainLay->addLayout(topLay, Qt::AlignCenter);
	mainLay->addLayout(midLay, Qt::AlignCenter);
	mainLay->addLayout(bottomLay, Qt::AlignCenter);
	mainLay->setSpacing(7);
	//�������������뷽ʽ�������˺ܶ���·
	mainLay->setContentsMargins(200, 200, 0, 50);
	setLayout(mainLay);
	setWindowTitle("������֤ʶ��ϵͳ");
	//���ô�Сͼ��
	setFixedSize(600, 400);
	QIcon icon(":/allImg/img/face.jpg");
	setWindowIcon(icon);
	//���ñ���
	QPalette pt;
	pt.setBrush(QPalette::Background, QBrush(QPixmap(":/allImg/img/cc.jpg")));
	setAutoFillBackground(true);
	setPalette(pt);

	//���ó���
	uint now = QDateTime::currentDateTime().toTime_t();
	if (now<QDateTime::fromString(QDate::currentDate().toString("yyyy-MM-dd") + " 09:30:00", "yyyy-MM-dd hh:mm:ss").toTime_t()) {
		changci = "ְҵ����";
	}
	else if (now<QDateTime::fromString(QDate::currentDate().toString("yyyy-MM-dd") + " 11:20:00", "yyyy-MM-dd hh:mm:ss").toTime_t()) {
		changci = "ְҵ����";
	}
	else {
		changci = "��λ����";
	}

	connect(this, SIGNAL(overLogin()), this, SLOT(handlerOverLogin()));
}

void Login::userLogin() {
	//���ݼ��
	QString uname = username->text().trimmed();
	QString pwd = password->text().trimmed();
	if (uname != ""&&pwd != "") {
		//�������ݿ��ѯ,���Ҹ��¿�Ŀ
		faceAdminService = new FaceAdminService;
		Faceadmin admin = faceAdminService->queryByUserAndPwd(uname, pwd, changci);
		if (admin.getBmname() != "") {
			//����paramsetup�������
			paramService = new ParamSetupService;
			if (paramService->getAllCount() == 0) {
				paramService->insertIntoParamsets(admin.getBmname());
			}
			// mainwin.show();
			mainWin = new MainWin;
			mainWin->show();
			this->close();
			emit(overLogin());
		}
		else {
			QMessageBox::information(NULL, "��ʾ", "�û�������������", QMessageBox::Yes);
		}
	}

}
void Login::handlerOverLogin() {

}
Login::~Login()
{
	if (faceAdminService != nullptr) {
		delete faceAdminService;
	}
	if (paramService != nullptr) {
		delete paramService;
	}
	if (mainWin != nullptr) {
		delete mainWin;
	}

}
