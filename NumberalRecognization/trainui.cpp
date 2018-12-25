#include "trainui.h"
#include "ui_trainui.h"
#include "string"



TrainUi::TrainUi(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TrainUi)
{
    ui->setupUi(this);
}

TrainUi::~TrainUi()
{
    delete ui;
}

void TrainUi::on_pushButton_clicked()
{

}
