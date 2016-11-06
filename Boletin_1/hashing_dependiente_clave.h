#ifndef HASHING_DEPENDIENTE_CLAVE_H_INCLUDED
#define HASHING_DEPENDIENTE_CLAVE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "model.h"

#define TAM 100
#define LIBRE -1
#define BORRADO -2

#define DATAFILE "data.txt"

///Iniciar la tabla hash. Pone todos los valores a -1
//void init(persona mitabla[]);

///Insertar. Pasar la tabla que quiero insertar y un registro persona
void dependInsert(persona mitabla[], persona * reg);


///Eliminar. Pasamos la tabla y el valor que queremos eliminar
int dependDelete(persona mitabla[], int v);

///Mostrar lo que tiene la tabla hash. Le vamos a pasar la tabla hash y muestra su contenido
void dependShow(persona mitabla[]);


int depenSsearch(persona mitabla[], int v);

///Factor de carga. N�mero de celdas ocupadas/n�mero total de celdas
float dependPerformance(persona mitabla[]);

#endif // HASHING_DEPENDIENTE_CLAVE_H_INCLUDED
