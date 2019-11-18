#pragma once
//
// Created by Administrator on 2019-08-28->
//

#ifndef FACEREG_AUTHENTICTJPOJO_H
#define FACEREG_AUTHENTICTJPOJO_H

#include <QString>
struct AuthenticTjPojo {
private:
	QString kd;
	QString shijain;
	QString changci;
	QString needCheck;
	QString notPass;
	QString pass;
	QString noRecord;
public:
	AuthenticTjPojo() {}
	AuthenticTjPojo(QString kd, QString shijian, QString changci, QString needCheck, QString notPass, QString pass, QString noRecord) {
		this->kd = kd;
		this->shijain = shijian;
		this->changci = changci;
		this->needCheck = needCheck;
		this->notPass = notPass;
		this->pass = pass;
		this->noRecord = noRecord;

	}

	QString getKd() {
		return kd;
	}
	void setKd(QString kd) {
		this->kd = kd;
	}
	QString getShijain() {
		return shijain;
	}
	void setShijain(QString shijain) {
		this->shijain = shijain;
	}
	QString getChangci() {
		return changci;
	}
	void setChangci(QString changci) {
		this->changci = changci;
	}
	QString getNeedCheck() {
		return needCheck;
	}
	void setNeedCheck(QString needCheck) {
		this->needCheck = needCheck;
	}
	QString getNotPass() {
		return notPass;
	}
	void setNotPass(QString notPass) {
		this->notPass = notPass;
	}
	QString getPass() {
		return pass;
	}
	void setPass(QString pass) {
		this->pass = pass;
	}
	QString getNoRecord() {
		return noRecord;
	}
	void setNoRecord(QString noRecord) {
		this->noRecord = noRecord;
	}

};



#endif //FACEREG_AUTHENTICTJPOJO_H
