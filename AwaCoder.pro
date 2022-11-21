QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++20

RC_ICONS = res/icon.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    awacoder.cpp \
    codeeditor.cpp \
    codepage.cpp \
    inputwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    modifiablepage.cpp \
    page.cpp \
    pagebrowser.cpp \
    plugininterface.cpp \
    welcomepage.cpp

HEADERS += \
    awacoder.h \
    codeeditor.h \
    codepage.h \
    debug.h \
    inputwidget.h \
    mainwindow.h \
    modifiablepage.h \
    page.h \
    pagebrowser.h \
    plugininterface.h \
    welcomepage.h

TRANSLATIONS += \
    AwaCoder_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

DISTFILES += \
    readme.md
