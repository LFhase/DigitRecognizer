#include "testui.h"
#include "ui_testui.h"
#include <QString>
#include <QFileDialog>
#include <QMessageBox>
using namespace  std;

testUi::testUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::testUi)
{
    ui->setupUi(this);
    this->setWindowTitle("Batch Test");
}

testUi::~testUi()
{
    delete ui;
}

void testUi::on_start_clicked()
{
    QString ad = this->ui->address->toPlainText();
    QString fileName = this->ui->fileName->toPlainText();
    int start = this->ui->startNum->value();
    string address = ad.toStdString();
    string filePrefix= fileName.toStdString();
    int amount = this->ui->setAmount->value();
    bool labelAns = this->ui->labelAns->isChecked();
    testSet.~dataset();
    if(labelAns)                                            //是否读取label作为答案
    {
           QString fileName = QFileDialog::getOpenFileName(this,
                    tr("Open LabelSet"),
                    "",
                    tr("Config Files (*.idx1-ubyte)"));
            if(!fileName.isNull())
            {
                if(!testSet.readLable(fileName.toStdString(),amount,start))
                   {
                    QMessageBox::about(this,"ReadLabel",
                              "Fail to read the label\nPlease check the configure");
                    this->close();
                    this->show();
                    return;
                    }
                else
                    QMessageBox::about(this,"ReadLabel",
                              "Succeed to read the label\n");
            }
    }
    if(!testSet.readData(address,filePrefix,amount,labelAns,start))
    {
        QMessageBox::about(this,"ReadData",
                  "Fail to read the data\nPlease check the configure");
        this->close();
        this->show();
        return;
    }
    bpnnet.test(testSet);
}
