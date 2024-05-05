#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

struct node *primeiro = NULL, *ultimo = NULL;

int vazia() {
    return primeiro == NULL;
}

int item() {
    return primeiro->item;
}

void insere(long long int data) {
    struct node* n = (struct node*)malloc(sizeof(struct node));
    n->item = data;
    n->link = NULL;
    if (ultimo == NULL) {
        primeiro = ultimo = n;
        return;
    }
    ultimo->link = n;
    ultimo = n;
}

void retira() {
    struct node *n;
    if (primeiro == NULL) {
        return;
    }
    n = primeiro;
    primeiro = primeiro->link;
    if (primeiro == NULL) {
        ultimo = NULL;
    }
    free(n);
}

void mostrar() {
    struct node *n = primeiro;
    while (primeiro != NULL) {
        printf("%d", n->item);
        n = n->link;
        retira();
        if (primeiro == NULL) {
            printf("\n");
            return;
        }
        printf(" ");
    }
}