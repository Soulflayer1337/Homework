QT += core testlib
QT -= gui

TARGET = viruses
CONFIG += console c++11
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    computer.cpp \
    computerfactory.cpp \
    operatingsystem.cpp \
    network.cpp \
    randomnumbergenerator.cpp \
    fakenumbergenerator.cpp

HEADERS += \
    computer.h \
    computerfactory.h \
    operatingsystem.h \
    computerfactorytest.h \
    network.h \
    networktest.h \
    macrodefinition.h \
    inumbergenerator.h \
    randomnumbergenerator.h \
    fakenumbergenerator.h

