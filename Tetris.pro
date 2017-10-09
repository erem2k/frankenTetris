#-------------------------------------------------
#
# Project created by QtCreator 2016-06-19T14:13:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetris
TEMPLATE = app

CONFIG += c++11


SOURCES += main.cpp\
        tetriswindow.cpp \
    loadingwidget.cpp \
    menuwidget.cpp \
    highscorewidget.cpp \
    gamewidget.cpp \
    quitmenuwidget.cpp \
    strategyswitch.cpp \
    tetrislogger.cpp \
    tetrispiece.cpp \
    tetrisboard.cpp \
    highscoresinteraction.cpp

HEADERS  += tetriswindow.h \
    basewidget.h \
    loadingwidget.h \
    menuwidget.h \
    highscorewidget.h \
    gamewidget.h \
    quitmenuwidget.h \
    strategyswitch.h \
    tetrislogger.h \
    tetrispiece.h \
    tetrisboard.h \
    highscoresinteraction.h \
    templatebubblesort.h

RESOURCES += \
    resources.qrc
