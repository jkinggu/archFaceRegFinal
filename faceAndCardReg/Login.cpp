#include "Login.h"

Login::Login(QWidget *parent) :QDialog(parent), faceAdminService(nullptr), paramService(nullptr), mainWin(nullptr) {
	QRegExp regExp("[A-Za-z0-9]{1,8}");
	loginFont = new QFont("Microsoft YaHei", 12, QFont::Normal);

	ulabel = new QLabel("用户名:");
	ulabel->setFont(*loginFont);
	username = new QLineEdit;
	username->setFont(*loginFont);
	username->setAlignment(Qt::AlignLeft);
	username->setFixedSize(130, 25);
	username->setMaxLength(130);
	username->setValidator(new QRegExpValidator(regExp));
	//ulabel->setBuddy(username);

	plabel = new QLabel("密   码:");
	plabel->setFont(*loginFont);
	password = new QLineEdit;
	password->setEchoMode(QLineEdit::Password);
	password->setFont(*loginFont);
	password->setFixedSize(130, 25);
	password->setMaxLength(130);
	password->setAlignment(Qt::AlignLeft);
	password->setValidator(new QRegExpValidator(regExp));
	// plabel->setBuddy(password);

	checkBtn = new QPushButton("登陆");
	checkBtn->setFont(*loginFont);
	checkBtn->setFixedSize(95, 30);
	connect(checkBtn, SIGNAL(clicked()), this, SLOT(userLogin()));



	cancelBtn = new QPushButton("取消");
	cancelBtn->setFont(*loginFont);
	cancelBtn->setFixedSize(95, 30);
	connect(cancelBtn, SIGNAL(clicked()), this, SLOT(close()));


	//手动布局
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
	//最简单设置组件距离方式。我走了很多弯路
	mainLay->setContentsMargins(200, 200, 0, 50);
	setLayout(mainLay);
	setWindowTitle("鼎星认证识别系统");
	//设置大小图标
	setFixedSize(600, 400);
	QIcon icon(":/allImg/img/face.jpg");
	setWindowIcon(icon);
	//设置背景
	QPalette pt;
	pt.setBrush(QPalette::Background, QBrush(QPixmap(":/allImg/img/cc.jpg")));
	setAutoFillBackground(true);
	setPalette(pt);

	//设置场次
	uint now = QDateTime::currentDateTime().toTime_t();
	if (now<QDateTime::fromString(QDate::currentDate().toString("yyyy-MM-dd") + " 09:30:00", "yyyy-MM-dd hh:mm:ss").toTime_t()) {
		changci = "职业道德";
	}
	else if (now<QDateTime::fromString(QDate::currentDate().toString("yyyy-MM-dd") + " 11:20:00", "yyyy-MM-dd hh:mm:ss").toTime_t()) {
		changci = "职业能力";
	}
	else {
		changci = "岗位技能";
	}

	connect(this, SIGNAL(overLogin()), this, SLOT(handlerOverLogin()));
}

void Login::userLogin() {
	//数据检查
	QString uname = username->text().trimmed();
	QString pwd = password->text().trimmed();
	if (uname != ""&&pwd != "") {
		//连接数据库查询,并且更新科目
		faceAdminService = new FaceAdminService;
		Faceadmin admin = faceAdminService->queryByUserAndPwd(uname, pwd, changci);
		if (admin.getBmname() != "") {
			//生成paramsetup表格内容
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
			QMessageBox::information(NULL, "提示", "用户名或密码有误", QMessageBox::Yes);
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
