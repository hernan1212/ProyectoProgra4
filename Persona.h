#ifndef _PERSONA_H_
#define _PERSONA_H_
typedef struct
{
	char nick[15];
	char contra[15];
	char nombre[15];
	char apellido[15];
	int edad;
}Persona;
typedef struct{
	Persona pers;
}Usuario;
typedef struct{
	Persona pers;
	char cod_administrador[8];
}Administrador;
void MostrarUsuario(Usuario u);
void MostrarAdmin(Administrador a);
#endif