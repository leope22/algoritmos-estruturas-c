#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

deque *inicio = NULL, *fim = NULL;

deque *node(int item)
{
	deque *q = (deque*)malloc(sizeof(deque));
	q->item = item;
	q->prev = NULL;
	q->next = NULL;
	return q;
}

int vazia()
{
	return inicio == NULL;
}

int removerI(deque *q)
{
	if (!vazia()) {
		q = inicio;
		int aux = inicio->item;
		inicio = q->next;
		if (inicio) {
			inicio->prev = NULL;
		}
		else {
			inicio = NULL;
			fim = NULL;
		}
		return aux;
	}
}

int removerF(deque *q)
{
	if (!vazia()) {
		q = fim;
		int aux = fim->item;
		fim = q->prev;
		if (fim) {
			fim->next = NULL;
		}
		else {
			inicio = NULL;
			fim = NULL;
		}
		return aux;
	}
}

void inserirI(deque *q, int item)
{
	q = node(item);
	if (inicio == NULL) {
		inicio = q;
		fim = q;
	}
	else {
		deque *aux;
		aux = inicio;
		q->next = aux;
		aux->prev = q;
		inicio = q;
	}
}

void inserirF(deque *q, int item)
{
	q = node(item);
	if (inicio == NULL) {
		inicio = q;
		fim = q;
	}
	else {
		deque *aux;
		aux = fim;
		q->prev = aux;
		aux->next = q;
		fim = q;
	}
}

void mostrar()
{
	deque *aux;
	aux = inicio;
	while (aux) {
		printf("%d ", aux->item);
		aux = aux->next;
	}
	printf("\n");
}