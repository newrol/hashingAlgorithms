#ifndef READFILE_H_INCLUDED
#define READFILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "model.h"

int readUsers(char *nombre_fichero, persona *personas);
void deleteUsers(persona *personas, int numeroPersonas);

#endif // READFILE_H_INCLUDED
