#include "dbmanager.h"

dbManager::dbManager()
{
    QSqlDatabase qsd = QSqlDatabase::addDatabase("QPSQL");
    qsd.setHostName("10.0.0.254");
    //qsd.setHostName("192.168.0.12");
    qsd.setDatabaseName("PLA06_005");
    qsd.setUserName("be_free");
    qsd.setPassword("123456");

    if(!qsd.open()){
            qDebug() << qsd.lastError().text();
    }

    query = QSqlQuery(qsd);
}

QSqlQuery dbManager::sendRequest(QString request){
    query.prepare(request);
    query.exec();
    qDebug()<< query.lastError().text();
    return query;

}
