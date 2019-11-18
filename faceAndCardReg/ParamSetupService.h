#pragma once

#ifndef FACEREG_PARAMSETUPSERVICE_H
#define FACEREG_PARAMSETUPSERVICE_H

#include "SqlLiteLoader.h"
#include <qstring.h>
#include<qvector.h>
#include<qvariant.h>
#include<qlist.h>
#include<qdatetime.h>
#include<QtSql/qsqlquery.h>
#include "ParamSetup.h"
#include "PageResult.h"
#include "AuthenticTjPojo.h"
#include "CommonUtil.h"
#include "AuthenticCon.h"
class ParamSetupService :public SqlLiteLoader
{
private:
	QSqlQuery query;
public:
	ParamSetupService();
	~ParamSetupService();
	int getAllCount();
	void insertIntoParamsets(const QString &uname);
	QVector<QString> getCity();
	QList<QString> getKdByCity(const QString &cityName);
	PageResult<AuthenticTjPojo> getAuthTjByCon(const QString &kd, const QString &changci, const QString &shijian, const int &currentPage);
	bool initSysData();
	bool initRenZhData();
private:
	AuthenticTjPojo getAuthTjByCondition(const QString &kd, const QString &changci, const QString &shijian);
	int getCountBySql(const QString &sql);
};

#endif