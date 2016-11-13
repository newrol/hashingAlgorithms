#include "hashing_chaining_controller.h"

void exercice3(){

    printf("--------Ejericicio3---------\n\n");

    P_NODO_LISTA * hash_table;

    person * personas = NULL;

    struct timeval t_ini, t_fin;
    double secs;


    chainingInit(&hash_table);

    int value = 0;

    value = readUsers(DATAFILE, &personas);


    gettimeofday(&t_ini, NULL);

    int i;
    for(i = 0; i< value; i++){

        chainingInsert(hash_table, &personas[i]);

    }

    gettimeofday(&t_fin, NULL);
    secs = timeval_diff(&t_fin, &t_ini);
    printf("Tiempo de ejecucíon: %.16g milliseconds\n\n", secs * 1000.0);


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



