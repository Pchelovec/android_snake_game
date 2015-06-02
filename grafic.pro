#-------------------------------------------------
#
# Project created by QtCreator 2015-05-30T14:22:04
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = grafic
TEMPLATE = app



SOURCES += main.cpp\
    mywidget.cpp \
    snake.cpp \
    my_map.cpp \
    game.cpp \
    view.cpp \
    bonus.cpp

HEADERS  += \
    mywidget.h \
    snake.h \
    my_map.h \
    game.h \
    view.h \
    bonus.h

FORMS    +=

RESOURCES += \
    res.qrc
RC_ICONS=snake(ico).ico

DISTFILES += \
    android/gradle/wrapper/gradle-wrapper.jar \
    android/AndroidManifest.xml \
    android/res/values/libs.xml \
    android/build.gradle \
    android/gradle/wrapper/gradle-wrapper.properties \
    android/gradlew \
    android/gradlew.bat

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android
