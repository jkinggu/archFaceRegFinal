#pragma once
#ifndef FACEREG_FACEADMIN_H
#define FACEREG_FACEADMIN_H

#include<qstring.h>

typedef struct _faceadmin {
private:
	QString bmname = "";
	QString curchangci = "";
	QString remarks = "";
public:
	_faceadmin()=default;
	_faceadmin(const QString &bmname,  const QString &curchangci,const QString &remarks) {
		this->bmname = bmname;
		this->curchangci = curchangci;
		this->remarks = remarks;
	}

	void setRemarks(const QString &remarks) {
		this->remarks = remarks;
	}

	QString& getRemarks() {
		return this->remarks;
	}

	void setBmname(const QString &bmname) {
		this->bmname = bmname;
	}
	QString& getBmname() {
		return this->bmname;
	}
	void setCurchangci(const QString &curchangci) {
		this->curchangci = curchangci;
	}
	QString& getCurchangci() {
		return this->curchangci;
	}



}Faceadmin;

#endif // !FACEREG_FACEADMIN_H


