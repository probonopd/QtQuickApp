#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QFileInfo>
#include <QIcon>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QGuiApplication::setWindowIcon(QIcon(app.applicationDirPath() + "/qtquickapp.svg"));

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    return app.exec();
}
