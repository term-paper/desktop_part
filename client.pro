#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T17:54:54
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app

DEPENDPATH += .
INCLUDEPATH += .
include(model/model.pri)
SOURCES += main.cpp \
    client.cpp \

HEADERS  += \
    client.h \

FORMS += \
    client.ui
