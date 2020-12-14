/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout_5;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *weather;
    QLabel *datetime;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *usefultime;
    QLabel *usefulbal;
    QLabel *inuse;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *caridline;
    QLabel *bal;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *enalbe;
    QSpacerItem *horizontalSpacer;
    QLabel *renttip;
    QPushButton *rent;
    QPushButton *pushButton_3;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_7;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableWidget_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_8;
    QTableWidget *tableWidget;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(800, 480);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Widget->sizePolicy().hasHeightForWidth());
        Widget->setSizePolicy(sizePolicy);
        Widget->setMinimumSize(QSize(800, 480));
        Widget->setMaximumSize(QSize(800, 480));
        verticalLayout_5 = new QVBoxLayout(Widget);
        verticalLayout_5->setSpacing(0);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        widget = new QWidget(Widget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, -1, 0);
        weather = new QLabel(widget);
        weather->setObjectName(QStringLiteral("weather"));

        verticalLayout->addWidget(weather);

        datetime = new QLabel(widget);
        datetime->setObjectName(QStringLiteral("datetime"));

        verticalLayout->addWidget(datetime);


        verticalLayout_5->addWidget(widget);

        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout = new QHBoxLayout(widget_2);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, -1, 0);
        groupBox = new QGroupBox(widget_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        usefultime = new QLabel(groupBox);
        usefultime->setObjectName(QStringLiteral("usefultime"));

        verticalLayout_2->addWidget(usefultime);

        usefulbal = new QLabel(groupBox);
        usefulbal->setObjectName(QStringLiteral("usefulbal"));

        verticalLayout_2->addWidget(usefulbal);

        inuse = new QLabel(groupBox);
        inuse->setObjectName(QStringLiteral("inuse"));

        verticalLayout_2->addWidget(inuse);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(widget_2);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMinimumSize(QSize(200, 0));
        groupBox_2->setMaximumSize(QSize(200, 16777215));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        caridline = new QLineEdit(groupBox_2);
        caridline->setObjectName(QStringLiteral("caridline"));
        caridline->setReadOnly(true);

        verticalLayout_3->addWidget(caridline);

        bal = new QLabel(groupBox_2);
        bal->setObjectName(QStringLiteral("bal"));

        verticalLayout_3->addWidget(bal);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(widget_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setLayoutDirection(Qt::LeftToRight);
        groupBox_3->setAlignment(Qt::AlignCenter);
        horizontalLayout_2 = new QHBoxLayout(groupBox_3);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(200, 0));
        pushButton->setMaximumSize(QSize(200, 16777215));
        pushButton->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_2->addWidget(pushButton);


        horizontalLayout->addWidget(groupBox_3);


        verticalLayout_5->addWidget(widget_2);

        widget_3 = new QWidget(Widget);
        widget_3->setObjectName(QStringLiteral("widget_3"));
        horizontalLayout_5 = new QHBoxLayout(widget_3);
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        enalbe = new QLabel(widget_3);
        enalbe->setObjectName(QStringLiteral("enalbe"));

        horizontalLayout_5->addWidget(enalbe);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        renttip = new QLabel(widget_3);
        renttip->setObjectName(QStringLiteral("renttip"));

        horizontalLayout_5->addWidget(renttip);

        rent = new QPushButton(widget_3);
        rent->setObjectName(QStringLiteral("rent"));
        rent->setEnabled(false);

        horizontalLayout_5->addWidget(rent);

        pushButton_3 = new QPushButton(widget_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout_5->addWidget(widget_3);

        groupBox_4 = new QGroupBox(Widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        verticalLayout_7 = new QVBoxLayout(groupBox_4);
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        verticalLayout_7->setContentsMargins(0, 0, 0, 0);
        stackedWidget = new QStackedWidget(groupBox_4);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        verticalLayout_6 = new QVBoxLayout(page);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        tableWidget_2 = new QTableWidget(page);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));

        verticalLayout_6->addWidget(tableWidget_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        verticalLayout_8 = new QVBoxLayout(page_2);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        tableWidget = new QTableWidget(page_2);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_8->addWidget(tableWidget);

        stackedWidget->addWidget(page_2);

        verticalLayout_7->addWidget(stackedWidget);


        verticalLayout_5->addWidget(groupBox_4);


        retranslateUi(Widget);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", 0));
        weather->setText(QApplication::translate("Widget", "\345\244\251\346\260\224", 0));
        datetime->setText(QApplication::translate("Widget", "\346\227\266\351\227\264", 0));
        groupBox->setTitle(QApplication::translate("Widget", "\346\266\210\350\264\271\344\277\241\346\201\257", 0));
        usefultime->setText(QApplication::translate("Widget", "\346\234\254\346\254\241\344\275\277\347\224\250\346\227\266\351\227\264", 0));
        usefulbal->setText(QApplication::translate("Widget", "\346\234\254\346\254\241\344\275\277\347\224\250\350\264\271\347\224\250", 0));
        inuse->setText(QApplication::translate("Widget", "\344\275\277\347\224\250\347\224\265\345\256\235\357\274\232", 0));
        groupBox_2->setTitle(QApplication::translate("Widget", "\347\224\250\346\210\267\344\270\252\344\272\272\344\277\241\346\201\257", 0));
        bal->setText(QApplication::translate("Widget", "\345\215\241\345\206\205\351\207\221\351\242\235\357\274\232", 0));
        groupBox_3->setTitle(QApplication::translate("Widget", "\346\224\257\344\273\230", 0));
        pushButton->setText(QApplication::translate("Widget", "\344\272\214\347\273\264\347\240\201\346\224\257\344\273\230", 0));
        enalbe->setText(QString());
        renttip->setText(QString());
        rent->setText(QApplication::translate("Widget", "\347\247\237\347\224\250", 0));
        pushButton_3->setText(QApplication::translate("Widget", "\345\210\207\346\215\242", 0));
        groupBox_4->setTitle(QApplication::translate("Widget", "\345\205\261\344\272\253\347\224\265\345\256\235", 0));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
