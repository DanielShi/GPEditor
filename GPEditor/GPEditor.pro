#-------------------------------------------------
#
# Project created by QtCreator 2014-08-26T13:37:28
#
#-------------------------------------------------

QT       += core gui

TARGET = GPEditor
TEMPLATE = app

INCLUDEPATH += ./src


SOURCES += main.cpp\
        gpeditor.cpp \
    src/gpprojectviewer.cpp \
    src/gpscenegraphviewer.cpp \
    src/gpconsole.cpp \
    src/gppropertyviewer.cpp \
    src/gpsceneeditor.cpp \
    src/gpgamepreviewer.cpp \
    src/gpdockwidget.cpp

HEADERS  += gpeditor.h \
    src/gpprojectviewer.h \
    src/gpscenegraphviewer.h \
    src/gpconsole.h \
    src/gppropertyviewer.h \
    src/gpsceneeditor.h \
    src/gpgamepreviewer.h \
    src/gpdockwidget.h

FORMS    += gpeditor.ui
