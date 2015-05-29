QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp

CONFIG += c++11

HEADERS += \
    bagtest.h \
    AVLTree.h \
    bag.h
