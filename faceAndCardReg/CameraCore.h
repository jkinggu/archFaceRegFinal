#pragma once
#ifndef FACEREG_CAMERACORE_H
#define FACEREG_CAMERACORE_H

#include "qmainwindow.h"
#include <ui_CameraCore.h>
#include <qdesktopwidget.h>
#include <qtimer.h>

#include <cv.h>
#include <opencv2/core/core.hpp>
#include <opencv2/opencv.hpp>  
#include <opencv2/imgproc/imgproc.hpp>







class CameraCore :public QMainWindow
{
	Q_OBJECT
public:
	CameraCore(int camNum=0, QMainWindow *parent=0);
	~CameraCore();

private slots:
	void nextFrame();
signals:
	void camCapClose();
private:
	void resizeEvent(QResizeEvent *event);
	void showEvent(QShowEvent *event);
	void closeEvent(QCloseEvent *event);
	void showCamera();

private:
	Ui::CameraCore *ui;
	cv::Mat curFrame;
	cv::VideoCapture capture;
	double videoRate = 0.0;
	QTimer *videoCtrTimer;
};

#endif // !FACEREG_CAMER
