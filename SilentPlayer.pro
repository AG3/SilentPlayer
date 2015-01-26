#-------------------------------------------------
#
# Project created by QtCreator 2015-01-21T19:58:26
#
#-------------------------------------------------

QT       += quick multimedia
QT -=network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SilentPlayer
TEMPLATE = app


SOURCES += main.cpp \
    SPplayer.cpp \
    SPmusicItem.cpp

HEADERS  += \
    SPplayer.h \
    SPmusicItem.h

RESOURCES += \
    src.qrc

OTHER_FILES += \
    android/AndroidManifest.xml
ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
CONFIG += mobility
