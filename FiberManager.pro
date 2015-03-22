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


SOURCES +=
    src/dbmanager.cpp \
    src/handler.cpp \
    src/main.cpp \
    src/parameters.cpp

HEADERS +=
    header/dbmanager.h \
    header/handler.h \
    header/parameters.h \
    header/request.h
