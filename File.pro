QT += core
QT -= gui
QT += core
QT += widgets
CONFIG += qt

DEFINES += QT_DEPRECATED_WARNINGS
TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
#CONFIG -= qt

SOURCES += main.cpp \
    filewatcher.cpp \
    file.cpp

HEADERS += \
    filewatcher.h \
    file.h
