TEMPLATE = subdirs

SUBDIRS += \
    app \
    lib \
    external \
    test

lib.depends = external
app.depends = lib
test.depends = lib
