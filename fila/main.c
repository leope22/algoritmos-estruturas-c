/* Os últimos serão os primeiros
Dada uma fila, implemente uma função recursiva que inverta todos os elementos
da fila. Veja os exemplos abaixo após as especificações de entrada e saída.

Entrada
A entrada consiste de duas linhas. Na primeira linha, há um inteiro \( T \)
indicando o número de elementos. Na segunda linha, os \( T \) números estão
separados por espaços.

Saída
Imprima uma única linha contendo os elementos da fila (invertidos), separados
por espaços. */

#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

/* Nessa função de inverter utilizando a fila, os elementos enfileirados são
retirados recursivamente e colocados novamente na fila, começando pelo primeiro
elemento retirado. Isso resulta na inversão de todos os elementos. */

void inverter();

int main(int argc, char *argv[]) {
    long long int tam, item;
    scanf("%lld", &tam);
    for (long long int i = 0; i < tam; i++) {
        scanf("%lld", &item);
        insere(item);
    }
    inverter();
    mostrar();

    /*int op;
    int item;
    for(int i = 0; i < 13; i++){
        scanf("%d", &op);
        switch(op){
            case 1:
                scanf("%d", &item);
                insere(item);
                break;
            case 2:
                retira();
                break;
            default:
                break;
        }
    }*/
    return 0;
}

void inverter() {
    if (!vazia()) {
        int data = item();
        retira();
        inverter();
        insere(data);
    }
}