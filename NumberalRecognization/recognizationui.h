#ifndef RECOGNIZATIONUI_H
#define RECOGNIZATIONUI_H

#include <QWidget>
#include "bmpImage.h"
#include "externVal.h"
namespace Ui {
class recognizationUi;
}

class recognizationUi : public QWidget
{
    Q_OBJECT
    friend class MainWindow;
public:
    explicit recognizationUi(QWidget *parent = 0);
    ~recognizationUi();

private slots:
    void on_browse_clicked();

    void on_go_clicked();

    void on_pushButton_clicked();

private:
    Ui::recognizationUi *ui;
    bmpImage* image;
};

#endif // RECOGNIZATIONUI_H
