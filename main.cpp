#include <iostream>
#include <stdlib.h>

#include "Persona.h"
#include "Pelicula.h"
#include "Prestamo.h"

using namespace std;

Pelicula registrarpeli()
{
    char titulpel[100];
    int anniopel;
    char generpel[100];
    char prodcpel[100];
    int minutos;

    char nombredir[100];
    char apelladir[100];
    char nacdire[100];

    cout << "+-----[DATOS DE LA PELICULA]-----+" << endl;
    cout << "Titulo: ";
    cin >> titulpel;
    cout << "Annio: ";
    cin >> anniopel;
    cout << "Genero: ";
    cin >> generpel;
    cout << "Productora: ";
    cin >> prodcpel;
    cout << "Minutos: ";
    cin >> minutos;

    cout << "+-----[DATOS DEL DIRECTOR]-----+" << endl;
    cout << "Nombre: ";
    cin >> nombredir;
    cout << "Apellido: ";
    cin >> apelladir;
    cout << "Nacionalidad: ";
    cin >> nacdire;

    Pelicula regis = Pelicula(titulpel,anniopel,generpel,prodcpel,minutos,nombredir,nacdire,apelladir);
    return regis;

}

Persona registroUsu()
{
    char nombrusu[100];
    char apellusu[100];
    char naciousu[100];
    int edadusu;

    cout << "-------[REGISTRO USUARIO]-------" << endl;
    cout << "Nombre:";
    cin >> nombrusu;
    cout << "Apellido:";
    cin >> apellusu;
    cout << "Edad:";
    cin >> edadusu;
    cout << "Nacionalidad:";
    cin >> naciousu;
    cout << "--------------------------------" << endl;

    return Persona(nombrusu,apellusu,naciousu,edadusu);
}

Prestamo registroPres(int numPeli)
{
    int numusua;

    char fechIn[100];
    int estatus = 0;


    cout << "Numero de Usuario:";
    cin >> numusua;
    cout << "Ingresa la Fecha de Prestamo:";
    cin >> fechIn;
    estatus = 1;
    return Prestamo(numusua,numPeli,fechIn,estatus);
}


void menuPrin()
{
    cout << "+----[MENU PRINCIPAL]----+" << endl;
    cout << "|    1.-Usuarios.        |" << endl;
    cout << "|    2.-Peliculas.       |" << endl;
    cout << "|    3.-Prestamos.       |" << endl;
    cout << "+------------------------+" << endl;
}

void menuUsu()
{
    cout << "+-----[MENU USUARIO]-----+" << endl;
    cout << "|     1.-Registrar.      |" << endl;
    cout << "|     2.-Editar.         |" << endl;
    cout << "|     3.-Consultar.      |" << endl;
    cout << "|     4.-Eliminar.       |" << endl;
    cout << "|   5.-Menu Principal.   |" << endl;
    cout << "+-------------------- ---+" << endl;
}

void menuPeli()
{
    cout << "+-------[MENU PELICULA]-------+" << endl;
    cout << "|    1.-Registrar.            |" << endl;
    cout << "|    2.-Editar.               |" << endl;
    cout << "|    3.-Consultar.            |" << endl;
    cout << "|    4.-Eliminar.             |" << endl;
    cout << "|    5.-Menu Principal.       |" << endl;
    cout << "+-----------------------------+" << endl;
}

void menuPres()
{
    cout << "+-----[MENU PRESTAMO]-----+" << endl;
    cout << "|  1.-Realizar Prestamo.  |" << endl;
    cout << "|  2.-Devolver Libro.     |" << endl;
    cout << "|  3.-Consultar Prestamo. |" << endl;
    cout << "|  4.-Menu Principal.     |" << endl;
    cout << "+-------------------------+" << endl;
}

void listaPelicula(Pelicula pelicula[10], int conPel)
{
    for(int p = 0; p < conPel; p++)
    {
        cout << "+-----[PELICULA " << p << "]-----+" << endl;
        pelicula[p].toString();
        cout << "+--------------------------------+" << endl;
    }
}

int main()
{
    Persona usuarios[10];
    Pelicula pelicula[10];
    Prestamo prest[100];

    bool sistema = true;
    bool repUsu = true;
    bool repPel = true;
    bool repPres = true;
    bool pre = true;

    int opc = 0;
    int opcUsu = 0;
    int opcPel = 0;
    int opcPres = 0;

    int conUsu = 0;
    int conPel = 0;
    int conPres = 0;
    int numPeli = 0;
    int numusua = 0;

    char fechFin[100];

    while(sistema == true)
    {

        menuPrin();
        cout << "Opcion:";
        cin >> opc;

        switch(opc)
        {
            case 1:

                repUsu = true;

                while(repUsu == true)
                {

                    menuUsu();
                    cout << "Opcion:";
                    cin >> opcUsu;

                    switch(opcUsu)
                    {
                        case 1:

                            usuarios[conUsu] = registroUsu();
                            cout << "Tu Numero de Usuario es:" << conUsu << endl;
                            conUsu ++;
                            cout << "-------[USUARIO REGISTRADO]-------" << endl;

                        break;

                        case 2:

                            cout << "-------[EDITAR USUARIO]-------" << endl;

                            cout << "Ingresa el Numero de Usuario a editar:";
                            cin >> conUsu;
                            usuarios[conUsu].toString();
                            usuarios[conUsu] = registroUsu();
                            cout << "-------[USUARIO EDITADO]-------" << endl;

                        break;

                        case 3:
                            cout << "-------[CONSULTAR USUARIO]-------" << endl;

                            cout << "Ingresa el Numero de Usuario:";
                            cin >> numusua;

                            usuarios[numusua].toString();

                            cout << "---------------------------------" << endl;
                        break;

                        case 4:
                            cout << "-------[ELIMINAR USUARIO]-------" << endl;

                            cout << "Ingresa el Numero de Usuario a eliminar:";
                            cin >> numusua;

                            usuarios[numusua].toString();

                            pre = true;

                            for(int q = 0; q < conPres; q++)
                            {
                                if(numusua == prest[q].getUsuario() && prest[q].getEstatus() == 1)
                                {
                                    pre = false;

                                }
                            }

                            if(pre == true)
                            {
                                usuarios[numusua] = Persona();
                                cout << "-------[USUARIO ELIMINADO]-------" << endl;
                            }
                            else
                            {
                                cout << "-------[NO PUEDES BORRAR ESTE USUARIO]-------" << endl;
                            }
                        break;

                        case 5:
                            repUsu = false;
                        break;
                    }
                }

            break;

            case 2:

                repPel = true;

                while(repPel == true)
                {

                    menuPeli();
                    cout << "Opcion:";
                    cin >> opcPel;

                    switch(opcPel)
                    {
                        case 1:
                            pelicula[conPel] = registrarpeli();
                            cout << "Numero de Pelicula:" << conPel << endl;
                            conPel ++;
                        break;

                        case 2:
                            cout << "-------[EDITAR PELICULA]-------" << endl;

                            listaPelicula(pelicula,conPel);

                            cout <<"Ingresa el Numero de Pelicula:";
                            cin >> conPel;

                            pelicula[conPel] = registrarpeli();

                            cout << "-------[PELICULA EDITADA]-------" << endl;
                        break;

                        case 3:
                            cout << "-------[CONSULTAR PELICULA]-------" << endl;

                            listaPelicula(pelicula,conPel);

                            cout << "Ingresa el Numero de Pelicula:";
                            cin >> conPel;

                            pelicula[conPel].toString();
                        break;

                        case 4:
                            cout << "-------[ELIMINAR PELICULA]-------" << endl;

                            cout << "Ingresa el Numero de Pelicula:";
                            cin >> numPeli;

                            pelicula[numPeli].toString();

                            pre = true;

                            for(int q = 0; q < conPres; q++)
                            {
                                if(numPeli == prest[q].getPelicula() && prest[q].getEstatus() == 1)
                                {
                                    pre = false;

                                }
                            }

                            if(pre == true)
                            {
                                pelicula[numPeli] = Pelicula();
                                cout << "-------[PELICULA ELIMINADA]-------" << endl;
                            }
                            else
                            {
                                cout << "-------[NO PUEDES BORRAR ESTA PELICULA]-------" << endl;
                            }
                        break;

                        case 5:
                            repPel = false;
                        break;
                    }
                }
            break;

            case 3:

                repPres = true;

                while(repPres == true)
                {
                    menuPres();
                    cout << "Opcion:";
                    cin >> opcPres;

                    switch(opcPres)
                    {
                        case 1:
                            listaPelicula(pelicula,conPel);

                            cout << "-------[REGISTRO DE PRESTAMO]-------" << endl;
                            cout << "Numero de Pelicula:";
                            cin >> numPeli;

                            pre = true;

                            for(int q = 0; q < conPres; q++)
                            {
                                if(numPeli == prest[q].getPelicula() && prest[q].getEstatus() == 1)
                                {
                                    pre = false;

                                }
                            }

                            if(pre == true)
                            {
                                prest[conPres] = registroPres(numPeli);
                                cout << "Numero de Prestamo:" << conPres << endl;
                                conPres ++;
                                cout << "-------[SE TE HA PRESTADO LA PELICULA]-------" << endl;
                            }
                            else
                            {
                                cout << "-------[ESTE PELICULA HA SIDO PRESTADO]-------" << endl;
                            }
                        break;

                        case 2:
                            cout << "-------[REGISTRO DE DEVOLUCION]-------" << endl;
                            cout << "Ingresa el Numero de Prestamo:";
                            cin >> conPres;

                            usuarios[prest[conPres].getUsuario()].toString();

                            pelicula[prest[conPres].getPelicula()].toString();

                            if(prest[conPres].getEstatus() == 1)
                            {
                                cout << "Ingresa la Fecha de Entrega:";
                                cin >> fechFin;

                                prest[conPres].Devolucion(fechFin);

                                cout << "-------[HAS DEVUELTO ESTA PELICULA]-------" << endl;
                            }
                            else
                            {
                                cout << "-------[ESTA PELICULA HA SIDO DEVUELTO ANTERIORMENTE]-------" << endl;
                            }
                        break;

                        case 3:
                            cout << "-------[CONSULTAR PRESTAMO]-------" << endl;
                            cout << "Ingresa el Numero de Prestamo:";
                            cin >> conPres;

                            usuarios[prest[conPres].getUsuario()].toString();

                            pelicula[prest[conPres].getPelicula()].toString();

                            prest[conPres].toString();
                        break;

                        case 4:
                            repPres = false;
                        break;
                    }
                }

            break;

            default:
                sistema = false;
                cout << "-------[VUELVA PRONTO]-------" << endl;
            break;
        }
    }

    return 0;
}
