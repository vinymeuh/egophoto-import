#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QSettings>
#include <QIcon>

int main(int argc, char *argv[])
{
    QGuiApplication::setApplicationName("EgoPhoto Import");
    QGuiApplication::setOrganizationName("EgoPhoto");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl("qrc:/src/main.qml"));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}