#ifndef TESTUI_H
#define TESTUI_H

#include <QWidget>
#include "externVal.h"

namespace Ui {
class testUi;
}

class testUi : public QWidget
{
    friend class MainWindow;
    Q_OBJECT

public:
    explicit testUi(QWidget *parent = 0);
    ~testUi();

private slots:
    void on_start_clicked();

private:
    Ui::testUi *ui;
};

#endif // TESTUI_H
