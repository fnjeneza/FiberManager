#include "dbmanager.h"

dbManager::dbManager(QString connection)
{
    qsd = QSqlDatabase::addDatabase("QPSQL", connection);

    this->host="192.168.0.29";
    this->bdd="PLA06_005";
    this->user = "be_free";
    this->password = "123456";

    qsd.setHostName(host);
    qsd.setDatabaseName(bdd);
    qsd.setUserName(user);
    qsd.setPassword(password);

    if(!qsd.open()){
            qDebug() << qsd.lastError().text();
            return;
    }
//    qDebug()<< "Connexion à la base de donnée "+host+": "+user+" reussie";
    query = QSqlQuery(qsd);
}

dbManager::~dbManager(){
    if(qsd.isOpen()){
        qsd.close();
    }
}



/**
 * @brief dbManager::sendRequest
 * @param request
 * @return
 */
QSqlQuery dbManager::sendRequest(QString request){
    if(!query.exec(request)){
        qDebug()<< query.lastError().text();
    }
    return query;
}

QStringList dbManager::sendRequest(QString request, QString commentaire){
    if(!query.exec(request)){
        qDebug()<< query.lastError().text();
    }
    QStringList response;
    QStringList tmp;
    QSqlRecord record = query.record();
    for(int i=0;i<record.count(); i++){
         tmp << record.fieldName(i);
    }
    response <<"Commentaire;"+tmp.join(";")+"\n";

    while(query.next()){
        tmp.clear();
        for(int i=0;i<record.count();i++){
            tmp<<query.value(i).toString().trimmed();
        }
        response <<commentaire+";"+tmp.join(";")+"\n";
    }
    return response;
}

void dbManager::execRequest(QString tableName, QStringList column, QStringList values){
    int nbCol = column.size();

    QString request = "INSERT INTO "+tableName+" (";
    QString request2=" VALUES (";

    for(int i=0; i<nbCol-1; i++){
            request+=column.at(i)+",";
            QString value = values.at(i);
            if(!value.isEmpty()){
                request2+="\'"+values.at(i)+"\',";
            }else{
                request2+="NULL,";
            }
    }
    request+=column.last()+")";
    if(!values.last().isEmpty()){
        request2+="\'"+values.last()+"\')";
    }
    else{
        request2+="NULL)";
    }
    request+=request2;
    sendRequest(request);

}
