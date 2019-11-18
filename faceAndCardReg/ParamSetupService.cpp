#include "ParamSetupService.h"

ParamSetupService::ParamSetupService() :query(QSqlQuery(db))
{
}

int ParamSetupService::getAllCount() {
	QString sql = "select count(*) from paramsetup";
	query.clear();
	query.exec(sql);
	int count = 0;
	if (query.next()) {
		count = query.value(0).toInt();
	}
	return count;
}
void ParamSetupService::insertIntoParamsets(const QString &uname) {
	QString sql = "SELECT  p.*,b.No1Code FROM (SELECT dishiname,kd1,kc1,sj1,sj3,dd1 FROM zkzdata  GROUP BY   dishiname,kd1,kc1,sj1,sj3,dd1) p  LEFT  join (SELECT No1Code,No1 FROM belongfor GROUP BY No1,No1Code) b ON p.dishiname=b.No1";
	QVector<ParamSetup> paramLists;
	query.clear();
	query.exec(sql);
	while (query.next()) {
		ParamSetup param;
		param.setDishi(query.value("No1Code").toString());
		param.setDishiname(query.value("dishiname").toString());
		param.setKaodianname(query.value("kd1").toString());
		param.setKaochang(query.value("kc1").toString());
		param.setStarttime(query.value("sj1").toString());
		param.setEndtime(query.value("sj3").toString());
		param.setDidian(query.value("dd1").toString());
		param.setAdminname(uname);
		param.setUstatu(QString::number(0));
		paramLists.append(param);
	}

	if (paramLists.size()>0) {
		QString insertSql = "insert into paramsetup(dishi,dishiname,kaodianname,kaochang,starttime,endtime,adminname,didian,ustatu ) values(?,?,?,?,?,?,?,?,?)";
		for (ParamSetup p : paramLists) {
			query.clear();
			query.prepare(insertSql);
			query.bindValue(0, p.getDishi());
			query.bindValue(1, p.getDishiname());
			query.bindValue(2, p.getKaodianname());
			query.bindValue(3, p.getKaochang());
			query.bindValue(4, p.getStarttime());
			query.bindValue(5, p.getEndtime());
			query.bindValue(6, p.getAdminname());
			query.bindValue(7, p.getDidian());
			query.bindValue(8, p.getUstatu());
			query.exec();
		}
	}
}

bool ParamSetupService::initRenZhData() {
	query.clear();
	try {

		QString sql = " DELETE FROM facelog  ";
		query.exec(sql);
		sql = "update sqlite_sequence SET seq = 0 where name ='facelog'";
		query.exec(sql);
		sql = "update paramsetup set ustatu='0' ";
		query.exec(sql);
		return  true;
	}
	catch (std::exception e) {
		return false;

	}

}
bool ParamSetupService::initSysData() {
	try {
		query.clear();
		QString sql = "delete from facelog ";
		query.exec(sql);
		sql = "update sqlite_sequence SET seq = 0 where name ='facelog'";
		query.exec(sql);

		sql = "delete from belongfor ";
		query.exec(sql);
		sql = "update sqlite_sequence SET seq = 0 where name ='belongfor'";
		query.exec(sql);

		sql = "delete from paramsetup ";
		query.exec(sql);
		sql = "update sqlite_sequence SET seq = 0 where name ='paramsetup'";
		query.exec(sql);
		sql = "delete from zkzdata ";
		query.exec(sql);
		sql = "update sqlite_sequence SET seq = 0 where name ='zkzdata'";
		query.exec(sql);
		return true;
	}
	catch (std::exception e) {
		return false;
	}

}

PageResult<AuthenticTjPojo> ParamSetupService::getAuthTjByCon(const QString &kd, const QString &changci, const QString &shijian, const int &currentPage) {
	QVector<AuthenticTjPojo> authTjVector;
	if (kd == "") {
		QString sql = "SELECT SUBSTR(shijian,0,LENGTH(shijian)-8) shijian,changci,kd FROM facelog  GROUP BY SUBSTR(shijian,0,LENGTH(shijian)-8),changci,kd";
		QVector<AuthenticCon> authCons;
		query.clear();
		query.exec(sql);
		while (query.next()) {
			AuthenticCon authCon;
			authCon.setShijian(query.value(0).toString());
			authCon.setChangci(query.value(1).toString());
			authCon.setKaodian(query.value(2).toString());
			authCons.append(authCon);
		}
		if (!authCons.empty()) {
			for (int i = 0; i<authCons.size(); i++) {
				AuthenticCon auConTmp = authCons[i];
				AuthenticTjPojo authenticTjPojo = getAuthTjByCondition(auConTmp.getKaodian(), auConTmp.getChangci(), auConTmp.getShijian());
				//qDebug()<<authenticTjPojo.getShijain()<<"--------"<<authenticTjPojo.getNeedCheck();
				authTjVector.push_back(authenticTjPojo);
			}

		}
		return PageResult<AuthenticTjPojo>(authTjVector, 1, 1);
	}
	else {
		authTjVector.push_back(getAuthTjByCondition(kd, changci, shijian));
		return PageResult<AuthenticTjPojo>(authTjVector, 1, 1);
	}
}

AuthenticTjPojo ParamSetupService::getAuthTjByCondition(const QString &kd, const QString &changci, const QString &shijian) {
	QString dataSql = "";
	QString zkzSql = "";
	QString formatTime = "";
	if (!shijian.isNull() && shijian != "") {
		formatTime = timeFormat::formatTime(shijian);
		dataSql = " AND f1.shijian LIKE '" + formatTime + "%' ";
		zkzSql = " AND z.sj1 LIKE '" + formatTime + "%' ";
	}
	else {
		formatTime = timeFormat::formatTime(QDate::currentDate().toString("yyyy-MM-dd"));
		dataSql = " AND f1.shijian LIKE '" + formatTime + "%' ";
		zkzSql = " AND z.sj1 LIKE '" + formatTime + "%' ";
	}
	QString needCheckSql = "SELECT COUNT(*) FROM ( SELECT * FROM facelog f1 WHERE f1.changci='" + changci + "' AND f1.kd IS '" + kd + "'  AND f1.shibieleixingint IN('1','4') " + dataSql + " AND f1.sfz NOT IN ( SELECT f.sfz FROM facelog f  WHERE  f.changci='" + changci + "' AND f.shibieleixingint IS '7' AND  f.kd IS '" + kd + "' GROUP BY f.sfz) GROUP BY f1.sfz ORDER BY f1.shijian DESC)";
	QString notPassSql = "SELECT COUNT(*) FROM (SELECT * FROM facelog WHERE changci='" + changci + "' AND kd IS '" + kd + "' AND  shibieleixingint  NOT IN ('7','2','1','4')  GROUP BY sfz ORDER BY shijian DESC ) f1  WHERE  f1.sfz NOT IN (SELECT sfz FROM facelog WHERE changci='" + changci + "' AND shibieleixingint IS '7' AND kd IS '" + kd + "'  GROUP BY sfz ORDER BY  shijian ) " + dataSql;
	QString passSql = "SELECT COUNT(*) FROM ( SELECT sfz FROM facelog f1 WHERE f1.changci='" + changci + "' AND  f1.kd IS '" + kd + "' AND f1.shibieleixingint IS '7' " + dataSql + "  GROUP BY f1.sfz ORDER BY   f1.shijian DESC)";
	QString noRecordSql = "SELECT  COUNT(*)    FROM zkzdata z  WHERE  z.upersonnum  NOT IN (SELECT f1.sfz FROM facelog f1 WHERE f1.changci='" + changci + "' AND f1.kd IS '" + kd + "' AND f1.shibieleixingint IN ('1','4','7','5','6')  " + dataSql + "  GROUP BY f1.sfz ORDER BY  f1.shijian DESC) " + zkzSql;
	int needCheck = getCountBySql(needCheckSql);
	int notPass = getCountBySql(notPassSql);
	int pass = getCountBySql(passSql);
	int noRecord = getCountBySql(noRecordSql);
	AuthenticTjPojo authenticTjPojo;
	authenticTjPojo.setKd(kd);
	authenticTjPojo.setShijain(formatTime);
	authenticTjPojo.setChangci(changci);
	authenticTjPojo.setNeedCheck(QString::number(needCheck));
	authenticTjPojo.setNotPass(QString::number(notPass));
	authenticTjPojo.setPass(QString::number(pass));
	authenticTjPojo.setNoRecord(QString::number(noRecord));
	return authenticTjPojo;
}

int ParamSetupService::getCountBySql(const QString &sql) {
	query.clear();
	query.exec(sql);
	int res = 0;
	if (query.next()) {
		res = query.value(0).toInt();
	}

	return  res;
}

QVector<QString> ParamSetupService::getCity() {
	QString sql = "SELECT b.no1 FROM belongfor b,faceadmin f WHERE ((b.no1code=f.bmname AND f.bmname != 'admin' ) OR (f.bmname = 'admin')) AND  b.no1code>0 AND f.curmana='1' GROUP BY no1";
	QVector<QString> citys;
	query.clear();
	query.exec(sql);
	while (query.next()) {
		citys.append(query.value(0).toString());
	}
	return citys;
}

QList<QString> ParamSetupService::getKdByCity(const QString &cityName) {
	QString sql = "select kd1 from zkzdata where  dishiname LIKE '%" + cityName + "%' and jbcode !='5' group by   dd1,kd1 ";
	QList<QString> kds;
	query.clear();
	query.exec(sql);
	while (query.next()) {
		kds.append(query.value(0).toString());
	}
	return  kds;
}

ParamSetupService::~ParamSetupService()
{
}
