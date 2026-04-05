#include "censo.h"
#include <stdio.h>

int cuantasPersonas(Persona* ap, int tamanyo, int edad)
{
    int contador = 0;
    while(ap->edad < edad)
    {
        contador++;
    }

    return contador;
}

GrupoPersonas recuperarJovenes(Persona* ap, int tamanyo)
{
    while(ap->edad < 30)
    {

    }
}
Persona* recuperarYogurin(Persona* ap, int tamanyo)
{

}
