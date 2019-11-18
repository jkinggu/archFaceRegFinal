#pragma once
#ifndef FACEREG_FACELOG_H
#define FACEREG_FACELOG_H
#include "QString"
struct FaceLog {
	int id = 0;
	QString sfz;
	QString xingming;
	QString xingbie;
	QString shibieleixing;
	QString shibieleixingint;
	QString shijian;
	QString renlianphoto;
	QString sfzphoto;
	QString remarks;
	QString changci;
	QString denglumana;
	QString zkzPhoto;
	QString kd;
	QString renzcount;
	QString xsd;

public:

	FaceLog() = default;
	FaceLog(int id, QString sfz, QString xingming, QString xingbie,
		QString shibieleixing, QString shibieleixingint, QString shijian, QString renlianphoto,
		QString remarks, QString sfzphoto, QString changci, QString denglumana, QString renzcount, QString xsd, QString zkzPhoto, QString kd) {
		this->id = id;
		this->sfz = sfz;
		this->xingming = xingming;
		this->xingbie = xingbie;
		this->shibieleixing = shibieleixing;
		this->shibieleixingint = shibieleixingint;
		this->shijian = shijian;
		this->renlianphoto = renlianphoto;
		this->remarks = remarks;
		this->sfzphoto = sfzphoto;
		this->changci = changci;
		this->denglumana = denglumana;
		this->renzcount = renzcount;
		this->xsd = xsd;
		this->zkzPhoto = zkzPhoto;
		this->kd = kd;
	}

	int getId() {
		return id;
	}

	void setId(int id) {
		this->id = id;
	}

	QString getSfz() {
		return sfz;
	}

	void setSfz(QString sfz) {
		this->sfz = sfz;
	}

	QString getXingming() {
		return xingming;
	}

	void setXingming(QString xingming) {
		this->xingming = xingming;
	}

	QString getXingbie() {
		return xingbie;
	}

	void setXingbie(QString xingbie) {
		this->xingbie = xingbie;
	}

	QString getShibieleixing() {
		return shibieleixing;
	}

	void setShibieleixing(QString shibieleixing) {
		this->shibieleixing = shibieleixing;
	}

	QString getShibieleixingint() {
		return shibieleixingint;
	}

	void setShibieleixingint(QString shibieleixingint) {
		this->shibieleixingint = shibieleixingint;
	}

	QString getShijian() {
		return shijian;
	}

	void setShijian(QString shijian) {
		this->shijian = shijian;
	}

	QString getRenlianphoto() {
		return renlianphoto;
	}

	void setRenlianphoto(QString renlianphoto) {
		this->renlianphoto = renlianphoto;
	}

	QString getRemarks() {
		return remarks;
	}

	void setRemarks(QString remarks) {
		this->remarks = remarks;
	}

	QString getSfzphoto() {
		return sfzphoto;
	}

	void setSfzphoto(QString sfzphoto) {
		this->sfzphoto = sfzphoto;
	}

	QString getChangci() {
		return changci;
	}

	void setChangci(QString changci) {
		this->changci = changci;
	}

	QString getDenglumana() {
		return denglumana;
	}

	void setDenglumana(QString denglumana) {
		this->denglumana = denglumana;
	}

	QString getRenzcount() {
		return renzcount;
	}

	void setRenzcount(QString renzcount) {
		this->renzcount = renzcount;
	}

	QString getXsd() {
		return xsd;
	}

	void setXsd(QString xsd) {
		this->xsd = xsd;
	}

	QString getZkzPhoto() {
		return zkzPhoto;
	}

	void setZkzPhoto(QString zkzPhoto) {
		this->zkzPhoto = zkzPhoto;
	}

	QString getKd() {
		return kd;
	}
	void setKd(QString kd) {
		this->kd = kd;
	}




};




#endif