#ifndef PRIME_H
#define PRIME_H
#include<QString>
#include<QSqlQuery>
#include<QSqlQueryModel>

class prime
{
public:
    prime();
    prime(int,int);

    int getnbh_supp();
    int getprimes();

    void setnbh_supp(int);
    void setprimes(int);


    bool ajouter_nbh_supp();
    QSqlQueryModel * afficher_nbh();

private:
    int nbh_supp,primes;

};

#endif // PRIME_H
