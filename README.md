# QtQuickApp [![Build Status](https://travis-ci.org/probonopd/QtQuickApp.svg?branch=master)](https://travis-ci.org/probonopd/QtQuickApp)

Demo Qt Quick application for use with [`linuxdeployqt`](https://github.com/probonopd/linuxdeployqt).
## Application icon

The application icon has been set in [main.cpp](https://github.com/probonopd/QtQuickApp/blob/master/main.cpp) like this:

```
QGuiApplication::setWindowIcon(QIcon(app.applicationDirPath() + "/../share/pixmaps/qtquickapp.png"));
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
    data.files += qtquickapp.png
    data.path = $$PREFIX/share/pixmaps/

    INSTALLS += shortcutfiles
    INSTALLS += data
}

INSTALLS += target

DISTFILES += \
    qtquickapp.desktop \
    qtquickapp.png
```

Note that the word `release` was added to the line

```
CONFIG += c++11 release
```
in the same file, so that the release configuration gets built.

This allows for the application to be installed with `make install`, and for `linuxdeployqt` to generate an AppImage.

## Generating an AppImage

See [`.travis.yml`](https://github.com/probonopd/QtQuickApp/blob/master/.travis.yml) for how to compile the application on [Travis CI](https://travis-ci.org/), generate an AppImage, and upload it to transfer.sh.

If you rather would not like to use Travis CI, you should be able to use the same commands on a local Ubuntu trusty machine.
