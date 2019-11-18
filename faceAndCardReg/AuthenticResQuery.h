#pragma once
#ifndef FACEREG_AUTHENTICRESQUERY_H
#define FACEREG_AUTHENTICRESQUERY_H


#pragma execution_character_set("utf-8");
#include "qmainwindow.h"
#include "ui_AuthenticResQuery.h"
#include <qdesktopwidget.h>
#include "FaceLogService.h"
#include "ZkzdataPojo.h"
#include "NeedCheck.h"
#include "ZkzdataService.h"
#include "MyMessageBox.h"
#include <QDebug>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/QPrintDialog>
#include <QtPrintSupport/QPrintPreviewDialog>
#include <QPainter>
#include <QVector>
#include <qdatetime.h>
class AuthenticResQuery : public QMainWindow
{
	Q_OBJECT
public:
	AuthenticResQuery(QWidget *parent = 0);
	~AuthenticResQuery();
private:
	void resizeEvent(QResizeEvent *event);
	void  showEvent(QShowEvent *event);
	void showPageResultInPanel(QString& kd, QString& kc, QString& rzRes, QString& shijian, int& currentPage);
	void createItemsARow(int& row, AuthenticResultPojo& authRepo);
	void setConditionAndShow(int curPage = 1);

private slots:
	void  queryByCon();
	void queryNextPage();
	void queryPrePage();
	void queryLastpage();
	void doPrintPreview();
	void printPreview(QPrinter *printer);
	void itemCheckState(int row, int col);

private:
	Ui::AuthenticResQuery *ui;
	FaceLogService *faceLogService;
	ZkzdataService *zkzdataService;
	//查询条件
	QString changci;
	QString kd;
	QString kc;
	QString auRes;
	QString shijian;
	PageResult<AuthenticResultPojo> pageResult;
	int currentPage;
	//要打印对象
	QVector<NeedCheck> checkNeedList;


};

#endif // !FACEREG_AUTHENTICRESQUERY_H