#include "AFN.h"
#include "AFN.h"
#include <cstring>

AFN::AFN()
{
    nQ=nE=nF=nTranz=0;
    sti=0;
    acceptat=0;
}

AFN::AFN(int nQ, int nE, int nF, int nTranz)
{
    Q=new int[nQ];
    E=new char[nE];
    F=new int[nF];
    T=new tranzitie[nTranz];
}

AFN::~AFN()
{
    delete[]E;
    delete[]F;
    delete[]T;
}

ifstream& operator >>(ifstream& in, AFN & automat)
{
    in>>automat.nQ;
    automat.Q=new int[automat.nQ+1];
    for(int i=1; i<=automat.nQ; i++)
    {
        in>>automat.Q[i];
    }
    in>>automat.nE;
    automat.E=new char[automat.nE+1];
    for(int i=1; i<=automat.nE; i++)
    {
        in>>automat.E[i];
    }
    in>>automat.sti;
    in>>automat.nF;
    automat.F=new int[automat.nF+1];
    for(int i=1; i<=automat.nF; i++)
    {
        in>>automat.F[i];
    }
    in>>automat.nTranz;
    automat.T=new tranzitie[automat.nTranz+1];
    for(int i=1; i<=automat.nTranz; i++)
    {
        in>>automat.T[i].s1;
        in>>automat.T[i].litera;
        in>>automat.T[i].s2;
    }
    return in;
}

ifstream & operator >> (ifstream & in, int &nrcuv)
{
    in>>nrcuv;
    return in;
}

ifstream & operator >> (ifstream & in, char *cuvant)
{
    in>>cuvant;
    return in;
}

ofstream & operator <<(ofstream & out, const AFN &automat)
{
    out<<automat.nQ<<"\n";
    for(int i=1; i<=automat.nQ; i++)
    {
        out<<automat.Q[i]<<" ";
    }
    out<<"\n";
    out<<automat.nE<<"\n";
    for(int i=1; i<=automat.nE; i++)
    {
        out<<automat.E[i]<<" ";
    }
    out<<"\n";
    out<<automat.sti<<"\n";;
    out<<automat.nF<<"\n";
    for(int i=1; i<=automat.nF; i++)
    {
        out<<automat.F[i]<<" ";
    }
    out<<"\n";
    out<<automat.nTranz<<"\n";
    for(int i=1; i<=automat.nTranz; i++)
    {
        out<<automat.T[i].s1<<" ";
        out<<automat.T[i].litera<<" ";
        out<<automat.T[i].s2<<"\n";
    }
    return out;
}

ofstream & operator <<(ofstream & out, const char  *s)
{
    out<<s;
    return out;
}

bool AFN::Verificare(char *cuvant, int stc, int pozitie)
{
    int i;
    if ((pozitie==strlen(cuvant))&&(stc<=nQ))
    {
        for (i=1;i<=nF;i++)
            if (stc==F[i])
            {
                acceptat=1;
                return true;
            }
    }
    else
    {
        for (i=1;i<=nTranz;i++)
        {
            if (acceptat==1) return true;
            if ((T[i].s1==stc)&&(T[i].litera==cuvant[pozitie]))
            {
                Verificare(cuvant,T[i].s2,pozitie+1);
            }
        }
        return false;
    }
}

bool AFN:: CuvantVid()
{
    int i;
    for(i=1; i<=nF; i++)
        if(sti==F[i]) return true;
    return false;
}