#ifndef TRAINUI_H
#define TRAINUI_H

#include <QWidget>

namespace Ui {
class TrainUi;
}

class TrainUi : public QWidget
{
    friend class MainWindow;
    Q_OBJECT

public:
    explicit TrainUi(QWidget *parent = 0);
    ~TrainUi();

private slots:
    void on_pushButton_clicked();

public:
    Ui::TrainUi *ui;
};

#endif // TRAINUI_H
