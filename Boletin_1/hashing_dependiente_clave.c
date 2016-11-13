#include "hashing_dependiente_clave.h"


void dependInit(persona **mitabla, int tableSize){

    int i;
    persona * newTable;

    newTable = malloc(sizeof(persona) * tableSize);

    for(i=0; i<  tableSize; i++){
        newTable[i].dni = LIBRE;
    }

    *mitabla = newTable;

}


void dispersion(persona ** table, int * tableSize){

    printf("%s %d \n", "Aplicando redispersion a la tabla de tamaño", *tableSize);

    int currentTablesize = *tableSize;

    int newTableSize =  *tableSize * 2;

    persona * inputTableBuffer = *table;

    persona * personasBuffer;

    dependInit(&personasBuffer, newTableSize);



    int i;

    for(i = 0; i < currentTablesize; i++){


            dependInsert(personasBuffer, newTableSize ,&inputTableBuffer[i]);
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


int dependInsert(persona * mitabla, int tableSize , persona * reg){

    int p, p2;


    p = dependH(reg->dni,  tableSize);


    if(mitabla[p].dni != LIBRE && mitabla[p].dni != BORRADO){

       int i;
       for(i=1; i < tableSize ; i++){

            p2= dependHCollision(reg->dni, tableSize,i + 1);

            if(mitabla[p2].dni == LIBRE || mitabla[p2].dni == BORRADO){

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

/*
int dependDelete(persona mitable[], int v){

    int p;

    p = search(mitable, v);

    if(p != -1){

        mitable[p].dni = BORRADO;
        return 0;
    }
    else{

            return -1;
    }

}
*/
void dependShow(persona * mitable, int tableSize){

    int i;

    for(i=0; i<tableSize; i++){

        printf("%d|", mitable[i].dni);
    }

    printf("\n");
}
/*
int dependSearch(persona mitable[], int v){

    int p, p2;

    p=H(v);                                         ///Funci�n hash del valor que queremos buscar

    if(mitable[p].dni == LIBRE){                    ///Fin de la b�squeda, el valor no est�

        return -1;
    }

    else if (mitable[p].dni!=v){                  ///Si no es el valor que buscamos, hay colisi�n

        int i;

        for(i=1; i< TAM; i++){
            p2 = (p+i) % TAM;

            if(mitable[p2].dni ==v){               ///Si el valor es el mismo que el que estaba buscando, termina y devuelve p2
                return p2;
            }

            else if (mitable[p2].dni ==LIBRE){     ///Si el valor est� libre, para de buscar
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
*/
float dependPerformance(persona * mitabla, int tableSize){

    int num_ocupadas=0;
    int i;

    for(i=0; i < tableSize; i++){

        if(mitabla[i].dni != LIBRE && mitabla[i].dni != BORRADO){
            num_ocupadas++;

            }

    }

    return (float) num_ocupadas/tableSize;      ///Devolvemos el factor de carga.
}


