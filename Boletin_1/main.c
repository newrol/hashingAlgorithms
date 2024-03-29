#include "hashing_lineal_controller.h"
#include "hashing_dependiente_clave_controller.h"
#include "hashing_chaining_controller.h"

#include <stdbool.h>


/**
*main text interface
**/
int menuInterface(){

    int input;

    printf("-------Ejercicios de hashing---------\n\n");

    printf("----Seleccione una opcion-----\n");
    printf("(1) Ejercicio1\n");
    printf("(2) Ejercicio2\n");
    printf("(3) Ejercicio3\n");

    printf("Pulse cualquier otra para salir\n");
    printf("Opcion:");
    scanf("%d", &input);

    return input;
}



/**
*app main menu
**/
int menu(){

     switch (menuInterface()){

        case 1:
            ejercicio1();
            return 0;

        case 2:
            exercice2();
            return 0;

        case 3:
            exercice3();
            return 0;


        default:
            exit(0);
    }

}




/**
*App launcher method
**/
int main( int argc, char *argv[])
{

    while(true){
        if(menu() != 0){
            break;
        }
    }
    return 0;
}
