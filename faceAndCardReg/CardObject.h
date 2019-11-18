#ifndef  FACEREG_CARD_OBJECt_H
#define  FACEREG_CARD_OBJECt_H
#pragma once
#include "qobject.h"
#include <qdesktopwidget.h>
#include <qapplication.h>
#include <qlibrary.h>
#include <CardInfo.h>
#include <wchar.h>
#include<locale>
#include <codecvt>
#include <Windows.h>
#include <qtimer.h>
#include <qdebug.h>
#include <qthread.h>
#include <qstring.h>
class CardObject :public QThread
{
	Q_OBJECT
public:
	CardObject(QObject *parent = 0);
	bool getDllFlag();
	void setExitFlag(const bool &exit);
	void setReadFlag(const bool &read);
	bool getReadFlag();
	~CardObject();

protected:
	void run();
	private slots:

private:
	bool OnInitCard();
	char* TrimStr(char *str);
	CardInfo handlerCtlTask();
signals:
	void emitCardInfo(CardInfo);
signals:
	void emitTestString(QString);
private:
	bool dllFlag = false;
	QLibrary dllLib;
	bool exitFlag = false;
	bool readFlag = false;

};

#endif // ! FACEREG_CARD_OBJECt_H