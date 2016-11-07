#include "readFile.h"


int readUsers(char *nombre_fichero, persona **personasValue){

        char linea[500]; // Para guardar la linea de cada fichero
        char *token;     // Para cada token de cada linea
        int numeroPersonas = 0;

        persona * personas = *personasValue;

        personas = malloc(sizeof(persona));     //Solve this malloc troubles

        //Abrimos el fichero
        FILE *fp = fopen(nombre_fichero,"r");

        // Comprobar que no hay error al abrir
        if(fp == NULL){
                printf("Error de lectura del archivo");
                return -1;
        }

        // Recorremos cada linea del fichero
        while(fgets(linea,500,fp) != NULL){

              personas = (persona *) realloc(personas, (sizeof(persona) * ++numeroPersonas));

              token = strtok(linea,","); // Separamos cada linea por ","



              personas[numeroPersonas -1].dni = (int) atoi(token);
              token = strtok(NULL, ",");
              strcpy(personas[numeroPersonas -1].nombre,token);
              token = strtok(NULL, ",");
              strcpy(personas[numeroPersonas -1].eMail, token);

        }


        *personasValue = personas;
        return numeroPersonas;

}

void deleteFileUsers(persona * personas, int numeroPersonas){

}
