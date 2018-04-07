#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "controlDatos.h"
#include "Persona.h"



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
int LeerUsuariosBin(Usuario* users)
{
  FILE * f;	
  int numUsers;
  int i;

  f = fopen("Users.dat", "rb");
	
	if(f == NULL)
	{
		//printf("No hay usuarios registrados\n");
		return 0;
	}
  numUsers = fgetc(f);

  fread(users, sizeof(Usuario), numUsers, f);
  for (i = 0; i < numUsers; i++)
    {
		//printf("%s\n",&users[i].pers.nick);
    }

  fclose(f);	
 
  return numUsers;
}
int LeerAdministradoresBin(Administrador* admins)
{
  FILE * f;	
  int numAdmins;
  int i;

  f = fopen("Admins.dat", "rb");
	if(f == NULL)
	{
		//printf("No hay administradores registrados\n");
		return 0;
	}

  numAdmins = fgetc(f);

  fread(admins, sizeof(Administrador), numAdmins, f);

  for (i = 0; i < numAdmins; i++)
    {
      //printf("%s\n",&admins[i].pers.nick);
    }


  fclose(f);	

  return numAdmins;

}
int LeerJuegosBin(Juego* juegos)
{
  FILE * f;	
  int numJuegos;
  int i;

  f = fopen("Juegos.dat", "rb");
	if(f == NULL)
	{
		//printf("No hay juegos registrados\n");
		return 0;
	}

  numJuegos = fgetc(f);

  fread(juegos, sizeof(Juego), numJuegos, f);

  for (i = 0; i < numJuegos; i++)
    {
      //printf("%s\n",&juegos[i].nombre);
    }


  fclose(f);	

  return numJuegos;


}
int LeerPartidasBin(pAhorcado* pa)
{
  FILE * f;	
  int numPa;
  int i;

  f = fopen("pAhorcado.dat", "rb");
	if(f == NULL)
	{
		//printf("No hay juegos registrados\n");
		return 0;
	}

  numPa = fgetc(f);

  fread(pa, sizeof(pAhorcado), numPa, f);

  for (i = 0; i < numPa; i++)
    {
      //printf("%s\n",&juegos[i].nombre);
    }


  fclose(f);	

  return numPa;


}
int escribirUsuariosBin(Usuario* users, int len)
{
	FILE* f;
	f=fopen("Users.dat", "wb");
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

	f=fopen("Admins.dat", "wb");
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

	f=fopen("Juegos.dat", "wb");
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

	f=fopen("pAhorcado.dat", "wb");
//escribir la cantidad de elementos
  fputc(len, f); 

  //escribir datos binarios
  fwrite(pa, sizeof(pAhorcado), len, f);
  fclose(f);
  return 0;
}