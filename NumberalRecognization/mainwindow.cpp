#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_trainui.h"
#include "ui_recognizationUi.h"
#include "ui_testui.h"
#include "externVal.h"
#include <QString>
#include <iostream>
#include <QMessageBox>
#include <QFileDialog>
using namespace  std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    trainUi = new TrainUi;
    trainUi->show();
    this->hide();
    connect(trainUi->ui->pushButton,SIGNAL(clicked()),this,SLOT(Display()));

}
void MainWindow:: Display()
{
    QString ad = trainUi->ui->address->toPlainText();
    QString fileName = trainUi->ui->fileName->toPlainText();
    string address = ad.toStdString();
    string filePrefix= fileName.toStdString();
    int amount = trainUi->ui->triansetAmount->value();
    int totalEpoch = trainUi->ui->totalEpoch->value();
    int hiddenLyaer = trainUi->ui->hiddenLayer->value();
    int start = trainUi->ui->start->value();
    double studyRate = trainUi->ui->studyRate->value();
    bool labelAns = trainUi->ui->checkBox->isChecked();
    dataSet.~dataset();
    if(labelAns)                                            //是否读取label作为答案
    {
           QString fileName = QFileDialog::getOpenFileName(this,
                    tr("Open LabelSet"),
                    "",
                    tr("Config Files (*.idx1-ubyte)"));
            if(!fileName.isNull())
            {
                if(!dataSet.readLable(fileName.toStdString(),amount,start))
                   {
                    QMessageBox::about(this,"ReadLabel",
                              "Fail to read the label\nPlease check the configure");
                    trainUi->close();
                    this->show();
                    return;
                    }
                else
                    QMessageBox::about(this,"ReadLabel",
                              "Succeed to read the label\n");
            }
    }
    if(!dataSet.readData(address,filePrefix,amount,labelAns,start))
    {
        QMessageBox::about(this,"ReadData",
                  "Fail to read the data\nPlease check the configure");
        trainUi->close();
        this->show();
        return;
    }
    dataSet.setEpoch(totalEpoch);
    if(!bpnnet.ifLoaded())                  //根据是否是加载的模型进行继续训练
    {
        bpnnet.~BPNeuralNetwork();
        bpnnet = BPNeuralNetwork(dataSet.data[1].List->imageInfo.imageHead.biSizeImage, hiddenLyaer, 10);
    }
    bpnnet.setStudyRate(studyRate);
    bpnnet.train(dataSet);
    if (QMessageBox::Yes == QMessageBox::question(trainUi,
                                              tr("SaveModel"),
                                              tr("Save the Model?"),
                                              QMessageBox::Yes | QMessageBox::No,
                                              QMessageBox::Yes))
    {
        QString fileName = QFileDialog::getSaveFileName(this,
                tr("Open Config"),
                "",
                tr("Config Files (*.gou)"));
        if(!fileName.isNull())
        {
            if(bpnnet.storeModel(fileName.toStdString()))
                QMessageBox::about(this,"SaveModel","Succeed to save the model");
           else
                QMessageBox::about(this,"SaveModel",
                          "Fail to save the model\nPlease check the configure");
        }
    }
    trainUi->close();
    this->show();

}

void MainWindow::on_pushButton_2_clicked()
{
    if (QMessageBox::Yes == QMessageBox::question(this,
                                              tr("LoadModel"),
                                              tr("Load an Existing Model?"),
                                              QMessageBox::Yes | QMessageBox::No,
                                              QMessageBox::Yes))
    {
        QString fileName = QFileDialog::getOpenFileName(this,
                tr("Open Config"),
                "",
                tr("Config Files (*.gou)"));
        if(!fileName.isNull())
            if(!bpnnet.loadModel(fileName.toStdString()))
                QMessageBox::about(this,"LoadModel",
          "Fail to load the model!\nPlease chek your input configure!");
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    rcgUi = new recognizationUi;
    rcgUi->show();
    this->hide();
    connect(rcgUi->ui->pushButton,SIGNAL(clicked()),this,SLOT(ODisplay()));
}

void MainWindow::ODisplay()
{
    rcgUi->close();
    this->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    teUi = new testUi;
    teUi->show();
    this->hide();
    connect(teUi->ui->start,SIGNAL(clicked(bool)),this,SLOT(TDisplay()));
}
void MainWindow::TDisplay()
{
    teUi->close();
    this->show();
}
