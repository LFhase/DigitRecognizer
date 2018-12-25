/********************************************************************************
** Form generated from reading UI file 'trainui.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRAINUI_H
#define UI_TRAINUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TrainUi
{
public:
    QPushButton *pushButton;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_7;
    QDoubleSpinBox *studyRate;
    QSpinBox *totalEpoch;
    QSpinBox *hiddenLayer;
    QSpinBox *triansetAmount;
    QLabel *label_6;
    QTextEdit *fileName;
    QCheckBox *checkBox;
    QTextEdit *address;
    QLabel *label_8;
    QSpinBox *start;

    void setupUi(QWidget *TrainUi)
    {
        if (TrainUi->objectName().isEmpty())
            TrainUi->setObjectName(QStringLiteral("TrainUi"));
        TrainUi->resize(470, 361);
        pushButton = new QPushButton(TrainUi);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(170, 310, 111, 31));
        QFont font;
        font.setFamily(QStringLiteral("DengXian"));
        font.setPointSize(12);
        pushButton->setFont(font);
        pushButton->setAutoDefault(true);
        label = new QLabel(TrainUi);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(240, 190, 121, 31));
        QFont font1;
        font1.setFamily(QStringLiteral("DengXian"));
        font1.setPointSize(11);
        label->setFont(font1);
        label_2 = new QLabel(TrainUi);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(20, 70, 121, 31));
        label_2->setFont(font1);
        label_3 = new QLabel(TrainUi);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(130, 10, 231, 31));
        QFont font2;
        font2.setFamily(QStringLiteral("DengXian"));
        font2.setPointSize(24);
        label_3->setFont(font2);
        label_3->setTextFormat(Qt::RichText);
        label_4 = new QLabel(TrainUi);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 210, 121, 31));
        label_4->setFont(font1);
        label_5 = new QLabel(TrainUi);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(20, 250, 111, 31));
        label_5->setFont(font1);
        label_7 = new QLabel(TrainUi);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(240, 240, 121, 31));
        label_7->setFont(font1);
        studyRate = new QDoubleSpinBox(TrainUi);
        studyRate->setObjectName(QStringLiteral("studyRate"));
        studyRate->setGeometry(QRect(350, 250, 81, 21));
        studyRate->setMaximum(1);
        studyRate->setSingleStep(0.01);
        studyRate->setValue(0.05);
        totalEpoch = new QSpinBox(TrainUi);
        totalEpoch->setObjectName(QStringLiteral("totalEpoch"));
        totalEpoch->setGeometry(QRect(150, 260, 61, 22));
        totalEpoch->setMaximum(10000);
        totalEpoch->setValue(500);
        hiddenLayer = new QSpinBox(TrainUi);
        hiddenLayer->setObjectName(QStringLiteral("hiddenLayer"));
        hiddenLayer->setGeometry(QRect(370, 200, 61, 22));
        hiddenLayer->setWrapping(false);
        hiddenLayer->setFrame(true);
        hiddenLayer->setKeyboardTracking(true);
        hiddenLayer->setMaximum(200);
        hiddenLayer->setValue(8);
        triansetAmount = new QSpinBox(TrainUi);
        triansetAmount->setObjectName(QStringLiteral("triansetAmount"));
        triansetAmount->setGeometry(QRect(150, 220, 61, 22));
        triansetAmount->setMinimum(1);
        triansetAmount->setMaximum(100000);
        label_6 = new QLabel(TrainUi);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(20, 130, 121, 31));
        label_6->setFont(font1);
        fileName = new QTextEdit(TrainUi);
        fileName->setObjectName(QStringLiteral("fileName"));
        fileName->setGeometry(QRect(150, 130, 291, 31));
        checkBox = new QCheckBox(TrainUi);
        checkBox->setObjectName(QStringLiteral("checkBox"));
        checkBox->setGeometry(QRect(20, 110, 121, 19));
        checkBox->setAcceptDrops(false);
        checkBox->setCheckable(true);
        checkBox->setChecked(true);
        address = new QTextEdit(TrainUi);
        address->setObjectName(QStringLiteral("address"));
        address->setGeometry(QRect(150, 70, 291, 41));
        label_8 = new QLabel(TrainUi);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(20, 170, 121, 31));
        label_8->setFont(font1);
        start = new QSpinBox(TrainUi);
        start->setObjectName(QStringLiteral("start"));
        start->setGeometry(QRect(150, 180, 61, 22));
        start->setMinimum(0);
        start->setMaximum(100000);
        start->setValue(0);

        retranslateUi(TrainUi);

        QMetaObject::connectSlotsByName(TrainUi);
    } // setupUi

    void retranslateUi(QWidget *TrainUi)
    {
        TrainUi->setWindowTitle(QApplication::translate("TrainUi", "Train", Q_NULLPTR));
        pushButton->setText(QApplication::translate("TrainUi", "Start", Q_NULLPTR));
        label->setText(QApplication::translate("TrainUi", "HiddenLayer", Q_NULLPTR));
        label_2->setText(QApplication::translate("TrainUi", "TrainsetAddress", Q_NULLPTR));
        label_3->setText(QApplication::translate("TrainUi", "<html><head/><body><p><span style=\" font-size:16pt;\">Training Setting</span></p></body></html>", Q_NULLPTR));
        label_4->setText(QApplication::translate("TrainUi", "TrainsetAmount", Q_NULLPTR));
        label_5->setText(QApplication::translate("TrainUi", "TotalEpoches", Q_NULLPTR));
        label_7->setText(QApplication::translate("TrainUi", "StudyRate", Q_NULLPTR));
        label_6->setText(QApplication::translate("TrainUi", "FileNamePrefix", Q_NULLPTR));
        fileName->setHtml(QApplication::translate("TrainUi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"justify\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:11pt;\">trainImage_</span></p></body></html>", Q_NULLPTR));
        checkBox->setText(QApplication::translate("TrainUi", "LabelAnswer", Q_NULLPTR));
        address->setHtml(QApplication::translate("TrainUi", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">F:\\projects\\datastructure\\hugeDataset\\</p></body></html>", Q_NULLPTR));
        label_8->setText(QApplication::translate("TrainUi", "PicStartNum(*)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class TrainUi: public Ui_TrainUi {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRAINUI_H
