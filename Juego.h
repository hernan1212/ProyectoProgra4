#ifndef _JUEGO_H_
#define _JUEGO_H_
#include "Persona.h"
typedef struct
{
	char nombre[15];
	char genero[15];
	Persona Creador;
	char ejecutable[20];
	int Precio;
}Juego;
void PrintJuego(Juego j);
#endif