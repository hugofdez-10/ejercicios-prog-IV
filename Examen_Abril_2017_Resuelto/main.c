#include "persona.h"
#include "censo.h"

#include <stdio.h>
#include <stdlib.h>

void crearInforme(GrupoPersonas gp, char* fichero)
{
	FILE* f;
	f = fopen(fichero, "w");

	fprintf(f, "CENSO DE JOVENES\n");
	fprintf(f, "----------------\n");

	int i=0;
	while(i<gp.numPersonas)
	{
		fprintf(f, "[Nombre: %s, Edad: %i]\n", gp.personas[i].nombre, gp.personas[i].edad);
		i++;
	}
	fprintf(f, "Media: %.2f\n", gp.mediaEdad);

	fclose(f);
}

int main(void)
{
	Persona personas[5];
	personas[0].nombre="Hodei"; personas[0].edad=6;
	personas[1].nombre="Anita"; personas[1].edad=41;
	personas[2].nombre="Aitor"; personas[2].edad=12;
	personas[3].nombre="Idoia"; personas[3].edad=31;
	personas[4].nombre="Maite"; personas[4].edad=24;

	imprimirPersona(personas[0]);

	int cp = cuantasPersonas(personas, 5, 15);
	GrupoPersonas gp = recuperarJovenes(personas, 5);
	Persona *p = recuperarYogurin(personas, 5);
	printf("Personas menores de 15 años = %d\n", cp);
	printf("Grupo de personas menores de 30 años:\n");
	int i=0;
	while(i<gp.numPersonas)
	{
		imprimirPersona(gp.personas[i]);
		i++;
	}
	printf("Media: %.2f\n", gp.mediaEdad);
	printf("La persona más joven es:\n");
	imprimirPersona(*p);

	crearInforme(gp, "informe.txt");
	free (gp.personas);

	char** listado = listadoNombres(personas, 5, 'A');
	int cuantos = cuantosNombres(personas, 5, 'A');
	printf("Nombres con la inicial ‘A’:\n");
	int j;
	for (j=0;j<cuantos;j++)
	{
		printf("%s\n", listado[j]);
		free (listado[j]);
	}
	free (listado);

	return 0;
}
