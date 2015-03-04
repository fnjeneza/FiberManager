#ifndef DBMANAGER_H
#define DBMANAGER_H

#include<QtSql/qsqldatabase.h>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>


class dbManager
{
public:
    dbManager();
    dbManager(QString connection);
    QSqlQuery sendRequest(QString request);
    QSqlQuery sendRequest(QString connection,QString request);

private:
//    QString host = "10.0.0.254";
//    QString dbName = "PLA06_005";
//    QString userName = "be_free";
//    QString passwd = "123456";

    QSqlDatabase qsd;
public:

    QSqlQuery query;
};

#endif // DBMANAGER_H
