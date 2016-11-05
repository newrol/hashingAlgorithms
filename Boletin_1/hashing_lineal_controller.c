#include "hashing_lineal.h"

void ejercicicio1(){


    printf("--------Ejericicio1---------\n\n");

    persona hash_table[TAM];

    persona * personas;

    int value = 0;

     init(hash_table);


    value = readUsers(DATAFILE, &personas);

    int i;

    for(i = 0; i< value; i++){

        insert(hash_table, &personas[i]);

    }

    free(personas);     //liberamos el especio de los usuarios leidos

    show(hash_table);            ///Mostramos la tabla


    system("PAUSE");
    return 0;

}
