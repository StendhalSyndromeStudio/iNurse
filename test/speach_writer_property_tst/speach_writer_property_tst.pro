QT += testlib
QT += gui
CONFIG += qt warn_on depend_includepath testcase

TEMPLATE = app

SOURCES +=  tst_speachwriterpropertytest.cpp

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
