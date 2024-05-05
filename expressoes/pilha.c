#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

struct stack *top = NULL;

int empty() {
    return top == NULL;
}

void push(T item) {
    struct stack *s = malloc(sizeof(struct stack));
    s->data = item;
    s->next = top;
    top = s;
}

void display() {
    struct stack *aux;
    aux = top;
    while (aux != NULL) {
        printf("%c\n", aux->data);
        aux = aux->next;
    }
}

T pop() {
    T removed;
    if (empty()) {
        // printf("empty\n");
        return 0;
    } else {
        struct stack *temp;
        temp = top;
        top = top->next;
        removed = temp->data;
        // printf("%c deleted\n", temp->data);
        free(temp);
        return removed;
    }
}