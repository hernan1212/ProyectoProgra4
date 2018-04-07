#ifndef _PARTIDA_H_
#define _PARTIDA_H_
#include "Persona.h"
typedef struct
{
	Persona Jugador;
	int PartidasJugadas;
	int PartidasGanadas;
}pAhorcado;
void MostrarPartidaAhorcado(pAhorcado p);
#endif