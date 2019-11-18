#pragma once
#pragma execution_character_set("utf-8");
#ifndef FACEREG_MAINWIN_H
#define FACEREG_MAINWIN_H
#include "ui_MainWin.h"
#include "qdesktopwidget.h"
#include <QBitmap>
#include "MyMessageBox.h"
#include "AuthenticResQuery.h"
#include "AuthenticLogsDetail.h"
#include "AuthenticResTj.h"
#include "CamerControllerPanel.h"

class MainWin:public QMainWindow{
	Q_OBJECT
public:
	MainWin(QWidget *parent=0);
	~MainWin();
private:
	Ui::MainWin *ui;
	CamerControllerPanel *camerControllerPanel;
	AuthenticResQuery *authQuery;
	AuthenticLogsDetail *authLogs;
	AuthenticResTj *authTj;
private slots:
	void camStart();
	void authResQuPanel();
	void authResTjPanel();
	void authResLogsPanel();
	void sysDataInit();
	void rzDataInit();
	void handlerCamerCtrlClose();
};

#endif