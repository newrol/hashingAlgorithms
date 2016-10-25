#ifndef HASHING_LINEAL_H_INCLUDED
#define HASHING_LINEAL_H_INCLUDED

#define TAM 4
#define LIBRE -1
#define BORRADO -2

typedef struct persona {

    int valor;

}persona;

void init(persona mitabla[]);
void insert(persona mitabla[], persona reg);
void show(persona mitabla[]);



#endif // HASHING_LINEAL_H_INCLUDED
