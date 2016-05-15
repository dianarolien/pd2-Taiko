#-------------------------------------------------
#
# Project created by QtCreator 2016-05-07T21:22:34
#
#-------------------------------------------------

QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = project2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    myrect.cpp \
    bullet.cpp \
    bottom.cpp \
    game.cpp \
    score.cpp \
    dialog.cpp \
    time.cpp \
    fri.cpp \
    bullet2.cpp

HEADERS  += mainwindow.h \
    myrect.h \
    bullet.h \
    bottom.h \
    game.h \
    score.h \
    dialog.h \
    time.h \
    fri.h \
    bullet2.h

FORMS    += mainwindow.ui \
    dialog.ui

RESOURCES += \
    a.qrc
