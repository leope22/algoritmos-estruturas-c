/* Deque
Implemente a API de uma fila duplamente terminada, chamada Deque (procure
sobre esta estrutura :-). Em seguida, faça o seguinte programa que utiliza
esta deque, no estilo simulação. Este programa irá ler uma entrada de
comandos, conforme especificado abaixo, e gerar a saída correspondente.

Entrada
A primeira linha contém dois números N (1 ≤ N ≤ 550.000) e M (1 ≤ M ≤ 550.000),
representando o número de comandos e o número máximo de elementos que podem ser
armazenados na deque, respectivamente. Em seguida, temos N linhas. Cada linha é
iniciada pela palavra “insereI”, “insereF”, “removeI” ou “removeF”, representando
a operação que deve ser executada na deque (“I” indica início e “F” indica fim).
Caso a operação seja de inserção, teremos um número inteiro logo em seguida,
na mesma linha. Esse número deve ser inserido na deque se esta não tiver atingido
sua capacidade máxima. Caso não tenha espaço disponível, seu programa deve
imprimir uma linha contendo a palavra “cheia”. Caso a operação seja de remoção,
seu programa deve imprimir na tela o número inteiro que saiu da deque ou a
palavra “vazia”.

Saída
Imprima uma linha para cada operação “removeI” ou “removeF”, contendo o número
inteiro que saiu da deque devido à operação. Caso a deque esteja vazia no momento,
imprima na linha a palavra “vazia”. Imprima uma linha contendo a palavra “cheia”
para cada operação “insereI” ou “insereF” que tenha a deque cheia no momento. */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "deque.h"

/* Aqui se reconhece as operacoes por meio de strings */

int main(int argc, char *argv[]) {
    int N, M, num, item;
    
    scanf("%d %d", &N, &M);
    
    deque q;
    iniciar(&q, M);
    
    char op[7];
    char iI[] = "insereI";
    char iF[] = "insereF";
    char rI[] = "removeI";
    char rF[] = "removeF";
    char m[] = "mostre";
    
    for (int i = 0; i < N; i++) {
        
        scanf("%s", op);
        
        if (strcmp(iI, op) == 0) {
            scanf("%d", &num);
            if (cheia(&q, M)) {
                printf("cheia\n");
            } else {
                inserirI(&q, num, M);
            }
        }
        if (strcmp(iF, op) == 0) {
            scanf("%d", &num);
            if (cheia(&q, M)) {
                printf("cheia\n");
            } else {
                inserirF(&q, num, M);
            }
        }
        if (strcmp(rI, op) == 0) {
            if (vazia(&q)) {
                printf("vazia\n");
            } else {
                item = removerI(&q, M);
                printf("%d\n", item);
            }
        }
        if (strcmp(rF, op) == 0) {
            if (vazia(&q)) {
                printf("vazia\n");
            } else {
                item = removerF(&q, M);
                printf("%d\n", item);
            }
        }
        if (strcmp(m, op) == 0) {
            mostrar(&q, M);
        }
    }
    return 0;
}