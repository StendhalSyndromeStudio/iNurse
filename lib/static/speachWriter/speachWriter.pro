QT          += gui

TARGET      = speachWriter
TEMPLATE    = lib
CONFIG      += staticlib
CONFIG      += c++11

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    interfaces/iproperty.cpp \
    interfaces/iproperty_provider.cpp \
    interfaces/ispeach_writer.cpp \
    impl/property_provider.cpp \
    interfaces/ivoice_object.cpp \
    impl/property/regexp_property.cpp \
    impl/property/snils_property.cpp \
    impl/property/base_property.cpp \
    impl/test_speach_writer.cpp \
    interfaces/ispeach_writer_provider.cpp \
    impl/speach_writer_provider.cpp \
    interfaces/iproperty_form.cpp \
    interfaces/iproperty_widget.cpp \
    interfaces/imedical_card.cpp \
    interfaces/iproperty_form_provider.cpp \
    interfaces/iproperty_widget_provider.cpp \
    impl/template_property_widget_provider.cpp \
    interfaces/imedica_card_provider.cpp \
    impl/medical_card_provider.cpp \
    impl/property_form_provider.cpp \
    impl/property_form.cpp \
    impl/medical_card.cpp

HEADERS += \
    interfaces/iproperty.h \
    interfaces/iproperty_provider.h \
    interfaces/ispeach_writer.h \
    impl/property_provider.h \
    interfaces/ivoice_object.h \
    impl/property/regexp_property.h \
    impl/property/snils_property.h \
    impl/property/base_property.h \
    impl/test_speach_writer.h \
    interfaces/ispeach_writer_provider.h \
    impl/speach_writer_provider.h \
    interfaces/iproperty_form.h \
    interfaces/iproperty_widget.h \
    interfaces/imedical_card.h \
    interfaces/iproperty_form_provider.h \
    interfaces/iproperty_widget_provider.h \
    impl/template_property_widget_provider.h \
    interfaces/imedica_card_provider.h \
    impl/medical_card_provider.h \
    impl/property_form_provider.h \
    impl/property_form.h \
    impl/medical_card.h
