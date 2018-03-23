//
// Created by Georgiana on 3/21/2018.
//

#ifndef TEMA1_LFA_AFN_H
#define TEMA1_LFA_AFN_H

#include <fstream>
using  namespace std;

// M=(Q, E, d, q0, F)
//Q= mult starilor
//E= alfabet de intrare
//F=mult starilor finale
//q0=starea initiala
//d= functie de tranzitie d:QxE->2^Q

struct tranzitie
{
    int s1, s2;   //starea 1 si starea 2
    char litera;   //litera asociata tranzitiei
};


class AFN {

    int nQ;              //numarul de stari
    int *Q;              ///starile
    int nE;              //numarul de litere din alfebetul de intrare
    char *E;             //alfabetul de intrare
    int nF;              //numarul de stari finale
    int *F;              //vector de stari finale
    int nTranz;           //numar de tranzitii
    tranzitie *T;         //vector de tranzitii
    int sti;              //stare initiala
    int stc;              //stare curenta
    int acceptat;         //0 pt nu, 1 pt da
public:
    //constructori si destructori
    AFN();
    AFN(int, int, int, int);
    ~AFN();

    int get_sti(){return sti;}

    friend ifstream & operator >> (ifstream &, AFN &);
    friend ifstream & operator >> (ifstream &, char *);
    friend ifstream & operator >> (ifstream &, int & );
    friend ofstream & operator << (ofstream &, const AFN &);    //afisam automatul pt verificare
    friend ofstream & operator << (ofstream &, const char *);

    bool Verificare (char *, int, int);
    bool CuvantVid();
    void Reset() {acceptat=0;}
};


#endif //TEMA1_LFA_AFN_H
