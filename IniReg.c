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
				printf("Lo siento, ha sido bloqueado indefinidamente.");
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
	int *opcionRegistro; 
	int control1;
	int control2;
	bool bienhecho;
	bool posible;
	
	printf("Has decidido registrarte,\n");
	printf("Elige una opcion:\n 1.- Si deseas registrarte como un usuario. \n 2.- Si deseas registrarte como un administrador. \n");
	opcionRegistro=malloc(sizeof(int));
	while(LeerValorInt(opcionRegistro)==-1||(*opcionRegistro<1||*opcionRegistro>2))
	{
		printf(" Te has confundido. Vuelve a elegir una opcion:\n 1.- Si deseas registrarte como un usuario. \n 2.- Si deseas registrarte como un administrador. \n");
	}
  	users = (Usuario*)malloc(30 * sizeof(Usuario));	
  	admins = (Administrador*)malloc(15 * sizeof(Administrador));	
	control1=LeerUsuariosBin(users);
	control2=LeerAdministradoresBin(admins);

	if(*opcionRegistro==1)
	{
		Usuario usu;
		printf("Has elegido registrarte como un usuario.\n");

		do
		{
			bienhecho=true;
			printf("Inserte el nick del usuario (de 1 a 14 caracteres): ");
			if(LeerValor(pers.nick,14)==-1)
			{

				printf("El nick no es adecuado.\n");
				bienhecho=false;
			}
			for(int i=0;control1>i;i++)
			{
				if(strcmp(pers.nick,users[i].pers.nick)==0)
				{
					printf("El nick ya existe.\n");
					bienhecho=false;
				}
			}

			for(int i=0;control2>i;i++)
			{
				if(strcmp(pers.nick,admins[i].pers.nick)==0)
				{
					printf("El nick ya existe.\n");
					bienhecho=false;
				}
			}
		}while(bienhecho==false);

		printf("Inserte la contrasena del usuario (de 1 a 14 caracteres): ");
		while(LeerValor(pers.contra,14)==-1)
		{
			printf("La contrasena no es adecuada.\n");
			printf("Inserte la contrasena del usuario (de 1 a 14 caracteres): ");
		}

		printf("Inserte el nombre del usuario (de 1 a 14 caracteres): ");
		while(LeerValor(pers.nombre,14)==-1)
		{
			printf("El nombre no es adecuado.\n");
			printf("Inserte el nombre del usuario (de 1 a 14 caracteres): ");
		}

		printf("Inserte el apellido del usuario (de 1 a 14 caracteres): ");
		while(LeerValor(pers.apellido,14)==-1)
		{
			printf("El apellido no es adecuado.\n");
			printf("Inserte el apellido del usuario (de 1 a 14 caracteres): ");
		}

		printf("Inserte la edad del usuario (de 1 a 100 anos): ");
		while(LeerValorInt(&pers.edad)||pers.edad<1||pers.edad>100)
		{
			printf("La edad no cumple las condiciones.\n");
			printf("Inserte la edad del usuario (de 1 a 100 anos): ");
		}
		usu.pers=pers;
		usu.bloq=false;
		users[control1]=usu;
		escribirUsuariosBin(users,control1+1);
		free(users);
		free(admins);
		return MenuU(usu);
	}
	else if(*opcionRegistro)
	{
		Administrador admin;
		printf("Has elegido registrarte como un administrador.\n");
		
		do
		{
		bienhecho=true;
		posible=true;
		printf("Inserte el nick del administrador (de 1 a 14 caracteres): ");
		scanf("%s",&pers.nick);	
		for(int i=0;control1>i;i++)
		{
		if(strcmp(pers.nick,users[i].pers.nick)==0)
		{
			printf("El nick ya existe.\n");
			bienhecho=false;
		}

		}

		for(int i=0;control2>i;i++)
		{
		if(strcmp(pers.nick,admins[i].pers.nick)==0)
		{
			printf("El nick ya existe.\n");
			bienhecho=false;
		}
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
			for(int i=0;control2>i;i++)
			{
				if(strcmp(admin.cod_administrador,admins[i].cod_administrador)==0)
				{
					printf("El nick ya existe.\n");
					bienhecho=false;
				}
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

int LeerValor(char * h, int lenMax)
{
	char* line=NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line, &len, stdin))) 
	{
		if(strlen(line)>lenMax||strcmp(line,"\n")==0)
		{	
   			return -1;
		}
		else
		{
			sscanf(line, "%s", h);
			return 0;
		}
  	}
}
int LeerValorInt(int* h)
{
	char* line=NULL;
	size_t len = 0;
	ssize_t read;

	while((read = getline(&line, &len, stdin))) 
	{
		if(sscanf(line, "%i", h)==1)
		{	
   			return 0;
		}
		else
		{
			return -1;
		}
  	}
}