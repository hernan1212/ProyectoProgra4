#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controlDatos.h"
#include "Persona.h"
#include "Partida.h"



int LeerDatostxt(char* nombrefic)
{
	FILE* f;

	f=fopen("hola.txt", "r");

	if(f == NULL)
	{
		printf("El archivo no se ha encontrado, o no existe\n");
		return -1;
	}
	char string[30];
	while(fgets(string, 20, f))
	{
		sscanf(string, "%s", string);

		clearifneeded(string);
	}
	

	return 0;

}
int EscribirDatostxt(char* nombrefic)
{
	FILE* f;

	f=fopen("hola.txt", "r");
}
void clearifneeded(char* str)
{
	if(str[strlen(str)-1]!='\n')
	{

	}
}
Usuario* LeerUsuariosBin(int * numUsers)
{
  FILE * f;	
  Usuario* users;
  int i;

  f = fopen("../extras/Users.dat", "rb");
	
	if(f == NULL)
	{
    *numUsers=0;
		users = (Usuario*)malloc(sizeof(Usuario)); 
		return users;
	}
  *numUsers = fgetc(f);
  users = (Usuario*)malloc((*numUsers+1) * sizeof(Usuario)); 
  fread(users, sizeof(Usuario), *numUsers, f);
  for (i = 0; i < *numUsers; i++)
    {
		//printf("%s\n",&users[i].pers.nick);
    }

  fclose(f);	
 
  return users;
}
Administrador* LeerAdministradoresBin(int * numAdmins)
{
  FILE * f;	
  Administrador* admins;
  int i;

  f = fopen("../extras/Admins.dat", "rb");
	if(f == NULL)
	{
		*numAdmins=0;
    admins = (Administrador*)malloc(sizeof(Administrador)); 
		return admins;
	}

  *numAdmins = fgetc(f);
  admins = (Administrador*)malloc((*numAdmins+1) * sizeof(Administrador)); 
  fread(admins, sizeof(Administrador), *numAdmins, f);

  for (i = 0; i < *numAdmins; i++)
    {
      //printf("%s\n",&admins[i].pers.nick);
    }


  fclose(f);	

  return admins;

}
Juego* LeerJuegosBin(int *numJuegos)
{
  FILE * f;	
  Juego* juegos;
  int i;

  f = fopen("../extras/Juegos.dat", "rb");
	if(f == NULL)
	{
		*numJuegos=0;
    juegos = (Juego*)malloc(sizeof(Juego)); 
    return juegos;
	}

  *numJuegos = fgetc(f);
  juegos = (Juego*)malloc((*numJuegos+1) * sizeof(Juego)); 
  fread(juegos, sizeof(Juego), *numJuegos, f);

  for (i = 0; i < *numJuegos; i++)
    {
      //printf("%s\n",&juegos[i].nombre);
    }


  fclose(f);	

  return juegos;


}
pAhorcado* LeerPartidasBin(int *numPa)
{
  FILE * f;	
  pAhorcado* pa;
  int i;

  f = fopen("../extras/pAhorcado.dat", "rb");
	if(f == NULL)
	{
		*numPa=0;
    pa = (pAhorcado*)malloc(sizeof(pAhorcado)); 
		return pa;
	}

  *numPa = fgetc(f);
  pa = (pAhorcado*)malloc((*numPa+1) * sizeof(pAhorcado)); 
  fread(pa, sizeof(pAhorcado), *numPa, f);

  for (i = 0; i < *numPa; i++)
    {
      //printf("%s\n",&juegos[i].nombre);
    }


  fclose(f);	

  return pa;


}

pCalc* LeerPartidasCBin(int *numPc)
{
  FILE * f; 
  pCalc* pc;
  int i;

  f = fopen("../extras/pCalculadora.dat", "rb");
  if(f == NULL)
  {
    *numPc=0;
    pc = (pCalc*)malloc(sizeof(pCalc)); 
    return pc;
  }

  *numPc = fgetc(f);
  pc = (pCalc*)malloc((*numPc+1) * sizeof(pCalc)); 
  fread(pc, sizeof(pCalc), *numPc, f);

  for (i = 0; i < *numPc; i++)
    {
      //printf("%s\n",&juegos[i].nombre);
    }


  fclose(f);  

  return pc;


}
int escribirUsuariosBin(Usuario* users, int len)
{
	FILE* f;
	f=fopen("../extras/Users.dat", "wb");

//escribir la cantidad de elementos
  fputc(len, f); 

  //escribir datos binarios
  fwrite(users, sizeof(Usuario), len, f);	
  fclose(f);
	return 0;
}

int escribirAdministradoresBin(Administrador* admins, int len)
{
	FILE* f;

	f=fopen("../extras/Admins.dat", "wb");
//escribir la cantidad de elementos
  fputc(len, f); 

  //escribir datos binarios
  fwrite(admins, sizeof(Administrador), len, f);
  fclose(f);
  return 0;
}
int escribirJuegosBin(Juego* juegos, int len)
{
	FILE* f;

	f=fopen("../extras/Juegos.dat", "wb");
//escribir la cantidad de elementos
  fputc(len, f); 

  //escribir datos binarios
  fwrite(juegos, sizeof(Juego), len, f);
  fclose(f);
  return 0;
}
int escribirPartidasBin(pAhorcado* pa, int len)
{
	FILE* f;

	f=fopen("../extras/pAhorcado.dat", "wb");
//escribir la cantidad de elementos
  fputc(len, f); 

  //escribir datos binarios
  fwrite(pa, sizeof(pAhorcado), len, f);
  fclose(f);
  return 0;
}
int escribirPartidasCBin(pCalc* pc, int len)
{
  FILE* f;

  f=fopen("../extras/pCalculadora.dat", "wb");
//escribir la cantidad de elementos
  fputc(len, f); 

  //escribir datos binarios
  fwrite(pc, sizeof(pCalc), len, f);
  fclose(f);
  return 0;
}