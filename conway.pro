#-------------------------------------------------
#
# Project created by QtCreator 2012-06-29 15:41:03
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = conway
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gamewidget.cpp \
    imagenascii.cpp \
    conversor.cpp \
    paleta.cpp \
    mapa.cpp \
    matbin.cpp \
    patron.cpp \
    vecbin.cpp \
    celda.cpp \
    mapaqt.cpp

HEADERS  += mainwindow.h \
    gamewidget.h \
    imagenascii.hpp \
    conversor.hpp \
    paleta.hpp \
    mapa.hpp \
    matbin.hpp \
    patron.hpp \
    vecbin.hpp \
    celda.hpp \
    mapaqt.hpp

FORMS    += mainwindow.ui

OTHER_FILES += \
    README.markdown
