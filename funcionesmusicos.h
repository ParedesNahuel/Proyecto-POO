#ifndef FUNCIONESMUSICOS_H_INCLUDED
#define FUNCIONESMUSICOS_H_INCLUDED

///---------------------
///fecha actual
///---------------------
int fecha_actual()
{

    time_t tiempo;
    struct tm *tmPtr;

    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec;

}
const int diaMin=15,mesMin=3,anioMin=2020,mesMinSusc=4;

bool menor_mayora(int x,int Max,int Min)
{

    if (x<=Max && x>=Min)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool fecha_mayora (int dia,int mes,int anio)
{
///dia 15 mes 3 año 2020
///1           3       2021

    if (anio>=anioMin )
    {
        if (mes>=mesMin)
        {
            if (dia>=diaMin)
            {
                return true;
            }
            else
            {
                if (anio>=anioMin && mes>mesMin)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            if (anio>anioMin)
            {
                return true;
            }
            else
            {
                return false;
            }
        }

    }
    else
    {
        return false;
    }


}

bool fecha_menor(int dia, int mes,int anio)
{
    time_t tiempo;
    struct tm *tmPtr;

    tiempo = time(NULL);
    tmPtr = localtime(&tiempo);
    ///tmPtr->tm_mday, tmPtr->tm_mon+1, 1900+tmPtr->tm_year, tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec;
///2 del 6 del 2020
///23 del 6 del 2020
    if (anio<= 1900+tmPtr->tm_year)
    {
        if (mes<= tmPtr->tm_mon+1)
        {
            if(dia<= tmPtr->tm_mday)
            {
                return true;
            }
            else
            {
                if (mes< tmPtr->tm_mon+1)
                {
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }


}

///---------------------
///parte1
///---------------------
int menu_musicos()
{
    int op=1;

    while (op!=0)
    {
        cout<< "menu musicos:"<<endl;
        cout<< "=====================" <<endl;
        cout << "1) Alta:" <<endl;
        cout<< "2) Baja: "<<endl;
        cout<< "3) Modificacion:" <<endl;
        cout<< "4) Listados: "<<endl;
        cout<< "0) Volver al menu principal"<<endl;
        cout<< "---------------------"<<endl;
        cout<< "Seleccione una opcion: "<<endl;
        cin>> op;


        system("cls");

        switch (op)
        {

        case 1:
            Alta_musicos();

            break;

        case 2:
            Baja_musicos();
            break;
        case 3:
            modificar_registro_mail();
            break;
        case 4:
            listados_musicos();

            break;


        case 0:
            system("cls");

            return 0;
            break;

        }

    }
}


void Alta_musicos()
{

    FILE *puntero;
    struct datos_musicos aux;
    bool claustro_sin_error,inst_sin_error,t_music_sin_error,comprobar_fechaMayora,comprobar_fechamenora;
    const int claustro_min=1,claustro_max=4,inst_min=1,inst_max=15,t_music_min=1,t_music_max=10;
    puntero=fopen("musicos.dat","ab");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo!!";
        exit(-1);

    }

    cout<< "DNI: " <<endl;
    cin>> aux.dni;
    cout<< "Nombre:" <<endl;
    cin>> aux.nombre;
    cout<< "Apellido: " <<endl;
    cin>> aux.apellido;
    cout<< "Mail:" <<endl;
    cin>> aux.mail;
    cout<< "Telefono: "<<endl;
    cin>> aux.tel;
    cout<< "Claustro: "<<endl;
    cin>> aux.claustro;
    claustro_sin_error=menor_mayora(aux.claustro,claustro_max,claustro_min);
    cout<< "Instrumento: "<<endl;
    cin>> aux.instrumento;
    inst_sin_error= menor_mayora(aux.instrumento,inst_max,inst_min);
    cout<< "Tipo de musica: " <<endl;
    cin>> aux.tipo_music;
    t_music_sin_error=menor_mayora(aux.tipo_music,t_music_max,t_music_min);
    cout<< "Dia: " <<endl;
    cin>> aux.dia;
    cout<< "Mes:" <<endl;
    cin>> aux.mes;
    cout<< "Año:" <<endl;
    cin>> aux.anio;

    comprobar_fechaMayora= fecha_mayora(aux.dia,aux.mes,aux.anio);
    comprobar_fechamenora= fecha_menor(aux.dia,aux.mes, aux.anio);

    aux.situacion=true;

    if (claustro_sin_error==true && inst_sin_error==true && t_music_sin_error==true && comprobar_fechaMayora==true && comprobar_fechamenora==true )
    {
        fwrite(&aux,sizeof aux,1,puntero);
        fclose(puntero);
        cout<<endl;
        cout<< "dado de alta con exito!"<<endl;
        system("pause");
        system("cls");
    }
    else
    {

        if (claustro_sin_error==false)
        {
            cout<< "Claustro no esta entre 1 y 4."<<endl;
        }
        if (inst_sin_error==false)
        {
            cout<< "Instrumento no esta entre 1 y 15."<<endl;
        }
        if (t_music_sin_error==false)
        {
            cout<< "Tipo de musica no esta entre 1 y 10."<<endl;
        }
      /* if (comprobar_fechaMayora==false||comprobar_fechamenora==false)
        {
            cout<< "Fechas invalida. Debe estar entre 15/03/2020 y la fecha actual."<<endl;
        }*/
        if (comprobar_fechaMayora==false){
            cout<< "error fechamayora"<<endl;
        }
        if (comprobar_fechamenora==false){
            cout<< "error fechamenora"<<endl;
        }

        system("pause");
        system("cls");
    }
    return;
}





void listado_musicoSecuencial ()
{
    FILE *puntero;
    struct datos_musicos aux;

    puntero=fopen("musicos.dat","rb");
    if (puntero==NULL)
    {
        cout << "!!error al abrir el archivo!!";
        exit(-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if (aux.situacion==true)
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


            system("pause");
            system("cls");
        }
    }

    fclose(puntero);
}

int buscarpos_musico(int dni)
{
    FILE *puntero;
    struct datos_musicos aux;
    int pos=0;

    puntero=fopen("musicos.dat","rb");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo 1!!";
        return(-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {

        if (dni==aux.dni)
        {

            fclose(puntero);
            return pos;
        }
        pos++;
    }
    fclose(puntero);
    return -1;
}

struct datos_musicos obtener_datos(int x)
{

    FILE *puntero;
    struct datos_musicos aux;

    puntero=fopen("musicos.dat","rb");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit(-1);
    }
    fseek(puntero,x*sizeof aux,SEEK_SET);

    fread(&aux,sizeof aux,1,puntero);
    fclose(puntero);
///revisar
    return aux;

};

bool modificar_registro (struct datos_musicos aux,int pos)
{

    FILE *puntero;

    puntero= fopen("musicos.dat", "rb+");
    if (puntero==NULL)
        {return false;
        }
    fseek(puntero,sizeof aux*pos,SEEK_SET);
    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return true;

}

void listar1_musico(struct datos_musicos aux)
{

if (aux.situacion==true){

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
    /*cout<< "estado: " <<endl;
    cout<< aux.situacion;*/
    ///sacar if para comprobar 1 reg Musicos
}
    system("pause");
    system("cls");

}

///dividir en trabajos.
void Baja_musicos ()
{
    int pos_busc,dni_baja;
    struct datos_musicos aux;
    cout<< "DNI DE BAJA: ";
    cin>> dni_baja;

    pos_busc= buscarpos_musico(dni_baja );
    aux= obtener_datos(pos_busc);

    aux.situacion=false;


    if (modificar_registro(aux,pos_busc)==true)
    {

        cout<< "REGISTRO DADO DE BAJA"<<endl;
        listar1_musico(aux);

    }
    else
    {

        cout << "NO SE PUDO DAR DE BAJA"<<endl;
    }



    system("pause");
    system("cls");


}

void modificar_registro_mail()
{

    int pos_busc, dni_mod;
    char nuevo_mail[50];
    struct datos_musicos aux;
    cout<< "ingrese dni del mail a modificar: ";
    cin>> dni_mod;
    pos_busc= buscarpos_musico(dni_mod);
    aux= obtener_datos(pos_busc);

    cout<< "INGRESE NUEVO MAIL: " ;
    cin>> nuevo_mail;

    strcpy(aux.mail,nuevo_mail);

    if (modificar_registro(aux,pos_busc)==true)
    {

        cout<< "MAIL MODIFICADO"<<endl;
        listar1_musico(aux);

    }
    else
    {

        cout << "NO SE PUDO MODIFICAR"<<endl;
    }

    system("pause");
    system("cls");


}

int listados_musicos(){
int op=1;
while (op!=0){
cout<< "menu listados musicos: "<<endl;
cout<< "=============================="<<endl;
cout<< "1. Listado secuencial: "<<endl;
cout<< "2. Listar 1 solo musico: "<<endl;
cout<< "3. Listado ordenado por orden alfabetico:"<<endl;
cout<< "0. volver al menu anterior: "<<endl;
cout<< "-------------------------------------"<<endl;
cout<< "ingrese opcion: ";
cin>> op;
system("cls");
switch(op){

case 1:
    listado_musicoSecuencial();
    break;
case 2:
    listado_musico1Solo();
    break;
case 3:
    listado_musicosOrdenado ();
    break;
case 0:
    return 0;
    break;

}

}
}

void listado_musico1Solo() {
FILE *puntero;
int dni;
struct datos_musicos aux;

puntero=fopen("musicos.dat","rb");

if (puntero==NULL){
    cout<< "errror al abrir el archivo";
    return;
}

cout<< "ingrese dni del musico a buscar: " <<endl;
cin>>dni;

while (fread(&aux,sizeof aux,1,puntero)==1) {
    if (aux.dni==dni){
        listar1_musico(aux);
    }
}
fclose(puntero);
return;
}

void listado_musicosOrdenado () {
struct datos_musicos *pMusico;
int cantReg,i;

cantReg=canRegMusicos();
pMusico= (struct datos_musicos *) malloc(cantReg*sizeof (struct datos_musicos));

if (pMusico==NULL) {
    cout<< "Error al asignar la memoria!!"<<endl;
    return;
}

for (i=0;i<cantReg;i++){
    pMusico [i]= obtener_datos(i);
}

OrdenarVecMusico (pMusico,cantReg);

for (i=0;i<cantReg;i++){
    listar1_musico(pMusico[i]);
}
free(pMusico);
system("pause");
}

int canRegMusicos(){
FILE *puntero;
puntero=fopen("musicos.dat","rb");
if (puntero==NULL) {
    cout<< "error al abrir archivo";
    return -1;
}

fseek(puntero,0,2);
long cantByte=ftell(puntero);
fclose(puntero);
return (int )cantByte/sizeof(struct datos_musicos);

}

void OrdenarVecMusico (struct datos_musicos *pMusico,int cantReg){
struct datos_musicos aux;
  int i, j, posmin;
  for(i=0;i<cantReg-1;i++){
    posmin=i;
    for(j=i+1;j<cantReg;j++){
      if(strcmp(pMusico[j].apellido,pMusico[posmin].apellido)<0)
        posmin=j;
      }
    aux=pMusico[i];
    pMusico[i]=pMusico[posmin];
    pMusico[posmin]=aux;
    }

}

///---------------------------
///parte2
///---------------------------



int menu_sesiones ()
{

    int op=1;

    while (op!=0)
    {
        cout<< "menu sesiones:"<<endl;
        cout<< "=====================" <<endl;
        cout << "1) Alta:" <<endl;
        cout<< "2) Baja: "<<endl;
        cout<< "3) Modificacion:" <<endl;
        cout<< "4) Listado: "<<endl;
        cout<< "0) Volver al menu principal"<<endl;
        cout<< "---------------------"<<endl;
        cout<< "Seleccione una opcion: "<<endl;
        cin>> op;

        system("cls");


        switch (op)
        {

        case 1:

            Alta_sesiones();
            system("cls");

            break;

        case 2:

            baja_sesiones();
            break;
        case 3:

            modificar_registro_URL();
            break;
        case 4:

            listados_sesiones();
            break;


        case 0:
            system("cls");

            return 0;
            break;

        }

    }

}
/// autonumerico
int contar_reg_sesiones ()
{
    FILE *puntero;

    int tamanio;
    puntero = fopen("Sesiones.dat", "rb");

    if (puntero==NULL)
    {

        return 0;
    }

    fseek(puntero,0,2);

    tamanio= ftell(puntero) / sizeof (struct sesiones);
    fclose(puntero);
///cout<< "ftell: " <<ftell(puntero);
///cout<< "tamanio: " <<tamanio<<endl;
    return tamanio;

}

void Alta_sesiones()
{
    struct sesiones aux;
    bool existe;/// existe =false -> guardar           existe=true -> no guardar
    bool comprabado;///comprobado=true -> nada        comprobado =false -> musico no registrado
    bool f_correcta,HI_correcta,HF_correcta,I_correcto;
    int c;
    int Hmin=0,Hmax=23,Imin=0,Imax=15;
    c=contar_reg_sesiones()+1;

    aux.Num_sesion=c;

    cout<< "numero de sesion: " <<aux.Num_sesion <<endl;
    cout<< "ingrese fecha:"<<endl;
    cin>>aux.f_sesiones.dia ;
    cin>>aux.f_sesiones.mes ;
    cin>>aux.f_sesiones.anio ;

    f_correcta= fecha_mayora(aux.f_sesiones.dia,aux.f_sesiones.mes,aux.f_sesiones.anio);

    cout<< "hora de inicio: " <<endl;
    cin>>aux.Hora_de_inicio;
    cout<< "hora de fin: " <<endl;
    cin>>aux.Hora_de_fin;

    HI_correcta= menor_mayora(aux.Hora_de_inicio,Hmax,Hmin);
    if (aux.Hora_de_fin>aux.Hora_de_inicio)
    {
        HF_correcta=menor_mayora(aux.Hora_de_fin,Hmax,Hmin);
    }
    else
    {
        HF_correcta=false;
    }

    cout<< "instrumento de la sesion:" <<endl;
    cin>>aux.Instrumento_sesion;

    I_correcto= menor_mayora(aux.Instrumento_sesion,Imax,Imin);

    cout<< "DNI del coordinador: " <<endl;
    cin>>aux.coordinador;
    cout<< "URL de la reunion: " <<endl;
    cin>>aux.URL;


    aux.sesion_activa=true;
    comprabado=comprobar_musico(aux.coordinador);

    if (comprabado==false)
    {
        cout<< "musico no registrado. REGISTRAR AL INSTRUCTOR EN EL MENU MUSICOS"<<endl;
        system("pause");
        system("cls");
        return;
    }

    if (c==1)
    {
        cargar_datos_sesiones(aux);
        cout<< "sesion cargada con exito!"<<endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {

        existe= no_repetir_sesion (aux);
        if (existe==false && f_correcta==true && HI_correcta==true && HF_correcta==true && I_correcto==true ) ///comprobaciones para guardar
        {
            cargar_datos_sesiones(aux);
            cout<< "sesion cargada con exito!"<<endl;
            system("pause");
            system("cls");
            return;

        }
        else
        {
            cout<< " no se puede registrar, ya existe, misma fecha y horario"<<endl;

            system("pause");
            system("cls");
            return;
        }
    }

}

bool comprobar_musico(int dni)
{
    FILE *puntero;
    struct datos_musicos aux;
    puntero= fopen("musicos.dat","rb");
    if (puntero==NULL)
    {
        cout<< "error comprobando";
        return false;
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if (dni== aux.dni)
        {
            fclose(puntero);
            return true;
        }
    }
    fclose(puntero);
    return false;
}

void cargar_datos_sesiones (struct sesiones aux)
{
    FILE *puntero;

    puntero=fopen("Sesiones.dat","ab");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo!!";
        exit(-1);

    }

    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;
}

bool no_repetir_sesion (struct sesiones aux)
{

    FILE *puntero;
    struct sesiones reg;
    puntero=fopen("Sesiones.dat","rb");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo!!";
        exit(-1);

    }

    while (fread(&reg,sizeof reg,1,puntero)==1)
    {


        if (reg.Instrumento_sesion==aux.Instrumento_sesion )
        {

            if ( aux.f_sesiones.mes==reg.f_sesiones.mes && aux.f_sesiones.dia== reg.f_sesiones.dia && aux.f_sesiones.anio == reg.f_sesiones.anio )
            {
                if (aux.Hora_de_fin==reg.Hora_de_fin || aux.Hora_de_fin==reg.Hora_de_inicio || aux.Hora_de_inicio==reg.Hora_de_fin || aux.Hora_de_inicio==reg.Hora_de_inicio )
                {
                    fclose(puntero);
                    return true;
                }

            }

        }

    }
    fclose (puntero);
    return false;
}


void baja_sesiones ()
{
    int sesion_baja,possesion;

    struct sesiones aux;

    cout<< "ingrese sesion de baja: "<<endl;
    cin>> sesion_baja;

    possesion=buscarpos_sesion(sesion_baja);

    aux= obtener_datos_sesiones(possesion);

    aux.sesion_activa=false;

    if (modificar_reg_sesiones(aux,possesion)==true)
    {
        cout<< "sesion dada de baja"<<endl;
        system("pause");
        system("cls");
    }
    else
    {

        cout<< "la sesion no pudo darse de baja" <<endl;
        system("pause");
        system ("cls");
    }


}

int buscarpos_sesion(int sesion)
{
    FILE *puntero;
    struct sesiones aux;
    int pos;

    puntero=fopen("Sesiones.dat","rb");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo 1!!";
        return(-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {

        if(sesion==aux.Num_sesion)
        {
            pos= aux.Num_sesion-1;
            fclose(puntero);
            return pos;

        }
    }
    fclose(puntero);
    return -1;
}

struct sesiones obtener_datos_sesiones(int x)
{

    FILE *puntero;
    struct sesiones aux;

    puntero=fopen("Sesiones.dat","rb");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit(-1);
    }
    fseek(puntero,x*sizeof aux,SEEK_SET);

    fread(&aux,sizeof aux,1,puntero);
    fclose(puntero);
///borrar el archivo y comenzarlo de vuelta.
    return aux;

};

bool modificar_reg_sesiones(struct sesiones aux,int pos)
{

    FILE *puntero;

    puntero=fopen("Sesiones.dat","rb+");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        return false;
    }

    fseek(puntero,sizeof aux*pos,SEEK_SET);
    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return true;



}

void modificar_registro_URL()
{
    struct sesiones aux;
    int pos,sesion_mod;
    char n_URL [40];

    cout<< "ingrese sesion a modificar URL: "<<endl;
    cin>>sesion_mod ;
    pos= buscarpos_sesion (sesion_mod);
    aux= obtener_datos_sesiones(pos);

    cout<< "nuevo URL: " <<endl;
    cin>> n_URL;

    strcpy(aux.URL,n_URL);

    modificar_reg_sesiones(aux,pos);

    if (modificar_reg_sesiones(aux,pos)==true)
    {
        cout<< "URL MODIFICADO"<<endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {

        cout<< "ERROR AL MODIFICAR URL"<<endl;
        system("pause");
        system("cls");
        return;
    }

}

int listados_sesiones(){
int op=1;
while (op!=0){
cout<< "menu listados sesiones: "<<endl;
cout<< "=============================="<<endl;
cout<< "1. Listado secuencial: "<<endl;
cout<< "2. Listar 1 sola sesion: "<<endl;
cout<< "3. Listado ordenado por hora de inicio:"<<endl;
cout<< "0. volver al menu anterior: "<<endl;
cout<< "-------------------------------------"<<endl;
cout<< "ingrese opcion: ";
cin>> op;
system("cls");
switch(op){

case 1:
    listado_sesioneSecuencial();
    break;
case 2:
    listado_sesiones1Solo();
    break;
case 3:
    listado_sesionesOrdenado();
    break;
case 0:
    return 0;
    break;

}

}
}

void listado_sesiones1Solo() {
FILE *puntero;
int sesion;
struct sesiones aux;

puntero=fopen("Sesiones.dat","rb");

if (puntero==NULL){
    cout<< "errror al abrir el archivo";
    return;
}

cout<< "ingrese NUM. de sesion a buscar: " <<endl;
cin>>sesion;

while (fread(&aux,sizeof aux,1,puntero)==1) {
    if (aux.Num_sesion==sesion){
        listar1_sesion(aux);
    }
}
fclose(puntero);
system("pause");
system("cls");
return;
}

void listar1_sesion(struct sesiones aux){

if(aux.sesion_activa==true)
        {
            cout<< "NUMERO DE SESION: "<<aux.Num_sesion <<endl;
            cout<< "FECHA DE SESION: " <<aux.f_sesiones.dia <<"/" <<aux.f_sesiones.mes <<"/" <<aux.f_sesiones.anio <<endl;
            cout<< "HORARIO: " <<aux.Hora_de_inicio <<" a " <<aux.Hora_de_fin <<endl;
            cout<< "INSTRUMENTO DE SESION: "<<aux.Instrumento_sesion <<endl;
            cout<< "COORDINADOR (DNI): " <<aux.coordinador <<endl;///(DNI del músico que coordinará la sesión)
            cout<< "URL: " <<aux.URL <<endl; ///de la reunión ///(cadena de 40 caracteres)
            cout<<endl;
            cout<< "----------------------------------"<<endl;
            cout<<endl;
        }

}


void listado_sesionesOrdenado () {
struct sesiones *pSesiones;
int cantReg,i;

cantReg=contar_reg_sesiones();
pSesiones= (struct sesiones *) malloc(cantReg*sizeof (struct sesiones));

if (pSesiones==NULL) {
    cout<< "Error al asignar la memoria!!"<<endl;
    return;
}

for (i=0;i<cantReg;i++){
    pSesiones [i]= obtener_datos_sesiones(i);
}

OrdenarVecSesiones (pSesiones,cantReg);

for (i=0;i<cantReg;i++){
    listar1_sesion(pSesiones[i]);
}
free(pSesiones);
system("pause");
system("cls");
}


void OrdenarVecSesiones (struct sesiones *pSesiones,int cantReg){
struct sesiones aux;
  int i, j, posmin;
  for(i=0;i<cantReg-1;i++){
    posmin=i;
    for(j=i+1;j<cantReg;j++){
      if(pSesiones[j].Hora_de_inicio<pSesiones[posmin].Hora_de_inicio)
        posmin=j;
      }
    aux=pSesiones[i];
    pSesiones[i]=pSesiones[posmin];
    pSesiones[posmin]=aux;
    }

}

void listado_sesioneSecuencial()
{
    FILE *puntero;
    struct sesiones aux;
    puntero=fopen("Sesiones.dat","rb");

    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit (-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if(aux.sesion_activa==true)
        {
            cout<< "NUMERO DE SESION: "<<aux.Num_sesion <<endl;
            cout<< "FECHA DE SESION: " <<aux.f_sesiones.dia <<"/" <<aux.f_sesiones.mes <<"/" <<aux.f_sesiones.anio <<endl;
            cout<< "HORARIO: " <<aux.Hora_de_inicio <<" a " <<aux.Hora_de_fin <<endl;
            cout<< "INSTRUMENTO DE SESION: "<<aux.Instrumento_sesion <<endl;
            cout<< "COORDINADOR (DNI): " <<aux.coordinador <<endl;///(DNI del músico que coordinará la sesión)
            cout<< "URL: " <<aux.URL <<endl; ///de la reunión ///(cadena de 40 caracteres)
            cout<<endl;
            cout<< "----------------------------------"<<endl;
            cout<<endl;
        }

    }
    fclose(puntero);
    system("pause");
    system("cls");
}



int menu_inscripcion ()
{


    int op=1;

    while (op!=0)
    {
        cout<< "menu suscripcion:"<<endl;
        cout<< "=====================" <<endl;
        cout << "1) Alta:" <<endl;
        cout<< "2) Baja: "<<endl;
        cout<< "3) Modificacion:" <<endl;
        cout<< "4) Listado: "<<endl;
        cout<< "0) Volver al menu principal"<<endl;
        cout<< "---------------------"<<endl;
        cout<< "Seleccione una opcion: "<<endl;
        cin>> op;

        system("cls");

        switch (op)
        {

        case 1:
            Alta_inscripcion();

            break;

        case 2:
            Baja_inscripcion();
            break;
        case 3:
            modificar_registro_Tparticipacion();
            break;
        case 4:
            listados_inscriptos ();
            break;


        case 0:
            system("cls");
            return 0;
            break;

        }

    }

}

///un músico no se inscriba a una sesión que no sea del instrumento de ese
///músico. Además debe evitarse que un músico se registre más de una vez a la misma sesión.
void Alta_inscripcion ()
{
    int instrumento_musico,instrumento_sesion;
    struct inscripcion aux;
    bool solo1,TP_correcta;
    int TPmin=1,TPmax=2;

    cout<< "INGRESE DATOS:" <<endl;
    cout<< "---------------------"<<endl;
    cout<< "DNI: ";
    cin >>aux.dni;
    cout<< "NUM. SESION: ";
    cin>> aux.n_sesion;
    cout<< "TIPO DE PARTICIPACION ( 1=OBSERBADOR ; 2=ACTIVO ):";
    cin>>aux.t_participacion;

    TP_correcta= menor_mayora(aux.t_participacion,TPmax,TPmin);

    aux.inscr_activa=true;

    instrumento_musico= comprobar_instrumento_musico(aux.dni);

    instrumento_sesion= comprobar_inst_sesion (aux.n_sesion);

    if ((instrumento_musico== instrumento_sesion||instrumento_musico==0||instrumento_sesion==0) && instrumento_musico!=-1 && instrumento_sesion!=-1 && TP_correcta==true)
    {

        solo1= comprobar_1solo(aux.dni,aux.n_sesion);

        if (solo1==true)
        {
            registrar_inscripcion(aux);
            cout<< "!!inscripcion realizada con exito!!"<<endl;
            system("pause");
            system("cls");
            return;
        }
        else
        {
            cout<< "ya esta inscripto a esa sesion" <<endl;
            system("pause");
            system("cls");
            return;
        }

    }
    else
    {

        cout<< " EL INSTRUMENTO DEL MUSICO NO SE CORRESPONDE CON LA SESION "<<endl;
        if (instrumento_musico!=-1)
        {
            cout<< "EL MUSICO NO SE REGISTRO PREVIAMENTE EN MUSICOS"<<endl;
        }
        if (instrumento_sesion!=-1)
        {
            cout<< "SESION NO ENCONTRADA"<<endl ;
        }
        if (TP_correcta==false)
        {
            cout<< "TIPO DE PARTICIPACION INCORRECTA"<<endl;
        }
        system("pause");
        system("cls");
        return;

    }

}

int comprobar_instrumento_musico(int x)
{

    FILE *puntero;
    struct datos_musicos aux;
    puntero=fopen("musicos.dat", "rb");

    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo MUSICOS.DAT!!";
        exit (-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if (x==aux.dni)
        {
            fclose(puntero);
            return aux.instrumento;
        }
    }
    fclose(puntero);
    return -1;
}

int comprobar_inst_sesion (int x)
{

    FILE *puntero;
    struct sesiones aux;
    puntero=fopen("Sesiones.dat", "rb");

    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo SESIONES.DAT!!";
        exit (-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if (x==aux.Num_sesion)
        {
            fclose(puntero);
            return aux.Instrumento_sesion;
        }
    }
    fclose(puntero);
    return -1;

}

bool comprobar_1solo(int x,int n)
{

    FILE *puntero;
    struct inscripcion aux;

    puntero=fopen("Inscripciones.dat","rb");
    if (puntero==NULL)
    {
        cout<< "!!PRIMER REGISTRO !!";
        return true;
    }

    while(fread(&aux,sizeof aux,1,puntero)==1)
    {
        if (aux.dni==x && n==aux.n_sesion)
        {
            fclose(puntero);
            return false;
        }
    }
    fclose(puntero);
    return true;
}

void registrar_inscripcion(struct inscripcion aux)
{

    FILE *puntero;

    puntero=fopen("Inscripciones.dat","ab");

    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit (-1);
    }

    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);

}


void Baja_inscripcion()
{

    struct inscripcion aux;
    int dni_baja,pos_baja;

    cout<< "DNI: ";
    cin>> dni_baja;

    pos_baja= buscarpos_inscripcion(dni_baja);

    aux= obtener_datos_inscripcion(pos_baja);
    aux.inscr_activa=false;

    modificar_reg_inscripcion(aux,pos_baja);

    if (modificar_reg_inscripcion(aux,pos_baja)==true)
    {
        cout<< "sesion dada de baja"<<endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {

        cout<< "la sesion no pudo darse de baja"<<endl;
        system("pause");
        system("cls");
        return;
    }

}

int buscarpos_inscripcion (int dniBaja)
{
    FILE *puntero;
    struct inscripcion aux;
    int pos=0;

    puntero=fopen("Inscripciones.dat","rb");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo 1!!";
        return(-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {

        if(dniBaja==aux.dni)
        {
            fclose(puntero);
            return pos;

        }
        pos++;
    }
    fclose(puntero);
    return -1;
}

struct inscripcion obtener_datos_inscripcion(int pos)
{

    FILE *puntero;
    struct inscripcion aux;

    puntero=fopen("Inscripciones.dat","rb");
    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit(-1);
    }
    fseek(puntero,pos*sizeof aux,SEEK_SET);

    fread(&aux,sizeof aux,1,puntero);
    fclose(puntero);
///revisar
    return aux;

};

bool modificar_reg_inscripcion(struct inscripcion aux,int pos)
{

    FILE *puntero;

    puntero= fopen("Inscripciones.dat", "rb+");
    if (puntero==NULL)
    {
        cout<< "error en modificar reg inscripcion";
        return false;

    }
    fseek(puntero,sizeof aux*pos,SEEK_SET);
    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return true;

}

void modificar_registro_Tparticipacion()
{

    int dni_modf,pos_mod;
    struct inscripcion aux;
    cout<< "DNI: ";
    cin>> dni_modf;

    pos_mod = buscarpos_inscripcion(dni_modf);
    aux= obtener_datos_inscripcion(pos_mod);

    if (aux.t_participacion==1)
    {
        aux.t_participacion=2;
        modificar_reg_inscripcion(aux,pos_mod);

    }
    else
    {
        if (aux.t_participacion==2)
        {
            aux.t_participacion=1;
            modificar_reg_inscripcion(aux,pos_mod);
        }
        else
        {
            cout<< "error de compilacion : -1"<<endl;
            system("pause");
            return;
        }

    }

    if (modificar_reg_inscripcion(aux,pos_mod)==true)
    {
        cout<< "tipo de participacion modificada!"<<endl;
        system("pause");
        system("cls");
        return;
    }
    else
    {

        cout<< "error al modificar la participacion "<<endl;
        system("pause");
        system("cls");
        return;
    }


}
int listados_inscriptos (){
int op=1;
while (op!=0){
cout<< "menu listados inscriptos: "<<endl;
cout<< "=============================="<<endl;
cout<< "1. Listado secuencial: "<<endl;
cout<< "2. Listar 1 sola inscripto: "<<endl;
cout<< "3. Listado ordenado por sesion:"<<endl;
cout<< "0. volver al menu anterior: "<<endl;
cout<< "-------------------------------------"<<endl;
cout<< "ingrese opcion: ";
cin>> op;
system("cls");
switch(op){

case 1:
    listado_inscriptoSecuencial();
    break;
case 2:
    listado_inscripto1Solo();
    break;
case 3:
    listado_inscriptOrdenado();
    break;
case 0:
    return 0;
    break;

}

}

}


void listado_inscriptoSecuencial ()
{

    struct inscripcion aux;
    FILE *puntero;

    puntero=fopen("Inscripciones.dat","rb");

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if (aux.inscr_activa==true)
        {
            cout<< "Numero de sesion: " <<aux.n_sesion <<endl;
            cout<< "DNI: " <<aux.dni <<endl;
            cout<< "Tipo de participacion: " <<aux.t_participacion <<endl;
            cout<< endl;
            cout<< "-------------------------------------------"<<endl;
        }
    }

    fclose(puntero);
    system("pause");
    system("cls");

}

void listado_inscripto1Solo(){

FILE *puntero;
int dni;
struct inscripcion aux;

puntero=fopen("Inscripciones.dat","rb");

if (puntero==NULL){
    cout<< "errror al abrir el archivo";
    return;
}

cout<< "ingrese NUM. de dni a buscar: " <<endl;
cin>>dni;

while (fread(&aux,sizeof aux,1,puntero)==1) {
    if (aux.dni==dni){
        listar1_inscripcion(aux);
    }
}
fclose(puntero);
system("pause");
system("cls");
return;

}

void listar1_inscripcion(struct inscripcion aux) {

 if (aux.inscr_activa==true)
        {
            cout<< "Numero de sesion: " <<aux.n_sesion <<endl;
            cout<< "DNI: " <<aux.dni <<endl;
            cout<< "Tipo de participacion: " <<aux.t_participacion <<endl;
            cout<< endl;
            cout<< "-------------------------------------------"<<endl;
        }

}


void listado_inscriptOrdenado() {

struct inscripcion *pInscripto;
int cantReg,i;

cantReg=contar_reg_inscriptos();
pInscripto= (struct inscripcion *) malloc(cantReg*sizeof (struct inscripcion));

if (pInscripto==NULL) {
    cout<< "Error al asignar la memoria!!"<<endl;
    return;
}

for (i=0;i<cantReg;i++){
    pInscripto [i]= obtener_datos_inscripcion(i);
}

OrdenarVecInscriptos (pInscripto,cantReg);

for (i=0;i<cantReg;i++){
    listar1_inscripcion(pInscripto[i]);
}
free(pInscripto);
system("pause");
system("cls");

}

int contar_reg_inscriptos ()
{
    FILE *puntero;

    int tamanio;
    puntero = fopen("Inscripciones.dat", "rb");

    if (puntero==NULL)
    {

        return 0;
    }

    fseek(puntero,0,2);

    tamanio= ftell(puntero) / sizeof (struct inscripcion);
    fclose(puntero);
///cout<< "ftell: " <<ftell(puntero);
///cout<< "tamanio: " <<tamanio<<endl;
    return tamanio;

}
void OrdenarVecInscriptos (struct inscripcion *pInscripto,int cantReg){

struct inscripcion aux;
  int i, j, posmin;
  for(i=0;i<cantReg-1;i++){
    posmin=i;
    for(j=i+1;j<cantReg;j++){
      if(pInscripto[j].n_sesion<pInscripto[posmin].n_sesion)
        posmin=j;
      }
    aux=pInscripto[i];
    pInscripto[i]=pInscripto[posmin];
    pInscripto[posmin]=aux;
    }
}


///acasssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
///acasssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssssss
///---------------------
///parte3
///---------------------

int menu_configuracion ()
{

    int op=1;

    while (op!=0)
    {
        cout<< "menu configuracion:"<<endl;
        cout<< "=====================" <<endl;
        cout << "1) Realizar backup de los archivos:" <<endl;
        cout<< "2) Restaurar los archivos: "<<endl;
        cout<< "3) Restaurar datos de inicio:" <<endl;
        cout<< "4) Recuperar registros borrados de musicos: "<<endl;
        cout<< "5) Recuperar registros borrados de sesiones"<< endl;
        cout<< "6) MOSTRAR LOS BKP"<<endl;
        cout<< "0) Volver al menu principal"<<endl;
        cout<< "---------------------"<<endl;
        cout<< "Seleccione una opcion: "<<endl;
        cin>> op;

        system("cls");


        switch (op)
        {

        case 1:

            backup_todo();

            break;

        case 2:

            restaurar_todo();
            break;
        case 3:
            restaurar_inicio();

            break;
        case 4:
            recuperar_Musicos ();
            break;
        case 5:
            recuperar_sesion ();
            break;
        case 6:
            mostrarBkp();
            break;
        case 0:
            system("cls");

            return 0;
            break;

        }

    }

}

void backup_todo()
{

    bool musicos_correcto,sesiones_correcto, inscripcion_correcto;

    musicos_correcto=bu_musicos();

    sesiones_correcto=bu_sesiones();

    inscripcion_correcto=bu_inscripcion();

    if (musicos_correcto==true)
    {
        cout<< "musicos.bkp realizado con exito"<<endl;
    }
    if (sesiones_correcto==true)
    {
        cout<< "sesiones.bkp realizado con exito"<<endl;
    }
    if (inscripcion_correcto==true)
    {
        cout<< "inscripcion.bkp realizado con exito"<<endl;
    }
    system("pause");
    system("cls");
}

bool bu_musicos()
{
    FILE *puntero;
    struct datos_musicos aux;
    puntero=fopen("musicos.dat","rb");
    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        bkp_musicos(aux);
    }
    fclose(puntero);
    return true;
}

void bkp_musicos(struct datos_musicos aux)
{
    FILE *puntero;
    puntero=fopen("musicos.bkp","ab");

    if (puntero==NULL)
    {
        cout<< "error al realizar bkp1!!"<<endl;
        return;
    }

    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;
}

bool bu_sesiones()
{
    FILE *puntero;
    struct sesiones aux;
    puntero=fopen("Sesiones.dat","rb");

    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        bkp_sesiones(aux);
    }
    fclose(puntero);
    return true;

}

void bkp_sesiones(struct sesiones aux)
{
    FILE *puntero;

    puntero=fopen("Sesiones.bkp","ab");

    if (puntero==NULL)
    {
        cout<< "error al realizar bkp2!!"<<endl;
        return;
    }

    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;
}

bool bu_inscripcion()
{

    FILE *puntero;
    struct inscripcion aux;
    puntero=fopen("Inscripciones.dat","rb");

    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        bkp_inscripcion(aux);
    }
    fclose(puntero);
    return true;
}

void bkp_inscripcion(struct inscripcion aux)
{
    FILE *puntero;

    puntero=fopen("Inscripciones.bkp","ab");

    if (puntero==NULL)
    {
        cout<< "error al realizar bkp3!!"<<endl;
        return;
    }

    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;
}

void restaurar_todo ()
{

    bool musicos_correcto,sesiones_correcto, inscripcion_correcto;

    musicos_correcto=restaurar_musicos();

    sesiones_correcto=restaurar_sesiones();

    inscripcion_correcto=restaurar_inscripciones();

    if (musicos_correcto==true)
    {
        cout<< "musicos.dat RESTAURADO con exito"<<endl;
    }
    if (sesiones_correcto==true)
    {
        cout<< "Sesiones.dat RESTAURADO con exito"<<endl;
    }
    if (inscripcion_correcto==true)
    {
        cout<< "Inscripcion.dat RESTAURADO con exito"<<endl;
    }
    system("pause");
    system("cls");


}

bool restaurar_musicos()
{
    FILE *puntero;
    struct datos_musicos aux;
    bool pr=false;
    puntero=fopen("musicos.bkp","rb");
    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        if (pr==false)
        {
            pr=true;
            vaciar_archivoM(aux);
        }
        else
        {
            devolver_Omusicos(aux);
        }
    }
    fclose(puntero);
    return true;
}

void devolver_Omusicos(struct datos_musicos aux)
{
    FILE *puntero;
    puntero=fopen("musicos.dat","ab");

    if (puntero==NULL)
    {
        cout<< "error al restaurar!!"<<endl;
        return;
    }

    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;
}

void vaciar_archivoM(struct datos_musicos aux)
{
    FILE *puntero;

    puntero=fopen("musicos.dat","wb");
    if (puntero==NULL)
    {
        cout<< "error al restaurar2"<<endl;
        return;
    }
    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;
}

bool restaurar_sesiones()
{
    FILE *puntero;
    struct sesiones aux;
    bool pr=false;
    puntero=fopen("Sesiones.bkp","rb");
    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        if (pr==false)
        {
            pr=true;
            vaciar_archivoS(aux);
        }
        else
        {
            devolver_Osesiones(aux);
        }
    }
    fclose(puntero);
    return true;
}

void devolver_Osesiones(struct sesiones aux)
{
    FILE *puntero;
    puntero=fopen("Sesiones.dat","ab");

    if (puntero==NULL)
    {
        cout<< "error al restaurar!!"<<endl;
        return;
    }

    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;
}

void vaciar_archivoS(struct sesiones aux)
{
    FILE *puntero;

    puntero=fopen("Sesiones.dat","wb");
    if (puntero==NULL)
    {
        cout<< "error al restaurar2"<<endl;
        return;
    }
    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;

}

bool restaurar_inscripciones()
{
    FILE *puntero;
    struct inscripcion aux;
    bool pr=false;
    puntero=fopen("Inscripciones.bkp","rb");
    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        if (pr==false)
        {
            pr=true;
            vaciar_archivoI(aux);
        }
        else
        {
            devolver_Oinscripciones(aux);
        }
    }
    fclose(puntero);
    return true;
}

void devolver_Oinscripciones(struct inscripcion aux)
{
    FILE *puntero;
    puntero=fopen("Inscripciones.dat","ab");

    if (puntero==NULL)
    {
        cout<< "error al restaurar!!"<<endl;
        return;
    }

    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;
}

void vaciar_archivoI(struct inscripcion aux)
{
    FILE *puntero;

    puntero=fopen("Inscripciones.dat","wb");
    if (puntero==NULL)
    {
        cout<< "error al restaurar2"<<endl;
        return;
    }
    fwrite(&aux,sizeof aux,1,puntero);
    fclose(puntero);
    return;

}

void restaurar_inicio(){

 bool musicos_correcto,sesiones_correcto, inscripcion_correcto;

    musicos_correcto=restaurar_musicosI();

    sesiones_correcto=restaurar_sesionesI();

    inscripcion_correcto=restaurar_inscripcionesI();

    if (musicos_correcto==true)
    {
        cout<< "musicos.dat RESTAURADO a INICIO con exito"<<endl;
    }
    if (sesiones_correcto==true)
    {
        cout<< "Sesiones.dat RESTAURADO a INICIO con exito"<<endl;
    }
    if (inscripcion_correcto==true)
    {
        cout<< "Inscripcion.dat RESTAURADO a INICIO con exito"<<endl;
    }
    system("pause");
    system("cls");
}

bool restaurar_musicosI()
{
    FILE *puntero;
    struct datos_musicos aux;
    bool pr=false;
    puntero=fopen("musicos.bkp2","rb");
    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        if (pr==false)
        {
            pr=true;
            vaciar_archivoM(aux);
        }
        else
        {
            devolver_Omusicos(aux);
        }
    }
    fclose(puntero);
    return true;
}

bool restaurar_sesionesI()
{
    FILE *puntero;
    struct sesiones aux;
    bool pr=false;
    puntero=fopen("Sesiones.bkp","rb");
    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        if (pr==false)
        {
            pr=true;
            vaciar_archivoS(aux);
        }
        else
        {
            devolver_Osesiones(aux);
        }
    }
    fclose(puntero);
    return true;
}

bool restaurar_inscripcionesI()
{
    FILE *puntero;
    struct inscripcion aux;
    bool pr=false;
    puntero=fopen("Inscripciones.bkp","rb");
    if (puntero==NULL)
    {
        return false;
    }
    while(fread(&aux,sizeof aux,1,puntero )==1)
    {
        if (pr==false)
        {
            pr=true;
            vaciar_archivoI(aux);
        }
        else
        {
            devolver_Oinscripciones(aux);
        }
    }
    fclose(puntero);
    return true;
}

void recuperar_Musicos () {

int dni,pos_busc;
struct datos_musicos aux;

cout<< "DNI a recuperar: ";
cin>> dni;

pos_busc= buscarpos_musico(dni );
    aux= obtener_datos(pos_busc);

    aux.situacion=true;


    if (modificar_registro(aux,pos_busc)==true)
    {

        cout<< "REGISTRO DADO DE ALTA NUEVAMENTE"<<endl;

    }
    else
    {

        cout << "NO SE PUDO DAR DE ALTA"<<endl;
    }



    system("pause");
    system("cls");

}

void recuperar_sesion (){

int sesion,possesion;
struct sesiones aux;

    cout<< "ingrese sesion a dar de alta: "<<endl;
    cin>> sesion;

    possesion=buscarpos_sesion(sesion);

    aux= obtener_datos_sesiones(possesion);

    aux.sesion_activa=true;

    if (modificar_reg_sesiones(aux,possesion)==true)
    {
        cout<< "sesion dada de ALTA"<<endl;
        system("pause");
        system("cls");
    }
    else
    {

        cout<< "la sesion no pudo darse de ALTA" <<endl;
        system("pause");
        system ("cls");
    }


}

void mostrarBkp()
{
    int op=1;

    while (op!=0)
    {
        cout<< "1) listar musicosbkp"<<endl;
        cout<< "2) listar sesionesbkp"<<endl;
        cout<< "3) listar inscriptosbkp" <<endl;
        cout<< "ingrese opcion:"<<endl;
        cin>>op;
        system ("cls");
        switch(op)
        {

        case 1:
            listado_musicosBkp ();

            break;
        case 2:
            listado_sesionesBkp();
            break;
        case 3:
            listado_inscriptosBkp ();

            break;
        case 0:
            return;
            break;

        }

    }
}
void listado_inscriptosBkp ()
{

    struct inscripcion aux;
    FILE *puntero;

    puntero=fopen("Inscripciones.bkp2","rb");

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if (aux.inscr_activa==true)
        {
            cout<< "Numero de sesion: " <<aux.n_sesion <<endl;
            cout<< "DNI: " <<aux.dni <<endl;
            cout<< "Tipo de participacion: " <<aux.t_participacion <<endl;
            cout<< endl;
            cout<< "-------------------------------------------"<<endl;
        }
    }

    fclose(puntero);
    system("pause");
    system("cls");

}

void listado_musicosBkp ()
{
    FILE *puntero;
    struct datos_musicos aux;

    puntero=fopen("musicos.bkp2","rb");
    if (puntero==NULL)
    {
        cout << "!!error al abrir el archivo!!";
        exit(-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if (aux.situacion==true)
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


            system("pause");
            system("cls");
        }
    }

    fclose(puntero);
}

void listado_sesionesBkp()
{
    FILE *puntero;
    struct sesiones aux;
    puntero=fopen("Sesiones.bkp2","rb");

    if (puntero==NULL)
    {
        cout<< "!!error al abrir el archivo2!!";
        exit (-1);
    }

    while (fread(&aux,sizeof aux,1,puntero)==1)
    {
        if(aux.sesion_activa==true)
        {
            cout<< "NUMERO DE SESION: "<<aux.Num_sesion <<endl;
            cout<< "FECHA DE SESION: " <<aux.f_sesiones.dia <<"/" <<aux.f_sesiones.mes <<"/" <<aux.f_sesiones.anio <<endl;
            cout<< "HORARIO: " <<aux.Hora_de_inicio <<" a " <<aux.Hora_de_fin <<endl;
            cout<< "INSTRUMENTO DE SESION: "<<aux.Instrumento_sesion <<endl;
            cout<< "COORDINADOR (DNI): " <<aux.coordinador <<endl;///(DNI del músico que coordinará la sesión)
            cout<< "URL: " <<aux.URL <<endl; ///de la reunión ///(cadena de 40 caracteres)
            cout<<endl;
            cout<< "----------------------------------"<<endl;
            cout<<endl;
        }

    }
    fclose(puntero);
    system("pause");
    system("cls");
}

#endif // FUNCIONESMUSICOS_H_INCLUDED
