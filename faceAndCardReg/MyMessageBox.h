#pragma once
//
// Created by Administrator on 2019-08-30.
//

#ifndef FACEREG_MYMESSAGEBOX_H
#define FACEREG_MYMESSAGEBOX_H
#pragma execution_character_set("utf-8");
#include <QMessageBox>
#include <QString>
#include <QIcon>
class MyMessageBox : public QMessageBox {
	Q_OBJECT
private:
	int m_width;
	int m_height;
public:
	explicit MyMessageBox(QWidget *parent = 0);
	~MyMessageBox();
	void setInformationMsg(const QString &msg);
	void setWarnningMsg(const QString &msg);
private:
	void showEvent(QShowEvent *event);
	void resizeEvent(QResizeEvent *event);
	void closeEvent(QCloseEvent *event);

};


#endif //FACEREG_MYMESSAGEBOX_H
