/* Expressões (OBI2011)
Pedrinho e Zezinho precisam estudar resolução de expressões matemáticas para uma
prova que vão fazer. Para isso, decidiram resolver muitos exercícios antes da prova.
Como sabem programar, optaram por criar um gerador de expressões matemáticas.
O gerador de expressões que criaram funciona em duas fases. Na primeira fase, é
gerada uma cadeia de caracteres que contém apenas os caracteres "{", "[", "(",
"}", "]", e ")". Na segunda fase, o gerador adiciona os números e operadores à
estrutura criada na primeira fase. Uma cadeia de caracteres é considerada bem
definida (ou válida) se atender às seguintes propriedades:

1. Ela é uma cadeia de caracteres vazia (não contém nenhum caractere).
2. Ela é formada por uma cadeia bem definida envolvida por parênteses, colchetes
ou chaves. Portanto, se a cadeia S é bem definida, então as cadeias (S), [S] e {S}
também são bem definidas.
3. Ela é formada pela concatenação de duas cadeias bem definidas. Logo, se as
cadeias X e Y são bem definidas, a cadeia XY também é bem definida.

Depois que Pedrinho e Zezinho geraram algumas expressões matemáticas, perceberam
que havia algum erro na primeira fase do gerador. Algumas cadeias não eram bem
definidas. Eles querem começar a resolver as expressões o mais rápido possível,
e sabendo que você é um ótimo programador (e participa da OBI), resolveram pedir
para você escrever um programa que, dadas várias cadeias geradas na primeira
fase, determine quais delas são bem definidas e quais não são.

Entrada
A entrada é composta por várias instâncias. A primeira linha da entrada contém
um inteiro T indicando o número de instâncias. Em seguida, temos T (1 ≤ T ≤ 20)
linhas, cada uma com uma cadeia A. A cadeia de caracteres A tem entre 1 e 100000
caracteres e contém apenas caracteres "{", "[", "(", "}", "]" e ")".

Saída
Para cada instância, imprima uma linha contendo a letra “S” se a cadeia é bem
definida, ou a letra “N” caso contrário. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100000
#include "pilha.h"

/* Foi implementada uma pilha dinâmica, onde inserimos uma string para balanceamento.
Nessa pilha, colocamos os caracteres (, [, ou { e, em seguida, desempilhamos, comparando
em outra função se o item desempilhado combina com o respectivo caractere que fecha esse
balanceamento na string. Se essa combinação não ocorrer ou a pilha estiver vazia sem
fechar esse balanceamento, significa que não está balanceado e retorna zero. Depois,
percorremos toda a string e, se a pilha foi totalmente desempilhada, o balanceamento
ocorreu. No entanto, se algum caractere restou na pilha, então também não estava
balanceado. */

int combina(char a, char b)
{
    if (a == '[' && b == ']') {
        return 1;
    }
    if (a == '{' && b == '}') {
        return 1;
    }
    if (a == '(' && b == ')') {
        return 1;
    }
    return 0;
}

int balanceamento(char A[])
{
    while (!empty()) {
        pop();
    }
    for (int i = 0; i < strlen(A); i++) {
        if (A[i] == '{' || A[i] == '(' || A[i] == '[') {
            push(A[i]);
        }
        if (A[i] == '}' || A[i] == ')' || A[i] == ']') {
            if (empty()) {
                return 0;
            } else if (!combina(pop(), A[i])) {
                return 0;
            }
        }
    }
    if (empty()) {
        return 1;
    } else {
        return 0;
    }
}

int main(int argc, char *argv[])
{
    int num_inst;
    scanf("%d", &num_inst);
    char A[MAX];
    for (int i = 0; i < num_inst; i++) {
        scanf(" %s", A);
        if (balanceamento(A)) {
            printf("S\n");
        } else {
            printf("N\n");
        }
    }
    
    /*int op;
    T item;
    for(int i = 0; i < 13; i++){
        scanf("%d", &op);
        switch(op){
            case 1:
                scanf(" %c", &item);
                push(item);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            default:
                break;
        }
    }*/
    
    return 0;
}