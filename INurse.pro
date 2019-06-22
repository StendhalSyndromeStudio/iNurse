TEMPLATE = subdirs

SUBDIRS += \
    app \
    lib \
    external \
    test \
    other

lib.depends = external
app.depends = lib
test.depends = lib
