QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    src/main.cpp \
    src/mainwindow.cpp \
    src/Date.cpp \
    src/db/DBManager.cpp \
    src/ticket/Message.cpp \
    src/ticket/Ticket.cpp \
    src/ticket/TicketManager.cpp \
    src/utilisateur/Client.cpp \
    src/utilisateur/Ingenieur.cpp \
    src/utilisateur/NonAdmin.cpp \
    src/utilisateur/User.cpp \

HEADERS += \
    src/Category.h \
    src/mainwindow.h \
    src/Date.h \
    src/db/DBManager.h \
    src/ticket/Message.h \
    src/ticket/Ticket.h \
    src/ticket/TicketManager.h \
    src/utilisateur/Client.h \
    src/utilisateur/Ingenieur.h \
    src/utilisateur/NonAdmin.h \
    src/utilisateur/User.h \
    src/stat/Stat.h

FORMS += \
    res/mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
