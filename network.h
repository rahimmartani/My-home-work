#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QString>

class NetworkManager : public QObject
{
    Q_OBJECT
    QNetworkAccessManager* manager;
public:
    explicit NetworkManager(QObject *parent = 0);
    Q_INVOKABLE QString loadWebPage();
signals:

public slots:
    QString myReplyFinished(QNetworkReply* reply);
};

#endif // NETWORKMANAGER_H
