/********************************************************************************
** Form generated from reading UI file 'AuthenticLogsDetail.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTHENTICLOGSDETAIL_H
#define UI_AUTHENTICLOGSDETAIL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AuthenticLogsDetail
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *changciBox;
    QLabel *label_2;
    QLineEdit *nameLineEdit;
    QLabel *label_3;
    QComboBox *kcBox;
    QLabel *label_5;
    QDateEdit *dateEdit;
    QPushButton *queryBtn;
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

    void setupUi(QMainWindow *AuthenticLogsDetail)
    {
        if (AuthenticLogsDetail->objectName().isEmpty())
            AuthenticLogsDetail->setObjectName(QStringLiteral("AuthenticLogsDetail"));
        AuthenticLogsDetail->resize(1268, 749);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AuthenticLogsDetail->sizePolicy().hasHeightForWidth());
        AuthenticLogsDetail->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(AuthenticLogsDetail);
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

        changciBox = new QComboBox(widget);
        changciBox->setObjectName(QStringLiteral("changciBox"));
        changciBox->setFont(font);

        horizontalLayout->addWidget(changciBox);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(label_2);

        nameLineEdit = new QLineEdit(widget);
        nameLineEdit->setObjectName(QStringLiteral("nameLineEdit"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(nameLineEdit->sizePolicy().hasHeightForWidth());
        nameLineEdit->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(nameLineEdit);

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
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(dateEdit->sizePolicy().hasHeightForWidth());
        dateEdit->setSizePolicy(sizePolicy3);
        dateEdit->setFont(font);

        horizontalLayout->addWidget(dateEdit);

        queryBtn = new QPushButton(widget);
        queryBtn->setObjectName(QStringLiteral("queryBtn"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(queryBtn->sizePolicy().hasHeightForWidth());
        queryBtn->setSizePolicy(sizePolicy4);
        queryBtn->setFont(font);

        horizontalLayout->addWidget(queryBtn);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);
        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(4, 1);
        horizontalLayout->setStretch(5, 2);
        horizontalLayout->setStretch(6, 1);
        horizontalLayout->setStretch(7, 2);
        horizontalLayout->setStretch(8, 1);
        horizontalLayout->setStretch(9, 2);

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
        if (resTableWidget->columnCount() < 6)
            resTableWidget->setColumnCount(6);
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
        resTableWidget->setObjectName(QStringLiteral("resTableWidget"));
        sizePolicy2.setHeightForWidth(resTableWidget->sizePolicy().hasHeightForWidth());
        resTableWidget->setSizePolicy(sizePolicy2);
        resTableWidget->setColumnCount(6);

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
        sizePolicy4.setHeightForWidth(firstPageBtn->sizePolicy().hasHeightForWidth());
        firstPageBtn->setSizePolicy(sizePolicy4);
        firstPageBtn->setFont(font);

        horizontalLayout_2->addWidget(firstPageBtn);

        prePagBtn = new QPushButton(widget_3);
        prePagBtn->setObjectName(QStringLiteral("prePagBtn"));
        sizePolicy4.setHeightForWidth(prePagBtn->sizePolicy().hasHeightForWidth());
        prePagBtn->setSizePolicy(sizePolicy4);
        prePagBtn->setFont(font);

        horizontalLayout_2->addWidget(prePagBtn);

        nextPagBtn = new QPushButton(widget_3);
        nextPagBtn->setObjectName(QStringLiteral("nextPagBtn"));
        sizePolicy4.setHeightForWidth(nextPagBtn->sizePolicy().hasHeightForWidth());
        nextPagBtn->setSizePolicy(sizePolicy4);
        nextPagBtn->setFont(font);

        horizontalLayout_2->addWidget(nextPagBtn);

        lastPagBtn = new QPushButton(widget_3);
        lastPagBtn->setObjectName(QStringLiteral("lastPagBtn"));
        sizePolicy4.setHeightForWidth(lastPagBtn->sizePolicy().hasHeightForWidth());
        lastPagBtn->setSizePolicy(sizePolicy4);
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
        AuthenticLogsDetail->setCentralWidget(centralWidget);

        retranslateUi(AuthenticLogsDetail);

        QMetaObject::connectSlotsByName(AuthenticLogsDetail);
    } // setupUi

    void retranslateUi(QMainWindow *AuthenticLogsDetail)
    {
        AuthenticLogsDetail->setWindowTitle(QApplication::translate("AuthenticLogsDetail", "\350\256\244\350\257\201\347\273\223\346\236\234\346\237\245\350\257\242", Q_NULLPTR));
        label->setText(QApplication::translate("AuthenticLogsDetail", "\350\257\267\351\200\211\346\213\251   \345\234\272\346\254\241\357\274\232", Q_NULLPTR));
        changciBox->clear();
        changciBox->insertItems(0, QStringList()
         << QApplication::translate("AuthenticLogsDetail", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR)
         << QApplication::translate("AuthenticLogsDetail", "\350\201\214\344\270\232\351\201\223\345\276\267", Q_NULLPTR)
         << QApplication::translate("AuthenticLogsDetail", "\350\201\214\344\270\232\350\203\275\345\212\233", Q_NULLPTR)
         << QApplication::translate("AuthenticLogsDetail", "\345\262\227\344\275\215\346\212\200\350\203\275", Q_NULLPTR)
        );
        changciBox->setCurrentText(QApplication::translate("AuthenticLogsDetail", "\350\257\267\351\200\211\346\213\251", Q_NULLPTR));
        label_2->setText(QApplication::translate("AuthenticLogsDetail", "\345\247\223\345\220\215\357\274\232", Q_NULLPTR));
        label_3->setText(QApplication::translate("AuthenticLogsDetail", "\350\256\244\350\257\201\347\261\273\345\236\213\357\274\232", Q_NULLPTR));
        kcBox->clear();
        kcBox->insertItems(0, QStringList()
         << QApplication::translate("AuthenticLogsDetail", "\351\234\200\344\272\272\345\267\245\345\256\241\346\240\270", Q_NULLPTR)
         << QApplication::translate("AuthenticLogsDetail", "\351\200\232\350\277\207", Q_NULLPTR)
         << QApplication::translate("AuthenticLogsDetail", "\344\270\215\351\200\232\350\277\207", Q_NULLPTR)
         << QApplication::translate("AuthenticLogsDetail", "\351\235\236\350\200\203\347\224\237", Q_NULLPTR)
        );
        label_5->setText(QApplication::translate("AuthenticLogsDetail", "\350\256\244\350\257\201\346\227\266\351\227\264\357\274\232", Q_NULLPTR));
        queryBtn->setText(QApplication::translate("AuthenticLogsDetail", "\346\237\245\350\257\242", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = resTableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("AuthenticLogsDetail", "\345\247\223\345\220\215", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = resTableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("AuthenticLogsDetail", "\350\272\253\344\273\275\350\257\201\345\217\267", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = resTableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("AuthenticLogsDetail", "\350\256\244\350\257\201\346\227\266\351\227\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = resTableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("AuthenticLogsDetail", "\350\256\244\350\257\201\347\247\221\347\233\256", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = resTableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("AuthenticLogsDetail", "\350\256\244\350\257\201\347\273\223\346\236\234", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = resTableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("AuthenticLogsDetail", "\347\205\247\347\211\207\347\274\251\347\225\245\345\233\276", Q_NULLPTR));
        firstPageBtn->setText(QApplication::translate("AuthenticLogsDetail", "\351\246\226\351\241\265", Q_NULLPTR));
        prePagBtn->setText(QApplication::translate("AuthenticLogsDetail", "\344\270\212\344\270\200\351\241\265", Q_NULLPTR));
        nextPagBtn->setText(QApplication::translate("AuthenticLogsDetail", "\344\270\213\344\270\200\351\241\265", Q_NULLPTR));
        lastPagBtn->setText(QApplication::translate("AuthenticLogsDetail", "\346\234\253\351\241\265", Q_NULLPTR));
        bottomLabel->setText(QApplication::translate("AuthenticLogsDetail", "\345\275\223\345\211\215\347\254\2541\351\241\265\357\274\214\345\205\2611\351\241\265\357\274\214\345\205\26115\346\235\241", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class AuthenticLogsDetail: public Ui_AuthenticLogsDetail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTHENTICLOGSDETAIL_H
