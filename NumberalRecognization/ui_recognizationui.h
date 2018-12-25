/********************************************************************************
** Form generated from reading UI file 'recognizationui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECOGNIZATIONUI_H
#define UI_RECOGNIZATIONUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recognizationUi
{
public:
    QLabel *label;
    QPushButton *browse;
    QPushButton *go;
    QLabel *label_2;
    QLabel *result;
    QLabel *image;
    QPushButton *pushButton;
    QLabel *label_3;
    QLabel *accuracy;

    void setupUi(QWidget *recognizationUi)
    {
        if (recognizationUi->objectName().isEmpty())
            recognizationUi->setObjectName(QStringLiteral("recognizationUi"));
        recognizationUi->resize(400, 300);
        label = new QLabel(recognizationUi);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(70, 10, 261, 51));
        QFont font;
        font.setFamily(QStringLiteral("DengXian"));
        font.setPointSize(12);
        label->setFont(font);
        browse = new QPushButton(recognizationUi);
        browse->setObjectName(QStringLiteral("browse"));
        browse->setGeometry(QRect(280, 80, 93, 28));
        go = new QPushButton(recognizationUi);
        go->setObjectName(QStringLiteral("go"));
        go->setGeometry(QRect(280, 130, 93, 28));
        label_2 = new QLabel(recognizationUi);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 220, 61, 51));
        label_2->setFont(font);
        result = new QLabel(recognizationUi);
        result->setObjectName(QStringLiteral("result"));
        result->setGeometry(QRect(110, 220, 61, 51));
        QFont font1;
        font1.setFamily(QStringLiteral("DengXian"));
        font1.setPointSize(20);
        result->setFont(font1);
        image = new QLabel(recognizationUi);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(80, 70, 140, 140));
        pushButton = new QPushButton(recognizationUi);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(280, 180, 93, 28));
        label_3 = new QLabel(recognizationUi);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(170, 220, 91, 51));
        label_3->setFont(font);
        accuracy = new QLabel(recognizationUi);
        accuracy->setObjectName(QStringLiteral("accuracy"));
        accuracy->setGeometry(QRect(270, 220, 91, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("DengXian"));
        font2.setPointSize(16);
        accuracy->setFont(font2);

        retranslateUi(recognizationUi);

        QMetaObject::connectSlotsByName(recognizationUi);
    } // setupUi

    void retranslateUi(QWidget *recognizationUi)
    {
        recognizationUi->setWindowTitle(QApplication::translate("recognizationUi", "Recognization", Q_NULLPTR));
        label->setText(QApplication::translate("recognizationUi", "Recognize a Picture of Digit", Q_NULLPTR));
        browse->setText(QApplication::translate("recognizationUi", "Browse", Q_NULLPTR));
        go->setText(QApplication::translate("recognizationUi", "Go", Q_NULLPTR));
        label_2->setText(QApplication::translate("recognizationUi", "Result:", Q_NULLPTR));
        result->setText(QString());
        image->setText(QString());
        pushButton->setText(QApplication::translate("recognizationUi", "Close", Q_NULLPTR));
        label_3->setText(QApplication::translate("recognizationUi", "Accuracy", Q_NULLPTR));
        accuracy->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class recognizationUi: public Ui_recognizationUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECOGNIZATIONUI_H
