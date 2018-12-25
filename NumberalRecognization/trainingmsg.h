#ifndef TRAININGMSG_H
#define TRAININGMSG_H

#include <QWidget>

namespace Ui {
class trainingMsg;
}

class trainingMsg : public QWidget
{
    Q_OBJECT

public:
    explicit trainingMsg(QWidget *parent = 0);
    ~trainingMsg();

public:
    Ui::trainingMsg *ui;
};

#endif // TRAININGMSG_H
