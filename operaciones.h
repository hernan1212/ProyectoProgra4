#ifndef _OPERACIONES_H_
#define _OPERACIONES_H_
#include "Juego.h"
#include "Partida.h"
void OrdenarJuegoPorNombre(Juego* j, int Control);
void OrdenarJuegoPorPrecio(Juego* j, int Control);
void OrdenarAhorcadoPorPGanadas(pAhorcado* p, int Control);
void OrdenarCalculadoraPorPuntMax(pCalc* p, int Control);
#endif