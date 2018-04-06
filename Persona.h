#ifndef _PERSONA_H_
#define _PERSONA_H_
typedef struct
{
	char nick[10];
	char contra[10];
	char nombre[10];
	char apellido[10];
	int edad;
}Persona;
typedef struct{
	Persona pers;
}Usuario;
typedef struct{
	Persona pers;
	char cod_administrador[8];
}Administrador;
#endif