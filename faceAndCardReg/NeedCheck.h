#pragma once

//
// Created by Administrator on 2019-08-26.
//

#ifndef FACEREG_NEEDCHECK_H
#define FACEREG_NEEDCHECK_H

#include <QString>
#include <QMap>
#include <QObject>
#include <QVector>


struct NeedCheck {

private:
	QString title = "���Ϲ�������ʶ����鵥";//����
	QString zkzPho = "";//׼��֤ͼƬ��ַ
	QString facePhoto = "";//�ֳ�������Ƭ��ַ
	QString sfzPhoto = "";//���֤��Ƭ��ַ
	QString name = "";//����
	QString sex = "";
	QString age = "";
	QString zkzNum = "";
	QString sfzNum = "";
	QString danweiName = "";//������λ
	QString baokaoName = "";//�걨����
	QString jbName = "";//��������
						//�����Ŀ��Ϣ  ���� ����ʱ�䣬���Եص�   ����
	QMap<QString, QVector<QString>> testInfo;
	QString signatureName; //����ǩ��Ϊ��ռλ
	QString rzResult = "";//��֤���
	QString printTime = "";//��ӡʱ��
public:
	NeedCheck() {}

	QMap<QString, QVector<QString>> getTestInfo() {
		return this->testInfo;
	}
	void setTestInfo(QMap<QString, QVector<QString>>  &testInfo) {
		this->testInfo = testInfo;
	}
	QString getTitle() {
		return title;
	}
	void setTitle(QString title) {
		this->title = title;
	}
	QString getZkzPho() {
		return zkzPho;
	}
	void setZkzPho(QString zkzPho) {
		this->zkzPho = zkzPho;
	}
	QString getFacePhoto() {
		return facePhoto;
	}
	void setFacePhoto(QString facePhoto) {
		this->facePhoto = facePhoto;
	}
	QString getSfzPhoto() {
		return sfzPhoto;
	}
	void setSfzPhoto(QString sfzPhoto) {
		this->sfzPhoto = sfzPhoto;
	}
	QString getName() {
		return name;
	}
	void setName(QString name) {
		this->name = name;
	}
	QString getSex() {
		return sex;
	}
	void setSex(QString sex) {
		this->sex = sex;
	}
	QString getAge() {
		return age;
	}
	void setAge(QString age) {
		this->age = age;
	}
	QString getZkzNum() {
		return zkzNum;
	}
	void setZkzNum(QString zkzNum) {
		this->zkzNum = zkzNum;
	}
	QString getSfzNum() {
		return sfzNum;
	}
	void setSfzNum(QString sfzNum) {
		this->sfzNum = sfzNum;
	}

	QString getDanweiName() {
		return danweiName;
	}
	QString getBaoKaoName() {
		return this->baokaoName;
	}
	QString getJbName() {
		return this->jbName;
	}
	QString getRzResult() {
		return this->rzResult;
	}
	QString getPrintTime() {
		return this->printTime;
	}
	void setDanweiName(QString danweiName) {
		this->danweiName = danweiName;
	}
	void setBaokaoName(QString baokaoName) {
		this->baokaoName = baokaoName;
	}
	void setJbName(QString jbName) {
		this->jbName = jbName;
	}
	void setRzResult(QString rzResult) {
		this->rzResult = rzResult;
	}
	void setPrintTime(QString printTime) {
		this->printTime = printTime;
	}
};



#endif //FACEREG_NEEDCHECK_H
