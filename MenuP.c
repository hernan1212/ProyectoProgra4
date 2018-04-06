#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Persona.h"
#include "MenuP.h"

int Menu(Persona p, bool t)
{
	int opcion;

	printf("Bienvenido a aPointlessApplication: \n 1.- Lista de juegos \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.");
	scanf("%i",&opcion);

	do
	{
		switch(opcion)
		{
			case 1:
				ListaJuegos();
				break;
			case 2:
				Jugar();
				break;
			case 3:
				Perfil();
				break;
			case 4:
				Estadisticas();
				break;
			case 5:
				SubirJuego();
				break;			
			case 6:
				printf("Se cerrará la sesión.");
				return 0;
				break;
			case 7:
				return 1;
				break;
			case 8:
				if(t)
				{
				GestionAplicacion();
				break;
				}
			default:
				while (scanf("%i", &opcion) != 1||(opcion<1||opcion>3)) {
   					printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Iniciar sesion. \n 2.- Registrarse. \n 3.- Salir.\n");
  					while (getchar() != '\n');
					 
 				}
				break;

		}

	}while(opcion!=3);
}

void ListaJuegos()
{

}
void Jugar()
{

}
void Perfil()
{

}
void Estadisticas()
{

}
void SubirJuego()
{

}
void GestionAplicacion()
{

}