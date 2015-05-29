#-------------------------------------------------
#
# Project created by QtCreator 1970-01-01T08:54:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = RaspPiQtOpenCVFaceRecognizer
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

INCLUDEPATH += -I/usr/include/opencv

LIBS += -lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_objdetect -lopencv_contrib
