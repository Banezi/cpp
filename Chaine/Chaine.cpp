#include "Chaine.hpp"
#include <cstring>
#include <iostream>
#include <sstream>
using namespace std;

Chaine::Chaine()
{
    taille = -1;
    t = 0; // t=NULL
}

Chaine::Chaine(int a)
{
    if(a<0)
    {
        taille = -1;
        t = NULL;
    }
    else
    {
        taille = a;
        t = new char[taille+1];
        t[0] = '\0';
    }
}

Chaine::Chaine(const char* ch)
{
    taille = strlen(ch);
    t = new char[taille+1];
    for(int i=0; i<taille; i++)
    {
        t[i] = ch[i];
    }
    t[taille] = '\0';
}

Chaine::Chaine(const Chaine& ch)
{
    taille = ch.taille;
    t = new char[taille+1];
    for(int i=0; i<taille; i++)
    {
        t[i] = ch.t[i];
    }
    t[taille] = '\0';
}

int Chaine::getCapacite() const
{
    return taille;
}

const char* Chaine::c_str() const
{
    return t;
}
Chaine::~Chaine()
{
    if(t)
        delete [] t;
}
/*
void Chaine::afficher()
{

}
void Chaine::afficher(const char* T)
{
    for(int i=0; T[i]!='\0'; i++)
    {
        cout << T[i];
    }
    cout << endl;
}
void Chaine::afficher(std::stringstream ss)
{
    cout << ss << endl;
}
*/

Chaine& Chaine::operator= (Chaine const& ch)
{
    if(&ch != this)
    {
        delete [] t;
        taille = ch.taille;
        t = new char[taille+1];
        for(int i = 0; i<=taille; i++)
        {
            t[i] = ch[i];
        }
    }
    return *this;
}

ostream& operator<< (ostream&, const Chaine&);
