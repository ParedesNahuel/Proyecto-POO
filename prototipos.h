#ifndef PROTOTIPOS_H_INCLUDED
#define PROTOTIPOS_H_INCLUDED

///---------------------
///parte1
///---------------------
int menu_musicos();
void Alta_musicos();
void Baja_musicos();
void modificar_registro_mail();
int buscarpos_musico(int );
struct datos_musicos obtener_datos(int );
bool modificar_registro (struct datos_musicos ,int );
void listar1_musico(struct datos_musicos );

int listados_musicos();

void listado_musico1Solo();
void listado_musicoSecuencial ();
void listado_musicosOrdenado ();
int canRegMusicos();
void OrdenarVecMusico (struct datos_musicos *,int);

///---------------------
///parte2
///---------------------

int menu_sesiones ();
int contar_reg_sesiones ();
void Alta_sesiones();
bool comprobar_musico(int );
bool no_repetir_sesion (struct sesiones aux);
void cargar_datos_sesiones (struct sesiones aux);
void baja_sesiones ();
int buscarpos_sesion(int sesion_baja);
struct sesiones obtener_datos_sesiones(int x);
bool modificar_reg_sesiones(struct sesiones aux,int pos);
void modificar_registro_URL();

int listados_sesiones();
void listado_sesioneSecuencial();
void listado_sesiones1Solo();
void listar1_sesion(struct sesiones);
void listado_sesionesOrdenado ();
void OrdenarVecSesiones (struct sesiones *,int );


int menu_inscripcion ();
void Alta_inscripcion ();
int comprobar_instrumento_musico(int x);
int comprobar_inst_sesion (int x) ;
bool comprobar_1solo(int x,int);
void registrar_inscripcion(struct inscripcion aux);
void Baja_inscripcion();
int buscarpos_inscripcion (int dniBaja);
struct inscripcion obtener_datos_inscripcion(int pos);
bool modificar_reg_inscripcion(struct inscripcion aux,int pos);
void modificar_registro_Tparticipacion();

int listados_inscriptos ();
void listado_inscriptoSecuencial();
void listar1_inscripcion(struct inscripcion aux);
void listado_inscripto1Solo();
int contar_reg_inscriptos ();
void listado_inscriptOrdenado();
void OrdenarVecInscriptos (struct inscripcion *,int cantReg);

///---------------------
///parte3
///---------------------

bool menor_mayora(int,int,int);
bool fecha_mayora (int dia,int mes,int anio);
bool fecha_menor(int dia, int mes,int anio);

void backup_todo();
bool bu_musicos();
void bkp_musicos(struct datos_musicos aux);
bool bu_sesiones();
void bkp_sesiones(struct sesiones aux);
bool bu_inscripcion();
void bkp_inscripcion (struct inscripcion aux);

void restaurar_todo ();

bool restaurar_musicos();
void vaciar_archivoM(struct datos_musicos aux);
void devolver_Omusicos(struct datos_musicos aux);

bool restaurar_sesiones();
void devolver_Osesiones(struct sesiones aux);
void vaciar_archivoS(struct sesiones aux);

bool restaurar_inscripciones();
void devolver_Oinscripciones(struct inscripcion aux);
void vaciar_archivoI(struct inscripcion aux);

void restaurar_inicio();
bool restaurar_musicosI();
bool restaurar_sesionesI();
bool restaurar_inscripcionesI();

void mostrarBkp();
void listado_inscriptosBkp ();
void listado_musicosBkp ();
void listado_sesionesBkp();

void recuperar_Musicos ();
void recuperar_sesion ();



#endif // PROTOTIPOS_H_INCLUDED
