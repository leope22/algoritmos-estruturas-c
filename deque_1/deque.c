#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

/* Nas funções, inicializa-se o deque, determina-se dinamicamente o tamanho do deque,
verifica-se se está vazio (sem nenhuma modificação da inicialização), se está cheio
(o resto do último elemento somado mais 1 com o tamanho seria igual ao primeiro elemento),
adiciona-se e remove-se no início e no fim, sempre tomando cuidado para manter todos os
elementos que não precisam ser removidos com as operações envolvendo o tamanho máximo
do vetor. */

void iniciar(deque *q, int M) {
    q->I = -1;
    q->F = -1;
    q->elementos = (int*)malloc(M * sizeof(int));
}

int vazia(deque *q) {
    if (q->F == -1) {
        return (1);
    } else {
        return (0);
    }
}

int cheia(deque *q, int M) {
    if ((q->F + 1) % M == q->I) {
        return (1);
    } else {
        return (0);
    }
}

void inserirF(deque *q, int item, int M) {
    if (vazia(q)) {
        q->F = 0;
        q->I = 0;
        q->elementos[0] = item;
    } else {
        q->F = (q->F + 1) % M;
        q->elementos[q->F] = item;
    }
}

void inserirI(deque *q, int item, int M) {
    if (vazia(q)) {
        q->F = 0;
        q->I = 0;
        q->elementos[0] = item;
    } else {
        q->I = (q->I - 1 + M) % M;
        q->elementos[q->I] = item;
    }
}

int removerI(deque *q, int M) {
    int item;
    item = q->elementos[q->I];
    if (q->F == q->I)
        iniciar(q, M);
    else
        q->I = (q->I + 1) % M;
    return (item);
}

int removerF(deque *q, int M) {
    int item;
    item = q->elementos[q->F];
    if (q->F == q->I)
        iniciar(q, M);
    else
        q->F = (q->F - 1 + M) % M;
    return (item);
}

void mostrar(deque *q, int M) {
    if (vazia(q)) {
        printf("vetor vazio\n");
    }
    int item;
    item = q->I;
    while (item != q->F) {
        printf("%d ", q->elementos[item]);
        item = (item + 1) % M;
    }
    printf("%d\n", q->elementos[q->F]);
}