#ifndef PILHA_H
#define PILHA_H

typedef char T;

struct stack{
    T data;
    struct stack *next;
};

int empty();
void push(T item);
void display();
T pop();

#endif