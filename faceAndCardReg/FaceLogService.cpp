#include "FaceLogService.h"



FaceLogService::FaceLogService() : query(QSqlQuery(db)) {
}


void  FaceLogService::getAuthenticLog(const QString &cc, const QString &xm, const QString &lx, const  QString &shijian, const int &currentPage) {
	QString baseSql = "SELECT * FROM facelog ";
	QString countSql = "SELECT COUNT(*) FROM facelog";
	QString tiaojian = "";
	bool m = false;
	if (cc != "") {
		if (m) {
			tiaojian = tiaojian + " AND  changci='" + cc + "' ";
		}
		else {
			tiaojian = tiaojian + " WHERE  changci='" + cc + "' ";
			m = true;
		}
	}

	if (xm != "") {
		if (m) {
			tiaojian = tiaojian + " AND  xingming LIKE '%" + xm + "%' ";
		}
		else {
			tiaojian = tiaojian + " WHERE  xingming LIKE '%" + xm + "%' ";
			m = true;
		}
	}

	if (lx != "") {
		if (m) {
			tiaojian = tiaojian + "  AND   shibieleixing='" + lx + "' ";
		}
		else {
			tiaojian = tiaojian + "  WHERE shibieleixing='" + lx + "' ";
			m = true;
		}
	}

	if (shijian != "") {
		QString ftime = shijian;
		ftime = timeFormat::formatTime(ftime);
		if (m) {
			tiaojian = tiaojian + " and shijian LIKE '" + ftime + "%' ";
		}
		else {
			tiaojian = tiaojian + " where shijian LIKE '" + ftime + "%' ";
			m = true;
		}
	}


	if (m) {
		baseSql += tiaojian;
		countSql += tiaojian;
	}
	baseSql += " ORDER BY shijian desc LIMIT ?,?";

	QVector<FaceLog> flogs;
	query.clear();
	query.prepare(baseSql);
	query.bindValue(0, (currentPage - 1) * 20);
	query.bindValue(1, 20);
	query.exec();
	while (query.next()) {
		FaceLog facelog;
		facelog.setId(query.value(0).toInt());
		facelog.setSfz(query.value(1).toString());
		facelog.setXingming(query.value(2).toString());
		facelog.setXingbie(query.value(3).toString());
		facelog.setShibieleixing(query.value(4).toString());
		facelog.setShibieleixingint(query.value(5).toString());
		facelog.setShijian(query.value(6).toString());
		facelog.setRenlianphoto(query.value(7).toString());
		facelog.setRemarks(query.value(8).toString());
		facelog.setSfzphoto(query.value(9).toString());
		facelog.setChangci(query.value(10).toString());
		facelog.setDenglumana(query.value(11).toString());
		facelog.setRenzcount(query.value(12).toString());
		facelog.setXsd(query.value(13).toString());
		facelog.setZkzPhoto(query.value(14).toString());
		facelog.setKd(query.value(15).toString());
		flogs.push_back(facelog);
	}
	query.clear();
	query.exec(countSql);
	int totalCount = 0;
	if (query.next()) {
		totalCount = query.value(0).toInt();
	}

}

PageResult<FaceLog> FaceLogService::getAuthenticLogs(const QString &cc, const QString &xm, const QString &lx, const QString &shijian, const int &currentPage) {
	QString baseSql = "SELECT * FROM facelog ";
	QString countSql = "SELECT COUNT(*) FROM facelog";
	QString tiaojian = "";
	bool m = false;
	if (cc != "") {
		if (m) {
			tiaojian = tiaojian + " AND  changci='" + cc + "' ";
		}
		else {
			tiaojian = tiaojian + " WHERE  changci='" + cc + "' ";
			m = true;
		}
	}

	if (xm != "") {
		if (m) {
			tiaojian = tiaojian + " AND  xingming LIKE '%" + xm + "%' ";
		}
		else {
			tiaojian = tiaojian + " WHERE  xingming LIKE '%" + xm + "%' ";
			m = true;
		}
	}

	if (lx != "") {
		if (m) {
			tiaojian = tiaojian + "  AND   shibieleixing='" + lx + "' ";
		}
		else {
			tiaojian = tiaojian + "  WHERE shibieleixing='" + lx + "' ";
			m = true;
		}
	}

	if (shijian != "") {
		QString ftime = shijian;
		ftime = timeFormat::formatTime(ftime);
		if (m) {
			tiaojian = tiaojian + " and shijian LIKE '" + ftime + "%' ";
		}
		else {
			tiaojian = tiaojian + " where shijian LIKE '" + ftime + "%' ";
			m = true;
		}
	}
	if (m) {
		baseSql += tiaojian;
		countSql += tiaojian;
	}
	baseSql += " ORDER BY shijian desc LIMIT ?,?";


	QVector<FaceLog> flogs;
	query.clear();
	query.prepare(baseSql);
	query.bindValue(0, (currentPage - 1) * 20);
	query.bindValue(1, 20);
	query.exec();
	while (query.next()) {
		FaceLog facelog;
		facelog.setId(query.value(0).toInt());
		facelog.setSfz(query.value(1).toString());
		facelog.setXingming(query.value(2).toString());
		facelog.setXingbie(query.value(3).toString());
		facelog.setShibieleixing(query.value(4).toString());
		facelog.setShibieleixingint(query.value(5).toString());
		facelog.setShijian(query.value(6).toString());
		facelog.setRenlianphoto(query.value(7).toString());
		facelog.setRemarks(query.value(8).toString());
		facelog.setSfzphoto(query.value(9).toString());
		facelog.setChangci(query.value(10).toString());
		facelog.setDenglumana(query.value(11).toString());
		facelog.setRenzcount(query.value(12).toString());
		facelog.setXsd(query.value(13).toString());
		facelog.setZkzPhoto(query.value(14).toString());
		facelog.setKd(query.value(15).toString());
		flogs.push_back(facelog);
	}
	query.clear();
	query.exec(countSql);
	int totalCount = 0;
	if (query.next()) {
		totalCount = query.value(0).toInt();
	}
	return PageResult<FaceLog>(flogs,totalCount,currentPage);
}

PageResult<AuthenticResultPojo> FaceLogService::queryByCon(QString& kd, QString& kc, QString& rzRes, QString& shijian, int& currentPage) {
	QString baseSql = "SELECT z.id, z.xingming,z.xingbie,z.upersonnum,f.changci,z.baokaoname,z.jbname,z.kc1,z.zh1,z.zkznum,f.shijian,f.shibieleixing,f.renzcount,f.renlianphoto,f.sfzphoto   FROM zkzdata z  JOIN  ";
	QString zkzSql = "";
	QString zkzdataSql = "";
	//拼接内层facelogsql
	QString faceSql = "";
	QString dataSql = "";

	QString countSql = "SELECT COUNT(*)  FROM zkzdata z  JOIN ";
	if (shijian != "") {
		QString formatTime = timeFormat::formatTime(shijian);
		dataSql = " AND f1.shijian LIKE '" + formatTime + "%' ";
		zkzdataSql = " AND z.sj1 LIKE '" + formatTime + "%' ";
	}
	

	if (rzRes != "") {
		faceSql = "";

		if (rzRes == "禁止通过") {
			faceSql = " (SELECT * FROM facelog f1 WHERE  f1.sfz NOT IN (SELECT sfz from facelog WHERE  f1.shibieleixingint IS '1' ) AND  f1.shibieleixingint IS '2' " + dataSql + "  GROUP BY f1.sfz ORDER BY   f1.shijian DESC) f ";

		}
		else if (rzRes == "通过") {
			faceSql = " (SELECT * FROM facelog f1 WHERE  f1.shibieleixingint IS '1' " + dataSql + "  GROUP BY f1.sfz ORDER BY   f1.shijian DESC) f ";

		}
		else if (rzRes == "姓名不一致") {
			faceSql = " (SELECT * FROM facelog f1 WHERE  f1.shibieleixingint IS '3' " + dataSql + "  GROUP BY f1.sfz ORDER BY   f1.shijian DESC) f ";
		}
		else if (rzRes == "无识别记录") {
			faceSql = " (SELECT f1.sfz FROM facelog f1 WHERE f1.shibieleixingint IN ('1','2','3') " + dataSql + "  GROUP BY f1.sfz ORDER BY  f1.shijian DESC) ";

		}
	}

		//拼接外层zkzdata数据库 sql和上面内层sql结合
		if (kd != NULL&&kd.trimmed() != "") {
			if (zkzSql.trimmed() != "") {
				zkzSql += " AND  z.kd1 LIKE '%" + kd + "%' ";
			}
			else {
				zkzSql = " AND z.kd1 LIKE '%" + kd + "%' ";
			}
		}

		if (kc != NULL && kc != "") {
			if (zkzSql.trimmed() != "") {
				zkzSql += "AND z.kc1 LIKE '%" + kc + "%' ";
			}
			else {
				zkzSql = " AND z.kc1 LIKE '%" + kc + "%' ";
			}
		}

	//拼接预备完成sql还差分页
	//未来的人，特殊处理
	if (rzRes.contains("无识别记录")) {
		baseSql = " SELECT z.id, z.xingming ,z.xingbie,z.upersonnum,'无信息',z.baokaoname,z.jbname,z.kc1,z.zh1,'无信息','无信息','无信息','无信息','无信息','无信息'  FROM zkzdata z   WHERE z.upersonnum  NOT IN " + faceSql + zkzSql + zkzdataSql;
		countSql = " SELECT COUNT(*)  FROM zkzdata z  WHERE z.upersonnum  NOT IN " + faceSql + zkzSql + zkzdataSql;
	}else {
		baseSql += (faceSql + " ON f.sfz=z.upersonnum " + zkzSql);
		//计算总条数
		countSql += (faceSql + " ON f.sfz=z.upersonnum " + zkzSql);
	}


	//拼接分页
	if (currentPage>0) {
		baseSql += " LIMIT " + QString::number((currentPage - 1) * 25) + " , 25 ";
	}


	QVector<AuthenticResultPojo> auRlist;
	query.exec(baseSql);
	while (query.next()) {
		AuthenticResultPojo authRepo;
		authRepo.id = query.value(0).toLongLong();
		authRepo.xingming = query.value(1).toString();
		authRepo.xingbie = query.value(2).toString();
		authRepo.sfz = query.value(3).toString();
		authRepo.kemu = query.value(4).toString();
		authRepo.gongzh = query.value(5).toString();
		authRepo.level = query.value(6).toString();
		authRepo.kc = query.value(7).toString();
		authRepo.zh = query.value(8).toString();
		authRepo.zkz = query.value(9).toString();
		authRepo.shijian = query.value(10).toString();
		authRepo.aures = query.value(11).toString();
		authRepo.auCou = query.value(12).toString();
		authRepo.facePhoto = query.value(13).toString();
		authRepo.sfzPhoto = query.value(14).toString();
		auRlist.push_back(authRepo);
	}

	int totalCount = 0;
	query.clear();
	query.exec(countSql);
	if (query.next()) {
		totalCount = query.value(0).toInt();
	}
	int curPage = currentPage;
	return PageResult<AuthenticResultPojo>(auRlist, totalCount, curPage);
}
PageResult<AuthenticResultPojo> FaceLogService::queryByCon(QString& changci, QString& kd, QString& kc, QString& rzRes, QString& shijian, int& currentPage) {
	QString baseSql = "SELECT z.id, z.xingming,z.xingbie,z.upersonnum,f.changci,z.baokaoname,z.jbname,z.kc1,z.zh1,z.zkznum,f.shijian,f.shibieleixing,f.renzcount,f.renlianphoto,f.sfzphoto   FROM zkzdata z  JOIN  ";
	QString zkzSql = "";
	QString zkzdataSql = "";
	//拼接内层facelogsql
	QString faceSql = "";
	QString dataSql = "";

	QString countSql = "SELECT COUNT(*)  FROM zkzdata z  JOIN ";
	if (shijian != NULL&&shijian != "") {
		QString formatTime = timeFormat::formatTime(shijian);
		dataSql = " AND f1.shijian LIKE '" + formatTime + "%' ";
		zkzdataSql = " AND z.sj1 LIKE '" + formatTime + "%' ";
	}
	if (changci != NULL&&changci != "") {
		if (dataSql != "") {
			dataSql += " AND f1.changci= '" + changci + "' ";
		}
		else {
			dataSql = " AND f1.changci= '" + changci + "' ";
		}

	}

	if (rzRes != NULL&&rzRes != "") {
		faceSql = "";
		if (rzRes == "需人工审核") {
			faceSql = " ( SELECT * FROM (SELECT * FROM facelog WHERE changci='" + changci + "' AND shibieleixingint IS '1' OR shibieleixingint IS '4'  GROUP BY sfz  ORDER BY  shijian DESC) f1  WHERE  f1.sfz NOT IN (SELECT sfz FROM facelog WHERE changci='" + changci + "' AND shibieleixingint IS '7' GROUP BY sfz  ) " + dataSql + " ORDER BY f1.shijian  ) f ";
		}
		else if (rzRes == "不通过") {
			faceSql = " ( SELECT * FROM (SELECT * FROM facelog WHERE changci='" + changci + "' AND shibieleixingint  NOT IN ('7','2','1','4')  GROUP BY sfz ORDER BY shijian DESC " +
				") f1  WHERE  f1.sfz NOT IN (SELECT sfz FROM facelog WHERE changci='" + changci + "' AND shibieleixingint IS '7' GROUP BY sfz ORDER BY  shijian ) " + dataSql + " ) f ";
		}
		else if (rzRes == "验证通过") {
			faceSql = " (SELECT * FROM facelog f1 WHERE  f1.shibieleixingint IS '7' " + dataSql + "  GROUP BY f1.sfz ORDER BY   f1.shijian DESC) f ";

		}
		else if (rzRes == "无识别记录") {
			faceSql = " (SELECT f1.sfz FROM facelog f1 WHERE f1.shibieleixingint IN ('1','4','7','5','6') " + dataSql + "  GROUP BY f1.sfz ORDER BY  f1.shijian DESC) ";

		}
		//拼接外层zkzdata数据库 sql和上面内层sql结合
		if (kd != NULL&&kd.trimmed() != "") {
			if (zkzSql.trimmed() != "") {
				zkzSql += " AND  z.kd1 LIKE '%" + kd + "%' ";
			}
			else {
				zkzSql = " AND z.kd1 LIKE '%" + kd + "%' ";
			}
		}

		if (kc != NULL && kc != "") {
			if (zkzSql.trimmed() != "") {
				zkzSql += "AND z.kc1 LIKE '%" + kc + "%' ";
			}
			else {
				zkzSql = " AND z.kc1 LIKE '%" + kc + "%' ";
			}
		}

	}
	//拼接预备完成sql还差分页
	//未来的人，特殊处理
	if (rzRes.contains("无识别记录")) {
		baseSql = " SELECT z.id, z.xingming ,z.xingbie,z.upersonnum,'无信息',z.baokaoname,z.jbname,z.kc1,z.zh1,'无信息','无信息','无信息','无信息','无信息','无信息'  FROM zkzdata z   WHERE z.upersonnum  NOT IN " + faceSql + zkzSql + zkzdataSql;
		countSql = " SELECT COUNT(*)  FROM zkzdata z  WHERE z.upersonnum  NOT IN " + faceSql + zkzSql + zkzdataSql;

	}
	else if (rzRes.contains("非考生")) {
		baseSql = "SELECT f1.id,f1.xingming,f1.xingbie,f1.sfz,f1.changci,'未认证','未认证','未认证','未认证','未认证',f1.shijian,f1.shibieleixing,'未认证','未认证','未认证' FROM facelog f1  WHERE  f1.shibieleixingint IS '2' " + dataSql + " GROUP BY  f1.sfz ORDER BY  f1.shijian ";
		countSql = " SELECT COUNT(*)  FROM facelog f1 WHERE  f1.shibieleixingint IS '2' " + dataSql + " GROUP BY  f1.sfz ORDER BY  f1.shijian ";
	}
	else {
		baseSql += (faceSql + " ON f.sfz=z.upersonnum " + zkzSql);
		//计算总条数
		countSql += (faceSql + " ON f.sfz=z.upersonnum " + zkzSql);
	}
	//拼接分页
	if (currentPage>0) {
		baseSql += " LIMIT " + QString::number((currentPage - 1) * 25) + " , 25 ";

	}
	

	QVector<AuthenticResultPojo> auRlist;
	query.exec(baseSql);
	while (query.next()) {
		AuthenticResultPojo authRepo;
		authRepo.id = query.value(0).toLongLong();
		authRepo.xingming = query.value(1).toString();
		authRepo.xingbie = query.value(2).toString();
		authRepo.sfz = query.value(3).toString();
		authRepo.kemu = query.value(4).toString();
		authRepo.gongzh = query.value(5).toString();
		authRepo.level = query.value(6).toString();
		authRepo.kc = query.value(7).toString();
		authRepo.zh = query.value(8).toString();
		authRepo.zkz = query.value(9).toString();
		authRepo.shijian = query.value(10).toString();
		authRepo.aures = query.value(11).toString();
		authRepo.auCou = query.value(12).toString();
		authRepo.facePhoto = query.value(13).toString();
		authRepo.sfzPhoto = query.value(14).toString();
		auRlist.push_back(authRepo);
	}

	int totalCount = 0;
	query.clear();
	query.exec(countSql);
	if (query.next()) {
		totalCount = query.value(0).toInt();
	}
	int curPage = currentPage;
	return PageResult<AuthenticResultPojo>(auRlist, totalCount, curPage);

}

void FaceLogService::insertIntoFaceLog(const FaceLog& faceLog) {
	query.clear();
	query.prepare("insert into facelog(sfz,xingming,xingbie,shibieleixing,shibieleixingint,shijian,renlianphoto,remarks,denglumana,zkzPhoto,kd,changci,renzcount) values("
		":sfz,:xingming,:xingbie,:shibieleixing,:shibieleixingint,:shijian,:renlianphoto,:remarks,:denglumana,:zkzPhoto,:kd,:changci,:renzcount)");
	query.bindValue(":sfz", faceLog.sfz);
	query.bindValue(":xingming", faceLog.xingming);
	query.bindValue(":xingbie", faceLog.xingbie);
	query.bindValue(":shibieleixing", faceLog.shibieleixing);
	query.bindValue(":shibieleixingint", faceLog.shibieleixingint);
	query.bindValue(":shijian", faceLog.shijian);
	query.bindValue(":renlianphoto", faceLog.renlianphoto);
	query.bindValue(":remarks", faceLog.remarks);
	query.bindValue(":changci", faceLog.changci);
	query.bindValue(":denglumana", faceLog.denglumana);
	query.bindValue(":zkzPhoto", faceLog.zkzPhoto);
	query.bindValue(":kd", faceLog.kd);
	query.bindValue(":changci",faceLog.changci);
	query.bindValue(":renzcount", faceLog.renzcount);
	query.exec();
}
void FaceLogService::insertIntoFaceLogs(const FaceLog& faceLog) {
	qDebug() << faceLog.sfz << "-=-=" << faceLog.xingming;
	db.transaction();
	query.prepare("insert into facelog(sfz,xingming,xingbie,shibieleixing,shibieleixingint,shijian,renlianphoto,sfzphoto,remarks,changci,denglumana,zkzPhoto,kd,renzcount) values("
		":sfz,:xingming,:xingbie,:shibieleixing,:shibieleixingint,:shijian,:renlianphoto,:sfzphoto,:remarks,:changci,:denglumana,:zkzPhoto,:kd,:renzcount)");
	query.bindValue(":sfz", faceLog.sfz);
	query.bindValue(":xingming", faceLog.xingming);
	query.bindValue(":xingbie", faceLog.xingbie);
	query.bindValue(":shibieleixing", faceLog.shibieleixing);
	query.bindValue(":shibieleixingint", faceLog.shibieleixingint);
	query.bindValue(":shijian", faceLog.shijian);
	query.bindValue(":renlianphoto", faceLog.renlianphoto);
	query.bindValue(":sfzphoto", faceLog.sfzphoto);
	query.bindValue(":remarks", faceLog.remarks);
	query.bindValue(":changci", faceLog.changci);
	query.bindValue(":denglumana", faceLog.denglumana);
	query.bindValue(":zkzPhoto", faceLog.zkzPhoto);
	query.bindValue(":kd", faceLog.kd);
	query.bindValue(":renzcount", faceLog.renzcount);
	query.execBatch();
	db.commit();
}




int  FaceLogService::queryRzCount(const QString &cnum, const QString &changci) {
	int cnt = 0;
	QString sql = "SELECT renzcount FROM facelog WHERE sfz LIKE '%" + cnum + "%' AND  changci  is '" + changci + "'";
	query.clear();
	query.exec(sql);
	if (query.next()) {
		cnt = query.value(0).toInt();
	}
	return cnt;
   

}
int  FaceLogService::queryFaceLogByCardNumAndChangci(const QString &cnum,const QString &changci) {
	int cnt = 0;
	QString sql = "SELECT COUNT(*) FROM facelog WHERE sfz LIKE '%" + cnum + "%' AND  changci  is '"+changci+"'";
	query.clear();
	query.exec(sql);
	if (query.next()) {
		cnt = query.value(0).toInt();
	}
	return cnt;

}


int  FaceLogService::queryFaceLogByCardNum(const QString &cnum) {
	int cnt = 0;
	QString sql = "SELECT COUNT(*) FROM facelog WHERE sfz LIKE '%"+cnum+"%'";
	query.clear();
	query.exec(sql);
	if (query.next()) {
		cnt = query.value(0).toInt();
	}
	return cnt;
}

void  FaceLogService::updateFaceLogByCardNum(const FaceLog& faceLog) {
	/*query.clear();
	QString sql = "UPDATE facelog SET shibieleixing=:shibieleixing,shibieleixingint=:shibieleixingint,renlianphoto=:renlianphoto,remarks=:remarks,changci=:changci,renzcount=:renzcount WHERE sfz LIKE '%:sfz%' ";
	query.prepare(sql);
	query.bindValue(":shibieleixing", faceLog.shibieleixing);
	query.bindValue(":shibieleixingint", faceLog.shibieleixingint);
	query.bindValue(":renlianphoto", faceLog.renlianphoto);
	query.bindValue(":remarks", faceLog.remarks);
	query.bindValue(":changci", faceLog.changci);
	query.bindValue(":renzcount", faceLog.renzcount);
	query.bindValue(":sfz", faceLog.sfz);
	query.exec();*/

	query.clear();
	QString sql = " UPDATE facelog SET shibieleixing='"+ faceLog.shibieleixing +"',shibieleixingint='"+ faceLog.shibieleixingint +"',shijian='"+faceLog.shijian+"',renlianphoto='"+ faceLog.renlianphoto +"',remarks='"+ faceLog.remarks +"',renzcount='"+ faceLog.renzcount +"' WHERE sfz LIKE '%"+ faceLog.sfz +"%' ";
	query.prepare(sql);
	query.exec();

}

FaceLogService::~FaceLogService()
{
}
