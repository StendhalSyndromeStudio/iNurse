#-------------------------------------------------
#
# Project created by QtCreator 2019-06-22T21:41:06
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iBolit
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
        mainwindow.cpp

HEADERS += \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#GUI
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/GUI/release/ -lGUI
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/GUI/debug/ -lGUI
else:unix: LIBS += -L$$OUT_PWD/../../lib/static/GUI/ -lGUI

INCLUDEPATH += $$PWD/../../lib/static/GUI
DEPENDPATH += $$PWD/../../lib/static/GUI

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/GUI/release/libGUI.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/GUI/debug/libGUI.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/GUI/release/GUI.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/GUI/debug/GUI.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/GUI/libGUI.a
