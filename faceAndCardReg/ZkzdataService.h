#pragma once
#ifndef FACEREG_ZKZDATASERVICE_H
#define  FACEREG_ZKZDATASERVICE_H


#include "SqlLiteLoader.h"
#include "qsqlquery.h"
#include "ZkzdataPojo.h"
#include <QVariant>
#include <qlist.h>
#pragma execution_character_set("utf-8");
class ZkzdataService :public SqlLiteLoader
{
private:
	QSqlQuery query;
public:
	ZkzdataService();
	~ZkzdataService();
	ZkzdataPojo queryZkzdataBySfzNum(const QString &sfz);
	QList<QString> queryConByCardNum(const QString &cnum);
	QList<QString> queryShowResByCardNum(const QString &cnum);

};

#endif // !FACEREG_ZKZDATASERVICE_H