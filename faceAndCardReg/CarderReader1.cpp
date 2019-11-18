#include "CarderReader1.h"



CarderReader1::CarderReader1(QWidget *parent)
{



}
void CarderReader1::run() {
	QTimer timer;
	connect(&timer,SIGNAL(timeout()),this,SLOT(dealTimeout()));
	timer.start(500);
	
	QEventLoop loop;
	loop.exec();
}
void CarderReader1::dealTimeout() {


	qDebug() << "openCamer";


	
}

CarderReader1::~CarderReader1()
{
}
