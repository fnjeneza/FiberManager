#include "conduite.h"

conduite::conduite()
{
     dbm = new dbManager("primary");

}

QString conduite::getNumft(QString noeudCorolle, dbManager d){
   // dbManager *dbmFt=new dbManager("numFt");
    QSqlQuery query = d.sendRequest("select noeud_bis from noeuds_ch where noeud='"+noeudCorolle+"'");

    QString out="";
    if(query.next()){
        out = query.value(0).toString().trimmed();

    }
//    delete dbmFt;
    return out;
}

void conduite::getConduiteUtilisee(){
    dbManager dbmFt=dbManager("numFt");
    QSqlQuery query = dbm->sendRequest("select noeud, n_amont, coffret, alveole from lesconduites");
    while(query.next()){
        QString noeud=query.value(0).toString();
        QString noeud_amont=query.value(1).toString();
        QString noeud_aval=query.value(2).toString();
        QString alveole = query.value(3).toString();

        QString out= getNumft(noeud_amont, dbmFt)+";"+getNumft(noeud_aval, dbmFt)+";"+alveole;
        std::cout<<out.toStdString()<<std::endl;
    }
}


