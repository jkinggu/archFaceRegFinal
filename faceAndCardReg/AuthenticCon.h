#pragma once
//
// Created by Administrator on 2019-08-28.
//

#ifndef FACEREG_AUTHENTICCON_H
#define FACEREG_AUTHENTICCON_H

#include <QString>
struct AuthenticCon {
private:
	QString kaodian;
	QString changci;
	QString shijian;
public:

	AuthenticCon() {}
	QString getKaodian() {
		return kaodian;
	}
	void setKaodian(QString kaodian) {
		this->kaodian = kaodian;
	}
	QString getChangci() {
		return changci;
	}
	void setChangci(QString changci) {
		this->changci = changci;
	}
	QString getShijian() {
		return shijian;
	}
	void setShijian(QString shijian) {
		this->shijian = shijian;
	}



};


#endif //FACEREG_AUTHENTICCON_H
