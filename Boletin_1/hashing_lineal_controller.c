#include "hashing_lineal.h"


void ejercicio1(){

    printf("--------Ejericicio1---------\n\n");

    persona hash_table[TAM];
    persona * personas = NULL;
    struct timeval t_ini, t_fin;
    double secs;
    int value = 0;


    linealInit(hash_table);//3

    value = readUsers(DATAFILE, &personas);//3

    gettimeofday(&t_ini, NULL);

    int i;
    for(i = 0; i< value; i++){

        linealInsert(hash_table, &personas[i]);


    }

    gettimeofday(&t_fin, NULL);
    secs = timeval_diff(&t_fin, &t_ini);
    printf("Tiempo de ejecucíon: %.16g milliseconds\n\n", secs * 1000.0);


    free(personas);     //liberamos el especio de los usuarios leidos

    printf("Solucion:\n\n");
    linealShow(hash_table);            ///Mostramos la tabla



    system("PAUSE");
    return 0;

}
