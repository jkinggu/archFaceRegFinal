#pragma once
#ifndef FACEREG_CARDERREADER_CARDINFO_H  
#define FACEREG_CARDERREADER_CARDINFO_H  

#include <qcoreapplication.h>
#include <Qtcore/qthread.h>
#include <qeventloop.h>
#include <QtCore/qdebug.h>
#include <QtCore/qtimer.h>
#include <QtCore/qstring.h>
#include <QtCore/qfile.h>
#include <QtCore/qdir.h>

#include <QTimer>
#include<wchar.h>
#include<locale>
#include <codecvt>
#include <Windows.h>
#include <iostream>
#include "CardInfo.h"

class CarderReader:public QThread
{
	Q_OBJECT
public:
	explicit CarderReader(QObject *parent=0);
	~CarderReader();
	bool& getDllFlag();
	CardInfo* hanlerCardTime();
	CardInfo *&getCinfo1();
private:
	bool OnInitCard();
	char* TrimStr(char *str);
protected:
	void run();

signals:
	void dllError();
	void cardReady();
	void cardChanged();
	void cardClean();
private slots:
	void handlerCardTimeout();
private:
	bool dllFlag;
	CardInfo *cinfo1;
	CardInfo *cinfo2;
};
#endif

