#include "handler.h"

Handler::Handler()
{
    dbm = new dbManager("primary");
    secondary = new dbManager("secondary");
}

Handler::~Handler(){
    delete dbm;
    delete secondary;
}

void Handler::extractionFlr(){
    qDebug() << "*** Extraction du Handler ***";
    QString request = "select * from Handler_tmp ";


    QSqlQuery qsq = dbm->sendRequest(request);

    QString out = "hexacle;adresse;nb_bal;phd;parcelle;zone;habitat;chaussée;ancienneté;trottoir;anciennté;gestionnaire;nro;poche;bpi;adduction;concessionnaire;pm;lr_pm;commentaire";
    qDebug()<<out;

    while(qsq.next()){
        QString hexacle = qsq.value(0).toString().trimmed();
        QString adresse;
        if(qsq.value(2).toString().isEmpty()){
            adresse= qsq.value(1).toString().trimmed()+" "+qsq.value(3).toString().trimmed();
            adresse+=" 06000 NICE";
        }else{
            adresse = qsq.value(1).toString().trimmed()+" "+qsq.value(2).toString().trimmed()+" "+qsq.value(3).toString().trimmed();
            adresse+=" 06000 NICE";
        }

        int bal = qsq.value(4).toInt();
        QString parcelle = qsq.value(5).toString().trimmed();
        QString type_ch = qsq.value(6).toString().trimmed();
        QString anc_chau =QString::number(qsq.value(7).toInt());
        QString type_tro = qsq.value(8).toString().trimmed();
        QString anc_tro = QString::number(qsq.value(9).toInt());
        QString poche = QString::number(qsq.value(10).toInt());
        QString bpi = qsq.value(11).toString().trimmed();
        QString pm = qsq.value(12).toString().trimmed();

        int lr_pm = qsq.value(13).toInt();
        QString commentaire = qsq.value(14).toString().trimmed();
        QString adduction="GC";
        QString concessionnaire="FT";
        QString gestionnaire="COMMUNAL";
        QString phd="PHD";
        QString nro="JOF06";

        QString habitat = (bal>1)?"COLL" :"INDIV";
        QString zone;

        /** Traitement pour PM */
        if(pm.isEmpty()) pm = "PAS DE PM";

        /** Traitement pour les adresses hors plaque/Inexistante */
        if(parcelle.contains("HORS") || parcelle.contains("INEXISTANTE")){
            phd.clear();
            habitat.clear();
            anc_chau.clear();
            anc_tro.clear();
            poche.clear();
            adduction.clear();
            concessionnaire.clear();
            nro.clear();
            gestionnaire.clear();
        }
        else{
            zone="ZONE ARRIERE";
        }

        if(hexacle.contains("CREA")){
            hexacle.clear();
            parcelle="CREATION ADRESSE";
        }

        QString sit = bpi.left(21).right(17);
        QSqlQuery qsq2 = secondary->sendRequest("select num_voie, type_voie,article, designatio, noeud from fictif_tmp where noeud_bis='"+sit+"'");

        /** Adresse d'un site */
        QString bpiAdress;
        if(qsq2.next()){
            if(qsq2.value(2).toString().isEmpty()){
                    bpiAdress=qsq2.value(0).toString().trimmed()+" "+qsq2.value(1).toString().trimmed()+" "+qsq2.value(3).toString().trimmed();
                    bpiAdress+=" 06000 NICE";
            }
            else{
                    bpiAdress=qsq2.value(0).toString().trimmed()+" "+qsq2.value(1).toString().trimmed()+" "+qsq2.value(2).toString().trimmed()+" "+qsq2.value(3).toString().trimmed();
                    bpiAdress+=" 06000 NICE";
            }

        }

        /** Determination de zone avant*/
        if(bpiAdress.compare(adresse)==0){
            zone="ZONE AVANT";
        }

        /** Determination de PDB fictif*/
        if(bpi.contains("99") ||bpi.contains("98") ||bpi.contains("97") ||bpi.contains("96")){
            qsq2 = secondary->sendRequest("select n_amont from noeuds where noeud='L"+qsq2.value(4).toString()+"'");
            if(qsq2.next()){
                QString noeudAmont="0000";
                noeudAmont+=qsq2.value(0).toString().trimmed();
                //bpi="PDB"+qsq2.value(1).toString().trimmed().left(17);

                bpi="PDB_PLA06_005_"+noeudAmont.right(5);
            }
        }
        out = "\""+hexacle+"\";"+adresse+";"+QString::number(bal)+";"+phd+";"+parcelle+";"+zone+";"+habitat+";"+type_ch+";"
                 +anc_chau+";"+type_tro+";"+anc_tro+";"+gestionnaire+";"+nro+";"+poche+";"+bpi+";"+adduction+";"+concessionnaire+";\""+pm+"\";"+QString::number(lr_pm)+";"+commentaire;

        qDebug()<< out;
    }
}


void Handler::execSqlFile(QString fileName){
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << fileName << file.errorString();
        return;
    }

    QTextStream in(&file);
    QString text = in.readAll();
    dbm->sendRequest(text);
    file.close();
}

void Handler::importFlr(QString HandlerFilePath){
    QStringList column;
    column << "hexacle" << "adresse" << "nb_bal" <<"phd_pbd"<<"parcelle"<<"zone"<<"type_habitat"
           <<"type_chaussee"<<"anc_chaussee"<<"type_trottoir"<<"anc_trottoir"<<"gest_voirie"
           <<"nro"<<"poche"<<"bpi_pdb_pme"<<"type_adduction"<<"concessionnaire"<<"ref_pm"<<"lr_pm"
           <<"commentaire"<<"analyse_fi";

    int lineCounter=0;

    QFile file(HandlerFilePath);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << HandlerFilePath << file.errorString();
        return;
    }

    QTextStream in(&file);
    while(!in.atEnd()){
        QStringList line = in.readLine().split(";");

        if(lineCounter>10){
            dbm->execRequest("Handler",column,line);
        }

        lineCounter++;
    }
    file.close();
}


void Handler::importTableFromCsv(QString schema,QString tableName){
    QString fileName = tableName+".csv";
    QFile file(fileName);
    if(!file.open(QFile::ReadOnly | QFile::Text)){
        qDebug() << fileName << file.errorString();
        return;
    }
    if(!schema.isEmpty()){
        tableName=schema+"."+tableName;
    }
    QTextStream in(&file);
    QStringList column = in.readLine().toLower().split(";");
    while(!in.atEnd()){
        QStringList line = in.readLine().split(";");
        dbm->execRequest(tableName, column, line);
    }
    file.close();
}

void Handler::control(QString requete, QString message){
    QStringList list = dbm->sendRequest(requete,message);

    QFile file("audit.csv");
    if(!file.open(QFile::WriteOnly | QFile::Text)){
        qDebug() << file.errorString();
    }

    QTextStream out(&file);
    for(int i=0;i<list.size();i++){
        out << list.at(i);
    }
    out.flush();
    file.close();
}

void Handler::exportMdb(QString mdbName, QString tableName){
    tableName = tableName.toLower();
    QProcess process;
    QString program = "./export.sh";
    QStringList arguments;
    arguments << mdbName << tableName;
    process.startDetached(program, arguments);
    process.waitForFinished(-1);
}
