#ifndef CENSO_H_
#define CENSO_H_
#include "persona.h"

typedef struct
{
	int numPersonas;
	Persona* personasGrupo;
    float mediaEdad;
} GrupoPersonas;

int cuantasPersonas(Persona* ap, int tamanyo, int edad);
GrupoPersonas recuperarJovenes(Persona* ap, int tamanyo);
Persona* recuperarYogurin(Persona* ap, int tamanyo);

#endif