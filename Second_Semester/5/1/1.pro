QT += testlib
TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle

SOURCES += main.cpp \
    list.cpp \
    ihashfunction.cpp \
    stringhash.cpp \
    hashtable.cpp \
    jenkinshash.cpp

HEADERS += \
    list.h \
    ihashfunction.h \
    stringhash.h \
    hashtable.h \
    jenkinshash.h \
    listtest.h \
    hashtabletest.h


CONFIG += c++11
