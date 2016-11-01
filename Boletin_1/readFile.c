#include "readFile.h"


int readUsers(char *nombre_fichero, persona *personas){

        char linea[500]; // Para guardar la linea de cada fichero
        char *token;     // Para cada token de cada linea
        int numeroPersonas;

        //Abrimos el fichero
        FILE *fp = fopen(nombre_fichero,"r");

        // Comprobar que no hay error al abrir
        if(fp == NULL){
                printf("Error de lectura del archivo");
                return -1;
        }

        // Recorremos cada linea del fichero
        while(fgets(linea,500,fp)!=NULL){

               personas = (persona *) realloc(personas, (sizeof(persona) * ++numeroPersonas));

               printf("Linea leida: %s\n", linea);
               token = strtok(linea,","); // Separamos cada linea por ","
               while (token != NULL){
                     printf("%s\n",token);
                     token = strtok(NULL, ",");  // Siguiente token en la linea (si quedan)
               }
               system("PAUSE");     // COMENTAR PARA EJECUCION REAL
        }
        return numeroPersonas;

}

void deleteUsers(persona *personas, int numeroPersonas){

    int i;
    for(i = 0; i<numeroPersonas; i++){

        free(personas[i]);
    }

}
