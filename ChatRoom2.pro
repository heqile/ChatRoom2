#-------------------------------------------------
#
# Project created by QtCreator 2016-02-22T19:35:38
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ChatRoom2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    clientframe.cpp \
    serverframe.cpp \
    tcpclient.cpp \
    tcpserver.cpp

HEADERS  += mainwindow.h \
    clientframe.h \
    serverframe.h \
    tcpclient.h \
    tcpserver.h

FORMS    += mainwindow.ui \
    clientframe.ui \
    serverframe.ui
