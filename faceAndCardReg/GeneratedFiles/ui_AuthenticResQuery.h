/********************************************************************************
** Form generated from reading UI file 'AuthenticResQuery.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICRESQUERY_H
#define UI_AUTHENTICRESQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthenticResQuery
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_4;
    QComboBox *auResBox;
    QLabel *label_2;
    QComboBox *kdBox;
    QLabel *label_3;
    QComboBox *kcBox;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QPushButton *queryBtn;
    QPushButton *printBtn;
    QSpacerItem *horizontalSpacer_4;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *resTableWidget;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *firstPageBtn;
    QPushButton *prePagBtn;
    QPushButton *nextPagBtn;
    QPushButton *lastPagBtn;
    QLabel *bottomLabel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QMainWindow *AuthenticResQuery)
    {
        if (AuthenticResQuery->objectName().isEmpty())
            AuthenticResQuery->setObjectName(QStringLiteral("AuthenticResQuery"));
        AuthenticResQuery->resize(1268, 749);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AuthenticResQuery->sizePolicy().hasHeightForWidth());
        AuthenticResQuery->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(AuthenticResQuery);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setMinimumSize(QSize(800, 600));
        centralWidget->setCursor(QCursor(Qt::ArrowCursor));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(3);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 5);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy1);
        QFont font;
        font.setFamily(QString::fromUtf8("\345\276\256\350\275\257\351\233\205\351\273\221"));
        font.setPointSize(10);
        label->setFont(font);
        label->setTextFormat(Qt::PlainText);
        label->setMargin(3);
        label->setIndent(-1);

        horizontalLayout->addWidget(label);

        label_4 = new QLabel(widget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_4);

        auResBox = new QComboBox(widget);
        auResBox->setObjectName(QStringLiteral("auResBox"));
        auResBox->setFont(font);

        horizontalLayout->addWidget(auResBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        kdBox = new QComboBox(widget);
        kdBox->setObjectName(QStringLiteral("kdBox"));
        kdBox->setFont(font);

        horizontalLayout->addWidget(kdBox);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_3);

        kcBox = new QComboBox(widget);
        kcBox->setObjectName(QStringLiteral("kcBox"));
        kcBox->setFont(font);

        horizontalLayout->addWidget(kcBox);

        label_5 = new QLabel(widget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setFont(font);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_5);

        dateEdit = new QDateEdit(widget);
        dateEdit->setObjectName(QStringLiteral("dateEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy2);
        dateEdit->setFont(font);

        horizontalLayout->addWidget(dateEdit);

        queryBtn = new QPushButton(widget);
        queryBtn->setObjectName(QStringLiteral("queryBtn"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(queryBtn->sizePolicy().hasHeightForWidth());
        queryBtn->setSizePolicy(sizePolicy3);
        queryBtn->setFont(font);

        horizontalLayout->addWidget(queryBtn);

        printBtn = new QPushButton(widget);
        printBtn->setObjectName(QStringLiteral("printBtn"));
        sizePolicy3.setHeightForWidth(printBtn->sizePolicy().hasHeightForWidth());
        printBtn->setSizePolicy(sizePolicy3);
        printBtn->setFont(font);

        horizontalLayout->addWidget(printBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(4, 2);
        horizontalLayout->setStretch(5, 1);
        horizontalLayout->setStretch(6, 2);
        horizontalLayout->setStretch(7, 1);
        horizontalLayout->setStretch(8, 2);
        horizontalLayout->setStretch(9, 1);
        horizontalLayout->setStretch(10, 1);
        horizontalLayout->setStretch(11, 2);

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        sizePolicy.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy);
        verticalLayout_2 = new QVBoxLayout(widget_2);
        verticalLayout_2->setSpacing(5);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 0, 0, 0);
        resTableWidget = new QTableWidget(widget_2);
        if (resTableWidget->columnCount() < 13)
            resTableWidget->setColumnCount(13);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(0, 170, 255));
        resTableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(9, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(10, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(11, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        resTableWidget->setHorizontalHeaderItem(12, __qtablewidgetitem12);
        resTableWidget->setObjectName(QStringLiteral("resTableWidget"));
        resTableWidget->setColumnCount(13);

        verticalLayout_2->addWidget(resTableWidget);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        sizePolicy.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy);
        horizontalLayout_2 = new QHBoxLayout(widget_3);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        firstPageBtn = new QPushButton(widget_3);
        firstPageBtn->setObjectName(QStringLiteral("firstPageBtn"));
        sizePolicy3.setHeightForWidth(firstPageBtn->sizePolicy().hasHeightForWidth());
        firstPageBtn->setSizePolicy(sizePolicy3);
        firstPageBtn->setFont(font);

        horizontalLayout_2->addWidget(firstPageBtn);

        prePagBtn = new QPushButton(widget_3);
        prePagBtn->setObjectName(QStringLiteral("prePagBtn"));
        sizePolicy3.setHeightForWidth(prePagBtn->sizePolicy().hasHeightForWidth());
        prePagBtn->setSizePolicy(sizePolicy3);
        prePagBtn->setFont(font);

        horizontalLayout_2->addWidget(prePagBtn);

        nextPagBtn = new QPushButton(widget_3);
        nextPagBtn->setObjectName(QStringLiteral("nextPagBtn"));
        sizePolicy3.setHeightForWidth(nextPagBtn->sizePolicy().hasHeightForWidth());
        nextPagBtn->setSizePolicy(sizePolicy3);
        nextPagBtn->setFont(font);

        horizontalLayout_2->addWidget(nextPagBtn);

        lastPagBtn = new QPushButton(widget_3);
        lastPagBtn->setObjectName(QStringLiteral("lastPagBtn"));
        sizePolicy3.setHeightForWidth(lastPagBtn->sizePolicy().hasHeightForWidth());
        lastPagBtn->setSizePolicy(sizePolicy3);
        lastPagBtn->setFont(font);

        horizontalLayout_2->addWidget(lastPagBtn);

        bottomLabel = new QLabel(widget_3);
        bottomLabel->setObjectName(QStringLiteral("bottomLabel"));
        sizePolicy.setHeightForWidth(bottomLabel->sizePolicy().hasHeightForWidth());
        bottomLabel->setSizePolicy(sizePolicy);
        bottomLabel->setFont(font);

        horizontalLayout_2->addWidget(bottomLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_2->setStretch(0, 5);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 1);
        horizontalLayout_2->setStretch(3, 1);
        horizontalLayout_2->setStretch(4, 1);
        horizontalLayout_2->setStretch(5, 1);
        horizontalLayout_2->setStretch(6, 5);

        verticalLayout->addWidget(widget_3);

        verticalLayout->setStretch(1, 15);
        AuthenticResQuery->setCentralWidget(centralWidget);

        retranslateUi(AuthenticResQuery);

        QMetaObject::connectSlotsByName(AuthenticResQuery);
    } // setupUi

    void retranslateUi(QMainWindow *AuthenticResQuery)
    {
        AuthenticResQuery->setWindowTitle(QApplication::translate("AuthenticResQuery", "\350\256\244\350\257\201\347\273\223\346\236\234\346\237\245\350\257\242", Q_NULLPTR));
        label->setText(QApplication::translate("AuthenticResQuery", "\350\257\267\351\200\211\346\213\251   ", Q_NULLPTR));
        label_4->setText(QApplication::translate("AuthenticResQuery", "\350\256\244\350\257\201\347\273\223\346\236\234\357\274\232", Q_NULLPTR));
        auResBox->clear();
        auResBox->insertItems(0, QStringList()
         << QApplication::translate("AuthenticResQuery", "\347\246\201\346\255\242\351\200\232\350\277\207", Q_NULLPTR)
         << QApplication::translate("AuthenticResQuery", "\351\200\232\350\277\207", Q_NULLPTR)
         << QApplication::translate("AuthenticResQuery", "\345\247\223\345\220\215\344\270\215\344\270\200\350\207\264", Q_NULLPTR)
         << QApplication::translate("AuthenticResQuery", "\346\227\240\350\257\206\345\210\253\350\256\260\345\275\225", Q_NULLPTR)
        );
        label_2->setText(QApplication::translate("AuthenticResQuery", "\350\200\203\347\202\271\357\274\232", Q_NULLPTR));
        kdBox->clear();
        kdBox->insertItems(0, QStringList()
         << QApplication::translate("AuthenticResQuery", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("AuthenticResQuery", "\350\200\203\345\234\272\357\274\232", Q_NULLPTR));
        kcBox->clear();
        kcBox->insertItems(0, QStringList()
         << QApplication::translate("AuthenticResQuery", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("AuthenticResQuery", "\350\256\244\350\257\201\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        queryBtn->setText(QApplication::translate("AuthenticResQuery", "\346\237\245\350\257\242", Q_NULLPTR));
        printBtn->setText(QApplication::translate("AuthenticResQuery", "\346\211\223\345\215\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = resTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AuthenticResQuery", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = resTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AuthenticResQuery", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = resTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AuthenticResQuery", "\346\200\247\345\210\253", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = resTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AuthenticResQuery", "\350\272\253\344\273\275\350\257\201\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = resTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("AuthenticResQuery", "\347\247\221\347\233\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = resTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("AuthenticResQuery", "\345\267\245\347\247\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = resTableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("AuthenticResQuery", "\347\272\247\345\210\253", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = resTableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("AuthenticResQuery", "\350\200\203\345\234\272", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = resTableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("AuthenticResQuery", "\345\272\247\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = resTableWidget->horizontalHeaderItem(9);
        ___qtablewidgetitem9->setText(QApplication::translate("AuthenticResQuery", "\345\207\206\350\200\203\350\257\201\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = resTableWidget->horizontalHeaderItem(10);
        ___qtablewidgetitem10->setText(QApplication::translate("AuthenticResQuery", "\350\256\244\350\257\201\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = resTableWidget->horizontalHeaderItem(11);
        ___qtablewidgetitem11->setText(QApplication::translate("AuthenticResQuery", "\350\256\244\350\257\201\347\273\223\346\236\234", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = resTableWidget->horizontalHeaderItem(12);
        ___qtablewidgetitem12->setText(QApplication::translate("AuthenticResQuery", "\350\256\244\350\257\201\346\254\241\346\225\260", Q_NULLPTR));
        firstPageBtn->setText(QApplication::translate("AuthenticResQuery", "\351\246\226\351\241\265", Q_NULLPTR));
        prePagBtn->setText(QApplication::translate("AuthenticResQuery", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        nextPagBtn->setText(QApplication::translate("AuthenticResQuery", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        lastPagBtn->setText(QApplication::translate("AuthenticResQuery", "\346\234\253\351\241\265", Q_NULLPTR));
        bottomLabel->setText(QApplication::translate("AuthenticResQuery", "\345\275\223\345\211\215\347\254\2541\351\241\265\357\274\214\345\205\2611\351\241\265\357\274\214\345\205\26115\346\235\241", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuthenticResQuery: public Ui_AuthenticResQuery {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICRESQUERY_H
