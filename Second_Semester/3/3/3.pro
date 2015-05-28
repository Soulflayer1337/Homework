QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    sortedlist.cpp \
    sortedset.cpp

CONFIG += c++11

HEADERS += \
    icomparable.h \
    sortedset.h \
    sortedlist.h \
    sortedlisttest.h \
    sortedsettest.h
