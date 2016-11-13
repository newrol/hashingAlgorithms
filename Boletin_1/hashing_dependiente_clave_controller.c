#include "hashing_dependiente_clave_controller.h"

void exercice2(){


    printf("--------Ejericicio2---------\n\n");

    int currentTableSize = DEPENDTABLETAM;

    person * hash_table = NULL;
    person * people = NULL;
    int collisionCounter = 0;
    int value = 0;
    struct timeval t_ini, t_fin;
    double secs;

    dependInit(&hash_table, currentTableSize);

    value = readUsers(DATAFILE, &people);

    int i;

    gettimeofday(&t_ini, NULL);
    for(i = 0; i< value; i++){


        int currentPerformance =  (int) (dependPerformance(hash_table, currentTableSize) * 100);

        if(currentPerformance >= 50 ){
            dispersion(&hash_table, &currentTableSize);
        }

        while(dependInsert(hash_table, currentTableSize, &people[i], &collisionCounter) != 0){
            dispersion(&hash_table, &currentTableSize);

        }

    }

    gettimeofday(&t_fin, NULL);
    secs = timeval_diff(&t_fin, &t_ini);
    printf("Tiempo de ejecucíon: %.16g milliseconds\n\n", secs * 1000.0);

    printf("Numero de colisiones: %d\n", collisionCounter);


    free(people);     //liberamos el especio de los usuarios leidos
    free(hash_table);


    printf("Solucion:\n\n");
    dependShow(hash_table, currentTableSize);            ///Mostramos la tabla

    linealSearch(hash_table, 10637290, currentTableSize);
    linealSearch(hash_table, 21039483, currentTableSize);
    linealSearch(hash_table, 89170831, currentTableSize);


    system("PAUSE");
    return 0;

}
