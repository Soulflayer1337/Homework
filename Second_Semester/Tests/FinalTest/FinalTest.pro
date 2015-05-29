QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    bintree.cpp \
    iterator.cpp

CONFIG += c++11

HEADERS += \
    bintree.h \
    iterator.h \
    bintreetest.h
