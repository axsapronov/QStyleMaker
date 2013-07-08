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
        src/main \
        src/defines \
        src/debug \
        src/dialogs/about \
        src/common

INCLUDEPATH += \
        src/main \
        src/defines \
        src/debug \
        src/dialogs/about \
        src/common

SOURCES += main.cpp\
        maindialog.cpp \
        src/debug/debughelper.cpp \
        src/dialogs/about/about.cpp \
        src/common/stringcommon.cpp

HEADERS  += maindialog.h \
        src/defines/defines.h \
        src/debug/debughelper.h \
        src/dialogs/about/about.h \
        src/common/stringcommon.h

FORMS    += maindialog.ui \
        src/dialogs/about/about.ui

RESOURCES += \
    resources/resources.qrc
