QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp

CONFIG += c++11

HEADERS += \
    sharedpointer.h \
    sharedpointertest.h
