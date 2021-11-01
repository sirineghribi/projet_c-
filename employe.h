#ifndef EMPLOYE_H
#define EMPLOYE_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class Employe
{
public:
    Employe();
    Employe(QString,QString,QString,QString,QString,QString,int,int,int);

    int getcin();
    int getnum_de_tel();
    int getid();
    QString getnom();
    QString getprenom();
    QString getsexe();
    QString getdate_de_naissance();
    QString getmail();
    QString getadresse();

    void setcin(int);
    void setnum_de_tel(int);
    void setid(int);
    void setnom(QString);
    void setprenom(QString);
    void setsexe(QString);
    void setdate_de_naissance(QString);
    void setmail(QString);
    void setadresse(QString);

    bool ajouter_employe();
    QSqlQueryModel * afficher();
    bool supprimer(int);

private:
    QString nom,prenom,sexe,date_de_naissance,mail,adresse;
    int cin,num_de_tel,id;

};

#endif // EMPLOYE_H
