#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Persona.h"
#include "IniReg.h"
#include "Partida.h"
#include "Juego.h"
#include "ControlDatos.h"
#include "operaciones.h"
#include "MenuP.h"

int MenuU(Usuario u)
{
	int opcion;
	int control;
	int controlP1;
	int controlP2;
	Juego* juegos;
	pAhorcado* pa;
	pCalc* pc;
	juegos=LeerJuegosBin(&control);
	pa=LeerPartidasBin(&controlP1);
	pc=LeerPartidasCBin(&controlP2);
	do
	{
	printf("Bienvenido a aPointlessApplication, eliga lo que desea hacer: \n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.\n");
	while(LeerValorInt(&opcion)==-1)
	{
		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Cerrar sesion.\n 7.- Salir.\n");
	}								

	
		switch(opcion)
		{
			case 1:
				ListaJuegos(juegos,control);
				break;
			case 2:																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																		
				if(Jugar(juegos, pa, pc, u.pers, control, controlP1, controlP2)==1)
				{
					pa=LeerPartidasBin(&controlP1);
					pc=LeerPartidasCBin(&controlP2);
				}
				break;
			case 3:
				PerfilU(u);
				break;
			case 4:
				Estadisticas(pa, pc, controlP1, controlP2);
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
   				printf("Error! No es un numero o no es un numero adecuado!\n ");
				break;

		}

	}while(true);
}
int MenuA(Administrador a)
{
	int opcion;
	int control;
	int controlP1;
	int controlP2;
	Juego* juegos;
	pAhorcado* pa;
	pCalc* pc;
	juegos=LeerJuegosBin(&control);
	pa=LeerPartidasBin(&controlP1);
	pc=LeerPartidasCBin(&controlP2);
	do
	{
	printf("Bienvenido a aPointlessApplication, eliga lo que desea hacer: \n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Gestion de la aplicacion.\n 7.- Cerrar sesion.\n 8.- Salir.\n");
	if(LeerValorInt(&opcion)==-1)
	{
		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.- Listas de juegos. \n 2.- Jugar. \n 3.- Mi Perfil.\n 4.- Estadisticas.\n 5.- Subir juego.\n 6.- Gestion de la aplicacion.\n 7.- Cerrar sesion.\n 8.- Salir.\n");
	}	
		switch(opcion)
		{
			case 1:
				ListaJuegos(juegos, control);
				break;
			case 2:
				if(Jugar(juegos, pa, pc, a.pers, control, controlP1, controlP2)==1)
				{
					pa=LeerPartidasBin(&controlP1);
					pc=LeerPartidasCBin(&controlP2);
				}
				break;
			case 3:
				PerfilA(a);
				break;
			case 4:
				Estadisticas(pa, pc, controlP1, controlP2);
				break;
			case 5:
				control=SubirJuego(juegos, a.pers, control);
				break;	
			case 6:
				GestionAplicacion(juegos, control);
				juegos=LeerJuegosBin(&control);
				break;			
			case 7:
				printf("Se cerrara la sesion.\n");
				return 0;
				break;
			case 8:
				return 1;
				break;
			default:
   				printf("Error! No es un numero o no es un numero adecuado!\n ");
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
	printf("Como quieres listar los juegos:\n 1.-Ordenar juegos por nombre de juego.\n 2.-Ordenar juegos por precio del juego.");
	while (LeerValorInt(&opcion)==-1||(opcion<1||opcion>2)) 
	{
   		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.-Ordenar juegos por nombre de juego.\n 2.-Ordenarjuegos por precio del juego."); 
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
int Jugar(Juego* j, pAhorcado* p1, pCalc * p2, Persona p, int control1, int control2, int control3)
{
	int opcion, resultado;
	bool existe=false;
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
	while (LeerValorInt(&opcion)==-1||(opcion<1||opcion>(control1))) 
	{
		printf("El valor no es correcto, debe insertar un numero de la lista. \nEliga uno de los juegos para jugar:\n");
		for(int i=0;i<control1;i++)
		{
			printf("%i.-",i+1);
			PrintJuego(j[i]);
		}
	}

	for(int i=0;i<control1;i++)
	{
		if(i==(opcion-1))
		{
			if(strcmp(j[i].ejecutable,"ahorcado.exe")==0)
			{
			system("cls");
			//Para linux: system("clear"); 
			resultado=system(j[i].ejecutable);
			for(int i=0;i<control2;i++)
			{
				if(strcmp(p1[i].Jugador.nick,p.nick)==0)
				{
					p1[i].PartidasJugadas++;
					if(resultado==1)
					{
						p1[i].PartidasGanadas++;
					}
					existe=true;
				}
			}
			if(!existe)
			{
				p1[control2].PartidasJugadas=1;
				p1[control2].PartidasGanadas=resultado;
				p1[control2].Jugador=p;
			}

			system("cls");
			escribirPartidasBin(p1,control2+1);
			return 1;
			}
			else if(strcmp(j[i].ejecutable,"CalcHumana.exe")==0)
			{
			system("cls");
			//Para linux: system("clear"); 
			resultado=system(j[i].ejecutable);
			existe=false;
			for(int i=0;i<control3;i++)
			{
				if(strcmp(p2[i].Jugador.nick,p.nick)==0)
				{
					p2[i].PartidasJugadas++;
					if(resultado>p2[i].PuntMax)
					{
						p2[i].PuntMax==resultado;
					}
					existe=true;
				}
			}
			if(!existe)
			{
				p2[control3].PartidasJugadas=1;
				p2[i].PuntMax==resultado;
				p1[control2].Jugador=p;
			}
			system("cls");
			escribirPartidasCBin(p2,control3+1);
			return 1;
			}
			else
			{
			system("cls");
			//Para linux: system("clear"); 
			system(j[i].ejecutable);
			system("cls");
			return 2;
			}
			
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
void Estadisticas(pAhorcado* p1, pCalc * p2, int control1, int control2)
{
	int opcion;
	printf("De que juego desea mostrar estadisticas:\n 1.-Ahorcado.\n 2.-Calculadora Humana.\n");
	while (LeerValorInt(&opcion)==-1||(opcion<1||opcion>2)) 
	{
   		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.-Ahorcado.\n 2.-Calculadora Humana.\n");       
 	}
 	printf("En proceso. Proximamente.");
/*
 	if(opcion==1)
 	{
 		if(control1==0)
 		{
 			printf("No hay estadisticas de ahorcado");
 		}

 		else
 		{
 		printf("Has elegido mostrar las estadisticas del ahorcado, se ordenaran por partidas ganadas:\n");
 		OrdenarAhorcadoPorPGanadas(p1, control1);
 		for(int i=0;i<control1;i++)
 		{
 			printf("%i.-",i+1);
			MostrarPartidaAhorcado(p1[i]);
 		}
 		}
 	}
 	else
 	{
 		if(control2==0)
 		{
 			printf("No hay estadisticas de calculadora humana");
 		}
 		else
 		{
 		printf("Has elegido mostrar las estadisticas de la calculadora humana, se ordenaran por puntuacion maxima:\n");
		OrdenarCalculadoraPorPuntMax(p2, control2);
		for(int i=0;i<control1;i++)
 		{
 			printf("%i.-",i+1);
			MostrarPartidaCalculadora(p2[i]);
 		}
 		}
 	}
 */
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
		printf("El nombre del juego es (de 1 a 14 caracteres):");

		if(LeerValor(ju.nombre,14)==-1)
		{
			printf("El nombre del juego no es adecuado.\n");
			bienhecho=false;
		}

		for(int i=0;control1>i;i++)
		{
			if(strcmp(ju.nombre,j[i].nombre)==0)
			{
				printf("El nombre ya existe\n");
				bienhecho=false;
			}
		}
	}while(bienhecho==false);

	printf("Inserte el genero del juego (de 1 a 14 caracteres): ");
	while(LeerValor(ju.genero,14)==-1)
	{
		printf("El genero del juego no es adecuado.\n");
		printf("Inserte el genero del juego (de 1 a 14 caracteres): ");
	}

	printf("Inserte el precio del juego (de 0 a 150 euros): ");
	while(LeerValorInt(&ju.Precio)==-1||ju.Precio<0||ju.Precio>150)
	{
		printf("El precio del juego no cumple las condiciones.\n");
		printf("Inserte el precio del juego (de 0 a 150 euros): ");
	}

	ju.Creador=p;
	
	do
	{
		existe=true;
		bienhecho=true;
		printf("El ejecutable del juego es:");
		LeerValor(ju.ejecutable,14);
		for(int i=0;control1>i;i++)
		{
			if(strcmp(ju.ejecutable,j[i].ejecutable)==0)
			{
				printf("La aplicacion ya existe\n");
				bienhecho=false;
			}
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
	while (LeerValorInt(&opcion)==-1||(opcion<1||opcion>2)) 
	{
   		printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion:\n 1.-Eliminar juegos de la plataforma.\n 2.-Bloquear/Desbloquear usuarios de la plataforma.\n");       
 	}

 	if(opcion==1)
 	{ 
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
			while (LeerValorInt(&opcion)==-1||(opcion<1||opcion>control1)) 
			{
   				printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion, eligiendo un numero de la lista:\n");
   				for(int i=0;i<control1;i++)
				{
					printf("%i.-",i+1);
					PrintJuego(j[i]);
				}	 
 			}
 			opcion--;
 			for(int i=0;i<(control1-1);i++)
 			{
 				if(i >= opcion)
 				{
 					j[i]=j[i+1];
 				}
 				else
 				{
 					j[i]=j[i];
 				}
 			}
 			escribirJuegosBin(j, control1-1);
 			free(j);
 		}
 		

 	}
 	else
 	{
 		Usuario* us;
 		int control2;
 		//us=(Usuario*)malloc(sizeof(Usuario)*30);
 		us=LeerUsuariosBin(&control2);
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
				printf("\n");
			}
			while (LeerValorInt(&opcion)==-1||(opcion<1||opcion>control2)) 
			{
   				printf("Error! No es un numero o no es un numero adecuado!\n Vuleva a introducir una opcion, eligiendo un numero de la lista:\n");
   				for(int i=0;i<control2;i++)
				{
					printf("%i.-",i+1);
					MostrarUsuario(us[i]);
					printf("\n");
				}
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