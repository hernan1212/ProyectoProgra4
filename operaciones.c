#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "Persona.h"
#include "Juego.h"
#include "ControlDatos.h"
#include "MenuP.h"

void OrdenarJuegoPorNombre(Juego* j, int Control)
{
	Juego jueg;
	int k, i, z;
	for(i=0; i<Control-1;i++)
	{
		for(k=i, z=i+1;z<Control;z++)
		{
			if(strcmp(j[z].nombre,j[k].nombre)<0)
			{
				k=z;
			}
		}
		if(k!=i)
		{
			jueg=j[i];
			j[i]=j[k];
			j[k]=jueg;
		}
	}
}
void OrdenarAhorcadoPorPGanadas(pAhorcado* p, int Control)
{
	pAhorcado p1;
	int k, i, z;
	for(i=0; i<Control-1;i++)
	{
		for(k=i, z=i+1;z<Control;z++)
		{
			if(p[z].PartidasGanadas>p[k].PartidasGanadas)
			{
				k=z;
			}
		}
		if(k!=i)
		{
			p1=p[i];
			p[i]=p[k];
			p[k]=p1;
		}
	}
}
void OrdenarCalculadoraPorPuntMax(pCalc* p, int Control)
{
	pCalc p1;
	int k, i, z;
	for(i=0; i<Control-1;i++)
	{
		for(k=i, z=i+1;z<Control;z++)
		{
			if(p[z].PuntMax>p[k].PuntMax)
			{
				k=z;
			}
		}
		if(k!=i)
		{
			p1=p[i];
			p[i]=p[k];
			p[k]=p1;
		}
	}
}
void OrdenarJuegoPorPrecio(Juego* j, int Control)		
{
	Juego jueg;
	int k, i, z;
	for(i=0; i<Control-1;i++)
	{
		for(k=i, z=i+1;z<Control;z++)
		{
			if(j[z].Precio<j[k].Precio)
			{
				k=z;
			}
		}
		if(k!=i)
		{
			jueg=j[i];
			j[i]=j[k];
			j[k]=jueg;
		}
	}
}
