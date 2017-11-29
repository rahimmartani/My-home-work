#include <QCoreApplication>
#include "network.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <network.h>
int main(int argc, char *argv[])
{

   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
   engine.load(QUrl(QLatin1String("qrc:/main.qml")));
   if (engine.rootObjects().isEmpty())
        return -1;

NetworkManager h;
        engine.rootContext()->setContextProperty("myfunction",&h);

    return app.exec();
}
