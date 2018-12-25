/********************************************************************************
** Form generated from reading UI file 'testui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTUI_H
#define UI_TESTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testUi
{
public:
    QTextEdit *fileName;
    QLabel *label_3;
    QLabel *label_6;
    QCheckBox *labelAns;
    QTextEdit *address;
    QLabel *label_2;
    QPushButton *start;
    QSpinBox *setAmount;
    QLabel *label_4;
    QLabel *label_8;
    QSpinBox *startNum;

    void setupUi(QWidget *testUi)
    {
        if (testUi->objectName().isEmpty())
            testUi->setObjectName(QStringLiteral("testUi"));
        testUi->resize(478, 348);
        fileName = new QTextEdit(testUi);
        fileName->setObjectName(QStringLiteral("fileName"));
        fileName->setGeometry(QRect(150, 170, 291, 31));
        label_3 = new QLabel(testUi);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 10, 231, 31));
        QFont font;
        font.setFamily(QStringLiteral("DengXian"));
        font.setPointSize(24);
        label_3->setFont(font);
        label_3->setTextFormat(Qt::RichText);
        label_6 = new QLabel(testUi);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 170, 121, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("DengXian"));
        font1.setPointSize(11);
        label_6->setFont(font1);
        labelAns = new QCheckBox(testUi);
        labelAns->setObjectName(QStringLiteral("labelAns"));
        labelAns->setGeometry(QRect(20, 130, 121, 19));
        labelAns->setAcceptDrops(false);
        labelAns->setCheckable(true);
        labelAns->setChecked(true);
        address = new QTextEdit(testUi);
        address->setObjectName(QStringLiteral("address"));
        address->setGeometry(QRect(150, 70, 291, 41));
        label_2 = new QLabel(testUi);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 70, 121, 31));
        label_2->setFont(font1);
        start = new QPushButton(testUi);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(170, 290, 111, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("DengXian"));
        font2.setPointSize(12);
        start->setFont(font2);
        start->setAutoDefault(true);
        setAmount = new QSpinBox(testUi);
        setAmount->setObjectName(QStringLiteral("setAmount"));
        setAmount->setGeometry(QRect(150, 230, 61, 22));
        setAmount->setMinimum(1);
        setAmount->setMaximum(100000);
        label_4 = new QLabel(testUi);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 220, 121, 31));
        label_4->setFont(font1);
        label_8 = new QLabel(testUi);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(250, 220, 121, 31));
        label_8->setFont(font1);
        startNum = new QSpinBox(testUi);
        startNum->setObjectName(QStringLiteral("startNum"));
        startNum->setGeometry(QRect(390, 230, 61, 21));
        startNum->setMinimum(0);
        startNum->setMaximum(100000);
        startNum->setValue(0);

        retranslateUi(testUi);

        QMetaObject::connectSlotsByName(testUi);
    } // setupUi

    void retranslateUi(QWidget *testUi)
    {
        testUi->setWindowTitle(QApplication::translate("testUi", "Form", Q_NULLPTR));
        fileName->setHtml(QApplication::translate("testUi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">TestImage_</span></p></body></html>", Q_NULLPTR));
        label_3->setText(QApplication::translate("testUi", "<html><head/><body><p><span style=\" font-size:16pt;\">BatchTest Setting</span></p></body></html>", Q_NULLPTR));
        label_6->setText(QApplication::translate("testUi", "FileNamePrefix", Q_NULLPTR));
        labelAns->setText(QApplication::translate("testUi", "LabelAnswer", Q_NULLPTR));
        address->setHtml(QApplication::translate("testUi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">F:\\projects\\datastructure\\dataset\\</p></body></html>", Q_NULLPTR));
        label_2->setText(QApplication::translate("testUi", "TrainsetAddress", Q_NULLPTR));
        start->setText(QApplication::translate("testUi", "Start", Q_NULLPTR));
        label_4->setText(QApplication::translate("testUi", "TestSetAmount", Q_NULLPTR));
        label_8->setText(QApplication::translate("testUi", "PicStartNum(*)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class testUi: public Ui_testUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTUI_H
