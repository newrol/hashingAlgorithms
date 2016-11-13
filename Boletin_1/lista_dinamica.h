#ifndef LISTA_DINAMICA_H_INCLUDED
#define LISTA_DINAMICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "model.h"

typedef struct t_lista{
    uintptr_t valor;
    struct t_lista *siguiente;  // puntero a siguiente
    struct t_lista *anterior;   // puntero a anterior
}NODO_LISTA, *P_NODO_LISTA;


int es_vacia (P_NODO_LISTA lista);

P_NODO_LISTA insertar(P_NODO_LISTA lst, uintptr_t valor, int pos);

P_NODO_LISTA borrar(P_NODO_LISTA lst, int pos, int *valor);

P_NODO_LISTA buscar(P_NODO_LISTA lst, int valor);

void imprimir_lista (P_NODO_LISTA lst);


#endif // LISTA_DINAMICA_H_INCLUDED
