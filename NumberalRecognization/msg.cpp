#include "msg.h"
#include "ui_msg.h"

Msg::Msg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Msg)
{
    ui->setupUi(this);
}

Msg::~Msg()
{
    delete ui;
}
