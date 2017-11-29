#include "network.h"
#include <QNetworkReply>
#include <QNetworkRequest>
#include "QNetworkAccessManager"
#include <QtNetwork>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDebug>
#include <QJsonDocument>

NetworkManager::NetworkManager(QObject *parent) : QObject(parent)
{

}

QString NetworkManager::loadWebPage(){
    manager = new QNetworkAccessManager();
    manager->setNetworkAccessible(QNetworkAccessManager::Accessible);

    QNetworkRequest request;

    QEventLoop eventloop;
    QString apiKey = "demo";



    QString urlString = QString("https://www.alphavantage.co/query?function=TIME_SERIES_DAILY&symbol=MSFT&apikey=%0").arg(apiKey);

    QUrl url(urlString);

    request.setUrl(url);
    QNetworkReply *reply = manager->get(request);
    connect(reply, SIGNAL(finished()), &eventloop, SLOT(quit()));

       eventloop.exec();



    return myReplyFinished(reply);

}


QString NetworkManager::myReplyFinished(QNetworkReply*reply)
{
    //QByteArray webdata = Reply->readAll();

    QString strReply   = (QString)reply->readAll();

    QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());

    QJsonObject jsonObject = jsonResponse.object();

    QJsonObject jsondataObject = jsonObject["Meta Data"].toObject();

    qDebug() << "its working" << jsondataObject["1.Information"].toString();




    QList<QPair<QString,QString>> graphValues;
    QPair<QString,QString> data;


    //QString webDataString = QString(webData);


    QJsonDocument documenttwo = QJsonDocument::fromJson(strReply.toUtf8());

          if(documenttwo.isArray() == true){
              //retreive the array
              QJsonArray rootArray = documenttwo.array();
          }

          else if(documenttwo.isObject() == true)
          {

              QJsonObject rootObject = documenttwo.object();

              QJsonObject timeSeries = rootObject["Time Series (1min)"].toObject();
              QStringList keys = timeSeries.keys();
              for (QString k : keys){
                  QJsonObject dayValues = timeSeries[k].toObject();
                  QString openValue =  dayValues["2. high"].toString();

                  QPair<QString,QString> dataItem;
                  dataItem.first = k;
                  dataItem.second = openValue;

                  graphValues.append(dataItem);
              }
          }



//*
       // QStringList keys = rootObject.keys();
       // for (QString k : keys){


           //if(rootObject[k].isObject() == true){
              //  QJsonObject object = rootObject[k].toObject();

               // for (QString childkey : object.keys()){
                   // qDebug() << childkey;
               // }
            //}
       // }
//
  //  }

   // for (int i=0; i<graphValues.size(); i++){
      //  QPair<QString,QString> data = graphValues[i];
    //  qDebug()<<data.first <<" - "<<data.second;
   // }

return strReply;
    //qDebug()<<webDataString;
}
