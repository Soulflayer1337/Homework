QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    list.cpp \
    uniquelist.cpp

CONFIG += c++11

HEADERS += \
    list.h \
    uniquelist.h \
    listtest.h \
    uniquelisttest.h
