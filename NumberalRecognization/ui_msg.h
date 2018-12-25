/********************************************************************************
** Form generated from reading UI file 'msg.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MSG_H
#define UI_MSG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_Msg
{
public:
    QLabel *label;

    void setupUi(QDialog *Msg)
    {
        if (Msg->objectName().isEmpty())
            Msg->setObjectName(QStringLiteral("Msg"));
        Msg->resize(400, 300);
        label = new QLabel(Msg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 80, 211, 101));

        retranslateUi(Msg);

        QMetaObject::connectSlotsByName(Msg);
    } // setupUi

    void retranslateUi(QDialog *Msg)
    {
        Msg->setWindowTitle(QApplication::translate("Msg", "Dialog", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Msg: public Ui_Msg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MSG_H
