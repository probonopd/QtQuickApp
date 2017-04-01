#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileInfo>
#include <QIcon>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    QFileInfo fi(app.applicationDirPath() + "/../share/pixmaps/qtquickapp.png");
    QGuiApplication::setWindowIcon(QIcon(fi.absoluteFilePath()));
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
