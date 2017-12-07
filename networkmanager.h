#ifndef NETWORKMANAGER_H
#define NETWORKMANAGER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QString>
#include<QVariant>

class NetworkManager : public QObject
{
    Q_OBJECT
    QNetworkAccessManager* manager;
public:
    explicit NetworkManager(QObject *parent = nullptr );
    Q_INVOKABLE void loadWebPage();
private:

signals:
  void valueUpdated(QVariant x,QVariant y);
  void valueUpdated2(QVariant x,QVariant y);
  void valueUpdated3(QVariant x,QVariant y);
public slots:
    void replyFinished(QNetworkReply* reply);
};

#endif // NETWORKMANAGER_H
