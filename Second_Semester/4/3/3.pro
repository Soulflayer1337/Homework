#-------------------------------------------------
#
# Project created by QtCreator 2015-04-24T14:34:39
#
#-------------------------------------------------

QT       += core gui testlib

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 4_3
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
        calcwindow.cpp \
    calculator.cpp

HEADERS  += calcwindow.h \
    calculator.h \
    calculatortest.h

FORMS    += calcwindow.ui
