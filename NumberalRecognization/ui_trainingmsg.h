/********************************************************************************
** Form generated from reading UI file 'trainingmsg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAININGMSG_H
#define UI_TRAININGMSG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_trainingMsg
{
public:
    QLabel *info;
    QLabel *label_2;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *trainingMsg)
    {
        if (trainingMsg->objectName().isEmpty())
            trainingMsg->setObjectName(QStringLiteral("trainingMsg"));
        trainingMsg->setEnabled(true);
        trainingMsg->resize(379, 148);
        info = new QLabel(trainingMsg);
        info->setObjectName(QStringLiteral("info"));
        info->setGeometry(QRect(50, 60, 321, 31));
        QFont font;
        font.setFamily(QStringLiteral("DengXian"));
        font.setPointSize(10);
        info->setFont(font);
        label_2 = new QLabel(trainingMsg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(140, 10, 81, 21));
        QFont font1;
        font1.setFamily(QStringLiteral("DengXian"));
        font1.setPointSize(12);
        label_2->setFont(font1);
        textBrowser = new QTextBrowser(trainingMsg);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(0, 40, 381, 111));
        textBrowser->setFrameShape(QFrame::NoFrame);
        textBrowser->setFrameShadow(QFrame::Sunken);

        retranslateUi(trainingMsg);

        QMetaObject::connectSlotsByName(trainingMsg);
    } // setupUi

    void retranslateUi(QWidget *trainingMsg)
    {
        trainingMsg->setWindowTitle(QApplication::translate("trainingMsg", "Training Infomation", Q_NULLPTR));
        info->setText(QString());
        label_2->setText(QApplication::translate("trainingMsg", "Training...", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class trainingMsg: public Ui_trainingMsg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAININGMSG_H
