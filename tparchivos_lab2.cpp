#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <fstream>
#include <ctime>
using namespace std;


#include "tipos.h"
#include "prototipos.h"
#include "funcionesmusicos.h"


int main ()
{

    int op=1;

    while (op!=0)
    {
        cout<< "MENU PRINCIPAL:"<<endl;
        cout<< "=====================" <<endl;
        cout << "1) MUSICOS:" <<endl;
        cout<< "2) SESIONES: "<<endl;
        cout<< "3) INSCRIPCION A SESIONES:" <<endl;
       // cout<< "4) REPORTES: "<<endl;
        cout<< "5) CONFIGURACION: " <<endl;
        cout<< "0) FIN DEL PROGRAMA"<<endl;
        cout<< "---------------------"<<endl;
        cout<< "Seleccione una opcion: "<<endl;
        cin>> op;

        system("cls");

        switch (op)
        {

        case 1:
            menu_musicos();

            break;

        case 2:
            menu_sesiones();
            break;
        case 3:
            menu_inscripcion ();
            break;
        case 4:

            break;
        case 5:
            menu_configuracion();
            break;


        case 0:

            return 0;
            break;

        }

    }
}
