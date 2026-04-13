#include "persona.h"
#include "censo.h"
#include <stdlib.h>
#include <string.h>

int cuantasPersonas(Persona ap[], int tamanyo, int edad)
{
	int cuantas = 0;
	int i=0;
	while (i<tamanyo)
	{
		if (ap[i].edad < edad) cuantas++;
		i++;
	}
	return cuantas;
}

GrupoPersonas recuperarJovenes(Persona ap[], int tamanyo)
{
	GrupoPersonas gp;
	gp.numPersonas = cuantasPersonas(ap, tamanyo, 30);
	gp.personas = (Persona*)malloc(sizeof(Persona)*gp.numPersonas);
	int i=0;
	int j=0;
	int suma=0;
	while (i<tamanyo)
	{
		if (ap[i].edad < 30)
		{
			gp.personas[j]=ap[i];
			suma = suma + ap[i].edad;
			j++;
		}
		i++;
	}
	gp.mediaEdad = suma/gp.numPersonas;
	return gp;
}

Persona* recuperarYogurin(Persona ap[], int tamanyo)
{
	Persona *p = ap;

	int i=0;
	while (i<tamanyo)
	{
		if (ap[i].edad < p->edad)
		{
			p = &ap[i];
		}
		i++;
	}

	return p;
}


int cuantosNombres(Persona ap[], int tamanyo, char letra)
{
	int cuantos=0;
	int i=0;
	while (i<tamanyo)
	{
		if (letra == ap[i].nombre[0]) cuantos++;
		i++;
	}
	return cuantos;

}

char** listadoNombres(Persona ap[], int tamanyo, char letra)
{
	int cuantos=cuantosNombres(ap,tamanyo,letra);
	char **listado=(char**)malloc(sizeof(char*)*cuantos);
	int i=0;
	int j=0;
	while (i<tamanyo)
	{
		if (letra == ap[i].nombre[0]){
			listado[j]=(char*)malloc(sizeof(char)*(strlen(ap[i].nombre)+1));
			strcpy(listado[j], ap[i].nombre);
			j++;
		}
		i++;
	}
	return listado;
}
