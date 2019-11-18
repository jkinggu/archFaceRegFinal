/********************************************************************************
** Form generated from reading UI file 'Login.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_faceAndCardRegClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *faceAndCardRegClass)
    {
        if (faceAndCardRegClass->objectName().isEmpty())
            faceAndCardRegClass->setObjectName(QStringLiteral("faceAndCardRegClass"));
        faceAndCardRegClass->resize(600, 400);
        menuBar = new QMenuBar(faceAndCardRegClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        faceAndCardRegClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(faceAndCardRegClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        faceAndCardRegClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(faceAndCardRegClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        faceAndCardRegClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(faceAndCardRegClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        faceAndCardRegClass->setStatusBar(statusBar);

        retranslateUi(faceAndCardRegClass);

        QMetaObject::connectSlotsByName(faceAndCardRegClass);
    } // setupUi

    void retranslateUi(QMainWindow *faceAndCardRegClass)
    {
        faceAndCardRegClass->setWindowTitle(QApplication::translate("faceAndCardRegClass", "faceAndCardReg", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class faceAndCardRegClass: public Ui_faceAndCardRegClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
