#pragma once
#ifndef FACEREG_SQLLITELOADER_H
#define FACEREG_SQLLITELOADER_H
#include <qcoreapplication.h>
#include <qsqldatabase.h>
#include<qdebug.h>
#include<qstring.h>
#include<qplugin.h>
#include <qfileinfo.h>
#include <qdir.h>
class SqlLiteLoader{
public:
	SqlLiteLoader();
	~SqlLiteLoader();
protected:
	QSqlDatabase db;
	bool openFlag;
};
#endif // !FACEREG_SQLLITELOADER_H


