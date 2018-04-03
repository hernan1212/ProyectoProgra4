#ifndef _MENUP_H_
#define _MENUP_H_
typedef struct{
	char *nick;
	char *contra;
	char *nombre;
	char *apellido;
	int edad;
}Persona;
typedef struct{
	Persona pers;
}Usuario;
typedef struct{
	Persona pers;
	char *cod_administrador;
}Administrador;
void ();
void Registrar();
#endif