#pragma once
#ifndef FACEREG_CARDINFO_H
#define FACEREG_CARDINFO_H
#include <QtCore/qstring.h>
struct CardInfo
{
private:
	//���֤����
	QString cname = "";
	//�Ա�
	QString csex = "";
	//���֤��
	QString cardNum = "";
public:
	CardInfo() = default;
	CardInfo(const QString &cname, const QString &csex, const QString &cardNum) {
		this->cname = cname;
		this->csex = csex;
		this->cardNum = cardNum;

	}
	CardInfo(const CardInfo &info) {
		this->cname = info.cname;
		this->csex = info.csex;
		this->cardNum = info.cardNum;
	}
	void setCname(const QString &cname) {
		this->cname = cname;
	}

	QString getCname() {
		return this->cname;
	}
	void setCsex(const QString &csex) {
		this->csex = csex;
	}
	QString getCsex() {
		return this->csex;
	}
	void setCardNum(const QString &cardNum) {
		this->cardNum = cardNum;
	}
	QString getCardNum() {
		return this->cardNum;
	}

};


#endif // !aaa