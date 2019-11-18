#pragma once
#ifndef FACEREG_LOGIN_H
#define FACEREG_LOGIN_H
#pragma execution_character_set("utf-8");
#include<qdialog.h>
#include<qlineedit.h>
#include<qpushbutton.h>
#include<qlabel.h>
#include<qfont.h>
#include<qstring.h>
#include<qregexp.h>
#include<qicon.h>
#include<qbitmap.h>
#include<qboxlayout.h>
#include<qdatetime.h>
#include<qvalidator.h>
#include"FaceAdminService.h"
#include "qmessagebox.h"
#include "ParamSetupService.h"
#include "MainWin.h"
class Login :public QDialog {
	Q_OBJECT
private:
	QLabel *ulabel;
	QLabel *plabel;
	QLineEdit *username;
	QLineEdit *password;
	QPushButton *checkBtn;
	QPushButton *cancelBtn;
	QFont *loginFont;
	QString changci;
	FaceAdminService *faceAdminService;
	ParamSetupService *paramService;
	MainWin *mainWin;
	private slots:
	void userLogin();
	void handlerOverLogin();
public:
	Login(QWidget *parent = 0);
	~Login();
signals:
	void overLogin();
};

#endif
