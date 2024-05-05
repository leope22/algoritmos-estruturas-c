#ifndef DEQUE_H
#define DEQUE_H

typedef struct deque{ 
	int *elementos;
	int I, F;
} deque;

void iniciar(deque *q, int M);
int vazia(deque *q);
int cheia(deque *q, int M);
void inserirF(deque *q, int item, int M);
void inserirI(deque *q, int item, int M);
int removerI(deque *q, int M);
int removerF(deque *q, int M);
void mostrar(deque *q, int M);

#endif