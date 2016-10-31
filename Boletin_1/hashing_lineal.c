#include "hashing_lineal.h"
#include <stdio.h>
#include <stdlib.h>
void init(persona mitabla[]){

    int i;
    for(i=0; i< TAM; i++){
        mitabla[i].valor = LIBRE;
    }
}

int H(int k){
    return (k % TAM);
}

void insert(persona mitabla[], persona reg){
    int p, p2;
    p = H(reg.valor);

    if(mitabla[p].valor != LIBRE || mitabla[p].valor != BORRADO){

       int i;
       for(i=1; i<TAM; i++){
            p2=(p+i) % TAM;
            if(mitabla[p2].valor == LIBRE && mitabla[p2].valor==BORRADO){
                mitabla[p2] = reg;
                break;
            }
       }

       if(i==TAM)
            printf("\nIMPOSIBLE INSERTAR VALOR %d\n\n", reg.valor);

    }
    else
        mitabla[p] = reg;

}

void show(persona mitabla[]){
    int i;
    for(i=0; i<TAM; i++){
        printf("%d|\n", mitabla[i].valor);
    }
    printf("\n");
}


