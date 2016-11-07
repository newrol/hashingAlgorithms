#include "hashing_dependiente_clave_controller.h"

void ejercicio2(){

    printf("--------Ejericicio2---------\n\n");

    persona * hash_table;

    persona * personas;

    int value = 0;

    dependInit(&hash_table);

    value = readUsers(DATAFILE, &personas);

    int i;

    for(i = 0; i< value; i++){

        dependInsert(hash_table, &personas[i]);

    }

    free(personas);     //liberamos el especio de los usuarios leidos

    dependShow(hash_table);            ///Mostramos la tabla


    system("PAUSE");
    return 0;

}
