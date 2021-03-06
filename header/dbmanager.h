#ifndef DBMANAGER_H
#define DBMANAGER_H

#include<QtSql/qsqldatabase.h>
#include <QSqlQuery>
#include <QDebug>
#include <QSqlError>
#include <QSqlRecord>

class dbManager
{
public:
    dbManager(QString connection);
    ~dbManager();
    QSqlQuery sendRequest(QString request);
    QStringList sendRequest(QString request, QString commentaire);
    void execRequest(QString,QStringList, QStringList);
private:
    QString host;
    QString bdd;
    QString nro;
    QString user;
    QString password;

    QSqlDatabase qsd;
    QSqlQuery query;

};

#endif // DBMANAGER_H
