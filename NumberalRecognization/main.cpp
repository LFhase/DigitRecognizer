#include "mainwindow.h"
#include <QApplication>
#include "externVal.h"
dataset dataSet ;
BPNeuralNetwork bpnnet;
dataset  testSet;
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
