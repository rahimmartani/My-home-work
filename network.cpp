#include "network.h"
#include "QString"
#include "QDebug"

network::network(QObject *parent) : QObject(parent)
{

}

QString network::networkfunction(QString in){
     qDebug() << in;
    return in;
}
