#ifndef _JUEGO_H_
#define _JUEGO_H_
typedef struct
{
	char nick[10];
	char contra[10];
	char nombre[10];
	char apellido[10];
	int edad;
}Juego;
void PrintJuego(Juego j);
#endif