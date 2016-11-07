#include "hashing_dependiente_clave.h"



void dependInit(persona **mitabla){

    int i;
    persona * newTable;

    newTable = malloc(sizeof(persona) *  TAM);

    for(i=0; i< TAM; i++){
        newTable[i].dni = LIBRE;
    }

    *mitabla = newTable;
}


//Funcion hash
int dependH(int k){

    return (k % TAM);
}

int dependHCollision(int k, int i){

    return (  (k + (dependH(k) * i)) % TAM );
}


void dependInsert(persona *mitabla, persona * reg){

    int p, p2;
    p = dependH(reg->dni);


    if(mitabla[p].dni != LIBRE && mitabla[p].dni != BORRADO){

       int i;
       for(i=1; i < TAM; i++){

            p2= dependHCollision(reg->dni,i + 1);

            if(mitabla[p2].dni == LIBRE || mitabla[p2].dni == BORRADO){

                mitabla[p2].dni = reg->dni;
                break;
            }
       }

       if(i == TAM)

            printf("\nIMPOSIBLE INSERTAR VALOR %d\n\n", reg->dni);

    }
    else {

         mitabla[p].dni = reg->dni;
    }

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
void dependShow(persona mitable[]){

    int i;

    for(i=0; i<TAM; i++){

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
float dependPerformance(persona mitabla[]){

    int num_ocupadas=0;
    int i;

    for(i=0; i<TAM; i++){

        if(mitabla[i].dni != LIBRE && mitabla[i].dni != BORRADO){
            num_ocupadas++;
            }

    }

    return ((float)num_ocupadas/TAM);      ///Devolvemos el factor de carga.
}


