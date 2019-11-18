#pragma once
#pragma execution_character_set("utf-8");
#ifndef FACEREG_AUTHENTICLOGSDETAIL_H
#define FACEREG_AUTHENTICLOGSDETAIL_H

#include "qmainwindow.h"
#include "FaceLogService.h"
#include <qdesktopwidget.h>
#include <qdialog.h>
#include <QVector>
#include "ui_AuthenticLogsDetail.h"
class AuthenticLogsDetail : public QMainWindow
{
	Q_OBJECT
private:
	Ui::AuthenticLogsDetail *ui;
	QString changci;
	QString xingming;
	QString authRes;
	QString shijian;
	int currentPage;
	PageResult<FaceLog> pageResult;
	FaceLogService *faceLogService;

public:
	AuthenticLogsDetail(QWidget *parent = 0);
	~AuthenticLogsDetail();

private:
	void showEvent(QShowEvent *event);
	void resizeEvent(QResizeEvent *event);
	void showFaceLogsPanel(const QString &changci, const QString &xingming, const QString &authRes, const QString &shijian, const int &curPag);
	void createAItem(int &row, FaceLog &faceLog);
	void showFaceLogsPanelByPage(const int &curPag);

private slots:
	void  handleCellDoubleClick(int row, int col);
	void queryFirst();
	void queryNextPage();
	void queryPrePage();
	void queryLastpage();

};

#endif // !FACEREG_AUTHENTICLOGSDETAIL_H