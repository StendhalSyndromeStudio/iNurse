QT          += gui

TARGET      = speachWriter
TEMPLATE    = lib
CONFIG      += staticlib
CONFIG      += c++11

DEFINES += QT_DEPRECATED_WARNINGS
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

SOURCES += \
    interfaces/iproperty.cpp \
    interfaces/iproperty_object.cpp \
    interfaces/iproperty_provider.cpp \
    interfaces/ispeach_writer.cpp \
    impl/property_provider.cpp \
    interfaces/ivoice_object.cpp \
    impl/property/regexp_property.cpp \
    impl/property/snils_property.cpp \
    impl/property/base_property.cpp \
    impl/test_speach_writer.cpp \
    impl/test_property_object.cpp \
    interfaces/ispeach_writer_provider.cpp \
    impl/speach_writer_provider.cpp

HEADERS += \
    interfaces/iproperty.h \
    interfaces/Iproperty_object.h \
    interfaces/iproperty_provider.h \
    interfaces/ispeach_writer.h \
    impl/property_provider.h \
    interfaces/ivoice_object.h \
    impl/property/regexp_property.h \
    impl/property/snils_property.h \
    impl/property/base_property.h \
    impl/test_speach_writer.h \
    impl/test_property_object.h \
    interfaces/ispeach_writer_provider.h \
    impl/speach_writer_provider.h
