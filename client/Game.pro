QT += quick
QT += websockets

CONFIG += c++11

SOURCES += \
        ../common/json_classes.cpp \
        src/authorization.cpp \
        src/game.cpp \
        src/info.cpp \
        src/login.cpp \
        src/registration.cpp \
        ../common/http_connection.cpp \
        src/websocket_connection.cpp

RESOURCES += qml.qrc

INCLUDEPATH += ../common
INCLUDEPATH += src

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    buttons/buttons_login-1.png \
    buttons/buttons_login-2.png \
    qml/Authorization.qml

HEADERS += \
    ../common/game.h \
    ../common/http_connection.h \
    ../common/json_classes.h \
    src/authorization.h \
    src/info.h \
    src/login.h \
    src/registration.h \
    src/websocket_connection.h

documentation.files = client.key client.crt

INSTALLS += documentation

