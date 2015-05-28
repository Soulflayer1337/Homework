#-------------------------------------------------
#
# Project created by QtCreator 2015-05-28T13:21:06
#
#-------------------------------------------------

QT       += core gui network widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Server
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        chatserver.cpp

HEADERS  += chatserver.h

FORMS    += chatserver.ui
