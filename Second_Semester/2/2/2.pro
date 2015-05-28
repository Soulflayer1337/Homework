QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    arraystack.cpp \
    linkedstack.cpp \
    calculator.cpp

CONFIG += c++11

HEADERS += \
    stack.h \
    arraystack.h \
    linkedstack.h \
    calculator.h \
    arraystacktest.h \
    linkedstacktest.h \
    calculatortest.h

