#include "CameraCore.h"

CameraCore::CameraCore(int camNum, QMainWindow *parent):QMainWindow(parent),ui(new Ui::CameraCore), videoCtrTimer(nullptr)
{
	ui->setupUi(this);
	ui->resInfoLabel->setAlignment(Qt::AlignCenter | Qt::AlignTop);
	ui->resInfoLabel->setFont(QFont("", 18, 3));
	ui->resInfoLabel->setStyleSheet("color:red;");
	ui->sfzLabel->setAlignment(Qt::AlignCenter | Qt::AlignBottom);
	ui->zkzInfoBrowser->setStyleSheet("QTextBrowser{border-width:0;border-style:outset}");
	ui->watchLcd->setDigitCount(19);
	ui->watchLcd->setStyleSheet("border:0px;color:green;");
	resize(QApplication::desktop()->geometry().width() - 20, QApplication::desktop()->geometry().height() - 20);
	setWindowIcon(QIcon(":/allImg/img/face.jpg"));

	//打开相机
	if (!capture.isOpened()) {
		capture.open(camNum);
		capture.set(CV_CAP_PROP_FRAME_WIDTH,ui->camerLabel->width());
		capture.set(CV_CAP_PROP_FRAME_HEIGHT,ui->camerLabel->height());
	}
	showCamera();



}
void CameraCore::showCamera() {
	if (!capture.isOpened()) {
		capture.open(0);
		capture.set(CV_CAP_PROP_FRAME_WIDTH, (int)ui->camerLabel->width());
		capture.set(CV_CAP_PROP_FRAME_HEIGHT, (int)ui->camerLabel->height());
	}
	if (capture.isOpened()) {
		videoRate = capture.get(CV_CAP_PROP_FPS);
		if ((int)videoRate==0) {
			videoRate = 30;
		}
		capture >> curFrame;
		if (!curFrame.empty()) {
			videoCtrTimer = new QTimer(this);
			videoCtrTimer->setInterval(1000/videoRate);
			connect(videoCtrTimer,SIGNAL(timerout()),this,SLOT());
			videoCtrTimer->start();
		
		}
	}else {
		//未打开报错
	}

}

void CameraCore::nextFrame() {
	capture >> curFrame;

	cv::cvtColor(curFrame,curFrame,CV_BGR2RGB);
	QImage srcQimg = QImage((uchar*)(curFrame.data), curFrame.cols, curFrame.rows, QImage::Format_RGB888);
	ui->camerLabel->setPixmap(QPixmap::fromImage(srcQimg));
	ui->camerLabel->show();

}
void CameraCore::resizeEvent(QResizeEvent *event) {}
void CameraCore::showEvent(QShowEvent *event) {}
void CameraCore::closeEvent(QCloseEvent *event) {}

CameraCore::~CameraCore()
{

	if (videoCtrTimer != nullptr) {
		delete videoCtrTimer;
	}

	delete ui;

}
