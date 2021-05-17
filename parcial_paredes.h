#ifndef PARCIAL_PAREDES_H_INCLUDED
#define PARCIAL_PAREDES_H_INCLUDED
///Listar los músicos que no tocan piano y hacen música clásica (piano=6;clasica8)

///La cantidad de sesiones para cada uno de los primeros 6 meses del año

///Dado un número de instrumento que se ingresa por teclado, generar un archivo de nombre ins_elegido.dat,
/// con las músicos que toquen ese instrumento. Cada registro debe tener el mismo formato que el archivo de músicos.


int menu_parcial ()
{

    int op=1;

    while (op!=0)
    {
        cout<< "menu reportes: "<<endl;
        cout<< "=====================" <<endl;
        cout << "1) listar no piano y hacen musica clasica:" <<endl;
        cout<< "2) sesiones para 6 meses: "<<endl;
        cout<< "3) nuevo archivo elegidos:" <<endl;
        cout<< "0) Fin del programa"<<endl;
        cout<< "---------------------"<<endl;
        cout<< "Seleccione una opcion: "<<endl;
        cin>> op;



        switch (op)
        {

        case 1:
       noPiano_mClasica();
       ///terminado
            break;

        case 2:
            sesiones_6m();
            ///
            break;
        case 3:
            generar_arch();
            ///terminado
            break;



        case 0:

            return 0;
            break;

        }

    }

}

///Listar los músicos que no tocan piano y hacen música clásica (piano=6;clasica8)

void noPiano_mClasica(){

FILE *puntero ;
struct datos_musicos aux;

puntero=fopen("musicos.dat","rb");
 if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit(-1);
    }
while (fread(&aux,sizeof aux,1,puntero)==1){
    if (aux.instrumento!=6 && aux.tipo_music!=8){
        listard1_musico(aux);
    }
}

fclose(puntero);
}



void listard1_musico(struct datos_musicos aux)
{



    cout<< "DNI: " <<endl;
    cout<< aux.dni<<endl;
    cout<< "Nombre:" <<endl;
    cout<< aux.nombre<<endl;
    cout<< "Apellido: " <<endl;
    cout<<  aux.apellido<<endl;
    cout<< "Mail:" <<endl;
    cout<< aux.mail<<endl;
    cout<< "Telefono: "<<endl;
    cout<< aux.tel<<endl;
    cout<< "Claustro: "<<endl;
    cout<<  aux.claustro<<endl;
    cout<< "Instrumento: "<<endl;
    cout<<  aux.instrumento<<endl;
    cout<< "Tipo de musica: " <<endl;
    cout<< aux.tipo_music<<endl;
    cout<< "Dia: " <<endl;
    cout<< aux.dia<<endl;
    cout<< "Mes:" <<endl;
    cout<< aux.mes<<endl;
    cout<< "Año:" <<endl;
    cout<< aux.anio<<endl;
    cout<< "estado: " <<endl;
    cout<< aux.situacion;

    system("pause");
    system("cls");

}

///La cantidad de sesiones para cada uno de los primeros 6 meses del año


void sesiones_6m(){
int v_meses[6]={0},i,ac;


for (i=0;i<6;i++) {

    ac=acumular_sesiones(i);
    v_meses[i]=ac;
}
mostrarV(v_meses);
}

int acumular_sesiones(int mes){

FILE *puntero;
int acumulador=0;
struct sesiones aux;

puntero=fopen("Sesiones.dat","rb");

if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit(-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1){
        if (mes == aux.f_sesiones.mes) {
            acumulador++;
        }
    }

fclose(puntero);
}

///Dado un número de instrumento que se ingresa por teclado, generar un archivo de nombre ins_elegido.dat,
/// con las músicos que toquen ese instrumento. Cada registro debe tener el mismo formato que el archivo de músicos.

void generar_arch(){
int n_instrumento;

FILE *puntero;
struct datos_musicos aux;
fopen("musicos.dat","rb");
 if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit(-1);
    }

cout<< "numero de instrumento: "<<endl;
cin>>n_instrumento;

while(fread(&aux,sizeof aux,1,puntero)==1){
    if (n_instrumento==aux.instrumento){
        nuevo_arch(aux);
    }
}

fclose(puntero);
}

void nuevo_arch(struct datos_musicos aux){

FILE *puntero;

puntero=fopen("ins_elegido.dat","ab");

if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit(-1);
    }

fwrite(&aux,sizeof aux,1,puntero);

fclose(puntero);
cout<< "archivo generado!!";
system("pause");
}

void mostrarV(int v[]){

    int i;

    for (i=0;i<6; i++) {

        cout<< "mes " <<i+1 <<" : " <<v[i] <<endl;


    }



}

#endif // PARCIAL_PAREDES_H_INCLUDED
