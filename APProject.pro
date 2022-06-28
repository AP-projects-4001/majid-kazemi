QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

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
    addproduct.cpp \
    adminpanel.cpp \
    buy.cpp \
    buypanel.cpp \
    clientpanel.cpp \
    customerpanel.cpp \
    detailproduct.cpp \
    editproductpanel.cpp \
    edituser.cpp \
    pay.cpp \
    product.cpp \
    rememberme.cpp \
    searchpanel.cpp \
    showproductcustomer.cpp \
    signup.cpp \
    utilities.cpp \
    main.cpp \
    mainwindow.cpp \
    user.cpp \
    validator.cpp

HEADERS += \
    addproduct.h \
    adminpanel.h \
    buy.h \
    buypanel.h \
    clientpanel.h \
    customerpanel.h \
    detailproduct.h \
    editproductpanel.h \
    edituser.h \
    mainwindow.h \
    pay.h \
    product.h \
    rememberme.h \
    searchpanel.h \
    showproductcustomer.h \
    signup.h \
    user.h \
    utilities.h \
    validator.h

FORMS += \
    addproduct.ui \
    adminpanel.ui \
    buypanel.ui \
    clientpanel.ui \
    customerpanel.ui \
    detailproduct.ui \
    editproductpanel.ui \
    edituser.ui \
    mainwindow.ui \
    rememberme.ui \
    searchpanel.ui \
    showproductcustomer.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    resources.qrc
