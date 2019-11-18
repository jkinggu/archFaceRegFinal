#pragma once

#ifndef FACEREG_AUTHENTICRESTJ_H
#define FACEREG_AUTHENTICRESTJ_H


#include "qmainwindow.h"
#include "ui_AuthenticResTj.h"
#include "ParamSetupService.h"
#include "AuthenticTjPojo.h"
#include <qdesktopwidget.h>
#include "CommonUtil.h"
#pragma execution_character_set("utf-8");
class AuthenticResTj : public QMainWindow
{
	Q_OBJECT
private:
	Ui::AuthenticResTj *ui;
	ParamSetupService *paramSetupService;
	QString kd;
	QString changci;
	QString shijian;
	int currentpage;
public:
	AuthenticResTj(QWidget *parent=0);
	~AuthenticResTj();
	void showEvent(QShowEvent *event);
	void resizeEvent(QResizeEvent *event);

private:
	void showPageResultInPanel(const QString &kd, const QString &changci, const QString &shijian, const int &currentPage);
	void  createItemsARow(const int &row, AuthenticTjPojo &authTjpo);

private slots:
	void changeKdItem();
	void showAuthTjResult();
};

#endif // !FACEREG_AUTHENTICRESTJ_H