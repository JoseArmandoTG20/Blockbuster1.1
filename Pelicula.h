#ifndef PELICULA_H
#define PELICULA_H


class Pelicula
{
    private:
        char titulpel[100];
        int anniopel;
        char generpel[100];
        char prodcpel[100];
        int minutos;

        char nombredir[100];
        char apelladir[100];
        char nacdire[100];
    public:
        Pelicula();
        Pelicula(char[],int,char[],char[],int,char[],char[],char[]);
        void toString();
};

#endif // PELICULA_H
