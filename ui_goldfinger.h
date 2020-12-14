/********************************************************************************
** Form generated from reading UI file 'goldfinger.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GOLDFINGER_H
#define UI_GOLDFINGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Goldfinger
{
public:
    QHBoxLayout *horizontalLayout_2;
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout_6;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_2;
    QLabel *monitoring;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QComboBox *comboBox;
    QLabel *label_6;
    QLabel *label_7;
    QWidget *widget;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QLabel *managercarid;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QGroupBox *groupBox_3;
    QGridLayout *gridLayout_3;
    QPushButton *pushButton_4;
    QLabel *selwork;
    QLabel *selcaridtip;
    QComboBox *ope;
    QLabel *userinput;
    QLabel *selworktip;
    QLabel *label_4;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QLabel *selcarid;
    QLineEdit *userinput_3;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout;
    QTreeWidget *treeWidget;
    QLineEdit *lineEdit;
    QLabel *storage_2;
    QComboBox *storage;
    QLabel *selwork_2;
    QPushButton *pushButton;
    QComboBox *Pope;
    QLabel *userinput_2;
    QLabel *label_5;
    QLabel *label_2;

    void setupUi(QWidget *Goldfinger)
    {
        if (Goldfinger->objectName().isEmpty())
            Goldfinger->setObjectName(QStringLiteral("Goldfinger"));
        Goldfinger->resize(800, 480);
        Goldfinger->setMinimumSize(QSize(800, 480));
        Goldfinger->setMaximumSize(QSize(800, 480));
        horizontalLayout_2 = new QHBoxLayout(Goldfinger);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        dockWidget = new QDockWidget(Goldfinger);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setMinimumSize(QSize(250, 450));
        dockWidget->setMaximumSize(QSize(250, 450));
        dockWidget->setFloating(false);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout_6 = new QGridLayout(dockWidgetContents);
        gridLayout_6->setSpacing(0);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        scrollArea = new QScrollArea(dockWidgetContents);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 248, 383));
        verticalLayout_2 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        monitoring = new QLabel(scrollAreaWidgetContents);
        monitoring->setObjectName(QStringLiteral("monitoring"));
        monitoring->setAlignment(Qt::AlignCenter);

        verticalLayout_2->addWidget(monitoring);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_6->addWidget(scrollArea, 0, 0, 1, 1);

        widget_2 = new QWidget(dockWidgetContents);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        horizontalLayout_4 = new QHBoxLayout(widget_2);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(widget_2);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        comboBox = new QComboBox(widget_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_4->addWidget(comboBox);


        gridLayout_6->addWidget(widget_2, 1, 0, 1, 1);

        label_6 = new QLabel(dockWidgetContents);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_6->addWidget(label_6, 2, 0, 1, 1);

        label_7 = new QLabel(dockWidgetContents);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_6->addWidget(label_7, 3, 0, 1, 1);

        dockWidget->setWidget(dockWidgetContents);

        horizontalLayout_2->addWidget(dockWidget);

        widget = new QWidget(Goldfinger);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setMinimumSize(QSize(400, 0));
        widget->setMaximumSize(QSize(400, 16777215));
        gridLayout_4 = new QGridLayout(widget);
        gridLayout_4->setSpacing(0);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_4->setContentsMargins(0, 0, 0, 0);
        groupBox = new QGroupBox(widget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(0, 0));
        label->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(label, 3, 3, 1, 1);

        managercarid = new QLabel(groupBox);
        managercarid->setObjectName(QStringLiteral("managercarid"));
        managercarid->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(managercarid, 4, 3, 1, 1);


        gridLayout_4->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_4 = new QGroupBox(widget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        gridLayout_2 = new QGridLayout(groupBox_4);
        gridLayout_2->setSpacing(3);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(groupBox_4);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout_2->addWidget(pushButton_5, 0, 0, 1, 1);


        gridLayout_4->addWidget(groupBox_4, 0, 1, 1, 1);

        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        gridLayout_3 = new QGridLayout(groupBox_3);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setHorizontalSpacing(0);
        gridLayout_3->setVerticalSpacing(2);
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(groupBox_3);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_3->addWidget(pushButton_4, 2, 2, 1, 1);

        selwork = new QLabel(groupBox_3);
        selwork->setObjectName(QStringLiteral("selwork"));

        gridLayout_3->addWidget(selwork, 1, 0, 1, 1);

        selcaridtip = new QLabel(groupBox_3);
        selcaridtip->setObjectName(QStringLiteral("selcaridtip"));

        gridLayout_3->addWidget(selcaridtip, 0, 2, 1, 1);

        ope = new QComboBox(groupBox_3);
        ope->setObjectName(QStringLiteral("ope"));

        gridLayout_3->addWidget(ope, 1, 1, 1, 1);

        userinput = new QLabel(groupBox_3);
        userinput->setObjectName(QStringLiteral("userinput"));

        gridLayout_3->addWidget(userinput, 2, 0, 1, 1);

        selworktip = new QLabel(groupBox_3);
        selworktip->setObjectName(QStringLiteral("selworktip"));
        selworktip->setMinimumSize(QSize(0, 0));
        selworktip->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_3->addWidget(selworktip, 1, 2, 1, 1);

        label_4 = new QLabel(groupBox_3);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_3->addWidget(label_4, 0, 0, 1, 1);

        groupBox_5 = new QGroupBox(groupBox_3);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        verticalLayout = new QVBoxLayout(groupBox_5);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget = new QListWidget(groupBox_5);
        listWidget->setObjectName(QStringLiteral("listWidget"));

        verticalLayout->addWidget(listWidget);


        gridLayout_3->addWidget(groupBox_5, 3, 0, 1, 3);

        selcarid = new QLabel(groupBox_3);
        selcarid->setObjectName(QStringLiteral("selcarid"));
        selcarid->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        gridLayout_3->addWidget(selcarid, 0, 1, 1, 1);

        userinput_3 = new QLineEdit(groupBox_3);
        userinput_3->setObjectName(QStringLiteral("userinput_3"));

        gridLayout_3->addWidget(userinput_3, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBox_3, 1, 0, 1, 2);


        horizontalLayout_2->addWidget(widget);

        groupBox_2 = new QGroupBox(Goldfinger);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_5 = new QGridLayout(groupBox_2);
        gridLayout_5->setSpacing(0);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_5->setContentsMargins(0, 0, 0, 0);
        groupBox_6 = new QGroupBox(groupBox_2);
        groupBox_6->setObjectName(QStringLiteral("groupBox_6"));
        horizontalLayout = new QHBoxLayout(groupBox_6);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(groupBox_6);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        treeWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);

        horizontalLayout->addWidget(treeWidget);


        gridLayout_5->addWidget(groupBox_6, 3, 0, 1, 4);

        lineEdit = new QLineEdit(groupBox_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        gridLayout_5->addWidget(lineEdit, 2, 1, 1, 1);

        storage_2 = new QLabel(groupBox_2);
        storage_2->setObjectName(QStringLiteral("storage_2"));

        gridLayout_5->addWidget(storage_2, 0, 0, 1, 1);

        storage = new QComboBox(groupBox_2);
        storage->setObjectName(QStringLiteral("storage"));

        gridLayout_5->addWidget(storage, 0, 1, 1, 1);

        selwork_2 = new QLabel(groupBox_2);
        selwork_2->setObjectName(QStringLiteral("selwork_2"));

        gridLayout_5->addWidget(selwork_2, 1, 0, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_5->addWidget(pushButton, 2, 2, 1, 2);

        Pope = new QComboBox(groupBox_2);
        Pope->setObjectName(QStringLiteral("Pope"));

        gridLayout_5->addWidget(Pope, 1, 1, 1, 1);

        userinput_2 = new QLabel(groupBox_2);
        userinput_2->setObjectName(QStringLiteral("userinput_2"));

        gridLayout_5->addWidget(userinput_2, 2, 0, 1, 1);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(0, 0));
        label_5->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(label_5, 0, 2, 1, 1);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(0, 0));
        label_2->setMaximumSize(QSize(16777215, 16777215));

        gridLayout_5->addWidget(label_2, 1, 2, 1, 1);


        horizontalLayout_2->addWidget(groupBox_2);


        retranslateUi(Goldfinger);

        QMetaObject::connectSlotsByName(Goldfinger);
    } // setupUi

    void retranslateUi(QWidget *Goldfinger)
    {
        Goldfinger->setWindowTitle(QApplication::translate("Goldfinger", "Form", 0));
        dockWidget->setWindowTitle(QApplication::translate("Goldfinger", "\347\233\221\346\216\247\347\224\273\351\235\242", 0));
        monitoring->setText(QString());
        label_3->setText(QApplication::translate("Goldfinger", "\347\247\237\345\200\237\347\224\273\351\235\242:", 0));
        label_6->setText(QApplication::translate("Goldfinger", "\347\233\221\346\216\247\345\215\241\345\217\267\357\274\232", 0));
        label_7->setText(QApplication::translate("Goldfinger", "\346\213\215\346\221\204\346\227\266\351\227\264\357\274\232", 0));
        groupBox->setTitle(QApplication::translate("Goldfinger", "\347\256\241\347\220\206\345\221\230\344\277\241\346\201\257", 0));
        label->setText(QApplication::translate("Goldfinger", "\347\256\241\347\220\206\345\221\230\345\215\241\345\217\267\357\274\232", 0));
        managercarid->setText(QString());
        groupBox_4->setTitle(QApplication::translate("Goldfinger", "\347\225\214\351\235\242\347\256\241\347\220\206", 0));
        pushButton_3->setText(QApplication::translate("Goldfinger", "\351\200\200\345\207\272", 0));
        pushButton_5->setText(QApplication::translate("Goldfinger", "\347\233\221\346\216\247\347\224\273\351\235\242", 0));
        groupBox_3->setTitle(QApplication::translate("Goldfinger", "\347\224\250\346\210\267\347\256\241\347\220\206", 0));
        pushButton_4->setText(QApplication::translate("Goldfinger", "\347\241\256\350\256\244", 0));
        selwork->setText(QApplication::translate("Goldfinger", "\351\200\211\346\213\251\346\223\215\344\275\234\357\274\232", 0));
        selcaridtip->setText(QString());
        userinput->setText(QApplication::translate("Goldfinger", "\350\276\223\345\205\245\345\206\205\345\256\271\357\274\232", 0));
        selworktip->setText(QString());
        label_4->setText(QApplication::translate("Goldfinger", "\351\200\211\346\213\251\345\215\241\345\217\267\357\274\232", 0));
        groupBox_5->setTitle(QApplication::translate("Goldfinger", "\347\224\250\346\210\267\345\215\241\344\277\241\346\201\257\345\210\227\350\241\250", 0));
        selcarid->setText(QString());
        groupBox_2->setTitle(QApplication::translate("Goldfinger", "\350\264\247\346\236\266\347\256\241\347\220\206", 0));
        groupBox_6->setTitle(QApplication::translate("Goldfinger", "\350\264\247\346\236\266\344\277\241\346\201\257", 0));
        QTreeWidgetItem *___qtreewidgetitem = treeWidget->headerItem();
        ___qtreewidgetitem->setText(0, QApplication::translate("Goldfinger", "\347\224\265\345\256\235\344\277\241\346\201\257", 0));
        storage_2->setText(QApplication::translate("Goldfinger", "\347\224\265\345\256\235\357\274\232", 0));
        selwork_2->setText(QApplication::translate("Goldfinger", "\346\223\215\344\275\234\357\274\232", 0));
        pushButton->setText(QApplication::translate("Goldfinger", "\347\241\256\350\256\244", 0));
        userinput_2->setText(QApplication::translate("Goldfinger", "\345\206\205\345\256\271\357\274\232", 0));
        label_5->setText(QString());
        label_2->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Goldfinger: public Ui_Goldfinger {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GOLDFINGER_H
