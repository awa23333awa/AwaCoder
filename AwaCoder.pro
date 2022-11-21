QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

RC_ICONS = res/icon.ico

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abstractpage.cpp \
    codeeditor.cpp \
    codepage.cpp \
    highlighter.cpp \
    main.cpp \
    mainwindow.cpp \
    modifiablepage.cpp \
    pagebrowser.cpp \
    settingsconfig.cpp \
    welcomepage.cpp

HEADERS += \
    abstractpage.h \
    codeeditor.h \
    codepage.h \
    debug.h \
    highlighter.h \
    mainwindow.h \
    modifiablepage.h \
    pagebrowser.h \
    settingsconfig.h \
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
