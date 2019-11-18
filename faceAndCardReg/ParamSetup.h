#pragma once
//
// Created by Administrator on 2019-08-30.
//

#ifndef FACEREG_PARAMSETUP_H
#define FACEREG_PARAMSETUP_H

#include <QString>
struct ParamSetup {
private:
	long pid;
	QString  dishi;
	QString dishiname;
	QString kaodianname;
	QString kaochang;
	QString starttime;
	QString endtime;
	QString remarks;
	QString adminname;
	long adminid;
	QString didian;
	QString ustatu;
public:
	ParamSetup() {}
	ParamSetup(long pid, QString  dishi, QString dishiname, QString kaodianname, QString kaochang,
		QString starttime, QString endtime, QString remarks, QString adminname, long adminid, QString didian, QString ustatu) {
		this->pid = pid;
		this->dishi = dishi;
		this->dishiname = dishiname;
		this->kaodianname = kaodianname;
		this->kaochang = kaochang;
		this->starttime = starttime;
		this->endtime = endtime;
		this->remarks = remarks;
		this->adminname = adminname;
		this->adminid = adminid;
		this->didian = didian;
		this->ustatu = ustatu;
	}

	long getPid() {
		return pid;
	}

	void setPid(long pid) {
		this->pid = pid;
	}

	QString getDishi() {
		return dishi;
	}

	void setDishi(QString dishi) {
		this->dishi = dishi;
	}

	QString getDishiname() {
		return dishiname;
	}

	void setDishiname(QString dishiname) {
		this->dishiname = dishiname;
	}

	QString getKaodianname() {
		return kaodianname;
	}

	void setKaodianname(QString kaodianname) {
		this->kaodianname = kaodianname;
	}

	QString getKaochang() {
		return kaochang;
	}

	void setKaochang(QString kaochang) {
		this->kaochang = kaochang;
	}

	QString getStarttime() {
		return starttime;
	}

	void setStarttime(QString starttime) {
		this->starttime = starttime;
	}

	QString getEndtime() {
		return endtime;
	}

	void setEndtime(QString endtime) {
		this->endtime = endtime;
	}

	QString getRemarks() {
		return remarks;
	}

	void setRemarks(QString remarks) {
		this->remarks = remarks;
	}

	QString getAdminname() {
		return adminname;
	}

	void setAdminname(QString adminname) {
		this->adminname = adminname;
	}

	long getAdminid() {
		return adminid;
	}

	void setAdminid(long adminid) {
		this->adminid = adminid;
	}

	QString getDidian() {
		return didian;
	}

	void setDidian(QString didian) {
		this->didian = didian;
	}

	QString getUstatu() {
		return ustatu;
	}

	void setUstatu(QString ustatu) {
		this->ustatu = ustatu;
	}

};



#endif //FACEREG_PARAMSETUP_H

