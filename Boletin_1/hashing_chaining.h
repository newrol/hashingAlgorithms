#ifndef HASHING_CHAINING_H_INCLUDED
#define HASHING_CHAINING_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#include "model.h"
#include "lista_dinamica.h"s

#define CHAININGSIZE 10

#define DATAFILE "data.txt"


///Iniciar la tabla hash. Pone todos los valores a -1
void chainingInit(P_NODO_LISTA ** mitabla);


///Insertar. Pasar la tabla que quiero insertar y un registro persona
void chainingInsert(P_NODO_LISTA * mitabla, person * reg);
/*
///Eliminar. Pasamos la tabla y el valor que queremos eliminar
int dependDelete(persona mitabla[],int * tableSize, int v);
*/
///Mostrar lo que tiene la tabla hash. Le vamos a pasar la tabla hash y muestra su contenido
void chainingShow(P_NODO_LISTA * mitabla);

/*
int depenSsearch(persona mitabla[],int tableSize, int v);

///Factor de carga. N�mero de celdas ocupadas/n�mero total de celdas
float dependPerformance(persona * mitabla, int tableSize);
*/

#endif // HASHING_CHAINING_H_INCLUDED
