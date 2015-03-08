#ifndef FLR_H
#define FLR_H

#include<dbmanager.h>
#include <QFile>
#include <iostream>
#include "parameters.h"


class flr
{
public:
    flr();
    ~flr();
    void extractionFlr();
    void importFlr(QString flrFilePath);
    void execSqlFile(QString fileName);
    void importTableFromCsv(QString schema, QString tableName);
    void control(QString requete, QString message);

private:
    dbManager *dbm;
    dbManager *secondary;
};

#endif // FLR_H
