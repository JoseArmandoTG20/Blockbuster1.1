#ifndef PRESTAMO_H
#define PRESTAMO_H


class Prestamo
{
    private:
        int numusua;
        int numPeli;
        char fechIn[100];
        char fechFin[100];
        int estatus;

    public:
        Prestamo();
        Prestamo(int,int,char[],int);
        void Devolucion (char[]);
        int getUsuario();
        int getPelicula();
        int getEstatus();
        void toString();
};

#endif // PRESTAMO_H
