#include "MyMessageBox.h"
MyMessageBox::MyMessageBox(QWidget *parent) :QMessageBox(parent), m_width(0), m_height(0) {
	setFixedSize(330, 120);
	setWindowTitle("提示消息");
	setWindowIcon(QIcon(":/faceReg/img/face.jpg"));
	addButton(QMessageBox::Yes);
	addButton(QMessageBox::No);
	setButtonText(QMessageBox::Yes, tr("确定"));
	setButtonText(QMessageBox::No, tr("取消"));
}

void MyMessageBox::closeEvent(QCloseEvent *event) {
	this->close();
}
void MyMessageBox::setWarnningMsg(const QString &msg) {
	setIcon(QMessageBox::Warning);
	setFont(QFont("Microsoft YaHei", 12, QFont::Normal));
	setText(msg);
}
void MyMessageBox::setInformationMsg(const QString &msg) {
	setIcon(QMessageBox::Information);
	setFont(QFont("Microsoft YaHei", 12, QFont::Normal));
	setText(msg);
}

void MyMessageBox::showEvent(QShowEvent *event) {
	setFixedSize(330, 120);

}

void MyMessageBox::resizeEvent(QResizeEvent *event) {
	setFixedSize(330, 120);

}

MyMessageBox::~MyMessageBox() {}


