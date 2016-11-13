#include "hashing_dependiente_clave.h"


void dependInit(person **mitabla, int tableSize){

    int i;
    person * newTable;

    newTable = malloc(sizeof(person) * tableSize);

    for(i=0; i<  tableSize; i++){
        newTable[i].dni = FREE;
    }

    *mitabla = newTable;

}


void dispersion(person ** table, int * tableSize){

    printf("%s %d \n", "Aplicando redispersion a la tabla de tamaño", *tableSize);

    int currentTablesize = *tableSize;
    int collisionCounter = 0;
    int newTableSize =  *tableSize * 2;

    person * inputTableBuffer = *table;

    person * personasBuffer;

    dependInit(&personasBuffer, newTableSize);



    int i;

    for(i = 0; i < currentTablesize; i++){


            dependInsert(personasBuffer, newTableSize ,&inputTableBuffer[i], &collisionCounter);
    }


    *tableSize = newTableSize;
    *table = personasBuffer;

    free(inputTableBuffer);

    printf("%s %d \n", "Tabla redispersionada con tamaño", newTableSize);

}

//Funcion hash
int dependH(int k, int tableSize){

    return (k % tableSize);
}

int dependHCollision(int k, int tableSize, int i){

    return (  (k + (dependH(k, tableSize) * i)) % tableSize );
}


int dependInsert(person * mitabla, int tableSize , person * reg, int * collisionCounter){

    int p, p2;


    p = dependH(reg->dni,  tableSize);


    if(mitabla[p].dni != FREE && mitabla[p].dni != DELETED){

       int i;
       for(i=1; i < tableSize ; i++){
            *collisionCounter = *collisionCounter + 1;

            p2= dependHCollision(reg->dni, tableSize,i + 1);

            if(mitabla[p2].dni == FREE || mitabla[p2].dni == DELETED){

                mitabla[p2].dni = reg->dni;
                break;
            }
       }

       if(i == tableSize){

       printf("\nIMPOSIBLE INSERTAR VALOR %d\n\n", reg->dni);
            return 1;

       }


    }

    else {

         mitabla[p].dni = reg->dni;

    }

    return 0;
}


int dependDelete(person * mitable, int v, int tableSize){

    int p;

    p = dependSearch(mitable, v, tableSize);

    if(p != -1){

        mitable[p].dni = DELETED;
        return 0;
    }
    else{

            return -1;
    }

}

void dependShow(person * mitable, int tableSize){

    int i;

    for(i=0; i<tableSize; i++){

        printf("%d|", mitable[i].dni);
    }

    printf("\n");
}


int dependSearch(person * mitable, int v, int tableSize){

    int p, p2;
    int collisions = 0;
    p = dependH(v, tableSize);                                         ///Funci�n hash del valor que queremos buscar

    if(mitable[p].dni == FREE){                    ///Fin de la b�squeda, el valor no est�

        return -1;
    }

    else if (mitable[p].dni!=v){                  ///Si no es el valor que buscamos, hay colisi�n

        int i;

        for(i=1; i< tableSize; i++){
            collisions++;
            p2 = dependHCollision(v, tableSize,i + 1);

            if(mitable[p2].dni ==v){               ///Si el valor es el mismo que el que estaba buscando, termina y devuelve p2
                printf("numero de colisiones dni %d : %d\n", v, collisions);

                return p2;
            }

            else if (mitable[p2].dni ==FREE){     ///Si el valor est� libre, para de buscar
                printf("numero de colisiones dni %d : %d\n", v, collisions);

                return -1;
            }
        }

        if (i == tableSize){                                ///Si has dado la vuelta a toda la tabla porque estaba llena y no est� el valor, devuelve un -1
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

float dependPerformance(person * mitabla, int tableSize){

    int num_ocupadas=0;
    int i;

    for(i=0; i < tableSize; i++){

        if(mitabla[i].dni != FREE && mitabla[i].dni != DELETED){
            num_ocupadas++;

            }

    }

    return (float) num_ocupadas/tableSize;      ///Devolvemos el factor de carga.
}


