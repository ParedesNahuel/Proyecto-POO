#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

struct datos_musicos
{

    int dni,tel,claustro,instrumento,tipo_music,dia,mes,anio;
    char nombre [50],apellido [50], mail[50];
    bool situacion;



};

struct fecha {

int dia,mes,anio;


};

struct sesiones{

int Num_sesion;
struct fecha f_sesiones;
int Hora_de_inicio;
int Hora_de_fin;
int Instrumento_sesion; ///(1 a 15 si se trata de un solo instrumento; 0 si puede participar cualquier instrumento)
char URL[40]; ///de la reunión ///(cadena de 40 caracteres)
int coordinador; ///(DNI del músico que coordinará la sesión)
bool sesion_activa;
};

struct inscripcion {

int dni;
int n_sesion;
int t_participacion;
bool inscr_activa;

};

#endif // TIPOS_H_INCLUDED
