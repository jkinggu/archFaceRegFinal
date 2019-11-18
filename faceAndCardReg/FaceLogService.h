#pragma once
#ifndef FACEREG_FACELOGSERVICE_H
#define FACEREG_FACELOGSERVICE_H
#pragma execution_character_set("utf-8");
#include "SqlLiteLoader.h"
#include "AuthenticPojo.h"
#include "FaceLog.h"
#include "qsqlquery.h"
#include "qsqlrecord.h"
#include "PageResult.h"
#include "CommonUtil.h"
#include<QVariant>
#include <QVector>
#include <QDebug>
class FaceLogService : public SqlLiteLoader
{
private:
	QSqlQuery query;
public:
	FaceLogService();
	~FaceLogService();
	int queryFaceLogByCardNumAndChangci(const QString &cnum, const QString &changci);
	int queryFaceLogByCardNum(const QString &cnum);
	int queryRzCount(const QString &cnum, const QString &changci);
	void insertIntoFaceLog(const FaceLog& faceLog);
	void insertIntoFaceLogs(const FaceLog& faceLog);
	void updateFaceLogByCardNum(const FaceLog& faceLog);
	PageResult<AuthenticResultPojo> queryByCon(QString& changci, QString& kd, QString& kc, QString& rzRes, QString& shijian, int& currentPage);

	PageResult<FaceLog> getAuthenticLogs(const QString &cc, const QString &xm, const QString &lx, const  QString &shijian, const int &currentPage);
	PageResult<AuthenticResultPojo> queryByCon(QString& kd, QString& kc, QString& rzRes, QString& shijian, int& currentPage);
	void  getAuthenticLog(const QString &cc, const QString &xm, const QString &lx, const  QString &shijian, const int &currentPage);

};

#endif // !FACEREG_FACELOGSERVICE_H