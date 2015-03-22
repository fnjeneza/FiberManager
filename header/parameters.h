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
     QString getScriptPath();

    void setHost(QString host);
    void setDbName(QString dbName);
    void setPlaque(QString plaque);
    void setDbUser(QString dbUser);
    void setUserPwd(QString userPwd);
     void setPathRoot(QString pathRoot);
     void setScriptPath(QString scriptPath);

private:
    QString host;
    QString dbName;
    QString plaque;
    QString dbUser;
    QString userPwd;
    QString pathRoot; // Root of all files of the program
    QString scriptPath;
};

#endif // PARAMETERS_H
