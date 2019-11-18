#include "AuthenticResQuery.h"

AuthenticResQuery::AuthenticResQuery(QWidget *parent) :QMainWindow(parent), ui(new Ui::AuthenticResQuery), faceLogService(new FaceLogService), zkzdataService(new ZkzdataService), changci("ְҵ����"), kd(""), kc(""), auRes("���˹����"),currentPage(1)
{

	ui->setupUi(this);
	QFont *mwFont = new QFont("Microsoft YaHei", 12, QFont::Normal);
	setWindowIcon(QIcon(":/allImg/img/face.jpg"));
	setFont(*mwFont);
	setWindowTitle("��֤�����ѯ");
	resize(QApplication::desktop()->geometry().width() - 20, QApplication::desktop()->geometry().height() - 20);
	ui->dateEdit->clear();
	ui->dateEdit->setDate(QDate(QDate::currentDate()));
	//����������
	ui->resTableWidget->insertColumn(13);
	ui->resTableWidget->insertColumn(14);
	ui->resTableWidget->setColumnHidden(13, true);
	ui->resTableWidget->setColumnHidden(14, true);
	//�����źźͲ�
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
	//������Ҫ��ӡ�Ķ���
	bool choseFlag = false;

	checkNeedList.clear();
	for (int i = 0; i<ui->resTableWidget->rowCount(); i++) {
		if (ui->resTableWidget->item(i, 0)->checkState() == Qt::Checked) {

			choseFlag = true;
			QString facePho = ui->resTableWidget->item(i, 13)->text();
			QString sfzPho = ui->resTableWidget->item(i, 14)->text();
			QString zkzPhoto = "/zkzpho/" + ui->resTableWidget->item(i, 3)->text() + ".JPG";
			QString rzResult = ui->resTableWidget->item(i, 11)->text();
			if (rzResult == "�ǿ���" || rzResult == "����Ϣ") {
				MyMessageBox message;
				message.setInformationMsg("�Ƿ���ӡ���鵥");
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
				//���쿼����Ϣ
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

				testInfo.insert("ְҵ����", value1);
				testInfo.insert("ְҵ����", value2);
				testInfo.insert("��λ����", value3);


				checkNeed.setTestInfo(testInfo);
				checkNeed.setRzResult(rzResult);
				checkNeed.setPrintTime(QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss"));
				checkNeedList.append(checkNeed);





			}
		}

	}


	//---------------------�������--------------//

	if (!choseFlag) {
		MyMessageBox box;
		box.setInformationMsg("������ѡ��һ��");
		return;
	}
	if (checkNeedList.empty()) {
		MyMessageBox box;
		box.setInformationMsg("��ӡʧ��");
		return;
	}


	//----------��ʼ�����ӡ-------------
	QPrinter printer;
	QPrintPreviewDialog preview(&printer, this);

	preview.setFixedSize((int)QApplication::desktop()->geometry().width()*0.75, (int)QApplication::desktop()->geometry().height()*0.75);
	preview.setWindowTitle("��ӡԤ��");
	preview.update();//����ϴμ�¼
	connect(&preview, SIGNAL(paintRequested(QPrinter*)), this, SLOT(printPreview(QPrinter*)));

	preview.exec();
	//-------------���-------------
}

void AuthenticResQuery::printPreview(QPrinter *printer) {

	//--------�����ӡʵ��-------
	QPainter painter(printer);
	painter.translate(0, 0);
	for (int i = 0; i<checkNeedList.size(); i++) {
		NeedCheck checkNeedTmp = checkNeedList[i];
		//��ӡ����
		QFont *prtTitleFont = new QFont("Microsoft YaHei", 18, QFont::Bold);
		painter.setFont(*prtTitleFont);
		//���ֱ��ⳤ�ȿ��
		int titleWidth = painter.fontMetrics().width(checkNeedTmp.getTitle());
		int titleHeight = painter.fontMetrics().height();
		int titleX = (int)(printer->width() - titleWidth) / 2;
		painter.drawText(titleX, 35, checkNeedTmp.getTitle());


		//������ӡͼƬ
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

		//���ݴ�ӡ��ʼ
		painter.translate(0, qmgH + 10);
		//qDebug()<<"newY2 "<<newY;
		QFont *prtContFont = new QFont("Microsoft YaHei", 13, QFont::Normal);
		painter.setFont(*prtContFont);
		int contentHeight = painter.fontMetrics().height();
		int contentHMargin = 6;
		int contentWidth = printer->width() - 2 * startX;
		painter.drawText(0, 0, "����:" + checkNeedTmp.getName());
		painter.drawText(0, contentHMargin + contentHeight, "�Ա�:" + checkNeedTmp.getSex());
		painter.drawText(0, 2 * (contentHMargin + contentHeight), "����" + checkNeedTmp.getAge());
		painter.drawText(0, 3 * (contentHMargin + contentHeight), "׼��֤��" + checkNeedTmp.getZkzNum());
		painter.drawText(0, 4 * (contentHMargin + contentHeight), "���֤��:" + checkNeedTmp.getSfzNum());
		painter.drawText(0, 5 * (contentHMargin + contentHeight), "������λ:" + checkNeedTmp.getDanweiName());
		painter.drawText(0, 6 * (contentHMargin + contentHeight), "�걨����:" + checkNeedTmp.getBaoKaoName());
		painter.drawText(0, 7 * (contentHMargin + contentHeight), "�걨����:" + checkNeedTmp.getJbName());
		//����������Ϣע��translate�Ƕ�̬�仯�ġ�Ϊ���˷Ѳ���ʱ��
		QMap<QString, QVector<QString>> testInfo = checkNeedTmp.getTestInfo();

		int changciLineH = 78;
		int changciWidth = painter.fontMetrics().width("ְҵ����") + 6;
		int changciHeight = painter.fontMetrics().height();
		int changciMargin = 7;
		painter.translate(0, 7 * (contentHMargin + contentHeight) + 15);
		painter.drawLine(0, 0, contentWidth, 0);
		painter.drawLine(0, 0, 0, changciLineH * 3);
		painter.drawText(3, (int)(changciLineH + changciHeight - 1) / 2, "ְҵ����");
		painter.drawText(3, (int)(changciLineH + changciHeight - 1) / 2 + changciLineH, "ְҵ����");
		painter.drawText(3, (int)(changciLineH + changciHeight - 1) / 2 + 2 * changciLineH, "��λ����");


		QVector<QString> moralInfo = testInfo.find("ְҵ����").value();
		QVector<QString> abilInfo = testInfo.find("ְҵ����").value();
		QVector<QString> skillsInfo = testInfo.find("��λ����").value();




		QFont *testInfoFont = new QFont("Microsoft YaHei", 11, QFont::Normal);
		painter.setFont(*testInfoFont);
		changciHeight = painter.fontMetrics().height();
		painter.drawText(changciWidth + 3, changciMargin + changciHeight, "����:" + moralInfo[0]);
		painter.drawText(painter.fontMetrics().width("����:" + moralInfo[0]) + 140, changciMargin + changciHeight, "����:" + moralInfo[1]);
		painter.setPen(QColor(Qt::red));
		painter.drawText(changciWidth + 3, 3 * changciMargin + changciHeight + 4, "����ʱ��:" + moralInfo[2]);
		painter.setPen(QColor(Qt::black));
		painter.drawText(changciWidth + 3, 3 * changciMargin + 2 * changciHeight + 3, "���Եص�:" + moralInfo[3]);


		painter.drawText(changciWidth + 3, changciMargin + changciHeight + changciLineH, "����:" + abilInfo[0]);
		painter.drawText(painter.fontMetrics().width("����:" + abilInfo[0]) + 140, changciMargin + changciHeight + changciLineH, "����:" + abilInfo[1]);
		painter.setPen(QColor(Qt::red));
		painter.drawText(changciWidth + 3, 3 * changciMargin + changciHeight + changciLineH + 4, "����ʱ��:" + abilInfo[2]);
		painter.setPen(QColor(Qt::black));
		painter.drawText(changciWidth + 3, 3 * changciMargin + 2 * changciHeight + changciLineH + 3, "���Եص�:" + abilInfo[3]);

		painter.drawText(changciWidth + 3, changciMargin + changciHeight + changciLineH * 2, "����:" + skillsInfo[0]);
		painter.drawText(painter.fontMetrics().width("����:" + skillsInfo[0]) + 140, changciMargin + changciHeight + changciLineH * 2, "����:" + skillsInfo[1]);
		painter.setPen(QColor(Qt::red));
		painter.drawText(changciWidth + 3, 3 * changciMargin + changciHeight + changciLineH * 2 + 4, "����ʱ��:" + skillsInfo[2]);
		painter.setPen(QColor(Qt::black));
		painter.drawText(changciWidth + 3, 3 * changciMargin + 2 * changciHeight + changciLineH * 2 + 3, "���Եص�:" + skillsInfo[3]);

		painter.drawLine(0, changciLineH, contentWidth, changciLineH);
		painter.drawLine(0, changciLineH * 2, contentWidth, changciLineH * 2);
		painter.drawLine(0, changciLineH * 3, contentWidth, changciLineH * 3);
		painter.drawLine(changciWidth, 0, changciWidth, changciLineH * 3);
		painter.drawLine(contentWidth, 0, contentWidth, changciLineH * 3);

		painter.translate(0, changciLineH * 3 + 35);
		painter.setFont(*prtContFont);
		painter.drawText(0, 0, "����ǩ��:");
		painter.drawLine(painter.fontMetrics().width("����ǩ��:") + 3, 0, painter.fontMetrics().width("����ǩ��:") + 120, 0);
		painter.drawText(0, 30, "�����:" + checkNeedTmp.getRzResult());
		painter.drawText(0, 60, "��ӡ����:" + checkNeedTmp.getPrintTime());

		if (i<checkNeedList.size() - 1) {
			printer->newPage();
		}

	}


	//ui->resTableWidget->row
	// printer->newPage();//��ҳ��ӡ����

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

//��װ���ݲ�����ʾ
void AuthenticResQuery::showPageResultInPanel(QString &kd, QString &kc, QString &rzRes, QString &shijian, int &currentPage) {
	//��ձ��
	ui->resTableWidget->clearContents();
	QFont *btmLabelFont = new QFont("Microsoft YaHei", 10, QFont::Normal);
	//Ĭ�ϲ�ѯ���˹��������
	pageResult = faceLogService->queryByCon(kd, kc, rzRes, shijian, currentPage);
	ui->bottomLabel->setFont(*btmLabelFont);
	ui->bottomLabel->setText("��ǰ��" + QString::number(pageResult.currentPage) + "ҳ����" + QString::number(pageResult.totalPage) + "ҳ����" + QString::number(pageResult.totalCount) + "��");

	QVector<AuthenticResultPojo> auResList = pageResult.resList;
	//��������������ʾ���ݣ��Ҳ��˺þ��˷�һЩʱ�䡣
	ui->resTableWidget->setRowCount(auResList.size());
	//qDebug() << auResList.size() << "--=-=";
	for (int i = 0; i<auResList.size(); i++) {
		AuthenticResultPojo authRepo = auResList[i];
		createItemsARow(i, authRepo);
	}



}
//����һ��
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
