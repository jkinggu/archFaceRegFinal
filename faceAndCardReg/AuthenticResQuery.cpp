#include "AuthenticResQuery.h"

AuthenticResQuery::AuthenticResQuery(QWidget *parent) :QMainWindow(parent), ui(new Ui::AuthenticResQuery), faceLogService(new FaceLogService), zkzdataService(new ZkzdataService), changci("职业道德"), kd(""), kc(""), auRes("需人工审核"),currentPage(1)
{

	ui->setupUi(this);
	QFont *mwFont = new QFont("Microsoft YaHei", 12, QFont::Normal);
	setWindowIcon(QIcon(":/allImg/img/face.jpg"));
	setFont(*mwFont);
	setWindowTitle("认证结果查询");
	resize(QApplication::desktop()->geometry().width() - 20, QApplication::desktop()->geometry().height() - 20);
	ui->dateEdit->clear();
	ui->dateEdit->setDate(QDate(QDate::currentDate()));
	//增加隐藏列
	ui->resTableWidget->insertColumn(13);
	ui->resTableWidget->insertColumn(14);
	ui->resTableWidget->setColumnHidden(13, true);
	ui->resTableWidget->setColumnHidden(14, true);
	//连接信号和曹
	connect(ui->queryBtn, SIGNAL(clicked()), this, SLOT(queryByCon()));
	connect(ui->firstPageBtn, SIGNAL(clicked()), this, SLOT(queryByCon()));
	connect(ui->nextPagBtn, SIGNAL(clicked()), this, SLOT(queryNextPage()));
	connect(ui->prePagBtn, SIGNAL(clicked()), this, SLOT(queryPrePage()));
	connect(ui->lastPagBtn, SIGNAL(clicked()), this, SLOT(queryLastpage()));
	connect(ui->printBtn, SIGNAL(clicked()), this, SLOT(doPrintPreview()));
	//connect(ui->resTableWidget,SIGNAL(cellChanged(int,int)),this,SLOT(itemCheckState(int,int)));
	showPageResultInPanel(kd, kc, auRes, shijian, currentPage);

}

void AuthenticResQuery::showEvent(QShowEvent *event) {
	int resTableWidth = ui->resTableWidget->width();
	if (resTableWidth > 100) {
		ui->resTableWidget->setColumnWidth(0, (int)(resTableWidth*0.03));
		ui->resTableWidget->setColumnWidth(1, (int)(resTableWidth*0.06));
		ui->resTableWidget->setColumnWidth(2, (int)(resTableWidth*0.03));//0.2
		ui->resTableWidget->setColumnWidth(3, (int)(resTableWidth*0.16));
		ui->resTableWidget->setColumnWidth(4, (int)(resTableWidth*0.06));
		ui->resTableWidget->setColumnWidth(5, (int)(resTableWidth*0.08));
		ui->resTableWidget->setColumnWidth(6, (int)(resTableWidth*0.06));
		ui->resTableWidget->setColumnWidth(7, (int)(resTableWidth*0.07));
		ui->resTableWidget->setColumnWidth(8, (int)(resTableWidth*0.04));
		ui->resTableWidget->setColumnWidth(9, (int)(resTableWidth*0.13));
		ui->resTableWidget->setColumnWidth(10, (int)(resTableWidth*0.15));
		ui->resTableWidget->setColumnWidth(11, (int)(resTableWidth*0.09));
		ui->resTableWidget->setColumnWidth(12, (int)(resTableWidth*0.03));
		ui->resTableWidget->setColumnHidden(13, true);
		ui->resTableWidget->setColumnHidden(14, true);
	}
	
}
void AuthenticResQuery::resizeEvent(QResizeEvent *event) {
	int resTableWidth = ui->resTableWidget->width();
	if (resTableWidth > 100) {
		ui->resTableWidget->setColumnWidth(0, (int)(resTableWidth*0.03));
		ui->resTableWidget->setColumnWidth(1, (int)(resTableWidth*0.06));
		ui->resTableWidget->setColumnWidth(2, (int)(resTableWidth*0.03));//0.2
		ui->resTableWidget->setColumnWidth(3, (int)(resTableWidth*0.16));
		ui->resTableWidget->setColumnWidth(4, (int)(resTableWidth*0.06));
		ui->resTableWidget->setColumnWidth(5, (int)(resTableWidth*0.08));
		ui->resTableWidget->setColumnWidth(6, (int)(resTableWidth*0.06));
		ui->resTableWidget->setColumnWidth(7, (int)(resTableWidth*0.07));
		ui->resTableWidget->setColumnWidth(8, (int)(resTableWidth*0.04));
		ui->resTableWidget->setColumnWidth(9, (int)(resTableWidth*0.13));
		ui->resTableWidget->setColumnWidth(10, (int)(resTableWidth*0.15));
		ui->resTableWidget->setColumnWidth(11, (int)(resTableWidth*0.09));
		ui->resTableWidget->setColumnWidth(12, (int)(resTableWidth*0.03));
		ui->resTableWidget->setColumnHidden(13, true);
		ui->resTableWidget->setColumnHidden(14, true);
	}
}

void AuthenticResQuery::doPrintPreview() {
	//构造需要打印的对象
	bool choseFlag = false;

	checkNeedList.clear();
	for (int i = 0; i<ui->resTableWidget->rowCount(); i++) {
		if (ui->resTableWidget->item(i, 0)->checkState() == Qt::Checked) {

			choseFlag = true;
			QString facePho = ui->resTableWidget->item(i, 13)->text();
			QString sfzPho = ui->resTableWidget->item(i, 14)->text();
			QString zkzPhoto = "/zkzpho/" + ui->resTableWidget->item(i, 3)->text() + ".JPG";
			QString rzResult = ui->resTableWidget->item(i, 11)->text();
			if (rzResult == "非考生" || rzResult == "无信息") {
				MyMessageBox message;
				message.setInformationMsg("非法打印核验单");
				return;
			}
			ZkzdataPojo zdata = zkzdataService->queryZkzdataBySfzNum(ui->resTableWidget->item(i, 3)->text());
			if (zdata.getId() != 0) {
				NeedCheck checkNeed;
				checkNeed.setZkzPho(zkzPhoto);
				checkNeed.setFacePhoto(facePho);
				checkNeed.setSfzPhoto(sfzPho);
				checkNeed.setName(zdata.getXingming());
				checkNeed.setSex(zdata.getXingbie());
				checkNeed.setAge(zdata.getNianlin());
				checkNeed.setSfzNum(zdata.getUpersonnum());
				checkNeed.setZkzNum(zdata.getZkznum());
				checkNeed.setDanweiName(zdata.getDanweiname());
				checkNeed.setBaokaoName(zdata.getBaokaoname());
				checkNeed.setJbName(zdata.getJbname());
				//构造考试信息
				QMap<QString, QVector<QString>> testInfo;

				QVector<QString> value1;
				value1.append(zdata.getKc1());
				value1.append(zdata.getZh1());
				value1.append(zdata.getSj1());
				value1.append(zdata.getDd1());

				QVector<QString> value2;
				value2.append(zdata.getKc2());
				value2.append(zdata.getZh2());
				value2.append(zdata.getSj2());
				value2.append(zdata.getDd2());


				QVector<QString> value3;
				value3.append(zdata.getKc3());
				value3.append(zdata.getZh3());
				value3.append(zdata.getSj3());
				value3.append(zdata.getDd3());

				testInfo.insert("职业道德", value1);
				testInfo.insert("职业能力", value2);
				testInfo.insert("岗位技能", value3);


				checkNeed.setTestInfo(testInfo);
				checkNeed.setRzResult(rzResult);
				checkNeed.setPrintTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
				checkNeedList.append(checkNeed);





			}
		}

	}


	//---------------------构造完毕--------------//

	if (!choseFlag) {
		MyMessageBox box;
		box.setInformationMsg("请至少选择一行");
		return;
	}
	if (checkNeedList.empty()) {
		MyMessageBox box;
		box.setInformationMsg("打印失败");
		return;
	}


	//----------开始定义打印-------------
	QPrinter printer;
	QPrintPreviewDialog preview(&printer, this);

	preview.setFixedSize((int)QApplication::desktop()->geometry().width()*0.75, (int)QApplication::desktop()->geometry().height()*0.75);
	preview.setWindowTitle("打印预览");
	preview.update();//清除上次记录
	connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printPreview(QPrinter*)));

	preview.exec();
	//-------------完毕-------------
}

void AuthenticResQuery::printPreview(QPrinter *printer) {

	//--------具体打印实现-------
	QPainter painter(printer);
	painter.translate(0, 0);
	for (int i = 0; i<checkNeedList.size(); i++) {
		NeedCheck checkNeedTmp = checkNeedList[i];
		//打印标题
		QFont *prtTitleFont = new QFont("Microsoft YaHei", 18, QFont::Bold);
		painter.setFont(*prtTitleFont);
		//文字标题长度宽度
		int titleWidth = painter.fontMetrics().width(checkNeedTmp.getTitle());
		int titleHeight = painter.fontMetrics().height();
		int titleX = (int)(printer->width() - titleWidth) / 2;
		painter.drawText(titleX, 35, checkNeedTmp.getTitle());


		//构建打印图片
		int newY = 35 + titleHeight + 5;
		int qmgW = 200, qmgH = 300, qmgMargin = 25;
		int startX = (int)((printer->width() - qmgW * 3 - qmgMargin * 2) / 2);
		painter.translate(startX, newY);
		QImage zkz;
		zkz.load(checkNeedTmp.getZkzPho());
		if (!zkz.isNull()) {
			zkz.scaled(qmgW, qmgH);
			painter.drawImage(0, 0, zkz);
		}
		QImage sfz;
		sfz.load(checkNeedTmp.getSfzPhoto());
		if (!sfz.isNull()) {
			sfz.scaled(qmgW, qmgH);
			painter.drawImage(qmgW + qmgMargin, 0, sfz);
		}

		QImage face;
		face.load(checkNeedTmp.getFacePhoto());
		if (!face.isNull()) {
			sfz.scaled(qmgW, qmgH);
			painter.drawImage(2 * (qmgW + qmgMargin), 0, sfz);
		}

		//内容打印起始
		painter.translate(0, qmgH + 10);
		//qDebug()<<"newY2 "<<newY;
		QFont *prtContFont = new QFont("Microsoft YaHei", 13, QFont::Normal);
		painter.setFont(*prtContFont);
		int contentHeight = painter.fontMetrics().height();
		int contentHMargin = 6;
		int contentWidth = printer->width() - 2 * startX;
		painter.drawText(0, 0, "姓名:" + checkNeedTmp.getName());
		painter.drawText(0, contentHMargin + contentHeight, "性别:" + checkNeedTmp.getSex());
		painter.drawText(0, 2 * (contentHMargin + contentHeight), "年龄" + checkNeedTmp.getAge());
		painter.drawText(0, 3 * (contentHMargin + contentHeight), "准考证号" + checkNeedTmp.getZkzNum());
		painter.drawText(0, 4 * (contentHMargin + contentHeight), "身份证号:" + checkNeedTmp.getSfzNum());
		painter.drawText(0, 5 * (contentHMargin + contentHeight), "工作单位:" + checkNeedTmp.getDanweiName());
		painter.drawText(0, 6 * (contentHMargin + contentHeight), "申报工种:" + checkNeedTmp.getBaoKaoName());
		painter.drawText(0, 7 * (contentHMargin + contentHeight), "申报级别:" + checkNeedTmp.getJbName());
		//构建考试信息注意translate是动态变化的。为此浪费不少时间
		QMap<QString, QVector<QString>> testInfo = checkNeedTmp.getTestInfo();

		int changciLineH = 78;
		int changciWidth = painter.fontMetrics().width("职业道德") + 6;
		int changciHeight = painter.fontMetrics().height();
		int changciMargin = 7;
		painter.translate(0, 7 * (contentHMargin + contentHeight) + 15);
		painter.drawLine(0, 0, contentWidth, 0);
		painter.drawLine(0, 0, 0, changciLineH * 3);
		painter.drawText(3, (int)(changciLineH + changciHeight - 1) / 2, "职业道德");
		painter.drawText(3, (int)(changciLineH + changciHeight - 1) / 2 + changciLineH, "职业能力");
		painter.drawText(3, (int)(changciLineH + changciHeight - 1) / 2 + 2 * changciLineH, "岗位技能");


		QVector<QString> moralInfo = testInfo.find("职业道德").value();
		QVector<QString> abilInfo = testInfo.find("职业能力").value();
		QVector<QString> skillsInfo = testInfo.find("岗位技能").value();




		QFont *testInfoFont = new QFont("Microsoft YaHei", 11, QFont::Normal);
		painter.setFont(*testInfoFont);
		changciHeight = painter.fontMetrics().height();
		painter.drawText(changciWidth + 3, changciMargin + changciHeight, "考场:" + moralInfo[0]);
		painter.drawText(painter.fontMetrics().width("考场:" + moralInfo[0]) + 140, changciMargin + changciHeight, "座号:" + moralInfo[1]);
		painter.setPen(QColor(Qt::red));
		painter.drawText(changciWidth + 3, 3 * changciMargin + changciHeight + 4, "考试时间:" + moralInfo[2]);
		painter.setPen(QColor(Qt::black));
		painter.drawText(changciWidth + 3, 3 * changciMargin + 2 * changciHeight + 3, "考试地点:" + moralInfo[3]);


		painter.drawText(changciWidth + 3, changciMargin + changciHeight + changciLineH, "考场:" + abilInfo[0]);
		painter.drawText(painter.fontMetrics().width("考场:" + abilInfo[0]) + 140, changciMargin + changciHeight + changciLineH, "座号:" + abilInfo[1]);
		painter.setPen(QColor(Qt::red));
		painter.drawText(changciWidth + 3, 3 * changciMargin + changciHeight + changciLineH + 4, "考试时间:" + abilInfo[2]);
		painter.setPen(QColor(Qt::black));
		painter.drawText(changciWidth + 3, 3 * changciMargin + 2 * changciHeight + changciLineH + 3, "考试地点:" + abilInfo[3]);

		painter.drawText(changciWidth + 3, changciMargin + changciHeight + changciLineH * 2, "考场:" + skillsInfo[0]);
		painter.drawText(painter.fontMetrics().width("考场:" + skillsInfo[0]) + 140, changciMargin + changciHeight + changciLineH * 2, "座号:" + skillsInfo[1]);
		painter.setPen(QColor(Qt::red));
		painter.drawText(changciWidth + 3, 3 * changciMargin + changciHeight + changciLineH * 2 + 4, "考试时间:" + skillsInfo[2]);
		painter.setPen(QColor(Qt::black));
		painter.drawText(changciWidth + 3, 3 * changciMargin + 2 * changciHeight + changciLineH * 2 + 3, "考试地点:" + skillsInfo[3]);

		painter.drawLine(0, changciLineH, contentWidth, changciLineH);
		painter.drawLine(0, changciLineH * 2, contentWidth, changciLineH * 2);
		painter.drawLine(0, changciLineH * 3, contentWidth, changciLineH * 3);
		painter.drawLine(changciWidth, 0, changciWidth, changciLineH * 3);
		painter.drawLine(contentWidth, 0, contentWidth, changciLineH * 3);

		painter.translate(0, changciLineH * 3 + 35);
		painter.setFont(*prtContFont);
		painter.drawText(0, 0, "本人签名:");
		painter.drawLine(painter.fontMetrics().width("本人签名:") + 3, 0, painter.fontMetrics().width("本人签名:") + 120, 0);
		painter.drawText(0, 30, "检查结果:" + checkNeedTmp.getRzResult());
		painter.drawText(0, 60, "打印日期:" + checkNeedTmp.getPrintTime());

		if (i<checkNeedList.size() - 1) {
			printer->newPage();
		}

	}


	//ui->resTableWidget->row
	// printer->newPage();//下页打印必须

}

void AuthenticResQuery::itemCheckState(int row, int col) {
	if (ui->resTableWidget->item(row, col)->checkState() == Qt::Checked) {
		//              qDebug()<<ui->resTableWidget->item(row,13)->text();
		//             qDebug()<<ui->resTableWidget->item(row,14)->text();

	}




}


void AuthenticResQuery::queryLastpage() {
	setConditionAndShow(pageResult.totalPage);
}

void AuthenticResQuery::queryPrePage() {
	setConditionAndShow(pageResult.previous);
}
void AuthenticResQuery::queryNextPage() {
	setConditionAndShow(pageResult.next);
}
void AuthenticResQuery::queryByCon() {
	setConditionAndShow(1);
}

void AuthenticResQuery::setConditionAndShow(int curPage) {

	//changci = stringUtil::getFormatStr(ui->changciBox->currentText());
	kd = stringUtil::getFormatStr(ui->kdBox->currentText());
	kc = stringUtil::getFormatStr(ui->kcBox->currentText());
	auRes = stringUtil::getFormatStr(ui->auResBox->currentText());
	shijian = stringUtil::getFormatStr(ui->dateEdit->text());
	currentPage = curPage;
	showPageResultInPanel( kd, kc, auRes, shijian, currentPage);


}

//封装数据并且显示
void AuthenticResQuery::showPageResultInPanel(QString &kd, QString &kc, QString &rzRes, QString &shijian, int &currentPage) {
	//清空表格
	ui->resTableWidget->clearContents();
	QFont *btmLabelFont = new QFont("Microsoft YaHei", 10, QFont::Normal);
	//默认查询需人工审核数据
	pageResult = faceLogService->queryByCon(kd, kc, rzRes, shijian, currentPage);
	ui->bottomLabel->setFont(*btmLabelFont);
	ui->bottomLabel->setText("当前第" + QString::number(pageResult.currentPage) + "页，共" + QString::number(pageResult.totalPage) + "页，共" + QString::number(pageResult.totalCount) + "条");

	QVector<AuthenticResultPojo> auResList = pageResult.resList;
	//设置行数否则不显示数据，我查了好久浪费一些时间。
	ui->resTableWidget->setRowCount(auResList.size());
	//qDebug() << auResList.size() << "--=-=";
	for (int i = 0; i<auResList.size(); i++) {
		AuthenticResultPojo authRepo = auResList[i];
		createItemsARow(i, authRepo);
	}



}
//生成一行
void AuthenticResQuery::createItemsARow(int& row, AuthenticResultPojo& authRepo) {

	QTableWidgetItem *item;
	QFont *itemFont = new QFont("Microsoft YaHei", 10, QFont::Normal);
	int nr = row;
	item = new QTableWidgetItem("", 1);
	item->setTextAlignment(Qt::AlignCenter);
	item->setCheckState(Qt::Unchecked);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 0, item);

	item = new QTableWidgetItem(authRepo.xingming, 2);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 1, item);

	item = new QTableWidgetItem(authRepo.xingbie, 3);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 2, item);

	item = new QTableWidgetItem(authRepo.sfz, 4);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 3, item);


	item = new QTableWidgetItem(authRepo.kemu, 5);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 4, item);

	item = new QTableWidgetItem(authRepo.gongzh, 6);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 5, item);

	item = new QTableWidgetItem(authRepo.level, 7);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 6, item);

	item = new QTableWidgetItem(authRepo.kc, 8);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 7, item);

	item = new QTableWidgetItem(authRepo.zh, 9);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 8, item);

	item = new QTableWidgetItem(authRepo.zkz, 10);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 9, item);

	item = new QTableWidgetItem(authRepo.shijian, 11);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 10, item);

	item = new QTableWidgetItem(authRepo.aures, 12);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 11, item);

	item = new QTableWidgetItem(authRepo.auCou, 13);
	item->setTextAlignment(Qt::AlignCenter);
	item->setFont(*itemFont);
	ui->resTableWidget->setItem(nr, 12, item);

	item = new QTableWidgetItem(authRepo.facePhoto, 14);
	item->setTextAlignment(Qt::AlignCenter);
	ui->resTableWidget->setItem(nr, 13, item);
	//qDebug()<<authRepo.facePhoto;

	item = new QTableWidgetItem(authRepo.sfzPhoto, 15);
	item->setTextAlignment(Qt::AlignCenter);
	ui->resTableWidget->setItem(nr, 14, item);
	//qDebug()<<authRepo.sfzPhoto;
}

AuthenticResQuery::~AuthenticResQuery()
{
	delete ui, faceLogService, zkzdataService;
}
