#include "DealAnalysis.h"

DealAnalysis::DealAnalysis(QObject *parent):cinfo(nullptr){

}
void DealAnalysis::handlerMatAndCinfo(CardInfo *c1, cv::Mat &tmp) {
	//qDebug() << c1->getCname()<<"-=-="<<c1->getCardNum();
	qDebug() << "heeeeehere";
	//cv::imwrite("D:/5.jpg",tmp);
	





}
DealAnalysis::~DealAnalysis(){

	if (cinfo != nullptr) {
		delete cinfo;
	}
}
