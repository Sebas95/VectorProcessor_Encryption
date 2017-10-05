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
    pipefetchdeco.cpp \
    datamem.cpp \
    pc.cpp \
    registerbankvector.cpp \
    registersbankscalar.cpp \
    pipedecoexe.cpp \
    alu8b.cpp \
    alu32b.cpp \
    alu64.cpp

HEADERS  += mainwindow.h \
    instructionmem.h \
    mux32.h \
    mux64.h \
    pipefetchdeco.h \
    datamem.h \
    pc.h \
    registerbankvector.h \
    registersbankscalar.h \
    pipedecoexe.h \
    alu8b.h \
    alu32b.h \
    alu64.h

FORMS    += mainwindow.ui
