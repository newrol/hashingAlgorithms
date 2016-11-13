#include "hashing_lineal.h"

void ejercicio1(){

    printf("--------Ejericicio1---------\n\n");

    persona hash_table[TAM];

    persona * personas = NULL;

    int value = 0;

    linealInit(hash_table);//3


   value = readUsers(DATAFILE, &personas);//3


    int i;

    for(i = 0; i< value; i++){

        linealInsert(hash_table, &personas[i]);


    }

    free(personas);     //liberamos el especio de los usuarios leidos


    printf("Solucion:\n\n");
    linealShow(hash_table);            ///Mostramos la tabla



    system("PAUSE");
    return 0;

}
