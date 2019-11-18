#include "MainWin.h"
#include<qdebug.h>
MainWin::MainWin(QWidget *parent):QMainWindow(parent),ui(new Ui::MainWin),authQuery(nullptr),authLogs(nullptr),authTj(nullptr),camerControllerPanel(nullptr)
{   //不能设置窗体透明度，暂时禁止
	ui->setupUi(this);
	QFont *mwFont = new QFont("Microsoft YaHei", 12, QFont::Normal);
	setWindowIcon(QIcon(":/allImg/img/face.jpg"));
	setWindowTitle("鼎星认证识别系统");
	setFixedSize(QApplication::desktop()->geometry().width() - 20, QApplication::desktop()->geometry().height() - 20);
	setFont(*mwFont);
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Background, QBrush(QPixmap(":/allImg/img/bg.jpg")));
	this->setPalette(palette);
	this->setAutoFillBackground(true);
	connect(ui->camStr, SIGNAL(triggered()), this, SLOT(camStart()));
	connect(ui->actionRzResu, SIGNAL(triggered()), this, SLOT(authResQuPanel()));
	connect(ui->actionRzSta, SIGNAL(triggered()), this, SLOT(authResTjPanel()));
	connect(ui->actionRzLog, SIGNAL(triggered()), this, SLOT(authResLogsPanel()));
	connect(ui->actionSysDataIni, SIGNAL(triggered()), this, SLOT(sysDataInit()));
	connect(ui->actionRzDatainit, SIGNAL(triggered()), this, SLOT(rzDataInit()));

}

void MainWin::rzDataInit() {

}
void MainWin::sysDataInit() {


}

void MainWin::authResLogsPanel() {
	authLogs = new AuthenticLogsDetail;
	authLogs->show();
}
void MainWin::authResTjPanel() {
	authTj = new AuthenticResTj;
	authTj->show();
}

void MainWin::authResQuPanel() {
	authQuery = new AuthenticResQuery;
	authQuery->show();
}
void MainWin::camStart() {
	camerControllerPanel = new CamerControllerPanel;
	connect(camerControllerPanel, SIGNAL(camClose()), this, SLOT(handlerCamerCtrlClose()));
}

void MainWin::handlerCamerCtrlClose() {
	//qDebug() << "enter destroy";
	delete camerControllerPanel;
	camerControllerPanel = nullptr;
}
MainWin::~MainWin()
{
	delete ui;
	if (authQuery != nullptr) {
		delete authQuery;
	}
	if (authLogs != nullptr) {
		delete authLogs;
	}
	if (authTj != nullptr) {
		delete authTj;
	}
}
