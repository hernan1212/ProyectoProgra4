#ifndef _PARTIDA_H_
#define _PARTIDA_H_
#include "Persona.h"
typedef struct
{
	Persona Jugador;
	int PartidasJugadas;
	int PartidasGanadas;
}pAhorcado;
typedef struct
{
	Persona Jugador;
	int PartidasJugadas;
	int PuntMax;
}pCalc;
void MostrarPartidaAhorcado(pAhorcado p);
void MostrarPartidaCalculadora(pCalc p);
#endif