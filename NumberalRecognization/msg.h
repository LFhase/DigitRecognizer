#ifndef MSG_H
#define MSG_H

#include <QDialog>
#include "trainingmsg.h"

namespace Ui {
class Msg;
}

class Msg : public QDialog
{
    Q_OBJECT

public:
    explicit Msg(QWidget *parent = 0);
    ~Msg();

public:
    Ui::Msg *ui;
    trainingMsg* mb;
};

#endif // MSG_H
