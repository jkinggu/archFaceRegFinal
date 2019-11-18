#pragma once
#ifndef FACEREG_FACEADMINSERVICE_H
#define FACEREG_FACEADMINSERVICE_H
#include "SqlLiteLoader.h"
#include "Faceadmin.h"
#include <QtSql/qsqlquery.h>
#include <CommonUtil.h>
#include "FaceAdmin.h"
class FaceAdminService :public SqlLiteLoader
{
private:
	QSqlQuery query;
public:
	FaceAdminService();
	~FaceAdminService();
	Faceadmin queryByUserAndPwd(const QString &username, const QString &password, const QString &changci);
	Faceadmin queryCurrentUser();

};

#endif // !FACEREG_FACEADMINSERVICE_H