# QtQuickApp [![Build Status](https://travis-ci.org/probonopd/QtQuickApp.svg?branch=master)](https://travis-ci.org/probonopd/QtQuickApp)

Demo Qt Quick application for use with linuxdeployqt

## Application icon

The application icon has been set in [main.cpp](https://github.com/probonopd/QtQuickApp/blob/master/main.cpp) like this:

```
 QGuiApplication::setWindowIcon(QIcon(app.applicationDirPath() + "/qtquickapp.svg"));
```

## Installability

In order to make it easier for `linuxdeployqt` to generate an AppImage, icon and desktop files have been added and have been configured in [QtQuickApp.pro](https://github.com/probonopd/QtQuickApp/blob/master/QtQuickApp.pro) like this:

```
unix {
    isEmpty(PREFIX) {
        PREFIX = /usr
    }

    target.path = $$PREFIX/bin

    shortcutfiles.files = qtquickapp.desktop
    shortcutfiles.path = $$PREFIX/share/applications/
    data.files += qtquickapp.svg
    data.path = $$PREFIX/share/pixmaps/

    INSTALLS += shortcutfiles
    INSTALLS += data
}

INSTALLS += target

DISTFILES += \
    qtquickapp.desktop \
    qtquickapp.svg
```

This allows for the application to be installed with `make install`, and for `linuxdeployqt` to generate an AppImage.
