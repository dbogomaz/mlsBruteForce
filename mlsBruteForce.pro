TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        acf.cpp \
        corr.cpp \
        mlsdatafile.cpp \
        main.cpp

HEADERS += \
    acf.h \
    corr.h \
    defines.h \
    mlsdata.h \
    mlsdatafile.h

DISTFILES +=
