#include "flr.h"

flr::flr(){
    dbm = new dbManager();
}

flr::~flr(){
    delete dbm;
}

void flr::extractionFlr(){
    qDebug() << "*** Extraction du FLR ***";
    QString request = "select * from flr_tmp limit 4";


    QSqlQuery qsq = dbm->sendRequest(request);

    // request ="select distinct hexacle, num,suf,voie from mediapost";
//    QString aa = "select  hexa, adr, bal, phd, parcelle, zoneavant, habitat, chau_type as \"type de chaussee\", chau_anc as \"anciennete\", tro_type as \"type de trottoir\", tro_anc as \"anciennete\", 'communal' as \"gestionnaire de voie\", nro, poche, pm, adduction, concessionnaire, reference as numpm, logements as lrpm, comment"
//                  "from (select *"
//                  "from ( select *"
//                  "from (select mediapost.hexacle as hexa, mediapost.num || ' ' || mediapost.suf || ' ' || mediapost.voie || '06000 NICE' as adr, mediapost.voie as voie , casage.\"LR\" as bal, 'PHD' as phd, parcelle, ' ' as zoneavant, ' ' as habitat, 'JOF06' as nro, poche, casage.\"PM\" as pm, 'GC' as adduction, 'FT' as concessionnaire, casage.\"COMMENTAIRE\"  as comment"
//                  "from casage, mediapost "
//                  "where mediapost.idpoint=casage.\"IDPOINT\") as adresse left join (select * from zav where zav.etat='EN ETUDE') as zzav on adresse.hexa=zzav.hexacle) as emprise left join rue on emprise.voie=rue.voie) as nroemprise";

    qDebug()<< "hexacle;adresse;nb_bal;phd;parcelle;zone;habitat;chaussée;ancienneté;trottoir;anciennté;gestionnaire;nro;poche;bpi;adduction;concessionnaire;pm;lr_pm;commentaire";

    while(qsq.next()){
        QString hexacle = qsq.value(0).toString().trimmed();
        QString adr = qsq.value(1).toString().trimmed();
        int bal = qsq.value(2).toInt();
        qDebug()<< "boite au lettres"<<bal;
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

        //qDebug()<<"$$$"<< bpi.left(7)<<bpi.right(5);
        //QString requete2 = "select * from fictif_tmp where '"+bpi.left(7)+"'";

        QSqlQuery monbpi = dbm->sendRequest("connection", "select * from fictif_tmp");
        while(monbpi.next()){
           // qDebug()<<"";
        }
        QString zone ="";
//        qDebug() << hexacle+";"+adr+";"<<bal<<";"<<"PHD;"+parcelle+";"+zone+";"+habitat+";"+type_ch+";"
//                 <<anc_chau<<+";"+type_tro+";"<<anc_tro<<+";COMMUNALE;JOF06;"<<poche<<+";"+bpi+";GC;FT;"+pm+";"<<lr_pm<<+";"+commentaire;
    }
}

