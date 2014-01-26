#-------------------------------------------------
#
# Project created by QtCreator 2013-12-08T23:00:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = oathOTP
TEMPLATE = app

CONFIG +=c++11
INCLUDEPATH += inc
INCLUDEPATH += lib
DEFINES += CRYPTOPP_DISABLE_ASM
DEFINES += CRYPTOPP_DISABLE_SSE2
QMAKE_CXXFLAGS_WARN_OFF -= -Wunused-parameter

SOURCES +=  src/main.cpp\
            src/mainwindow.cpp \
            src/addaccount.cpp \
            src/configfile.cpp \
            src/accountconfigfile.cpp \
            src/otp.cpp \
            lib/base32.cpp

HEADERS  += inc/mainwindow.h \
            inc/addaccount.h \
            inc/Account.h \
            inc/configfile.h \
            inc/accountconfigfile.h \
            inc/otp.h \
            lib/base32.h

FORMS    += forms/mainwindow.ui \
            forms/addaccount.ui

linux {
QMAKE_CXXFLAGS += -std=c++0x
}

windows {
QMAKE_CXXFLAGS += -std=c++0x
RC_FILE = oautOTP.rc
}

macx {
QMAKE_CXXFLAGS = -mmacosx-version-min=10.7 -std=gnu0x -stdlib=libc+
ICON = ressource/oathOTP.icns
}

RESOURCES += \
    ressource.qrc
