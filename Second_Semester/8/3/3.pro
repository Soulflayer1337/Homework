#-------------------------------------------------
#
# Project created by QtCreator 2015-05-09T20:48:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 3
TEMPLATE = app


SOURCES += main.cpp\
        tictactoewidget.cpp \
    tictactoe.cpp

HEADERS  += tictactoewidget.h \
    tictactoe.h

FORMS    += tictactoewidget.ui

CONFIG += c++11
