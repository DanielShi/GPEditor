#-------------------------------------------------
#
# Project created by QtCreator 2014-08-26T13:37:28
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = GPEditor
TEMPLATE = app

INCLUDEPATH += ./src
INCLUDEPATH += ./src/model
INCLUDEPATH += ./src/core


SOURCES += main.cpp\
        gpeditor.cpp \
    src/gpprojectviewer.cpp \
    src/gpscenegraphviewer.cpp \
    src/gpconsole.cpp \
    src/gppropertyviewer.cpp \
    src/gpsceneeditor.cpp \
    src/gpgamepreviewer.cpp \
    src/gpdockwidget.cpp \
    src/model/gpproject.cpp \
    src/model/gplogmanager.cpp \
    src/widget/gpgamewidget.cpp

HEADERS  += gpeditor.h \
    src/gpprojectviewer.h \
    src/gpscenegraphviewer.h \
    src/gpconsole.h \
    src/gppropertyviewer.h \
    src/gpsceneeditor.h \
    src/gpgamepreviewer.h \
    src/gpdockwidget.h \
    src/model/gpproject.h \
    src/core/gpsingleton.h \
    src/model/gplogmanager.h \
    src/widget/gpgamewidget.h

FORMS    += ui/gpeditor.ui

RESOURCES += \
    res/gpeditor.qrc

unix:!macx:!symbian: LIBS += -L$$PWD/extern/gameplay/libs/ -lgameplay

INCLUDEPATH += $$PWD/extern/gameplay/libs
DEPENDPATH += $$PWD/extern/gameplay/libs

unix:!macx:!symbian: PRE_TARGETDEPS += $$PWD/extern/gameplay/libs/libgameplay.a
