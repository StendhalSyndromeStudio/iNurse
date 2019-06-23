#-------------------------------------------------
#
# Project created by QtCreator 2019-06-22T13:28:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TestGUI
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
        #form_direction.cpp \
        #form_medical_record.cpp \
        #form_recipe.cpp \
        #form_visit_doctor.cpp \
        main.cpp \
        mainwindowui.cpp

HEADERS += \
        #form_direction.h \
        #form_medical_record.h \
        #form_recipe.h \
        #form_visit_doctor.h \
        mainwindowui.h

FORMS += \
        #form_direction.ui \
        #form_medical_record.ui \
        #form_recipe.ui \
        #form_visit_doctor.ui \
        mainwindowui.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


#LibJson
win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/LibJson/release/ -lLibJson
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/LibJson/debug/ -lLibJson
else:unix: LIBS += -L$$OUT_PWD/../../lib/static/LibJson/ -lLibJson

INCLUDEPATH += $$PWD/../../lib/static/LibJson
DEPENDPATH += $$PWD/../../lib/static/LibJson

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/LibJson/release/libLibJson.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/LibJson/debug/libLibJson.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/LibJson/release/LibJson.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/LibJson/debug/LibJson.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/LibJson/libLibJson.a

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/speachWriter/release/ -lspeachWriter
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../../lib/static/speachWriter/debug/ -lspeachWriter
else:unix: LIBS += -L$$OUT_PWD/../../lib/static/speachWriter/ -lspeachWriter

INCLUDEPATH += $$PWD/../../lib/static/speachWriter
DEPENDPATH += $$PWD/../../lib/static/speachWriter

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/speachWriter/release/libspeachWriter.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/speachWriter/debug/libspeachWriter.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/speachWriter/release/speachWriter.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/speachWriter/debug/speachWriter.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../../lib/static/speachWriter/libspeachWriter.a
