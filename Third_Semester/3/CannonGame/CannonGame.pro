#-------------------------------------------------
#
# Project created by QtCreator 2015-10-01T13:42:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CannonGame
TEMPLATE = app
CONFIG += c++11

SOURCES += main.cpp\
    CannonGameWidget.cpp \
    GameObjects/landscape.cpp \
    gameclass.cpp \
    GameObjects/cannon.cpp \
    GameObjects/Projectiles/heavyprojectile.cpp \
    GameObjects/Projectiles/lightprojectile.cpp \
    GameObjects/Projectiles/projectile.cpp \
    InputManager/inputmanager.cpp \
    InputManager/keyboardmanager.cpp \
    GameObjects/explosion.cpp

HEADERS  += \
    CannonGameWidget.h \
    GameObjects/landscape.h \
    gameclass.h \
    util.h \
    GameObjects/cannon.h \
    GameObjects/Projectiles/heavyprojectile.h \
    GameObjects/Projectiles/lightprojectile.h \
    GameObjects/Projectiles/projectile.h \
    InputManager/inputmanager.h \
    InputManager/keyboardmanager.h \
    GameObjects/explosion.h
