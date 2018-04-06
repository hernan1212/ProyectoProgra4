#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Persona.h"
#include "Juego.h"
#include "ControlDatos.h"
#include "MenuP.h"

int MenuU(Usuario u)
{
	int opcion;
	int control;
	Juego* juegos;
	juegos=(Juego*)malloc(30*sizeof(Juego));
	control=LeerJuegosBin(juegos);
	do
	{
	printf("Bienvenido a aPointlessApplication: \n 1.- Lista de juegos \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.");
	scanf("%i",&opcion);

	
		switch(opcion)
		{
			case 1:
				ListaJuegos(juegos,control);
				break;
			case 2:
				Jugar(juegos, control);
				break;
			case 3:
				PerfilU(u);
				break;
			case 4:
				Estadisticas();
				break;
			case 5:
				control=SubirJuego(juegos, u.pers, control);
				break;			
			case 6:
				printf("Se cerrará la sesión.\n");
				return 0;
				break;
			case 7:
				return 1;
				break;
			default:
				while (scanf("%i", &opcion) != 1||(opcion<1||opcion>7)) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Lista de juegos \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.");
  					while (getchar() != '\n');
					 
 				}
				break;

		}

	}while(true);
}
int MenuA(Administrador a)
{
	int opcion;
	int control;
	Juego* juegos;
	juegos=(Juego*)malloc(30*sizeof(Juego));
	control=LeerJuegosBin(juegos);
	do
	{
	printf("Bienvenido a aPointlessApplication: \n 1.- Lista de juegos \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Gestion de la aplicacion.\n 7.- Cerrar sesion.\n 8.- Salir.");
	scanf("%i",&opcion);


		switch(opcion)
		{
			case 1:
				ListaJuegos(juegos, control);
				break;
			case 2:
				Jugar(juegos, control);
				break;
			case 3:
				PerfilA(a);
				break;
			case 4:
				Estadisticas();
				break;
			case 5:
				control=SubirJuego(juegos, a.pers, control);
				break;	
			case 6:
				GestionAplicacion();
				break;			
			case 7:
				printf("Se cerrará la sesión.\n");
				return 0;
				break;
			case 8:
				return 1;
				break;
			default:
				while (scanf("%i", &opcion) != 1||(opcion<1||opcion>8)) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Lista de juegos \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Gestion de la aplicacion.\n 7.- Cerrar sesion.\n 8.- Salir.");
  					while (getchar() != '\n');
					 
 				}
				break;

		}

	}while(true);
}

void ListaJuegos(Juego* j, int control1)
{
	int opcion;
	if(control1==0)
	{
		printf("No hay ningun juego introducido en la base de datos");
	}
	else
	{
	printf("Como quieres listar los juegos:\n 1.-Ordenar juegos por nombre de juego.\n 2.-Ordenarjuegos por precio del juego.");
	while (scanf("%i", &opcion) != 1||(opcion<1||opcion>2)) 
	{
   		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.-Ordenar juegos por nombre de juego.\n 2.-Ordenarjuegos por precio del juego.");
  		while (getchar() != '\n');	 
 	}
 	}
}
void Jugar(Juego* j, int control1)
{
	int opcion;
	if(control1==0)
	{
		printf("No hay ningun juego introducido en la base de datos");
	}
	else
	{
		printf("Eliga uno de los juegos:\n");
	
	for(int i=0;i<control1;i++)
	{
		printf("%i.-",i+1);
		PrintJuego(j[i]);
	}
	scanf("%i",&opcion);
	for(int i=0;i<control1;i++)
	{
		if(i==(opcion-1))
		{
			system("cls");
			//Para linux: system("clear"); 
			system(j[i].ejecutable);
			system("cls");

		}
	}
	}
}
void PerfilU(Usuario u)
{
printf("Este es tu perfil de usuario:\n");
MostrarUsuario(u);
}
void PerfilA(Administrador a)
{
printf("Este es tu perfil de administrador:\n");
MostrarAdmin(a);
}
void Estadisticas()
{

}
int SubirJuego(Juego* j,  Persona p, int control1)
{
	Juego ju;
	bool bienhecho;
	bool existe;
	int i;
	FILE*f;
	printf("Has decidido subir un juego.\n");
	do
	{
		bienhecho=true;
		printf("El nombre del juego es:");
		scanf("%s", &ju.nombre);
		i=0;
		while(control1>i)
		{
		if(strcmp(ju.nombre,j[i].nombre)==0)
		{
			printf("El nombre ya existe\n");
			bienhecho=false;
		}

		i++;

		}

	}while(bienhecho==false);
	printf("El genero del juego:");
	scanf("%s", &ju.genero);
	printf("El precio del juego:");
	scanf("%i", &ju.Precio);
	do
	{
	existe=true;
	bienhecho=true;
	printf("El ejecutable del juego es:");
	scanf("%s", &ju.ejecutable);
	i=0;
		while(control1>i)
		{
		if(strcmp(ju.ejecutable,j[i].ejecutable)==0)
		{
			printf("La aplicacion ya existe\n");
			bienhecho=false;
		}

		i++;

		}
		f = fopen(ju.ejecutable, "rb");
			if(f == NULL)
			{
				printf("La direccion no es correcta\n");
				existe=false;
			}
		fclose(f);

	}while(bienhecho==false||existe==false);

	j[control1]=ju;
	return control1+1;
}
void GestionAplicacion()
{

}