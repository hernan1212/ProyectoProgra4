#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Persona.h"
#include "Partida.h"
#include "Juego.h"
#include "ControlDatos.h"
#include "operaciones.h"
#include "MenuP.h"

int MenuU(Usuario u)
{
	int opcion;
	int control;
	int controlP;
	Juego* juegos;
	pAhorcado* pa;
	pa=(pAhorcado*)malloc(30*sizeof(pAhorcado));
	juegos=(Juego*)malloc(30*sizeof(Juego));
	control=LeerJuegosBin(juegos);
	do
	{
	printf("Bienvenido a aPointlessApplication, eliga lo que desea hacer: \n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.\n");
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
				printf("Se cerrara la sesion.\n");
				return 0;
				break;
			case 7:
				return 1;
				break;
			default:
				while (scanf("%i", &opcion) != 1||(opcion<1||opcion>7)) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.\n");
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
	printf("Bienvenido a aPointlessApplication, eliga lo que desea hacer: \n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Gestion de la aplicacion.\n 7.- Cerrar sesion.\n 8.- Salir.\n");
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
				GestionAplicacion(juegos, control);
				control=LeerJuegosBin(juegos);
				break;			
			case 7:
				printf("Se cerrara la sesion.\n");
				return 0;
				break;
			case 8:
				return 1;
				break;
			default:
				while (scanf("%i", &opcion) != 1||(opcion<1||opcion>8)) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Gestion de la aplicacion.\n 7.- Cerrar sesion.\n 8.- Salir.\n");
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
		printf("No hay ningun juego introducido en la base de datos.\n");
	}
	else
	{
	printf("Como quieres listar los juegos:\n 1.-Ordenar juegos por nombre de juego.\n 2.-Ordenarjuegos por precio del juego.");
	while (scanf("%i", &opcion) != 1||(opcion<1||opcion>2)) 
	{
   		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.-Ordenar juegos por nombre de juego.\n 2.-Ordenarjuegos por precio del juego.");
  		while (getchar() != '\n');	 
 	}

 	if(opcion==1)
 	{
 		printf("Has decidido mostrar los juegos ordenados por nombre:\n");
 		OrdenarJuegoPorNombre(j, control1);
 	}
 	else
 	{
 		printf("Has decidido mostrar los juegos ordenados por precio:\n");
		OrdenarJuegoPorPrecio(j, control1);
 	}
 		for(int i=0;i<control1;i++)
 		{
 			printf("%i.-",i+1);
			PrintJuego(j[i]);
 		}
 	}
}
void Jugar(Juego* j, int control1)
{
	int opcion;
	if(control1==0)
	{
		printf("No hay ningun juego introducido en la base de datos.\n");
	}
	else
	{
	printf("Eliga uno de los juegos para jugar:\n");
	
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
			int l;
			system("cls");
			//Para linux: system("clear"); 
			l=system(j[i].ejecutable);
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
	bool posible;
	bool existe;
	int i;
	FILE*f;
	printf("Has decidido subir un juego.\n");
	do
	{
		bienhecho=true;
		posible=true;
		printf("El nombre del juego es (de 1 a 14 caracteres):");
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
		if(strlen(ju.nombre)>14)
			{
				printf("El nombre del juego es demasiado largo.\n");
				posible=false;
			}

	}while(bienhecho==false||posible==false);
	posible=false;
	while(posible==false)
	{
		posible=true;
		printf("Inserte el genero del juego (de 1 a 14 caracteres): ");
		scanf("%s",&ju.genero);
			if(strlen(ju.genero)>14)
			{
				printf("El genero del juego es demasiado largo.\n");
				posible=false;
			}

		}
		posible=false;
		while(posible==false)
		{
			posible=true;
			printf("Inserte el precio del juego (de 0 a 150 euros): ");
			if(scanf("%i",&ju.Precio)!=1||ju.Precio<0||ju.Precio>150)
			{
				printf("El precio del juego no cumple las condiciones.\n");
				posible=false;
			}
			while (getchar() != '\n');
	}
	ju.Creador=p;
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
	escribirJuegosBin(j,control1+1);
	return control1+1;
}
void GestionAplicacion(Juego* j, int control1)
{
	int opcion;
	printf("Cual de las opciones de administrador quiere ejecutar:\n 1.-Eliminar juegos de la plataforma.\n 2.-Bloquear/Desbloquear usuarios de la plataforma.\n");
	while (scanf("%i", &opcion) != 1||(opcion<1||opcion>2)) 
	{
   		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.-Eliminar juegos de la plataforma.\n 2.-Bloquear/Desbloquear usuarios de la plataforma.\n");
  		while (getchar() != '\n');	            
 	}

 	if(opcion==1)
 	{ 
 		Juego* js;
 		js=(Juego*)malloc(sizeof(Juego)*30);
 		if(control1==0)
 		{
 			printf("No hay juegos registrados en la plataforma.\n");
 		}
 		else
 		{
 			printf("Has decidido borrar un juego de la plataforma, elige un numero de la lista:\n");
 			for(int i=0;i<control1;i++)
			{
				printf("%i.-",i+1);
				PrintJuego(j[i]);
			}
			while (scanf("%i", &opcion) != 1||(opcion<1||opcion>control1)) 
			{
   				printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion, eligiendo un numero de la lista:\n");
   				for(int i=0;i<control1;i++)
				{
					printf("%i.-",i+1);
					PrintJuego(j[i]);
				}
  				while (getchar() != '\n');	 
 			}
 			opcion--;
 			for(int i=0;i<(control1-1);i++)
 			{
 				if(i >= opcion)
 				{
 					js[i]=j[i+1];
 				}
 				else
 				{
 					js[i]=j[i];
 				}
 			}
 			escribirJuegosBin(js, control1-1);
 			free(js);
 		}
 		

 	}
 	else
 	{
 		Usuario* us;
 		int control2;
 		us=(Usuario*)malloc(sizeof(Usuario)*30);
 		control2=LeerUsuariosBin(us);
 		if(control2==0)
 		{
 			printf("No hay usuarios registrados en la plataforma.\n");
 		}
 		else
 		{
 			printf("Has decidido bloquear/desbloquear un usuario de la plataforma, elige un numero de la lista:\n");
 			for(int i=0;i<control2;i++)
			{
				printf("%i.-",i+1);
				MostrarUsuario(us[i]);
			}
			while (scanf("%i", &opcion) != 1||(opcion<1||opcion>control2)) 
			{
   				printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion, eligiendo un numero de la lista:\n");
   				for(int i=0;i<control2;i++)
				{
					printf("%i.-",i+1);
					MostrarUsuario(us[i]);
				}
  				while (getchar() != '\n');	 
 			}
 			opcion--;
 			if(us[opcion].bloq)
 			{
 				us[opcion].bloq=false;
 			}
 			else
 			{
 				us[opcion].bloq=true;
 			}
 			escribirUsuariosBin(us, control2);
 			free(us);
 		}
 	}
 	
}