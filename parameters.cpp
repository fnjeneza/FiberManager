#include "parameters.h"

parameters::parameters()
{
}

QString parameters::getHost(){
    return host;
}

QString parameters::getDbName(){
    return dbName;
}

QString parameters::getPlaque(){
    return plaque;
}

QString parameters::getDbUser(){
    return dbUser;
}

QString parameters::getUserPwd(){
    return userPwd;
}

QString parameters::getPathRoot(){
    return pathRoot;
}

void parameters::setHost(QString host){
    this->host=host;
}

void parameters::setDbName(QString dbName){
    this->dbName =dbName;
}

void parameters::setPlaque(QString plaque){
    this->plaque = plaque;
}

void parameters::setDbUser(QString dbUser){
    this->dbUser=dbUser;
}

void parameters::setUserPwd(QString userPwd){
    this->userPwd=userPwd;
}

void parameters::setPathRoot(QString pathRoot){
    this->pathRoot=pathRoot;
}
