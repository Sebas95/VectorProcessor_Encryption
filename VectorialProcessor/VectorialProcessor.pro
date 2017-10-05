#-------------------------------------------------
#
# Project created by QtCreator 2017-10-01T23:08:36
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VectorialProcessor
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    instructionmem.cpp \
    mux32.cpp \
    mux64.cpp \
    pipefetchdeco.cpp

HEADERS  += mainwindow.h \
    instructionmem.h \
    mux32.h \
    mux64.h \
    pipefetchdeco.h

FORMS    += mainwindow.ui
