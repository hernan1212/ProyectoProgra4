#ifndef _CONTROLDATOS_H_
#define _CONTROLDATOS_H_
#include "Persona.h"
#include "Juego.h"
#include "Partida.h"
Usuario* LeerUsuariosBin(int *numUsers);
Administrador* LeerAdministradoresBin(int *numAdmins);
Juego* LeerJuegosBin(int *numJuegos);
pAhorcado* LeerPartidasBin(int *numPa);
pCalc* LeerPartidasCBin(int *numPc);
int escribirUsuariosBin(Usuario* users, int len);
int escribirAdministradoresBin(Administrador* admins, int len);
int escribirJuegosBin(Juego* juegos, int len);
int escribirPartidasBin(pAhorcado* pa, int len);
int escribirPartidasCBin(pCalc* pc, int len);
int LeerDatostxt(char* nombrefic);
int EscribirDatostxt(char* nombrefic);
void clearifneeded(char* str);

#endif