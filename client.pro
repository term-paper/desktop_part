#-------------------------------------------------
#
# Project created by QtCreator 2015-09-07T17:54:54
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = client
TEMPLATE = app


SOURCES += main.cpp \
    client.cpp \
    class_with_info.cpp \
    serializedbase.cpp \



HEADERS  += \
    client.h \
    class_with_info.h \
    serializedbase.h \


FORMS += \
    client.ui
