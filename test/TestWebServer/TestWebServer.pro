#-------------------------------------------------
#
# Project created by QtCreator 2019-06-22T13:10:10
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestWebServer
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

QT += websockets
QT += texttospeech

SOURCES += \
        main.cpp \
        mainwebserver.cpp \
    webclient.cpp \
    webserver.cpp\


HEADERS += \
        mainwebserver.h \
    webclient.h \
    webserver.h\


FORMS += \
        mainwebserver.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

SUBDIRS += \
    ../../lib/lib.pro




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/TextToSpeech/release/ -lTextToSpeech
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/TextToSpeech/debug/ -lTextToSpeech
else:unix: LIBS += -L$$OUT_PWD/../../lib/static/TextToSpeech/ -lTextToSpeech

INCLUDEPATH += $$PWD/../../lib/static/TextToSpeech
DEPENDPATH += $$PWD/../../lib/static/TextToSpeech

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/TextToSpeech/release/libTextToSpeech.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/TextToSpeech/debug/libTextToSpeech.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/TextToSpeech/release/TextToSpeech.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/TextToSpeech/debug/TextToSpeech.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/TextToSpeech/libTextToSpeech.a
