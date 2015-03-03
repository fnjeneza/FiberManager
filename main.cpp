#include <QCoreApplication>

#include <iostream>
#include <QtSql/qsqldatabase.h>
#include <QDebug>
#include <QSqlError>
#include <QSqlQuery>

#include "gestionLivrables.h"

using namespace std;

void lineOut(QString tranche, QString noeud, QString noeud_bis, QString comadre, QString message, QString niveau){
    //qDebug() << tranche << ";"<<noeud<<";"<<noeud_bis<<";"<<comadre<<";"<<message<<";"<<niveau;
    //cout<< tranche.toStdString() << ";"<<noeud.toStdString()<<";"<<noeud_bis.toStdString()<<";"<<comadre.toStdString()<<";"<<message.toStdString()<<";"<<niveau.toStdString() <<endl;
}

void namingControl(QString deleted, QString noeud, QString tranche, QString noeud_bis, QString comadre){
    if(!deleted.contains("*")){
        if(tranche.size()!=2){
//            qDebug() << tranche <<";"<< noeud<<";"<<tranche<< ";Numéro poche incohérent;Erreur";
            lineOut(tranche,noeud,tranche,"","Numéro poche incohérent ","Erreur");
            return;
        }
        //traitement câble
        if(noeud.contains("L")){



            QString poche = "";
            if(noeud.size()==5){
                poche =poche+"0"+noeud.at(1);
                if(tranche.compare(poche)!=0){
//                    qDebug() << tranche <<";"<< noeud<<";"<<tranche<< ";;;Numéro poche incohérent;Erreur";
                    lineOut(tranche,noeud,tranche,"","Numéro poche incohérent ","Erreur");
                    return;
                }
            }
            if(noeud.size()==6){
                poche =poche+noeud.at(1)+noeud.at(2);
                if(tranche.compare(poche)!=0){
//                    qDebug() << tranche <<";"<< noeud<<";"<<tranche<< ";;;Numéro poche incohérent;Erreur";
                    lineOut(tranche,noeud,tranche,"","Numéro poche incohérent ","Erreur");
                    return;
                }
            }

            QString CAD = "CAD_PLA06_005_"+tranche+"_"+noeud.right(2);
            QString CDI = "CDI_PLA06_005_"+tranche+"_"+noeud.right(2);
            QString CTR = "CTR_PLA06_005_"+tranche+"_01";

            int compare = 1;
            compare = noeud_bis.compare(CAD);
            if(compare!=0){
                compare = noeud_bis.compare(CDI);
            }
            if(compare!=0){
                compare = noeud_bis.compare(CTR);
            }
            if(compare!=0){
//                qDebug() << tranche <<";"<< noeud<<";"<<noeud_bis<<";"<<comadre<< ";Nommage câble incorrect;Erreur";
                lineOut(tranche,noeud,noeud_bis,comadre,"Nommage câble incorrect ","Erreur");
                return;
            }
            return;
        }

        if(noeud_bis.contains("PCH")){
//            if(tranche.size()!=2){
//                qDebug() << tranche <<";"<< noeud<<";"<<tranche<< ";Numéro poche incohérent;Erreur";
//                return;
//            }
            QString nom = "";
            QString poche = "";
            if(noeud.size()==4){
                nom = nom+"PCH_PLA06_005_00"+noeud;
                poche = poche+"0"+noeud.at(0);
                //pec = "PEC_PLA06_005_0"+noeud;

            }
            if(noeud.size()==5){
                nom = nom+"PCH_PLA06_005_0"+noeud;
                poche = poche+noeud.at(0)+noeud.at(1);
                }
            if(tranche.compare(poche)!=0){
//                qDebug() << tranche <<";"<< noeud<<";"<<tranche<< ";Numéro poche incohérent;Erreur";
                lineOut(tranche,noeud,tranche,"","Numéro poche incohérent ","Erreur");
                return;
            }
            if(noeud_bis.compare(nom)!=0){
//                qDebug() <<tranche <<";"<< noeud<<";"<<noeud_bis<<";"<<comadre<<  ";Nommage PT incorrect;Erreur";
                lineOut(tranche,noeud,noeud_bis,comadre,"Nommage PT incorrect ","Erreur");
                return;
            }
            nom.remove(14,1);
            nom.replace("PCH","PDB");
            return;
        }
        if(noeud_bis.contains("SIT")){
//            if(tranche.size()!=2){
//                qDebug() << tranche <<";"<< noeud<<";"<<tranche<< ";Numéro poche incohérent;Erreur";
//                return;
//            }
            QString nom = "";
            QString poche = "";
            if(noeud.size()==4){
                nom = "SIT_JOF06_000"+noeud;
                poche = poche+"0"+noeud.at(0);
            }
            if(noeud.size()==5){
                nom = "SIT_JOF06_00"+noeud;
                poche = poche+noeud.at(0)+noeud.at(1);
                }
            if(tranche.compare(poche)!=0){
//                qDebug() << tranche <<";"<< noeud<<";"<<tranche<< ";;Numéro poche incohérent;Erreur";
                lineOut(tranche,noeud,tranche,"","Numéro poche incohérent ","Erreur");
                return;
            }
            if(noeud_bis.compare(nom)!=0){
//                qDebug() <<tranche <<";"<< noeud<<";"<<noeud_bis<<";"<<comadre<<  ";Nommage PT incorrect;Erreur";
                lineOut(tranche,noeud,noeud_bis,comadre,"Nommage PT incorrect ","Erreur");
                return;
            }
            nom = "BPI_"+nom+"_01";
            if(comadre.compare(nom)!=0){
//                qDebug() <<tranche <<";"<< noeud<<";"<<noeud_bis<<";"<<comadre<<  ";Nommage boîte incorrect;Erreur";
                lineOut(tranche,noeud,noeud_bis,comadre,"Nommage boîte incorrect ","Erreur");
                return;
            }
            return;
        }
//        qDebug() <<tranche <<";"<< noeud<<";"<<noeud_bis<<";"<<comadre<<  ";Nommage PT incorrect;Erreur";
        lineOut(tranche,noeud,noeud_bis,comadre,"Nommage boîte incorrect ","Erreur");
    }
}

/*Controle de l'extremité du cable*/
void extremiteControl(QString deleted, QString noeud, QString coffret){
    if(!deleted.contains("*") && noeud.contains("L")){
        QString noeud2=noeud.right(noeud.size()-1);
        if(coffret.compare(noeud2)!=0){
//            qDebug() <<";"<< noeud<<";"<< coffret<< ";Extrérmité du câble incorrect;Erreur";
            lineOut("",noeud,coffret,"","Extrérmité du câble incorrect ","Erreur");
        }
    }
}

/*Controle d'adresse*/
void adresseControl(QString deleted, QString noeud, QString noeud_bis, QString num_voie, QString rivoli){
    if(!deleted.contains("*") && noeud_bis.contains("SIT")){
        if(num_voie.isEmpty() || rivoli.isEmpty()){
//            qDebug() << ";" << noeud << ";" << noeud_bis << ";Num voie ou code rivoli non renseigné;Erreur ";
            lineOut("",noeud,noeud_bis,"","Num voie ou code rivoli non renseigné ","Erreur");
        }
    }
}

/*Nombre de câble par par boîte*/
void cableParBoite(QString noeud, QString nb_cable, QString ref_mat, QString designat){
//    lineOut("", noeud, nb_cable, ref_mat, designat);
    cout<<noeud.toStdString()<<";"<<nb_cable.toStdString()<<";"<<ref_mat.toStdString()<<";"<<designat.toStdString()<<endl;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    cout << "Démarrage de FiberManager"<< endl;
/*    cout<< "poche" << ";"<<"Noeud"<<";"<<"Etiquette"<<";"<<"Point Tech"<<";"<<"Type erreur"<<";"<<"Niveau" <<endl;


    QSqlDatabase qsd = QSqlDatabase::addDatabase("QPSQL");
    //qsd.setHostName("10.0.0.254");
    qsd.setHostName("192.168.0.12");
    qsd.setDatabaseName("PLA06_005");
    qsd.setUserName("be_free");
    qsd.setPassword("123456");

    if(!qsd.open()){
            qDebug() << qsd.lastError().text();
            return false;
    }
    */

    /** Contrôle nommage */
/*    //QSqlQuery query("SELECT \"DELETED\", \"NOEUD\", \"TRANCHE\", \"NOEUD_BIS\" from noeuds order by \"TRANCHE\"");
    QSqlQuery query("select noeuds.\"DELETED\", noeuds.\"NOEUD\", noeuds.\"TRANCHE\", noeuds.\"NOEUD_BIS\", pb.\"COMADRE\" from noeuds, pb where noeuds.\"NOEUD\"=pb.\"NOEUD\" order by \"TRANCHE\"");
    qDebug() << query.lastError().text();
    while(query.next()){
//        if(query.value(0).toString().contains("*")){
//            qDebug()<< query.value(0).toString() << " " << query.value(1).toString() << " " << query.value(2).toString() << query.value(3).toString();
//        }

        //qDebug()<< query.value(0).toString() << " " << query.value(1).toString() << " " << query.value(2).toString() << query.value(3).toString();
        QString deleted = query.value(0).toString().trimmed();
        QString noeud = query.value(1).toString().trimmed();
        QString tranche = query.value(2).toString().trimmed();
        QString noeud_bis = query.value(3).toString().trimmed();
        QString comadre = query.value(4).toString().trimmed();
        namingControl(deleted, noeud, tranche, noeud_bis, comadre);


    }
    */

    /** Contrôle extrémité câble*/
/*   query.prepare("SELECT \"DELETED\", \"NOEUD\", \"COFFRET\" from noeuds order by \"NOEUD\"") ;
    query.exec();
    while(query.next()){
        QString deleted = query.value(0).toString().trimmed();
        QString noeud = query.value(1).toString().trimmed();
        QString coffret = query.value(2).toString().trimmed();

        extremiteControl(deleted, noeud, coffret);
    }
*/
    /** Vérification adresse BPI*/
 /*   query.prepare("SELECT \"DELETED\", \"NOEUD\", \"NOEUD_BIS\", \"NUM_VOIE\", \"RIVOLI\" from noeuds order by \"NOEUD\"");
    query.exec();
    while(query.next()){
        QString deleted = query.value(0).toString().trimmed();
        QString noeud = query.value(1).toString().trimmed();
        QString noeud_bis = query.value(2).toString().trimmed();
        QString num_voie = query.value(3).toString().trimmed();
        QString rivoli = query.value(4).toString().trimmed();

        adresseControl(deleted, noeud, noeud_bis, num_voie, rivoli);
    }
*/
    /** Vérification matériel utilisé: Réference NetGeo*/
 /*   query.prepare("SELECT \"DELETED\", \"NOEUD\", \"REF_MAT\" from noeuds where \"REF_MAT\" NOT IN (SELECT \"REF_MAT\" from b_freeo)");
    query.exec();
    while(query.next()){
        QString deleted = query.value(0).toString().trimmed();
        QString noeud = query.value(1).toString().trimmed();
        QString ref_mat = query.value(2).toString().trimmed();
        if(!deleted.contains("*"))
            qDebug() << noeud << ref_mat <<"matériel non utilisé en INDC; Erreur";
    }/
     /** Nombre de câble par boîte */
    /*
    QString req = "select boite.noeud, nb_cable, noeuds.\"REF_MAT\", \"DESIGNAT\" "
                  "from (select \"N_AMONT\" as noeud, (count(\"N_AMONT\")+1) as nb_cable from noeuds "
                  "where \"DELETED\"!='*' group by \"N_AMONT\") as boite, noeuds, b_freeo "
                  "where boite.noeud=noeuds.\"NOEUD\" and noeuds.\"REF_MAT\"=cast(b_freeo.\"REF_MAT\" as text)";
    query.prepare(req);
    query.exec();
    while(query.next()){
        QString noeud=query.value(0).toString().trimmed();
        QString nb_cable=query.value(1).toString().trimmed();
        QString ref_mat=query.value(2).toString().trimmed();
        QString designat=query.value(3).toString().trimmed();

        cableParBoite(noeud, nb_cable, ref_mat, designat);
    }
*/
    /** EBM d'une poche*/
/*
    QString poche = "12";
    cout << poche.toStdString()+";"+poche.toStdString()<<endl;
    cout << "A déployer, à ne pas dépoyer"<<endl;

   query.prepare("select \"NOEUD\", \"REF_MAT\", \"TYPE_CABLE\", \"LONG_CABLE\", \"RIVOLI\", \"NUM_VOIE\", \"COFFRET\", \"TRANCHE\" "
                  ", \"NOEUD_BIS\" from noeuds where \"DELETED\"!='*' and \"TRANCHE\"='"+poche+"'");

    query.exec();
    query.lastError().text();
    while(query.next()){
        QString noeud=query.value(0).toString().trimmed();
        QString ref_mat=query.value(1).toString().trimmed();
        QString type_cable=query.value(2).toString().trimmed();
        QString long_cable=query.value(3).toString().trimmed();
        QString rivoli=query.value(4).toString().trimmed();
        QString num_voie=query.value(5).toString().trimmed();
        QString coffret=query.value(6).toString().trimmed();
        QString tranche=query.value(7).toString().trimmed();
        QString noeud_bis=query.value(8).toString().trimmed();

        bool isFictif=false;
        if(noeud.right(2).toInt()>95)
            isFictif=true;

        if(!isFictif){
            if(!noeud.contains("l")){ //si le noeud est une boîte
                switch (ref_mat) {
                case 3125:

                    break;
                    break;
                }
            }
        }
        cout << fictif << endl;
      }
*/


    /** Cable utilisé */
/*
    QString bpi;
    query.prepare("select casage.\"PM\", mediapost.hexacle from casage, mediapost where casage.\"IDPOINT\"=mediapost.idpoint");
    query.exec();
    query.lastError().text();
    cout <<"DELETED"<<";RECNO"<<";NO_SITE"<<";HEXACODE"<<";NOEUD"<<";NUM_SECT"<<";NOEUD_BIS"<<endl;
    while(query.next()){
        QString pm=query.value(0).toString().trimmed();
        QString hexacle=query.value(1).toString().trimmed();
        if(pm.contains("BPI") && pm.size()==24){
            pm=pm.right(10);
            pm=pm.left(7);
            int noeud=pm.toInt();
            if(noeud<9000){
                noeud=(int)(noeud/1000);
                //cout<<"** "<<noeud<<endl;
                QString cable="CAD_PLA13_014_0"+QString::number(noeud)+"_"+pm.right(2);
                QString nomNoeud="L"+pm.right(4);
                cout<<";;;"<<hexacle.toStdString()<<";"<<nomNoeud.toStdString()<<";D47D;"<<cable.toStdString()<<endl;

            }
            else{
                noeud=(int)(noeud/1000);
                //cout<<"** "<<noeud<<endl;
                QString cable="CAD_PLA06_005_"+QString::number(noeud)+"_"+pm.right(2);
                QString nomNoeud="L"+pm.right(5);
                cout<<";;;"<<hexacle.toStdString()<<";"<<nomNoeud.toStdString()<<";D47D;"<<cable.toStdString()<<endl;
            }

        }


   }
*/
    /** FLR */
   // query.prepare("select mediapost.hexacle, mediapost.num, mediapost.suf, mediapost.voie, mediapost.pm, mediapost.z_avant, ")


    /** Gestion des livrable*/

    return a.exec();

}
