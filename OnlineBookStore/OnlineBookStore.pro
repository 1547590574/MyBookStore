#-------------------------------------------------
#
# Project created by QtCreator 2019-07-17T13:00:08
#
#-------------------------------------------------

QT       += core gui
QT       +=sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = OnlineBookStore
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        login.cpp \
    mainwindow.cpp \
    register.cpp \
    personinfor.cpp \
    orderisok.cpp \
    manager.cpp \
    fillbookinfor.cpp \
    historyorder.cpp

HEADERS += \
        login.h \
    mainwindow.h \
    register.h \
    personinfor.h \
    orderisok.h \
    manager.h \
    fillbookinfor.h \
    historyorder.h

FORMS += \
        login.ui \
    mainwindow.ui \
    register.ui \
    register.ui \
    register.ui \
    personinfor.ui \
    orderisok.ui \
    manager.ui \
    fillbookinfor.ui \
    historyorder.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pic.qrc
