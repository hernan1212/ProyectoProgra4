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

	printf("Has decidido iniciar sesion,\n");
	printf("Inserte el nick: ");
	scanf("%s",&pers.nick);
	printf("Inserte la contrasena: ");
	scanf("%s",&pers.contra);
	control1=LeerUsuariosBin(users);
	control2=LeerAdministradoresBin(admins);
	i=0;
	while(control1>i)
	{
		if(strcmp(users[i].pers.nick,pers.nick)==0&&strcmp(users[i].pers.contra,pers.contra)==0)
		{
			if(users[i].bloq)
			{
				printf("Lo siento, ha sido bloqueado indefinidamente.\n");
				return 0;
			}
			free(users);
			free(admins);
			return MenuU(users[i]);
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
			return MenuA(admins[i]);
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
	bool bienhecho;
	bool posible;
	
	printf("Has decidido registrarte,\n");
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
		posible=true;
		printf("Inserte el nick del usuario (de 1 a 14 caracteres): ");
		scanf("%s",&pers.nick);	
		i=0;
		while(control1>i)
		{
		if(strcmp(pers.nick,users[i].pers.nick)==0)
		{
			printf("El nick ya existe.\n");
			bienhecho=false;
		}

		i++;

		}

		i=0;

		while(control2>i)
		{
		if(strcmp(pers.nick,admins[i].pers.nick)==0)
		{
			printf("El nick ya existe.\n");
			bienhecho=false;
		}

		i++;
		}
		if(strlen(pers.nick)>14)
		{
			printf("El nick es demasiado largo.\n");
			posible=false;
		}
		}while(bienhecho==false||posible==false);
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte la contrasena del usuario (de 1 a 14 caracteres): ");
			scanf("%s",&pers.contra);
			if(strlen(pers.contra)>14)
			{
				printf("La contrasena es demasiado larga.\n");
				posible=false;
			}

		}
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte el nombre del usuario (de 1 a 14 caracteres): ");
			scanf("%s",&pers.nombre);
			if(strlen(pers.nombre)>14)
			{
				printf("El nombre es demasiado largo.\n");
				posible=false;
			}

		}
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte el apellido del usuario (de 1 a 14 caracteres): ");
			scanf("%s",&pers.apellido);
			if(strlen(pers.apellido)>14)
			{
				printf("El apellido es demasiado largo.\n");
				posible=false;
			}

		}
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte la edad del usuario (de 1 a 100 anos): ");
			if(scanf("%i",&pers.edad)!=1||pers.edad<1||pers.edad>100)
			{
				printf("La edad no cumple las condiciones.\n");
				posible=false;
			}
			while (getchar() != '\n');
		}
		usu.pers=pers;
		usu.bloq=false;
		users[control1]=usu;

		escribirUsuariosBin(users,control1+1);
		free(users);
		free(admins);
		return MenuU(usu);

	}
	else if(opcionRegistro)
	{
		Administrador admin;
		printf("Has elegido registrarte como un administrador.\n");
		
		do
		{
		bienhecho=true;
		posible=true;
		printf("Inserte el nick del administrador (de 1 a 14 caracteres): ");
		scanf("%s",&pers.nick);	
		i=0;
		while(control1>i)
		{
		if(strcmp(pers.nick,users[i].pers.nick)==0)
		{
			printf("El nick ya existe.\n");
			bienhecho=false;
		}

		i++;

		}

		i=0;

		while(control2>i)
		{
		if(strcmp(pers.nick,admins[i].pers.nick)==0)
		{
			printf("El nick ya existe.\n");
			bienhecho=false;
		}

		i++;
		}
		if(strlen(pers.nick)>14)
		{
			printf("El nick es demasiado largo.\n");
			posible=false;
		}
		}while(bienhecho==false);
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte la contrasena del administrador (de 1 a 14 caracteres): ");
			scanf("%s",&pers.contra);
			if(strlen(pers.contra)>14)
			{
				printf("La contrasena es demasiado larga.\n");
				posible=false;
			}

		}
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte el nombre del administrador (de 1 a 14 caracteres): ");
			scanf("%s",&pers.nombre);
			if(strlen(pers.nombre)>14)
			{
				printf("El nombre es demasiado largo.\n");
				posible=false;
			}

		}
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte el apellido del administrador (de 1 a 14 caracteres): ");
			scanf("%s",&pers.apellido);
			if(strlen(pers.apellido)>14)
			{
				printf("El apellido es demasiado largo.\n");
				posible=false;
			}

		}
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte la edad del administrador (de 1 a 100 anos): ");
			if(scanf("%i",&pers.edad)!=1||pers.edad<1||pers.edad>100)
			{
				printf("La edad no cumple las condiciones.\n");
				posible=false;
			}
			while (getchar() != '\n');
		}
		posible=false;
		bienhecho=false;
		while(posible==false||bienhecho==false)
		{
			posible=true;
			bienhecho=true;
			printf("Inserte el codigo del administrador (debe tener 5 caracteres): ");
			scanf("%s",&admin.cod_administrador);
			i=0;

			while(control2>i)
			{
				if(strcmp(admin.cod_administrador,admins[i].cod_administrador)==0)
				{
					printf("El nick ya existe.\n");
					bienhecho=false;
				}

			i++;
			}
			if(strlen(admin.cod_administrador)!=5)
			{
				printf("El codigo de administrador no cumple las condiciones.\n");
				posible=false;
			}
		}
		admin.pers=pers;
		admins[control2]=admin;
		escribirAdministradoresBin(admins,control2+1);
		free(users);
		free(admins);
		return MenuA(admin);
	}
}