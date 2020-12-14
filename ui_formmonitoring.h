/********************************************************************************
** Form generated from reading UI file 'formmonitoring.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMMONITORING_H
#define UI_FORMMONITORING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Formmonitoring
{
public:
    QDockWidget *dockWidget;
    QWidget *dockWidgetContents;

    void setupUi(QWidget *Formmonitoring)
    {
        if (Formmonitoring->objectName().isEmpty())
            Formmonitoring->setObjectName(QStringLiteral("Formmonitoring"));
        Formmonitoring->resize(700, 400);
        Formmonitoring->setMinimumSize(QSize(700, 400));
        Formmonitoring->setMaximumSize(QSize(700, 400));
        dockWidget = new QDockWidget(Formmonitoring);
        dockWidget->setObjectName(QStringLiteral("dockWidget"));
        dockWidget->setGeometry(QRect(20, 30, 491, 301));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        dockWidget->setWidget(dockWidgetContents);

        retranslateUi(Formmonitoring);

        QMetaObject::connectSlotsByName(Formmonitoring);
    } // setupUi

    void retranslateUi(QWidget *Formmonitoring)
    {
        Formmonitoring->setWindowTitle(QApplication::translate("Formmonitoring", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class Formmonitoring: public Ui_Formmonitoring {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMMONITORING_H
