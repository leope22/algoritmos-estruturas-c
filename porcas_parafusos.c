/* Porcas e Parafusos
Considere um conjunto de N porcas e N parafusos, ambos de tamanhos diferentes.
Cada porca se encaixa perfeitamente em apenas um parafuso e vice-versa. Não é
possível comparar parafusos entre si nem porcas entre si, apenas uma porca e um
parafuso para verificar se são maiores, menores ou iguais (se encaixam). Faça
um programa que eficientemente encontre os encaixes perfeitos.

Entrada
O programa deve receber como entrada 3 linhas:
A primeira contém um inteiro, representando o número de porcas e de parafusos,
onde 1 ≤ N ≤ 200.000. A segunda linha contém os tamanhos das porcas, representados
por números inteiros separados por espaço. A terceira linha contém os tamanhos dos
parafusos, também representados por números inteiros separados por espaço.

Saída
O programa deve imprimir N linhas, cada uma contendo um par encontrado, seguindo
o padrão de saída abaixo:
for(int i=0; i<n; i++)
    printf("%d - %d\n", porcas[i], parafusos[i]);

Exemplo 1 Entrada
5
1 3 6 2 4
6 2 4 3 1

Exemplo 1 Saída
1 - 1
2 - 2
3 - 3
4 - 4
6 - 6

Exemplo 2 Entrada
8
1 7 3 6 5 2 8 4
5 2 4 3 1 8 6 7

Exemplo 2 Saída
1 - 1
2 - 2
3 - 3
4 - 4
5 - 5
6 - 6
7 - 7
8 - 8

Restrições
Documente adequadamente o código, incluindo a identificação do autor;
Não compare porcas com porcas, ou parafusos com parafusos;
Não utilize variáveis globais. */

#include <stdio.h>

void swap(int vetor[], int a, int b);
int partition(int vetor[], int imin, int imax, int pivo);
void quicksort_doisvet(int vetor1[], int vetor2[], int imin, int imax);

int main(int argc, char *argv[]) {
    int N;
    scanf("%d", &N);
    int porcas[N], parafusos[N];
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &porcas[i]);
    }
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &parafusos[i]);
    }
    
    quicksort_doisvet(porcas, parafusos, 0, N - 1);
    
    for(int i = 0; i < N; i++) {
        printf("%d - %d\n", porcas[i], parafusos[i]);
    }
}

void swap(int vetor[], int a, int b) {
    int t = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = t;
}

int partition(int vetor[], int imin, int imax, int pivo) {
    int i = imin;
    for(int j = imin; j < imax; j++) {
        if(vetor[j] < pivo) {
            swap(vetor, i, j);
            i++;
        } else if(vetor[j] == pivo) {
            swap(vetor, j, imax);
            j--;
        }
    }
    swap(vetor, i, imax);
    return i;
}

void quicksort_doisvet(int vetor1[], int vetor2[], int imin, int imax) {
    if(imin < imax) {
        int pivo = partition(vetor1, imin, imax, vetor2[imax]);
        partition(vetor2, imin, imax, vetor1[pivo]);
        quicksort_doisvet(vetor1, vetor2, imin, pivo - 1);
        quicksort_doisvet(vetor1, vetor2, pivo + 1, imax);
    }
}