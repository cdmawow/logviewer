#-------------------------------------------------
#
# Project created by QtCreator 2016-10-13T20:39:33
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LogViewer_v1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    CFileMaker.cpp \
    CFileThread.cpp

HEADERS  += mainwindow.h \
    CFileMaker.h \
    CFileThread.h \
    CMyTableWidget.cpp\

FORMS    += mainwindow.ui
