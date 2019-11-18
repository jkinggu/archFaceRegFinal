#include "AuthenticResTj.h"
AuthenticResTj::AuthenticResTj(QWidget *parent) :QMainWindow(parent), ui(new Ui::AuthenticResTj), kd(""), changci(""), shijian(""), currentpage(1),paramSetupService(new ParamSetupService){
	ui->setupUi(this);
	QFont *mwFont = new QFont("Microsoft YaHei", 12, QFont::Normal);
	setWindowIcon(QIcon(":/faceReg/img/face.jpg"));
	setFont(*mwFont);
	setWindowTitle("认证结果统计");
	resize(QApplication::desktop()->geometry().width() - 20, QApplication::desktop()->geometry().height() - 20);
	ui->dateEdit->clear();
	ui->dateEdit->setDate(QDate(QDate::currentDate()));
	QVector<QString> citys = paramSetupService->getCity();
	if (!citys.empty()) {
		for (int i = 0; i<citys.size(); i++) {
			ui->cityBox->addItem(citys[i]);
		}
	}
	connect(ui->cityBox, SIGNAL(currentIndexChanged(int)), this, SLOT(changeKdItem()));
	connect(ui->queryBtn, SIGNAL(clicked()), this, SLOT(showAuthTjResult()));
	showPageResultInPanel(kd, changci, shijian, currentpage);
}


void AuthenticResTj::showAuthTjResult() {
	kd = stringUtil::getFormatStr(ui->kdBox->currentText());
	changci = stringUtil::getFormatStr(ui->kcBox->currentText());
	shijian = stringUtil::getFormatStr(ui->dateEdit->text());
	currentpage = 1;
	showPageResultInPanel(kd, changci, shijian, currentpage);

}

void AuthenticResTj::showPageResultInPanel(const QString &kd, const QString &changci, const QString &shijian, const int &currentPage) {
	ui->resTableWidget->clearContents();//清空表格
	PageResult<AuthenticTjPojo> pageResult = paramSetupService->getAuthTjByCon(kd, changci, shijian, currentPage);
	QFont *btmLabelFont = new QFont("Microsoft YaHei", 10, QFont::Normal);
	//默认查询需人工审核数据
	ui->bottomLabel->setFont(*btmLabelFont);
	ui->bottomLabel->setText("当前第" + QString::number(pageResult.currentPage) + "页，共" + QString::number(pageResult.totalPage) + "页，共" + QString::number(pageResult.totalCount) + "条");
	QVector<AuthenticTjPojo> auths = pageResult.resList;
	ui->resTableWidget->setRowCount(auths.size());
	if (!auths.empty()) {
		for (int i = 0; i<auths.size(); i++) {
			AuthenticTjPojo authTjpo = auths[i];
			createItemsARow(i, authTjpo);
		}

	}

}

void AuthenticResTj::createItemsARow(const int &row, AuthenticTjPojo &authTjpo) {

	QTableWidgetItem *item;
	QFont *itemFont = new QFont("Microsoft YaHei", 10, QFont::Normal);
	item = new QTableWidgetItem(authTjpo.getKd(), 1);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 0, item);

	item = new QTableWidgetItem(authTjpo.getChangci(), 2);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 1, item);

	item = new QTableWidgetItem(authTjpo.getShijain(), 3);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 2, item);



	item = new QTableWidgetItem(authTjpo.getNeedCheck(), 4);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 3, item);

	item = new QTableWidgetItem(authTjpo.getPass(), 5);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 4, item);

	item = new QTableWidgetItem(authTjpo.getNotPass(), 6);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 5, item);

	item = new QTableWidgetItem(authTjpo.getNoRecord(), 7);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(row, 6, item);
}
void AuthenticResTj::changeKdItem() {
	QString citySel = stringUtil::getFormatStr(ui->cityBox->currentText());
	if (citySel != "") {
		QList<QString> kds = paramSetupService->getKdByCity(citySel);
		if (!kds.empty()) {
			ui->kdBox->addItems(kds);
		}
	}
	else {
		ui->kdBox->clear();
		ui->kdBox->addItem("请选择");
	}

}
void AuthenticResTj::showEvent(QShowEvent *event) {
	int resTableWidth = ui->resTableWidget->width();
	if (resTableWidth > 100) {
		ui->resTableWidget->setColumnWidth(0, (int)(resTableWidth*0.2));
		ui->resTableWidget->setColumnWidth(1, (int)(resTableWidth*0.15));
		ui->resTableWidget->setColumnWidth(2, (int)(resTableWidth*0.15));
		ui->resTableWidget->setColumnWidth(3, (int)(resTableWidth*0.1));
		ui->resTableWidget->setColumnWidth(4, (int)(resTableWidth*0.1));
		ui->resTableWidget->setColumnWidth(5, (int)(resTableWidth*0.1));
		ui->resTableWidget->setColumnWidth(6, (int)(resTableWidth*0.1));
	}

}

void AuthenticResTj::resizeEvent(QResizeEvent *event) {
	int resTableWidth = ui->resTableWidget->width();
	if (resTableWidth > 100) {
		ui->resTableWidget->setColumnWidth(0, (int)(resTableWidth*0.2));
		ui->resTableWidget->setColumnWidth(1, (int)(resTableWidth*0.15));
		ui->resTableWidget->setColumnWidth(2, (int)(resTableWidth*0.15));
		ui->resTableWidget->setColumnWidth(3, (int)(resTableWidth*0.1));
		ui->resTableWidget->setColumnWidth(4, (int)(resTableWidth*0.1));
		ui->resTableWidget->setColumnWidth(5, (int)(resTableWidth*0.1));
		ui->resTableWidget->setColumnWidth(6, (int)(resTableWidth*0.1));
	}
}

AuthenticResTj::~AuthenticResTj() {
	delete ui,paramSetupService;
}

