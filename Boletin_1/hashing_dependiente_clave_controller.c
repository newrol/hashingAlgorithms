#include "hashing_dependiente_clave_controller.h"

void ejercicio2(){


    printf("--------Ejericicio2---------\n\n");

    int currentTableSize = DEPENDTABLETAM;

    persona * hash_table = NULL;
    persona * personas = NULL;

    int value = 0;

    dependInit(&hash_table, currentTableSize);

    value = readUsers(DATAFILE, &personas);

    int i;

    for(i = 0; i< value; i++){


        int currentPerformance =  (int) (dependPerformance(hash_table, currentTableSize) * 100);

        if(currentPerformance >= 50 ){
            dispersion(&hash_table, &currentTableSize);
        }

        while(dependInsert(hash_table, currentTableSize, &personas[i]) != 0){
            dispersion(&hash_table, &currentTableSize);

        }

    }

    free(personas);     //liberamos el especio de los usuarios leidos
    free(hash_table);


    printf("Solucion:\n\n");
    dependShow(hash_table, currentTableSize);            ///Mostramos la tabla


    system("PAUSE");
    return 0;

}
