#ifndef HASHING_LINEAL_H_INCLUDED
#define HASHING_LINEAL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "model.h"

#define TAM 100
#define LIBRE -1
#define BORRADO -2

#define DATAFILE "data.txt"

///Iniciar la tabla hash. Pone todos los valores a -1
void init(persona mitabla[]);

///Insertar. Pasar la tabla que quiero insertar y un registro persona
void insert(persona mitabla[], persona * reg, int * collisionCounter);


///Eliminar. Pasamos la tabla y el valor que queremos eliminar
int delete(persona mitabla[], int v);

///Mostrar lo que tiene la tabla hash. Le vamos a pasar la tabla hash y muestra su contenido
void show(persona mitabla[]);


int search(persona mitabla[], int v);

///Factor de carga. N�mero de celdas ocupadas/n�mero total de celdas
float linealPerformance(persona mitabla[]);


#endif // HASHING_LINEAL_H_INCLUDED
