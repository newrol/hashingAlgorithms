#include "hashing_lineal.h"



void linealInit(person myTable[]){

    int i;
    for(i=0; i< SIZE; i++){
        myTable[i].dni = FREE;
    }
}

//Funcion hash
int linealH(int k){

    return (k % SIZE);
}


void linealInsert(person myTable[], person * reg, int * collisionCounter){

    int p, p2;
    p = linealH(reg->dni);

    if(myTable[p].dni != FREE && myTable[p].dni != DELETED){

       int i;
       for(i=1; i < SIZE; i++){
            *collisionCounter = *collisionCounter + 1;

            p2=(p+i) % SIZE;

            if(myTable[p2].dni == FREE || myTable[p2].dni == DELETED){

                myTable[p2].dni = reg->dni;
                break;
            }
       }

       if(i == SIZE)

            printf("\nIMPOSIBLE INSERTAR VALOR %d\n\n", reg->dni);



    }
    else {

         myTable[p].dni = reg->dni;
    }


}

int linealDelete(person myTable[], int v){

    int p;

    p= linealSearch(myTable, v);

    if(p != -1){

        myTable[p].dni = DELETED;
        return 0;
    }
    else{

            return -1;
    }

}

void linealShow(person myTable[]){

    int i;

    for(i=0; i<SIZE; i++){

        printf("%d|", myTable[i].dni);
    }

    printf("\n");
}

int linealSearch(person myTable[], int v){
    int collisions = 0;
    int p, p2;

    p= linealH(v);                                         ///Funci�n hash del valor que queremos buscar

    if(myTable[p].dni == FREE){                    ///Fin de la b�squeda, el valor no est�
         printf("numero de colisiones dni %d : %d\n", v, collisions);
        return -1;
    }

    else if (myTable[p].dni!=v){                  ///Si no es el valor que buscamos, hay colisi�n

        int i;

        for(i=1; i< SIZE; i++){
            collisions++;
            p2 = (p+i) % SIZE;

            if(myTable[p2].dni ==v){
                printf("numero de colisiones dni %d : %d\n", v, collisions);

                return p2;                      ///Si el valor es el mismo que el que estaba buscando, termina y devuelve p2
            }

            else if (myTable[p2].dni ==FREE){     ///Si el valor est� libre, para de buscar
                printf("numero de colisiones dni %d : %d\n", v, collisions);
                return -1;
            }
        }

        if (i == SIZE){                                ///Si has dado la vuelta a toda la tabla porque estaba llena y no est� el valor, devuelve un -1
             printf("numero de colisiones dni %d : %d\n", v, collisions);
            printf(" La tabla esta llena. \n");
            return -1;
        }
    }

    else {                                          ///Hemos encontrado el registro, devolvemos su posici�n
         printf("numero de colisiones dni %d : %d\n", v, collisions);
        return p;
    }

    return 0;
}



float linealPerformance(person myTable[]){
    float value;
    int num_ocupadas = 0;
    int i;

    for(i=0; i < SIZE; i++){

        if(myTable[i].dni != FREE && myTable[i].dni != DELETED){
            num_ocupadas++;

            }

    }

    return (float) num_ocupadas/  SIZE;     ///Devolvemos el factor de carga.
}

