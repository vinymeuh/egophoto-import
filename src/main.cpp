#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "FileListToImport.h"

int main(int argc, char *argv[])
{
    // quick workaround for window resize problem, to be investigated later
    qputenv("QT_QUICK_BACKEND", "softwarecontext");

    QGuiApplication::setApplicationName("EgoPhoto Import");
    QGuiApplication::setOrganizationName("EgoPhoto");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    FileListToImport model;
    engine.rootContext()->setContextProperty("myModel", &model);

    engine.load(QUrl("qrc:/src/main.qml"));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
