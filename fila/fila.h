#ifndef FILA_H
#define FILA_H

struct node{
    int item;
    struct node* link;
};

int vazia();
int item();
void insere(long long int data);
void retira();
void mostrar();

#endif