QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    developermode.cpp \
    main.cpp \
    mainwindow.cpp \
    thread.cpp

HEADERS += \
    HS/KMP.h \
    developermode.h \
    mainwindow.h \
    HS/boyer_moore.h \
    HS/brute_force_algorithm.h \
    HS/Database.h \
    HS/dict.h \
    HS/rabin.h

FORMS += \
    developermode.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    HS/files/filenames.txt \
    HS/files/pattern.txt \
    HS/files/text.txt \
    HS/files/text2.txt

RESOURCES += \
    files.qrc\
    HS/images.jpeg
