#ifndef CENSO_H_
#define CENSO_H_

typedef struct
{
	Persona* personas;
	int numPersonas;
	float mediaEdad;
} GrupoPersonas;

int cuantasPersonas(Persona[], int, int);
GrupoPersonas recuperarJovenes(Persona[], int);
Persona* recuperarYogurin(Persona[], int);

int cuantosNombres(Persona[], int, char);
char** listadoNombres(Persona[], int, char);

#endif /* CENSO_H_ */
