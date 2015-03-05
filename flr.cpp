#include "flr.h"
#include <iostream>

flr::flr(){
    dbm = new dbManager("primary");
    secondary = new dbManager("secondary");
}

flr::~flr(){
    delete dbm;
    delete secondary;
}

void flr::extractionFlr(){
    std::cout << "*** Extraction du FLR ***"<<std::endl;
    QString request = "select * from flr_tmp limit 4";


    QSqlQuery qsq = dbm->sendRequest(request);

    QString out = "hexacle;adresse;nb_bal;phd;parcelle;zone;habitat;chaussée;ancienneté;trottoir;anciennté;gestionnaire;nro;poche;bpi;adduction;concessionnaire;pm;lr_pm;commentaire";
    std::cout<<out.toStdString()<<std::endl;

    while(qsq.next()){
        QString hexacle = qsq.value(0).toString().trimmed();
        QString adr = qsq.value(1).toString().trimmed();
        int bal = qsq.value(2).toInt();
        QString parcelle = qsq.value(3).toString().trimmed();
        QString type_ch = qsq.value(4).toString().trimmed();
        int anc_chau = qsq.value(5).toInt();
        QString type_tro = qsq.value(6).toString().trimmed();
        int anc_tro = qsq.value(7).toInt();
        int poche = qsq.value(8).toInt();
        QString bpi = qsq.value(9).toString().trimmed();
        QString pm = qsq.value(10).toString().trimmed();
        int lr_pm = qsq.value(11).toInt();
        QString commentaire = qsq.value(12).toString().trimmed();

        QString habitat = (bal>1)?"COLL" :"IND";
        QString zone="";
        if(!parcelle.contains("HORS") || !parcelle.contains("INEXISTANTE")){
            zone="ZONE ARRIERE";
        }

        QString sit = bpi.left(21).right(17);
        QSqlQuery qsq2 = secondary->sendRequest("select noeud from noeuds where noeud_bis='"+sit+"'");

        /** Adresse d'un site */
        QString bpiAdress;
        if(qsq2.value(1).isNull()){
            bpiAdress=qsq2.value(0).toString().trimmed()+" "+qsq2.value(2).toString().trimmed();
        }
        else{
            bpiAdress=qsq2.value(0).toString().trimmed()+" "+qsq2.value(1).toString().trimmed()+" "+qsq2.value(2).toString().trimmed();
        }

        /** Determination de zone avant*/
        while(qsq2.next()){
                if(bpiAdress.compare(adr)==0){
                    zone="ZONE AVANT";
                    qDebug()<<sit<<" "<<qsq2.value(0).toString()<<zone;
                }
        }
        /** Determination de PDB fictif*/
        if(bpi.contains("99") ||bpi.contains("98") ||bpi.contains("97") ||bpi.contains("96")){
            qsq2 = secondary->sendRequest("select n_amont from noeuds where noeud='L"+qsq2.value(0).toString()+"'");
            QString noeudAmont;
            QString tranche;
            bpi="PDB_PLA06_005_"+tranche+"_"+noeudAmont;
        }

        out = hexacle+";"+adr+";"+bal+";"+"PHD;"+parcelle+";"+zone+";"+habitat+";"+type_ch+";"
                 +anc_chau+";"+type_tro+";"+anc_tro+";COMMUNALE;JOF06;"+poche+";"+bpi+";GC;FT;"+pm+";"+lr_pm+";"+commentaire;

        std::cout<< out.toStdString()<<std::endl;
    }
}

