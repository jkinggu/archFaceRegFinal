#include "AuthenticLogsDetail.h"

AuthenticLogsDetail::AuthenticLogsDetail(QWidget *parent) : QMainWindow(parent), ui(new Ui::AuthenticLogsDetail), changci(""), xingming(""),
authRes(""), shijian(""), currentPage(1),faceLogService(new FaceLogService){
	ui->setupUi(this);
	QFont *mwFont = new QFont("Microsoft YaHei", 12, QFont::Normal);
	setWindowIcon(QIcon(":/faceReg/img/face.jpg"));
	setWindowTitle("认证日志详情");
	resize(QApplication::desktop()->geometry().width() - 20, QApplication::desktop()->geometry().height() - 20);
	setFont(*mwFont);
	ui->dateEdit->setDate(QDate::currentDate());
	ui->dateEdit->setCalendarPopup(true);

	//保存地址
	ui->resTableWidget->insertColumn(6);
	ui->resTableWidget->setColumnHidden(6, true);
	showFaceLogsPanel(changci, xingming, authRes, shijian, currentPage);
	//连接信号和曹
	connect(ui->resTableWidget, SIGNAL(cellDoubleClicked(int, int)), this, SLOT(handleCellDoubleClick(int, int)));
	connect(ui->queryBtn, SIGNAL(clicked()), this, SLOT(queryFirst()));
	connect(ui->firstPageBtn, SIGNAL(clicked()), this, SLOT(queryFirst()));
	connect(ui->nextPagBtn, SIGNAL(clicked()), this, SLOT(queryNextPage()));
	connect(ui->prePagBtn, SIGNAL(clicked()), this, SLOT(queryPrePage()));
	connect(ui->lastPagBtn, SIGNAL(clicked()), this, SLOT(queryLastpage()));

}



void AuthenticLogsDetail::queryLastpage() {
	showFaceLogsPanelByPage(pageResult.totalPage);
}
void AuthenticLogsDetail::queryPrePage() {
	showFaceLogsPanelByPage(pageResult.previous);
}
void AuthenticLogsDetail::queryNextPage() {
	showFaceLogsPanelByPage(pageResult.next);

}
void AuthenticLogsDetail::queryFirst() {
	showFaceLogsPanelByPage(1);
}

void AuthenticLogsDetail::showFaceLogsPanelByPage(const int &curPag) {
	changci = stringUtil::getFormatStr(ui->changciBox->currentText());
	xingming = stringUtil::getFormatStr(ui->nameLineEdit->text());
	authRes = stringUtil::getFormatStr(ui->kcBox->currentText());
	shijian = timeFormat::formatTime(ui->dateEdit->text());
	currentPage = curPag;
	showFaceLogsPanel(changci, xingming, authRes, shijian, currentPage);
}

void AuthenticLogsDetail::handleCellDoubleClick(int row, int col) {
	if (col == 5) {
		QString picPath = ui->resTableWidget->item(row, 6)->text();
		QStringList picPathList = picPath.split(";");
		QString sfzPath = "";
		QString facePath = "";
		QString zkzPath = "";
		if (picPathList.size() == 3) {
			sfzPath = picPathList.at(0);
			facePath = picPathList.at(1);
			zkzPath = picPathList.at(2);
		}
		QDialog *picDialog = new QDialog(this);
		picDialog->resize(1020, 370);
		picDialog->setWindowTitle("图片详情");
		QHBoxLayout *picDialogBox = new QHBoxLayout;
		picDialogBox->setMargin(30);
		picDialog->setLayout(picDialogBox);

		QLabel *sfzLabel = new QLabel("");
		if (sfzPath != "") {
			QPixmap sfzPix;
			sfzPix.load(sfzPath);
			if (!sfzPix.isNull()) {
				sfzLabel->setPixmap(sfzPix.scaled(300, 350));
			}
		}
		sfzLabel->setParent(picDialog);
		picDialogBox->addWidget(sfzLabel);

		QLabel *faceLabel = new QLabel("");
		if (facePath != "") {
			QPixmap facePix;
			facePix.load(facePath);
			if (!facePix.isNull()) {
				faceLabel->setPixmap(facePix.scaled(300, 350));
			}
		}
		faceLabel->setParent(picDialog);
		picDialogBox->addWidget(faceLabel);

		QLabel *zkzLabel = new QLabel("");
		if (zkzPath != "") {
			QPixmap zkzPix;
			zkzPix.load(zkzPath);
			if (!zkzPix.isNull()) {
				zkzLabel->setPixmap(zkzPix.scaled(300, 350));
			}
		}
		zkzLabel->setParent(picDialog);
		picDialogBox->addWidget(zkzLabel);
		picDialog->show();
	}
}

void AuthenticLogsDetail::showFaceLogsPanel(const QString &changci, const QString &xingming, const QString &authRes, const QString &shijian, const int &curPag) {
	ui->resTableWidget->clearContents();
	PageResult<FaceLog> pageResult = faceLogService->getAuthenticLogs(changci, xingming, authRes, shijian, curPag);
	QFont *btmLabelFont = new QFont("Microsoft YaHei", 10, QFont::Normal);
	ui->bottomLabel->setFont(*btmLabelFont);
	ui->bottomLabel->setText("当前第" + QString::number(pageResult.currentPage) + "页，共" + QString::number(pageResult.totalPage) + "页，共" + QString::number(pageResult.totalCount) + "条");
	QVector<FaceLog> flogs = pageResult.resList;
	//qDebug() << flogs.size() << "===---";
	ui->resTableWidget->setRowCount(flogs.size());
	if (!flogs.empty()) {
		for (int i = 0; i<flogs.size(); i++) {
			FaceLog logTmp = flogs[i];
			createAItem(i, logTmp);
		}
	}
}

void AuthenticLogsDetail::createAItem(int &row, FaceLog &faceLog) {
	QTableWidgetItem *item = nullptr;
	QFont *itemFont = new QFont("Microsoft YaHei", 10, QFont::Normal);

	item = new QTableWidgetItem(faceLog.getXingming(), 1);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	item->setSelected(false);
	ui->resTableWidget->setItem(row, 0, item);


	item = new QTableWidgetItem(faceLog.getSfz(), 2);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 1, item);

	item = new QTableWidgetItem(faceLog.getShijian(), 3);
	item->setTextAlignment(Qt::AlignCenter);

	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 2, item);

	item = new QTableWidgetItem(faceLog.getChangci(), 4);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 3, item);

	item = new QTableWidgetItem(faceLog.getShibieleixing(), 5);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 4, item);

	//保存地址
	QString picPath = faceLog.getSfzphoto() + ";" + faceLog.getRenlianphoto() + ";" + faceLog.getZkzPhoto();
	item = new QTableWidgetItem(picPath, 7);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 6, item);


	QWidget *picWidget = new QWidget;
	QHBoxLayout *hlay = new QHBoxLayout;
	picWidget->resize(370, 115);
	hlay->setMargin(15);
	hlay->setContentsMargins(50, 2, 50, 2);
	picWidget->setLayout(hlay);

	QLabel *picLabel = new QLabel("");
	QPixmap sfzPic;
	sfzPic.load(faceLog.getSfzphoto());
	if (!sfzPic.isNull()) {
		picLabel->setPixmap(sfzPic.scaled(110, 110));
	}
	picLabel->setParent(picWidget);

	QLabel *picLabel2 = new QLabel("");
	QPixmap facePic;
	facePic.load(faceLog.getRenlianphoto());
	if (!facePic.isNull()) {
		picLabel2->setPixmap(facePic.scaled(110, 110));
	}
	picLabel2->setParent(picWidget);
	QLabel *picLabel3 = new QLabel("");
	QPixmap zkzPic;
	zkzPic.load(faceLog.getZkzPhoto());
	if (!zkzPic.isNull()) {
		picLabel3->setPixmap(zkzPic.scaled(100, 100));
	}
	picLabel3->setParent(picWidget);

	hlay->addWidget(picLabel);
	hlay->addWidget(picLabel2);
	hlay->addWidget(picLabel3);
	ui->resTableWidget->setCellWidget(row, 5, picWidget);
	//设置行高
	ui->resTableWidget->setRowHeight(row, 105);
}
void AuthenticLogsDetail::showEvent(QShowEvent *event) {
	int resTableWidth = ui->resTableWidget->width();
	if (resTableWidth > 100) {
		ui->resTableWidget->setColumnWidth(0, resTableWidth*0.06);
		ui->resTableWidget->setColumnWidth(1, resTableWidth*0.2);
		ui->resTableWidget->setColumnWidth(2, resTableWidth*0.14);
		ui->resTableWidget->setColumnWidth(3, resTableWidth*0.1);
		ui->resTableWidget->setColumnWidth(4, resTableWidth*0.1);
		ui->resTableWidget->setColumnWidth(5, resTableWidth*0.38);
		ui->resTableWidget->setColumnHidden(6, true);
	}
}
void AuthenticLogsDetail::resizeEvent(QResizeEvent *event) {
	int resTableWidth = ui->resTableWidget->width();
	if (resTableWidth > 100) {
		ui->resTableWidget->setColumnWidth(0, resTableWidth*0.06);
		ui->resTableWidget->setColumnWidth(1, resTableWidth*0.2);
		ui->resTableWidget->setColumnWidth(2, resTableWidth*0.14);
		ui->resTableWidget->setColumnWidth(3, resTableWidth*0.1);
		ui->resTableWidget->setColumnWidth(4, resTableWidth*0.1);
		ui->resTableWidget->setColumnWidth(5, resTableWidth*0.35);
		ui->resTableWidget->setColumnHidden(6, true);
	}
}

AuthenticLogsDetail::~AuthenticLogsDetail() {
	delete ui,faceLogService;
}
