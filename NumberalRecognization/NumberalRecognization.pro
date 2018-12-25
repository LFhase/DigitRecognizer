#-------------------------------------------------
#
# Project created by QtCreator 2017-06-18T11:38:45
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = NumberalRecognization
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    trainui.cpp \
    bmpinmage.cpp \
    bpneuralnetwork.cpp \
    neuron.cpp \
    mvector.cpp \
    dataset.cpp \
    trainingmsg.cpp \
    msg.cpp \
    recognizationui.cpp \
    testui.cpp

HEADERS += \
        mainwindow.h \
    trainui.h \
    bmpdeclaration.h \
    bmpImage.h \
    bpneuralnetwork.h \
    neuron.h \
    mvector.h \
    dataset.h \
    externVal.h \
    trainingmsg.h \
    msg.h \
    recognizationui.h \
    testui.h

FORMS += \
        mainwindow.ui \
    trainui.ui \
    trainingmsg.ui \
    msg.ui \
    recognizationui.ui \
    testui.ui
