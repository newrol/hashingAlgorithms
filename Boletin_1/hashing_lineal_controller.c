#include "hashing_lineal.h"

void ejercicicio1(){

persona hash_table[TAM];

    persona reg1, reg2, reg3, reg4, reg5;

    reg1.valor = 0;
    reg2.valor = 4;
    reg3.valor = 8;
    reg4.valor = 12;
    reg5.valor = 16;

    init(hash_table);                                                      //Iniciamos la tabla hash

    printf(" Factor de carga: %.2f \n" ,performance(hash_table));        ///Mostramos el factor de carga

    ///Insertamos los valores
    insert(hash_table, reg1);
    printf(" Factor de carga: %.2f \n" ,performance(hash_table));

    insert(hash_table, reg2);
    printf(" Factor de carga: %.2f \n" ,performance(hash_table));

    insert(hash_table, reg3);
    printf(" Factor de carga: %.2f \n" ,performance(hash_table));

    insert(hash_table, reg4);
    printf(" Factor de carga: %.2f \n" ,performance(hash_table));

    insert(hash_table, reg5);
    printf(" Factor de carga: %.2f \n" ,performance(hash_table));


    show(hash_table);         ///Mostramos la tabla

    printf(" la posicion del registro 12 --> %d \n", search(hash_table, 12));
    printf(" la posicion del registro 16 --> %d \n", search(hash_table, 16));

    delete(hash_table, 0);        ///Borramos el 0
    show(hash_table);            ///Mostramos la tabla

    printf(" la posicion del registro 12 --> %d \n", search(hash_table, 12));

    insert(hash_table, reg5);     ///Insertamos el valor 16 (reg5)
    show(hash_table);            ///Mostramos la tabla


    system("PAUSE");
    return 0;

}
