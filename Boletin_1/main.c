#include <stdio.h>
#include <stdlib.h>
#include "hashing_lineal.h"

int main( int argc, char *argv[])
{
    persona hash_tabla[TAM];

    persona reg1, reg2, reg3, reg4, reg5;

    reg1.valor = 0;
    reg2.valor = 4;
    reg3.valor = 8;
    reg4.valor = 12;
    reg5.valor = 16;
    init(hash_tabla);



    insert(hash_tabla, reg1);
    insert(hash_tabla, reg2);
    insert(hash_tabla, reg3);
    insert(hash_tabla, reg4);
    insert(hash_tabla, reg5);
    show(hash_tabla);

    system("PAUSE");
    return 0;
}
