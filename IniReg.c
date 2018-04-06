#include "IniReg.h"
#include "ControlDatos.h"
#include "MenuP.h"
#include "Persona.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int IniciarSesion()
{
	int control1;
	int control2;	
	int i;
	Persona *personas;
	Usuario* users;
	Administrador* admins;
	Persona pers;
	users=(Usuario*)malloc(30*sizeof(Usuario));
	admins=(Administrador*)malloc(15*sizeof(Administrador));

	printf("Has decidido iniciar sesion\n");
	printf("Inserte el nick:");
	scanf("%s",&pers.nick);
	printf("Inserte la contraseña:");
	scanf("%s",&pers.contra);
	control1=LeerUsuariosBin(users);
	control2=LeerAdministradoresBin(admins);
	i=0;
	while(control1>i)
	{
		if(strcmp(users[i].pers.nick,pers.nick)==0&&strcmp(users[i].pers.contra,pers.contra)==0)
		{
			free(users);
			free(admins);
			return Menu(pers, false);
		}
		i++;
	}
	i=0;
	while(control2>i)
	{
		if(strcmp(admins[i].pers.nick,pers.nick)==0&&strcmp(admins[i].pers.contra,pers.contra)==0)
		{
			free(users);
			free(admins);
			return Menu(pers, true);
		}
		i++;
	}
	free(users);
	free(admins);
	return -1;
}
int Registrar()
{
	Usuario* users;
	Administrador* admins;
	Persona pers;
	int opcionRegistro; 
	int control1;
	int control2;
	int i;
	bool bienhecho=true;
	
	printf("Has decidido registrarte\n");
	printf("Elige una opcion:\n 1.- Si deseas registrarte como un usuario. \n 2.- Si deseas registrarte como un administrador. \n");
	scanf("%i",&opcionRegistro);
  	users = (Usuario*)malloc(30 * sizeof(Usuario));	
  	admins = (Administrador*)malloc(15 * sizeof(Administrador));	
	control1=LeerUsuariosBin(users);
	control2=LeerAdministradoresBin(admins);

	if(opcionRegistro==1)
	{
		Usuario usu;
		printf("Has elegido registrarte como un usuario.\n");

		do
		{
		bienhecho=true;

		printf("Inserte el nick del usuario:");
		scanf("%s",&pers.nick);	
		i=0;
		while(control1>i)
		{
		printf("%s\n",&users[i].pers.nick);
		if(strcmp(pers.nick,users[i].pers.nick)==0)
		{
			printf("%s\n",&users[i].pers.nick);
			printf("El nick ya existe\n");
			bienhecho=false;
		}

		i++;

		}

		i=0;

		while(control2>i)
		{
		if(strcmp(pers.nick,admins[i].pers.nick)==0)
		{
			printf("El nick ya existe\n");
			bienhecho=false;
		}

		i++;
		}
		}while(bienhecho==false);

		printf("Inserte la contraseña del usuario:");
		scanf("%s",&pers.contra);
		printf("Inserte el nombre del usuario:");
		scanf("%s",&pers.nombre);
		printf("Inserte el apellido del usuario:");
		scanf("%s",&pers.apellido);
		printf("Inserte la edad del usuario:");
		scanf("%i",&pers.edad);
		usu.pers=pers;
		users[control1]=usu;

		escribirUsuariosBin(users,control1+1);
		free(users);
		free(admins);
		return Menu(pers, false);

	}
	else if(opcionRegistro)
	{
		Administrador admin;
		printf("Has elegido registrarte como un administrador.\n");
		
		do
		{
		bienhecho=true;

		printf("Inserte el nick del administrador:");
		scanf("%s",&pers.nick);	
		i=0;
		while(control1>i)
		{
		if(strcmp(pers.nick,users[i].pers.nick)==0)
		{
			printf("%s\n",&users[i].pers.nick);
			printf("El nick ya existe\n");
			bienhecho=false;
		}

		i++;

		}

		i=0;

		while(control2>i)
		{
		if(strcmp(pers.nick,admins[i].pers.nick)==0)
		{
			printf("El nick ya existe\n");
			bienhecho=false;
		}

		i++;
		}
		}while(bienhecho==false);
		printf("Inserte la contraseña del administrador:");
		scanf("%s",&pers.contra);
		printf("Inserte el nombre del administrador:");
		scanf("%s",&pers.nombre);
		printf("Inserte el apellido del administrador:");
		scanf("%s",&pers.apellido);
		printf("Inserte la edad del administrador:");
		scanf("%i",&pers.edad);
		printf("Inserte el codigo del administrador:");
		scanf("%i",&admin.cod_administrador);
		admin.pers=pers;
		admins[control2]=admin;
		escribirAdministradoresBin(admins,control2+1);
		free(users);
		free(admins);
		return Menu(pers, true);
	}
}