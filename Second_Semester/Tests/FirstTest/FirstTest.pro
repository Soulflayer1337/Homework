#-------------------------------------------------
#
# Project created by QtCreator 2015-05-07T15:33:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FirstTest
TEMPLATE = app


SOURCES += main.cpp\
        findpairwdget.cpp \
    findpair.cpp \
    matrix.cpp

HEADERS  += findpairwdget.h \
    findpair.h \
    matrix.h

FORMS    += findpairwdget.ui

CONFIG += c++11
