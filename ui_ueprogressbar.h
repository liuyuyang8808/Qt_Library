/********************************************************************************
** Form generated from reading UI file 'ueprogressbar.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UEPROGRESSBAR_H
#define UI_UEPROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UEProgressBar
{
public:
    QProgressBar *progressBar;

    void setupUi(QWidget *UEProgressBar)
    {
        if (UEProgressBar->objectName().isEmpty())
            UEProgressBar->setObjectName(QString::fromUtf8("UEProgressBar"));
        UEProgressBar->resize(400, 300);
        progressBar = new QProgressBar(UEProgressBar);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(110, 120, 118, 23));
        progressBar->setValue(24);

        retranslateUi(UEProgressBar);

        QMetaObject::connectSlotsByName(UEProgressBar);
    } // setupUi

    void retranslateUi(QWidget *UEProgressBar)
    {
        UEProgressBar->setWindowTitle(QCoreApplication::translate("UEProgressBar", "Form", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UEProgressBar: public Ui_UEProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UEPROGRESSBAR_H
