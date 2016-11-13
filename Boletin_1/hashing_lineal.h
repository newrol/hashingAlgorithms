#ifndef HASHING_LINEAL_H_INCLUDED
#define HASHING_LINEAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "model.h"

#define SIZE 100
#define FREE -1
#define DELETED -2

#define DATAFILE "data.txt"

///Iniciar la tabla hash. Pone todos los valores a -1
void init(person mitabla[]);

///Insertar. Pasar la tabla que quiero insertar y un registro persona
void insert(person mitabla[], person * reg, int * collisionCounter);


///Eliminar. Pasamos la tabla y el valor que queremos eliminar
int delete(person mitabla[], int v);

///Mostrar lo que tiene la tabla hash. Le vamos a pasar la tabla hash y muestra su contenido
void show(person mitabla[]);


int linealSearch(person mitabla[], int v);

///Factor de carga. N�mero de celdas ocupadas/n�mero total de celdas
float linealPerformance(person mitabla[]);


#endif // HASHING_LINEAL_H_INCLUDED
