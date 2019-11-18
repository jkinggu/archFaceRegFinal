#include "ZkzdataService.h"



ZkzdataService::ZkzdataService():query(QSqlQuery(db))
{
}


ZkzdataPojo ZkzdataService::queryZkzdataBySfzNum(const QString &sfz) {
	ZkzdataPojo zdata;
	if (sfz != NULL&&sfz.trimmed() != "") {
		QString sql = "SELECT * FROM zkzdata WHERE  upersonnum LIKE '" + sfz + "%' ";
		query.clear();
		query.exec(sql);
		if (query.next()) {
			zdata.setId(query.value(0).toInt());
			zdata.setXingming(query.value(1).toString());
			zdata.setXingbie(query.value(2).toString());
			zdata.setNianlin(query.value(3).toString());
			zdata.setZkznum(query.value(4).toString());
			zdata.setUpersonnum(query.value(5).toString());
			zdata.setDanweiid(query.value(6).toString());
			zdata.setDanweiname(query.value(7).toString());
			zdata.setBaokaocode(query.value(8).toString());
			zdata.setBaokaoname(query.value(9).toString());
			zdata.setJbcode(query.value(10).toString());
			zdata.setJbname(query.value(11).toString());
			zdata.setKd1(query.value(12).toString());
			zdata.setKc1(query.value(13).toString());
			zdata.setZh1(query.value(14).toString());
			zdata.setSj1(query.value(15).toString());
			zdata.setDd1(query.value(16).toString());
			zdata.setKd2(query.value(17).toString());
			zdata.setKc2(query.value(18).toString());
			zdata.setZh2(query.value(19).toString());
			zdata.setSj2(query.value(20).toString());
			zdata.setDd2(query.value(21).toString());
			zdata.setKd3(query.value(22).toString());
			zdata.setKc3(query.value(23).toString());
			zdata.setZh3(query.value(24).toString());
			zdata.setSj3(query.value(25).toString());
			zdata.setDd3(query.value(26).toString());
			zdata.setZmarks(query.value(27).toString());
			zdata.setDishiname(query.value(28).toString());
			zdata.setZkzpho(query.value(29).toString());
			zdata.setSfzpho(query.value(30).toString());
		}

	}
	return  zdata;


}
QList<QString> ZkzdataService::queryConByCardNum(const QString &cnum) {
	QList<QString> res;
	if (cnum != NULL&&cnum.trimmed() != "") {
		QString sql = "SELECT xingming,sj1,kd1 FROM zkzdata WHERE  upersonnum LIKE '%" + cnum + "%' ";
		query.clear();
		query.exec(sql);
		if (query.next()) {
			res.append(query.value(0).toString());
			res.append(query.value(1).toString());
			res.append(query.value(2).toString());
		}
	}
	return res;
}

QList<QString> ZkzdataService::queryShowResByCardNum(const QString &cnum) {
	QList<QString> res;
	if (cnum != NULL&&cnum.trimmed() != "") {
		QString sql = "SELECT xingming,upersonnum,baokaoname,jbname,sj1,kd1,kc1 FROM zkzdata WHERE  upersonnum LIKE '%" + cnum + "%' ";
		query.clear();
		query.exec(sql);
		if (query.next()) {
			res.append("<font size='4'>姓名:"+ query.value(0).toString()+"</font>");
			res.append("<font size='4'>身份证号:" +query.value(1).toString() + "</font>");
			res.append("<font size='4'>工种:" +query.value(2).toString() + "</font>");
			res.append("<font size='4'>级别:" + query.value(3).toString() + "</font>");
			res.append("<font size='4' color='red'>考试时间:" + query.value(4).toString().split(" ")[0] + "</font>");
			res.append("<font size='4' color='red'>考试地点:" + query.value(5).toString() + "</font>");
			res.append("<font size='4' color='red'>考场:" + query.value(6).toString() + "</font>");
		
		}
	
	}
	return res;
}

ZkzdataService::~ZkzdataService()
{
}
