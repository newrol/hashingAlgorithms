#include "hashing_lineal.h"

void ejercicio1(){


    printf("--------Ejericicio1---------\n\n");

    persona hash_table[TAM];

    persona * personas;

    int value = 0;

     linealInit(hash_table);


    value = readUsers(DATAFILE, &personas);

    int i;

    for(i = 0; i< value; i++){

        linealInsert(hash_table, &personas[i]);

    }

    free(personas);     //liberamos el especio de los usuarios leidos

    linealShow(hash_table);            ///Mostramos la tabla


    system("PAUSE");
    return 0;

}
