#ifndef PARAMETERS_H
#define PARAMETERS_H

#include <QString>

class parameters
{
public:
    parameters();

    QString getHost();
    QString getDbName();
    QString getPlaque();
    QString getDbUser();
    QString getUserPwd();
    QString getPathRoot();

    void setHost(QString host);
    void setDbName(QString dbName);
    void setPlaque(QString plaque);
    void setDbUser(QString dbUser);
    void setUserPwd(QString userPwd);
    void setPathRoot(QString pathRoot);
private:
    QString host;
    QString dbName;
    QString plaque;
    QString dbUser;
    QString userPwd;
    QString pathRoot; // Root of all files of the program
};

#endif // PARAMETERS_H
