#-------------------------------------------------
#
# Project created by QtCreator 2017-11-25T21:56:12
#
#-------------------------------------------------

QT       += core gui serialport
CONFIG   += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QSerialMonitor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serialconnect.cpp
HEADERS  += mainwindow.h \
    serialconnect.h
FORMS    += mainwindow.ui \
    serialconnect.ui
RESOURCES += \
    resources.qrc

