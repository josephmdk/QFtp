#-------------------------------------------------
#
# Project created by QtCreator 2013-04-23T19:01:06
#
#-------------------------------------------------

QT       += core gui ftp

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QFtp
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h

FORMS    += dialog.ui

RESOURCES += \
    resource.qrc

#RC_FILE += \
#    qftp.rc

OTHER_FILES += \
    Readme.txt
