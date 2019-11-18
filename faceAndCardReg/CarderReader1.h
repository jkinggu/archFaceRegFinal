#pragma once

#include<Qtcore/qthread.h>
#include <qeventloop.h>
#include <QtCore/qlibrary.h>
#include <QtCore/qdebug.h>
#include <qtimer.h>
#include <qstring.h>



class CarderReader1 :public QThread
{
	Q_OBJECT
public:
	CarderReader1(QWidget *parent=0);
	~CarderReader1();
private slots:
	void dealTimeout();
protected:
	void run();


};

