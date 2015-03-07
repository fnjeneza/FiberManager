#ifndef CONDUITE_H
#define CONDUITE_H

#include "dbmanager.h"
#include <iostream>

class conduite
{
public:
    conduite();
    void getConduiteUtilisee();
    dbManager *dbm;

private:
    QString getNumft(QString noeudCorolle, dbManager d);
};

#endif // CONDUITE_H
