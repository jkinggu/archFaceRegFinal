#pragma once

//
// Created by Administrator on 2019-08-26->
//

#ifndef FACEREG_ZKZDATAPOJO_H
#define FACEREG_ZKZDATAPOJO_H

#include <QString>
struct ZkzdataPojo {
private:
	long id = 0;				//主键
	QString xingming;		//姓名
	QString xingbie;			//性别
	QString nianlin;			//年龄
	QString zkznum;			//准考证号
	QString upersonnum;		//身份证号
	QString danweiid;		//单位id
	QString danweiname;		//单位名称
	QString baokaocode;		//报考工种代码
	QString baokaoname;		//报考工种
	QString jbcode;			//报考级别代码
	QString jbname;			//报考级别
	QString kd1;				//考点1
	QString kc1;				//考场1
	QString zh1;				//座号1
	QString sj1;				//时间1
	QString dd1;				//地点1
	QString kd2;				//考点2
	QString kc2;				//考场2
	QString zh2;				//座号2
	QString sj2;				//时间2
	QString dd2;				//地点2
	QString kd3;				//考点3
	QString kc3;				//考场3
	QString zh3;				//座号3
	QString sj3;				//时间3
	QString dd3;				//地点3
	QString zmarks;			//保留字段
	QString dishiname;
	QString zkzpho;
	QString sfzpho;


	// Constructors
public:

	ZkzdataPojo() {}

	/** full constructor */
	ZkzdataPojo(QString xingming, QString xingbie, QString nianlin,
		QString zkznum, QString upersonnum, QString danweiid,
		QString danweiname, QString baokaocode, QString baokaoname,
		QString jbcode, QString jbname, QString kd1, QString kc1, QString zh1,
		QString sj1, QString dd1, QString kd2, QString kc2, QString zh2,
		QString sj2, QString dd2, QString kd3, QString kc3, QString zh3,
		QString sj3, QString dd3, QString zmarks, QString dishiname, QString zkzpho, QString sfzpho) {
		this->xingming = xingming;
		this->xingbie = xingbie;
		this->nianlin = nianlin;
		this->zkznum = zkznum;
		this->upersonnum = upersonnum;
		this->danweiid = danweiid;
		this->danweiname = danweiname;
		this->baokaocode = baokaocode;
		this->baokaoname = baokaoname;
		this->jbcode = jbcode;
		this->jbname = jbname;
		this->kd1 = kd1;
		this->kc1 = kc1;
		this->zh1 = zh1;
		this->sj1 = sj1;
		this->dd1 = dd1;
		this->kd2 = kd2;
		this->kc2 = kc2;
		this->zh2 = zh2;
		this->sj2 = sj2;
		this->dd2 = dd2;
		this->kd3 = kd3;
		this->kc3 = kc3;
		this->zh3 = zh3;
		this->sj3 = sj3;
		this->dd3 = dd3;
		this->zmarks = zmarks;
		this->dishiname = dishiname;
		this->zkzpho = zkzpho;
		this->sfzpho = sfzpho;
	}

	long getId() {
		return this->id;
	}

	void setId(long id) {
		this->id = id;
	}

	QString getXingming() {
		return this->xingming;
	}

	void setXingming(QString xingming) {
		this->xingming = xingming;
	}

	QString getXingbie() {
		return this->xingbie;
	}

	void setXingbie(QString xingbie) {
		this->xingbie = xingbie;
	}

	QString getNianlin() {
		return this->nianlin;
	}

	void setNianlin(QString nianlin) {
		this->nianlin = nianlin;
	}

	QString getZkznum() {
		return this->zkznum;
	}

	void setZkznum(QString zkznum) {
		this->zkznum = zkznum;
	}

	QString getUpersonnum() {
		return this->upersonnum;
	}

	void setUpersonnum(QString upersonnum) {
		this->upersonnum = upersonnum;
	}

	QString getDanweiid() {
		return this->danweiid;
	}

	void setDanweiid(QString danweiid) {
		this->danweiid = danweiid;
	}

	QString getDanweiname() {
		return this->danweiname;
	}

	void setDanweiname(QString danweiname) {
		this->danweiname = danweiname;
	}

	QString getBaokaocode() {
		return this->baokaocode;
	}

	void setBaokaocode(QString baokaocode) {
		this->baokaocode = baokaocode;
	}

	QString getBaokaoname() {
		return this->baokaoname;
	}

	void setBaokaoname(QString baokaoname) {
		this->baokaoname = baokaoname;
	}

	QString getJbcode() {
		return this->jbcode;
	}

	void setJbcode(QString jbcode) {
		this->jbcode = jbcode;
	}

	QString getJbname() {
		return this->jbname;
	}

	void setJbname(QString jbname) {
		this->jbname = jbname;
	}

	QString getKd1() {
		return this->kd1;
	}

	void setKd1(QString kd1) {
		this->kd1 = kd1;
	}

	QString getKc1() {
		return this->kc1;
	}

	void setKc1(QString kc1) {
		this->kc1 = kc1;
	}

	QString getZh1() {
		return this->zh1;
	}

	void setZh1(QString zh1) {
		this->zh1 = zh1;
	}

	QString getSj1() {
		return this->sj1;
	}

	void setSj1(QString sj1) {
		this->sj1 = sj1;
	}

	QString getDd1() {
		return this->dd1;
	}

	void setDd1(QString dd1) {
		this->dd1 = dd1;
	}

	QString getKd2() {
		return this->kd2;
	}

	void setKd2(QString kd2) {
		this->kd2 = kd2;
	}

	QString getKc2() {
		return this->kc2;
	}

	void setKc2(QString kc2) {
		this->kc2 = kc2;
	}

	QString getZh2() {
		return this->zh2;
	}

	void setZh2(QString zh2) {
		this->zh2 = zh2;
	}

	QString getSj2() {
		return this->sj2;
	}

	void setSj2(QString sj2) {
		this->sj2 = sj2;
	}

	QString getDd2() {
		return this->dd2;
	}

	void setDd2(QString dd2) {
		this->dd2 = dd2;
	}

	QString getKd3() {
		return this->kd3;
	}

	void setKd3(QString kd3) {
		this->kd3 = kd3;
	}

	QString getKc3() {
		return this->kc3;
	}

	void setKc3(QString kc3) {
		this->kc3 = kc3;
	}

	QString getZh3() {
		return this->zh3;
	}

	void setZh3(QString zh3) {
		this->zh3 = zh3;
	}

	QString getSj3() {
		return this->sj3;
	}

	void setSj3(QString sj3) {
		this->sj3 = sj3;
	}

	QString getDd3() {
		return this->dd3;
	}

	void setDd3(QString dd3) {
		this->dd3 = dd3;
	}
	QString getZmarks() {
		return zmarks;
	}

	void setZmarks(QString zmarks) {
		this->zmarks = zmarks;
	}



	QString getDishiname() {
		return dishiname;
	}

	void setDishiname(QString dishiname) {
		this->dishiname = dishiname;
	}

	QString getZkzpho() {
		return zkzpho;
	}

	void setZkzpho(QString zkzpho) {
		this->zkzpho = zkzpho;
	}

	QString getSfzpho() {
		return sfzpho;
	}

	void setSfzpho(QString sfzpho) {
		this->sfzpho = sfzpho;
	}



};

#endif //FACEREG_ZKZDATA_H
