#-------------------------------------------------
#
# Project created by QtCreator 2013-07-08T11:03:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QStyleMaker
TEMPLATE = app

DESTDIR     = build/bin
OBJECTS_DIR = build/obj
MOC_DIR     = build/moc
RCC_DIR     = build/rc
UI_DIR      = build/ui


DEPENDPATH += \
        src/main

INCLUDEPATH += \
        src/main

SOURCES += main.cpp\
        maindialog.cpp

HEADERS  += maindialog.h

FORMS    += maindialog.ui

RESOURCES += \
    resources/resources.qrc
