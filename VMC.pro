#-------------------------------------------------
#
# Project created by QtCreator 2014-07-02T14:21:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VMC
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 -lm -Wsign-compare


SOURCES += main.cpp\
        vmc.cpp \
    metropolis.cpp \
    wavefunction.cpp

HEADERS  += vmc.h \
    metropolis.h \
    wavefunction.h

FORMS    += vmc.ui
