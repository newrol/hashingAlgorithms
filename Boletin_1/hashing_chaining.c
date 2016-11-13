#include "hashing_chaining.h"



void chainingInit(P_NODO_LISTA **mitabla){

    int i;
    P_NODO_LISTA * newTable;

    newTable = malloc(sizeof(P_NODO_LISTA) * CHAININGSIZE);

    for(i=0; i<  CHAININGSIZE; i++){
        newTable[i] = NULL;
    }

    *mitabla = newTable;

}


int chainingH(int k){

    return (k % CHAININGSIZE);
}


void chainingInsert(P_NODO_LISTA * table, person * reg){

    int p, p2;
    p = chainingH(reg->dni);

    table[p] = insertar(table[p],(uintptr_t) reg, 1);

}


void chainingShow(P_NODO_LISTA * mitable){

    int i;

    for(i=0; i < CHAININGSIZE; i++){

        if(mitable[i] != NULL){


            printf("%d|-->" ,i);

            NODO_LISTA * nodo_lista;
            person * person;

            nodo_lista = mitable[i];


            do{

            person = (uintptr_t) nodo_lista->valor;
            printf("%d|", person->dni);


            if(nodo_lista->siguiente != NULL){
                nodo_lista = nodo_lista->siguiente;

            }
            else{
                nodo_lista = NULL;
            }

            }while(nodo_lista != NULL);

              printf("\n\n");
        }

    }

    printf("\n");
}


