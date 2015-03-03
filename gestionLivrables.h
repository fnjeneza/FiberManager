/**
Gestion de la création et du contrôle des dossiers des livrables
  */

#ifndef DOSSIER_H
#define DOSSIER_H

#include <QDir>


class gestionLivrables
{
public:
    gestionLivrables(QString nro, QString date, QString phase);
    bool livrableAps();
    bool livrablePiq();
    bool livrableApd();
    bool livrableDoe();

private:

    QDir root;
    QString nro;
    QString date;
    QString phase;
};

#endif // DOSSIER_H
