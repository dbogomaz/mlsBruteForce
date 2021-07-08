TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        ../../QtProjects/!BClasses/Btimer/btimer.cpp \
        acf.cpp \
        corr.cpp \
        mlsdatafile.cpp \
        main.cpp

HEADERS += \
    ../../QtProjects/!BClasses/Btimer/btimer.h \
    acf.h \
    corr.h \
    defines.h \
    mlsdata.h \
    mlsdatafile.h

DISTFILES +=
