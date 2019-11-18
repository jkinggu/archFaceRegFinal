
#include <QtWidgets/QApplication>
#include <MainWin.h>
//#include "Login.h"
#include "CamerCore.h"
//#include "CamerTest.h"
int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	//CamerCore core;
	//core.show();
	MainWin win;
	win.show();
	return a.exec();
}
