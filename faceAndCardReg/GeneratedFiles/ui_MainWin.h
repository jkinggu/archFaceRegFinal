/********************************************************************************
** Form generated from reading UI file 'MainWin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIN_H
#define UI_MAINWIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWin
{
public:
    QAction *camStr;
    QAction *actionRzResu;
    QAction *actionRzSta;
    QAction *actionRzLog;
    QAction *actionSysDataIni;
    QAction *actionDataInAndOut;
    QAction *actionDataSet;
    QAction *actionRzDatainit;
    QAction *actiontest;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_3;

    void setupUi(QMainWindow *MainWin)
    {
        if (MainWin->objectName().isEmpty())
            MainWin->setObjectName(QStringLiteral("MainWin"));
        MainWin->resize(1268, 749);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWin->sizePolicy().hasHeightForWidth());
        MainWin->setSizePolicy(sizePolicy);
        camStr = new QAction(MainWin);
        camStr->setObjectName(QStringLiteral("camStr"));
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        camStr->setFont(font);
        actionRzResu = new QAction(MainWin);
        actionRzResu->setObjectName(QStringLiteral("actionRzResu"));
        actionRzSta = new QAction(MainWin);
        actionRzSta->setObjectName(QStringLiteral("actionRzSta"));
        actionRzLog = new QAction(MainWin);
        actionRzLog->setObjectName(QStringLiteral("actionRzLog"));
        actionSysDataIni = new QAction(MainWin);
        actionSysDataIni->setObjectName(QStringLiteral("actionSysDataIni"));
        actionDataInAndOut = new QAction(MainWin);
        actionDataInAndOut->setObjectName(QStringLiteral("actionDataInAndOut"));
        actionDataSet = new QAction(MainWin);
        actionDataSet->setObjectName(QStringLiteral("actionDataSet"));
        actionRzDatainit = new QAction(MainWin);
        actionRzDatainit->setObjectName(QStringLiteral("actionRzDatainit"));
        actiontest = new QAction(MainWin);
        actiontest->setObjectName(QStringLiteral("actiontest"));
        actiontest->setMenuRole(QAction::ApplicationSpecificRole);
        centralWidget = new QWidget(MainWin);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        centralWidget->setMinimumSize(QSize(800, 600));
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        MainWin->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWin);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1268, 25));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(10);
        sizePolicy1.setVerticalStretch(10);
        sizePolicy1.setHeightForWidth(menuBar->sizePolicy().hasHeightForWidth());
        menuBar->setSizePolicy(sizePolicy1);
        menuBar->setSizeIncrement(QSize(10, 10));
        QFont font1;
        font1.setPointSize(10);
        menuBar->setFont(font1);
        menuBar->setDefaultUp(false);
        menuBar->setNativeMenuBar(true);
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_2->setFont(font1);
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_3->setFont(font1);
        MainWin->setMenuBar(menuBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menu->addAction(camStr);
        menu_2->addAction(actionRzResu);
        menu_2->addAction(actionRzSta);
        menu_2->addAction(actionRzLog);
        menu_3->addAction(actionSysDataIni);
        menu_3->addAction(actionDataInAndOut);
        menu_3->addAction(actionDataSet);
        menu_3->addAction(actionRzDatainit);

        retranslateUi(MainWin);

        QMetaObject::connectSlotsByName(MainWin);
    } // setupUi

    void retranslateUi(QMainWindow *MainWin)
    {
        MainWin->setWindowTitle(QApplication::translate("MainWin", "\351\274\216\346\230\237\344\272\272\350\204\270\350\257\206\345\210\253\350\272\253\344\273\275\346\240\270\351\252\214\347\263\273\347\273\237", Q_NULLPTR));
        camStr->setText(QApplication::translate("MainWin", "\345\274\200\345\247\213\350\257\206\345\210\253", Q_NULLPTR));
        camStr->setIconText(QApplication::translate("MainWin", "\345\274\200\345\247\213\350\257\206\345\210\253", Q_NULLPTR));
        actionRzResu->setText(QApplication::translate("MainWin", "\350\256\244\350\257\201\347\273\223\346\236\234\346\237\245\350\257\242", Q_NULLPTR));
        actionRzSta->setText(QApplication::translate("MainWin", "\350\256\244\350\257\201\347\273\223\346\236\234\347\273\237\350\256\241", Q_NULLPTR));
        actionRzLog->setText(QApplication::translate("MainWin", "\350\256\244\350\257\201\346\227\245\345\277\227\350\257\246\346\203\205", Q_NULLPTR));
        actionSysDataIni->setText(QApplication::translate("MainWin", "\347\263\273\347\273\237\346\225\260\346\215\256\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        actionDataInAndOut->setText(QApplication::translate("MainWin", "\346\225\260\346\215\256\345\257\274\345\205\245\345\257\274\345\207\272", Q_NULLPTR));
        actionDataSet->setText(QApplication::translate("MainWin", "\350\256\244\350\257\201\346\225\260\346\215\256\350\256\276\347\275\256", Q_NULLPTR));
        actionRzDatainit->setText(QApplication::translate("MainWin", "\350\256\244\350\257\201\346\225\260\346\215\256\345\210\235\345\247\213\345\214\226", Q_NULLPTR));
        actiontest->setText(QApplication::translate("MainWin", "\344\275\240\345\245\275", Q_NULLPTR));
        menu->setTitle(QApplication::translate("MainWin", "\350\256\244\350\257\201\350\257\206\345\210\253", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWin", "\350\256\244\350\257\201\346\237\245\350\257\242", Q_NULLPTR));
        menu_3->setTitle(QApplication::translate("MainWin", "\346\225\260\346\215\256\347\256\241\347\220\206", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWin: public Ui_MainWin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIN_H
