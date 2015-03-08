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
    static QString getPathRoot();
    static QString getScriptPath();

    void setHost(QString host);
    void setDbName(QString dbName);
    void setPlaque(QString plaque);
    void setDbUser(QString dbUser);
    void setUserPwd(QString userPwd);
    static void setPathRoot(QString pathRoot);
    static void setScriptPath(QString scriptPath);

private:
    QString host;
    QString dbName;
    QString plaque;
    QString dbUser;
    QString userPwd;
    static QString pathRoot; // Root of all files of the program
    static QString scriptPath;
};

#endif // PARAMETERS_H
