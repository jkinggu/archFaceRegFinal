#include "FaceAdminService.h"



FaceAdminService::FaceAdminService(): query(QSqlQuery(db)){}
Faceadmin FaceAdminService::queryCurrentUser() {
	QString sql = "SELECT bmname,remarks,curchangci FROM faceadmin where curmana='1'";
	query.prepare(sql);
	query.exec();
	Faceadmin faceadmin;
	if (query.next()) {
		faceadmin.setBmname(query.value("bmname").toString());
		faceadmin.setRemarks(query.value("remarks").toString());
		faceadmin.setCurchangci(query.value("curchangci").toString());
	}
	return faceadmin;
}
Faceadmin FaceAdminService::queryByUserAndPwd(const QString &username, const QString &password, const QString &changci) {
	QString sql = "SELECT bmname,remarks,curchangci FROM faceadmin WHERE bmname IS '" + username + "' AND bmpass IS '" + password + "'";
	query.prepare(sql);
	query.exec();
	Faceadmin faceadmin;
	if (query.next()) {
		faceadmin.setBmname(query.value("bmname").toString());
		faceadmin.setRemarks(query.value("remarks").toString());
		faceadmin.setCurchangci(query.value("curchangci").toString());
	}
	if (!changci.isEmpty() && faceadmin.getBmname() != "") {
		QString updSql = "UPDATE faceadmin SET curchangci='" + changci + "' WHERE bmname LIKE '%" + username + "%'";
		query.clear();
		query.exec(updSql);
	}

	return faceadmin;


}

FaceAdminService::~FaceAdminService(){}
