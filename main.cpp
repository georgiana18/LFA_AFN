#include <iostream>
#include <fstream>
#include <cstring>
#include "AFN.h"
using namespace std;

ifstream fin("..\\automat.in");
ofstream fout("..\\automat.out");

int main() {

    AFN automat;    //se apeleaza constructor fara parametri->initializare cu 0
    fin>>automat;
    // fout<<automat;  // ar trebui ca fisierul de intrare sa fie identic cu cel de iesire

    //verific separat pt cuv vid

    if(automat.CuvantVid()==1) fout<<"Cuvantul vid e acceptat\n";
    else fout<<"Cuvantul vid nu e acceptat\n";

    int nrcuv;
    char cuvant[100];
    fin>>nrcuv;
    for(int i=1;i<=nrcuv;i++)
    {
        fin>>cuvant;
        automat.Reset();
        if(automat.Verificare(cuvant, automat.get_sti(), 0)==1) fout<<"acceptat\n";
        else fout<<"neacceptat\n";
        for(int j=0; j<=strlen(cuvant); j++) cuvant[j]=0;
    }

    return 0;
}