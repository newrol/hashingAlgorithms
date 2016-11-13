#ifndef READFILE_H_INCLUDED
#define READFILE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "model.h"

///Get all users from a format text file
int readUsers(char *nombre_fichero, person ** personas);

#endif // READFILE_H_INCLUDED
