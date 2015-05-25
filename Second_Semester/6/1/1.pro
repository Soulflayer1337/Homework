QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    operand.cpp \
    additionoperator.cpp \
    operator.cpp \
    subtractionoperator.cpp \
    multiplicationoperator.cpp \
    divisionoperator.cpp \
    expressionparser.cpp

HEADERS += \
    ioperand.h \
    operand.h \
    additionoperator.h \
    operator.h \
    subtractionoperator.h \
    multiplicationoperator.h \
    divisionoperator.h \
    expressionparser.h \
    expressionparsertest.h

CONFIG += c++11

DISTFILES += \
    SimpleTest.txt

