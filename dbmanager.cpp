#include "dbmanager.h"

dbManager::dbManager()
{
    QSqlDatabase qsd = QSqlDatabase::addDatabase("QPSQL");
    //qsd.setHostName("10.0.0.254");
    qsd.setHostName("192.168.0.14");
    qsd.setDatabaseName("PLA06_005");
    qsd.setUserName("be_free");
    qsd.setPassword("123456");

    if(!qsd.open()){
            qDebug() << qsd.lastError().text();
    }

    query = QSqlQuery(qsd);
}

//dbManager::dbManager(QString connection){
//    QSqlDatabase qsd = QSqlDatabase::addDatabase("QPSQL",connection);
//    //qsd.setHostName("10.0.0.254");
//    qsd.setHostName("192.168.0.12");
//    qsd.setDatabaseName("PLA06_005");
//    qsd.setUserName("be_free");
//    qsd.setPassword("123456");

//    if(!qsd.open()){
//            qDebug() << qsd.lastError().text();
//    }

//}

QSqlQuery dbManager::sendRequest(QString request){
    query.prepare(request);
    query.exec();
    qDebug()<< query.lastError().text();
    return query;
}

QSqlQuery dbManager::sendRequest(QString connection, QString request){
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL",connection);
    //qsd.setHostName("10.0.0.254");
    db.setHostName("192.168.0.14");
    db.setDatabaseName("PLA06_005");
    db.setUserName("be_free");
    db.setPassword("123456");



    if(!db.open()){

            qDebug() << db.lastError().text();
    }

    QSqlQuery qq = QSqlQuery(db);
    qq.exec(request);
    return qq;

}

