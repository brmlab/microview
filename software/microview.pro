#-------------------------------------------------
#
# Project created by QtCreator 2011-08-12T19:14:06
#
#-------------------------------------------------

QT       += core gui

TARGET = microview
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    videoview.cpp

HEADERS  += mainwindow.h \
    videoview.h

FORMS    += mainwindow.ui

unix {
    CONFIG += link_pkgconfig
    PKGCONFIG += gstreamer-0.10 gstreamer-interfaces-0.10
}

RESOURCES += \
    resources.qrc
