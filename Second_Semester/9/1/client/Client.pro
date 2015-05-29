#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T20:15:42
#
#-------------------------------------------------

QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Client
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        chatclient.cpp

HEADERS  += chatclient.h

FORMS    += chatclient.ui
