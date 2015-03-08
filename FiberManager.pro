#-------------------------------------------------
#
# Project created by QtCreator 2015-01-11T16:51:56
#
#-------------------------------------------------

QT       += core\
            sql

QT       -= gui

TARGET = FiberManager
CONFIG   += console\
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    dbmanager.cpp \
    parameters.cpp \
    handler.cpp

HEADERS += \
    dbmanager.h \
    parameters.h \
    request.h \
    handler.h

OTHER_FILES +=
