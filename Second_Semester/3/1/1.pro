QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    quicksorter.cpp \
    sorter.cpp \
    mergesorter.cpp

CONFIG += c++11

HEADERS += \
    sorter.h \
    quicksorter.h \
    mergesorter.h \
    sortertest.h
