#pragma once
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>



#include "dlib/image_processing.h"
#include "dlib/opencv.h"
#include "dlib/image_io.h"
#include <QtCore/qobject.h>
#include "ExtraPicValue.h"
#include "CardInfo.h"
#include <QDebug>
class DealAnalysis :public QObject
{
	Q_OBJECT
public:
	DealAnalysis(QObject *parent=0);
	void dealAly();
	~DealAnalysis();
public slots:
	void handlerMatAndCinfo( CardInfo *c1,  cv::Mat &tmp);
private:
	CardInfo *cinfo;
	cv::Mat tmp;
};

