#include "Pelicula.h"

#include <iostream>
#include <cstring>

using namespace std;

Pelicula::Pelicula()
{

}

Pelicula::Pelicula(char titulpel[100],int anniopel,char generpel[100],char prodcpel[100],int minutos,char nombredir[100],char apelladir[100],char nacdire[100])
{
    this->titulpel[100] = titulpel[100];
    this->anniopel = anniopel;
    this->generpel[100] = generpel[100];
    this->prodcpel[100] = prodcpel[100];
    this->minutos = minutos;
    this->nombredir[100] = nombredir[100];
    this->apelladir[100] = apelladir[100];
    this->nacdire[100] = nacdire[100];

    strcpy(this->titulpel,titulpel);
    strcpy(this->generpel,generpel);
    strcpy(this->prodcpel,prodcpel);

    strcpy(this->nombredir,nombredir);
    strcpy(this->apelladir,apelladir);
    strcpy(this->nacdire,nacdire);
}

void Pelicula::toString()
{
    cout << "+-----[DATOS PELICULA]-----+" << endl;
    cout << "Titulo:" << this->titulpel << endl;
    cout << "Annio:" << this->anniopel << endl;
    cout << "Genero:" << this->generpel << endl;
    cout << "Productora:" << this->prodcpel << endl;
    cout << "Minutos:" << this->minutos << endl;
    cout << "+-----[DATOS DIRECTOR]-----+" << endl;
    cout << "Nombre:" << this->nombredir << " " << this->apelladir << endl;
    cout << "Nacionalidad:"  << this->nacdire << endl;
}


