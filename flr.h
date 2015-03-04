#ifndef FLR_H
#define FLR_H

#include<dbmanager.h>

class flr
{
public:
    flr();
    ~flr();
    void extractionFlr();

private:
    dbManager *dbm;
};

#endif // FLR_H
