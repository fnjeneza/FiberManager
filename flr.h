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
    void flrTableDbInit(QString fileName);

private:
    dbManager *dbm;
    dbManager *secondary;
};

#endif // FLR_H
