QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    consoleoutputer.cpp \
    outputer.cpp \
    fileoutputer.cpp \
    matrix.cpp

CONFIG += c++11

HEADERS += \
    consoleoutputer.h \
    outputer.h \
    fileoutputer.h \
    matrix.h \
    matrixtest.h \
    outputertest.h
