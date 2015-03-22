#ifndef HANDLER_H
#define HANDLER_H

#include <QProcess>
#include <QFile>

#include "dbmanager.h"

class Handler
{
public:
    Handler();
    ~Handler();
    void extractionFlr();
    void importFlr(QString flrFilePath);
    void execSqlFile(QString fileName);
    void importTableFromCsv(QString schema, QString tableName);
    void control(QString requete, QString message);
    void exportMdb(QString mdbName, QString tableName);

private:
    dbManager *dbm;
    dbManager *secondary;
};

#endif // HANDLER_H
