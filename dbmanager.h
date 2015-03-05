#ifndef DBMANAGER_H
#define DBMANAGER_H

#include<QtSql/qsqldatabase.h>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>


class dbManager
{
public:
    dbManager(QString connection);
    dbManager(QString connection, QString host, QString dbName, QString userName, QString pwd);
    ~dbManager();
    QSqlQuery sendRequest(QString request);
    //QSqlQuery sendRequest(QString connection,QString request);

    QSqlDatabase qsd;
public:

    QSqlQuery query;
};

#endif // DBMANAGER_H
