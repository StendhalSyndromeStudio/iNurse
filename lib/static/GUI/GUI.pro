#-------------------------------------------------
#
# Project created by QtCreator 2019-06-22T21:43:22
#
#-------------------------------------------------

QT       += widgets

QT       -= gui

TARGET = GUI
TEMPLATE = lib
CONFIG += staticlib

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        form_direction.cpp \
        form_medical_record.cpp \
        form_recipe.cpp \
        form_visit_doctor.cpp \
        gui.cpp

HEADERS += \
        form_direction.h \
        form_medical_record.h \
        form_recipe.h \
        form_visit_doctor.h \
        gui.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

FORMS += \
    form_direction.ui \
    form_medical_record.ui \
    form_recipe.ui \
    form_visit_doctor.ui
