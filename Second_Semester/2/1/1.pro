QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    sortedlist.cpp \
    doublelinkedlist.cpp

CONFIG += c++11

HEADERS += \
    list.h \
    sortedlist.h \
    doublelinkedlist.h \
    doublelinkedlisttest.h \
    sortedlisttest.h
