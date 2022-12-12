QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
greaterThan(QT_MAJOR_VERSION, 4): QT += multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += multimediawidgets


CONFIG += c++11

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
    src/vues/mainwindow.cpp \
    src/vues/vueclient.cpp \
    src/vues/vueadmin.cpp \
    src/vues/vueingetech.cpp \
    src/vues/vueticket.cpp \
    src/vues/vuepriseticket.cpp \
    src/vues/vuechangecategorie.cpp \
    src/vues/vuetransferer.cpp \
    src/vues/vuenouveauticket.cpp \
    src/model/EasyTicket.cpp \
    src/model/db/DBManager.cpp \
    src/model/ticket/Message.cpp \
    src/model/ticket/Ticket.cpp \
    src/model/ticket/TicketManager.cpp \
    src/model/utilisateur/Client.cpp \
    src/model/utilisateur/Ingenieur.cpp \
    src/model/utilisateur/Admin.cpp \
    src/model/utilisateur/NonAdmin.cpp \
    src/model/utilisateur/Technicien.cpp \
    src/model/utilisateur/User.cpp \
    src/model/stat/StatManager.cpp \
    src/model/states/StateManager.cpp \

HEADERS += \
    src/vues/mainwindow.h \
    src/vues/vueclient.h \
    src/vues/vueadmin.h \
    src/vues/vueingetech.h \
    src/vues/vueticket.h \
    src/vues/vuepriseticket.h \
    src/vues/vuechangecategorie.h \
    src/vues/vuetransferer.h \
    src/vues/vuenouveauticket.h \
    src/model/EasyTicket.h \
    src/model/Category.h \
    src/model/db/DBManager.h \
    src/model/ticket/Message.h \
    src/model/ticket/Ticket.h \
    src/model/ticket/TicketManager.h \
    src/model/utilisateur/Client.h \
    src/model/utilisateur/Ingenieur.h \
    src/model/utilisateur/Admin.h \
    src/model/utilisateur/NonAdmin.h \
    src/model/utilisateur/Technicien.h \
    src/model/utilisateur/User.h \
    src/model/stat/Stat.h \
    src/model/stat/StatManager.h \
    src/model/states/StateManager.h \

FORMS += src/vues/mainwindow.ui \
    src/vues/VueClient.ui \
    src/vues/VueIngeTech.ui \
    src/vues/VueAdmin.ui \
    src/vues/VueTicket.ui \
    src/vues/VuePriseTicket.ui \
    src/vues/VueChangeCategorie.ui \
    src/vues/VueTransferer.ui \
    src/vues/VueNouveauTicket.cpp \



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
