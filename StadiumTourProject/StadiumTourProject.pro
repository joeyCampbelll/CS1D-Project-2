QT       += core gui sql \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    database.cpp \
    dfsBfsMst.cpp \
    graphal.cpp \
    grapham.cpp \
    main.cpp \
    mainwindow.cpp \
    souveniredit.cpp \
    souvenirshop.cpp \
    tablefilter.cpp \
    teamedit.cpp \
    tripplanner.cpp

HEADERS += \
    database.h \
    graphal.h \
    grapham.h \
    mainwindow.h \
    priorityqueue.h \
    souvenirshop.h \
    tablefilter.h

FORMS += \
    mainwindow.ui \
    souvenirshop.ui \
    tablefilter.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
