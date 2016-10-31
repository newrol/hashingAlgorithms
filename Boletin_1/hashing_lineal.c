#include "hashing_lineal.h"



void init(persona mitabla[]){

    int i;
    for(i=0; i< TAM; i++){
        mitabla[i].valor = LIBRE;
    }
}

//Funcion hash
int H(int k){

    return (k % TAM);
}


void insert(persona mitabla[], persona reg){

    int p, p2;
    p = H(reg.valor);

    if(mitabla[p].valor != LIBRE && mitabla[p].valor != BORRADO){

       int i;
       for(i=1; i < TAM; i++){
            p2=(p+i) % TAM;
            if(mitabla[p2].valor == LIBRE || mitabla[p2].valor==BORRADO){
                mitabla[p2] = reg;
                break;
            }
       }

       if(i == TAM)
            printf("\nIMPOSIBLE INSERTAR VALOR %d\n\n", reg.valor);

    }
    else
        mitabla[p] = reg;

}

int delete(persona mitable[], int v){

    int p;

    p= search(mitable, v);

    if(p != -1){
        mitable[p].valor = BORRADO;
        return 0;
    }
    else{
            return -1;
    }

}

void show(persona mitable[]){

    int i;

    for(i=0; i<TAM; i++){
        printf("%d|", mitable[i].valor);
    }

    printf("\n");
}

int search(persona mitable[], int v){

    int p, p2;

    p=H(v);                                         ///Funci�n hash del valor que queremos buscar

    if(mitable[p].valor==LIBRE){                    ///Fin de la b�squeda, el valor no est�

        return -1;
    }

    else if (mitable[p].valor!=v){                  ///Si no es el valor que buscamos, hay colisi�n

        int i;

        for(i=1; i< TAM; i++){
            p2 = (p+i) % TAM;

            if(mitable[p2].valor==v){               ///Si el valor es el mismo que el que estaba buscando, termina y devuelve p2
                return p2;
            }

            else if (mitable[p2].valor==LIBRE){     ///Si el valor est� libre, para de buscar
                return -1;
            }
        }

        if (i == TAM){                                ///Si has dado la vuelta a toda la tabla porque estaba llena y no est� el valor, devuelve un -1

            printf(" La tabla esta llena. \n");
            return -1;
        }
    }

    else {                                          ///Hemos encontrado el registro, devolvemos su posici�n

        return p;
    }

    return 0;
}

float performance(persona mitabla[]){

    int num_ocupadas=0;
    int i;

    for(i=0; i<TAM; i++){

        if(mitabla[i].valor != LIBRE && mitabla[i].valor != BORRADO){
            num_ocupadas++;
            }

    }

    return ((float)num_ocupadas/TAM);      ///Devolvemos el factor de carga.
}

