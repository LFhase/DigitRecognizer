#include "recognizationui.h"
#include "ui_recognizationui.h"
#include "mvector.h"
#include <QString>
#include <QMessageBox>
#include <QFileDialog>
#include <QImage>
#include <QPixmap>
recognizationUi::recognizationUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::recognizationUi),
    image(0)
{
    ui->setupUi(this);
    this->setMinimumSize(400,300);
    this->setMaximumSize(400,300);
}

recognizationUi::~recognizationUi()
{
    delete ui;
}

void recognizationUi::on_browse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
            tr("Open BmpPic"),
            "",
            tr("Images (*.bmp)"));
    if(!fileName.isNull())
    {
        QImage qimage;
        if(!qimage.load(fileName))
        {
            QMessageBox::about(this,"OpenPic",
                      "Fail to open the picture\nPlease check the configure");
            return;
        }
        if(image)   delete image;
        image = new bmpImage;
        image->readImage(fileName.toStdString());

        this->ui->image->QLabel::setPixmap(QPixmap::fromImage(
                                               qimage.scaled(
                                                    this->ui->image->width(),
                                                   this->ui->image->height()))
                                           );
    }
}

void recognizationUi::on_go_clicked()
{
    int height = bpnnet.trainPicHeight;
    int width = bpnnet.trainPicWidth;
    if(image==0
            ||image->imageHead.biHeight!=height
            ||((int)image->imageHead.biSizeImage!=bpnnet.getInum()&&bpnnet.getInum())
            ||image->imageHead.biWidth!=width)
       {
        if(!height||!width)
        {
            QMessageBox::about(this,"ReadPic",
                      "Fail to read the picture\nPlease check the configure");
            return;
        }
        char warning[100];
        sprintf(warning,"Fail to read the picture\n"
                        "It should be a bmp of %dX%d\n"
                        "Please check the configure",width,height);
        QMessageBox::about(this,"ReadPic",
                  warning);
        delete image;
        image = 0;
        return;
       }
    int re = bpnnet.praAsssumpt(mvector(*image));
    char num[5];
    sprintf(num,"%d",re);
    this->ui->result->setText(QString(num));

    int sec=re==0?2:1;
    for(int i=1;i<=10;++i)
     if(bpnnet.getResult()[i]>bpnnet.getResult()[sec]&&i!=re+1)
             sec = i;

    sprintf(num,"%.2f",bpnnet.getResult()[re+1]-bpnnet.getResult()[sec]);
    this->ui->accuracy->setText(QString(num));
    QApplication::processEvents();
}

void recognizationUi::on_pushButton_clicked()
{

}
