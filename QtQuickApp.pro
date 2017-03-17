TEMPLATE = app

QT += qml quick
CONFIG += c++11 release

SOURCES += main.cpp

RESOURCES += qml.qrc

QML_IMPORT_PATH =

QML_DESIGNER_IMPORT_PATH =

DEFINES += QT_DEPRECATED_WARNINGS

# Default rules for deployment.

unix {
    isEmpty(PREFIX) {
        PREFIX = /usr
    }

    target.path = $$PREFIX/bin

    shortcutfiles.files = qtquickapp.desktop
    shortcutfiles.path = $$PREFIX/share/applications/
    data.files += qtquickapp.png
    data.path = $$PREFIX/share/pixmaps/

    INSTALLS += shortcutfiles
    INSTALLS += data
}

INSTALLS += target

DISTFILES += \
    qtquickapp.desktop \
    qtquickapp.png
