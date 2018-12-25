#include "trainingmsg.h"
#include "ui_trainingmsg.h"

trainingMsg::trainingMsg(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::trainingMsg)
{
    ui->setupUi(this);
}

trainingMsg::~trainingMsg()
{
    delete ui;
}
