#include <QCoreApplication>
#include "networkmanager.h"
#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <networkmanager.h>


int main(int argc, char *argv[])
{

   QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);

    QQmlApplicationEngine engine;
   engine.load(QUrl(QLatin1String("qrc:/main.qml")));
   if (engine.rootObjects().isEmpty())
        return -1;
   NetworkManager* manager= new NetworkManager();
   manager->loadWebPage();


        engine.rootContext()->setContextProperty("myfunction", manager);

    return app.exec();
}
