#include "hashing_chaining_controller.h"

void exercice3(){

    printf("--------Ejericicio3---------\n\n");

    P_NODO_LISTA * hash_table;

    persona * personas = NULL;

    chainingInit(&hash_table);

    int value = 0;

    value = readUsers(DATAFILE, &personas);

    int i;

    for(i = 0; i< value; i++){

        chainingInsert(hash_table, &personas[i]);

    }

    printf("Solucion:\n\n");
    chainingShow(hash_table);            ///Mostramos la tabla


    for(i = 0; i < CHAININGSIZE; i++){

        do{
           hash_table[i] =  borrar(hash_table[i], 1, &hash_table[i]->valor);

        }while(hash_table[i] != NULL);
    }

    free(hash_table);
    free(personas);     //liberamos el especio de los usuarios leidos



    system("PAUSE");
    return 0;


}



