#include "readFile.h"


/**
*Get all users from a format text file.
*format : dni,mail,name.
*returns the number of people read in the file.
**/
int readUsers(char *fileName, person **peopleValue){

        char line[500];  /// save one line.
        char *token;     /// line token.
        int people = 0;  /// number of people in the file.

        person * peopleList = *peopleValue;    ///aux.

        FILE *fp = fopen(fileName,"r");         ///openFile.

                                                ///test troubles at file.
        if(fp == NULL){
                printf("Error de lectura del archivo");
                return -1;
        }

        while(fgets(line,500,fp) != NULL){    /// line file iterator.

              peopleList = (person *) realloc(peopleList, (sizeof(person) * ++people));   ///allocate memory for one person.

              token = strtok(line,","); /// line splitter",".


              /// fill up values.
              peopleList[people -1].dni = (int) atoi(token);
              token = strtok(NULL, ",");
              strcpy(peopleList[people -1].name,token);
              token = strtok(NULL, ",");
              strcpy(peopleList[people -1].mail, token);

        }


        *peopleValue = peopleList;      ///redefine people list to use outside this function.
        return people;

}

