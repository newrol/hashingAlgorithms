#ifndef HASHING_DEPENDIENTE_CLAVE_H_INCLUDED
#define HASHING_DEPENDIENTE_CLAVE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "model.h"

#define DEPENDTABLETAM 32
#define DISPERSIONSIZE 0,50
#define FREE -1
#define DELETED -2

#define DATAFILE "data.txt"

///Iniciar la tabla hash. Pone todos los valores a -1
void dependInit(person **mitabla, int tableSize);

///Insertar. Pasar la tabla que quiero insertar y un registro persona
int dependInsert(person * mitabla,int tableSize , person * reg, int * collisionCounter);

///Eliminar. Pasamos la tabla y el valor que queremos eliminar
int dependDelete(person * mitabla,int tableSize, int v);

///Mostrar lo que tiene la tabla hash. Le vamos a pasar la tabla hash y muestra su contenido
void dependShow(person * mitabla, int tableSize);


int depenSsearch(person mitabla[],int tableSize, int v);

///Factor de carga. N�mero de celdas ocupadas/n�mero total de celdas
float dependPerformance(person * mitabla, int tableSize);

#endif // HASHING_DEPENDIENTE_CLAVE_H_INCLUDED
