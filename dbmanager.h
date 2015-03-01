#ifndef DBMANAGER_H
#define DBMANAGER_H

#include<QtSql/qsqldatabase.h>

class dbManager
{
public:
    dbManager();

    QSqlDatabase qsd;
};

#endif // DBMANAGER_H
