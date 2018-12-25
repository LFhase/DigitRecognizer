#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trainui.h"
#include "recognizationui.h"
#include "externVal.h"
#include "testui.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void Display();
    void on_pushButton_clicked();
    void ODisplay();
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();
    void TDisplay();
    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
    TrainUi* trainUi;
    recognizationUi* rcgUi;
    testUi* teUi;
};

#endif // MAINWINDOW_H
