#ifndef DEQUE_H
#define DEQUE_H

typedef struct deque {
	int item;
	struct deque *next, *prev;
} deque;

deque *node(int item);
int vazia();
int removerI(deque *q);
int removerF(deque *q);
void inserirI(deque *q, int item);
void inserirF(deque *q, int item);
void mostrar();

#endif