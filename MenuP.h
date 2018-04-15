#ifndef _MENUP_H_
#define _MENUP_H_
#include "Persona.h"
#include "Partida.h"
#include "Juego.h"
#include <stdbool.h>
int MenuU(Usuario u);
int MenuA(Administrador a);
void ListaJuegos(Juego* j, int control1);
int Jugar(Juego* j, pAhorcado* p1, pCalc * p2, Persona p, int control1, int control2, int control3);
void PerfilU(Usuario u);
void PerfilA(Administrador a);
void Estadisticas(pAhorcado* p1, pCalc * p2, int control1, int control2);
int SubirJuego(Juego* j, Persona p, int control1);
void GestionAplicacion(Juego* j, int control1);
#endif