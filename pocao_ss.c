/* Poção (Embalagem)
Encontre a quantidade de poção mais apropriada, ou seja, a maior quantidade
menor ou igual, para armazenar dentro de cada uma das garrafas de poções
mágicas fornecidas. Considere que existe um número ilimitado de poções de
cada quantidade.

Entrada
A primeira linha contém um inteiro P (1 ≤ P ≤ 1.000.000) que indica o
número de quantidades diferentes de poções. Na segunda linha são
fornecidos as P quantidades de poções, separados por um espaço. Na
terceira linha é fornecido o número de garrafas G (1 ≤ G < 1.000.000),
e na linha seguinte os tamanhos de cada garrafa, também separados por
um espaço. Todos os tamanhos, de poções e garrafas, são números inteiros
positivos e menores ou iguais a 10.000.000.

Saída
Você deverá imprimir uma linha para cada garrafa fornecida. Nesta linha
exiba o tamanho da maior quantidade de poção que pode ser utilizada
(menor ou igual). Quando não for possível encontrar uma quantidade de
poção, imprima a palavra “descartar”.

Exemplo Entrada
5
6 3 4 2 7
6
2 3 1 8 7 5

Exemplo Saída
2
3
descartar
7
7
4

Restrições
Documente adequadamente o código, incluindo a identificação do autor;
Utilize a busca binária;
Implemente um dos algoritmos de ordenação - InsertionSort, SelectionSort ou BubbleSort. */

#include <stdio.h>

// Declaração da função de ordenação Selection Sort
void selection_sort(int vetor[], int n);

// Declaração da função para trocar dois elementos de posição no vetor
void swap(int vetor[], int a, int b);

// Declaração da função para encontrar a maior quantidade de poção menor ou igual a key
int menor_igual(int vetor[], int key, int n);

int main(int argc, char *argv[]) {
    int P, G;
    
    // Leitura do número de quantidades diferentes de poções
    scanf("%d", &P);
    
    int qtd_poc[P];
    
    // Leitura das quantidades de poções
    for (int i = 0; i < P; i++) {
        scanf("%d", &qtd_poc[i]);
    }
    
    // Ordenação das quantidades de poções usando Selection Sort
    selection_sort(qtd_poc, P);
    
    // Leitura do número de garrafas
    scanf("%d", &G);
    
    int tam_gar[G];

    // Leitura dos tamanhos das garrafas
    for (int i = 0; i < G; i++) {
        scanf("%d", &tam_gar[i]);
    }
    
    // Verificação do tamanho da maior quantidade de poção que pode ser utilizada para cada garrafa
    for (int i = 0; i < G; i++) {
        int quantidade_pocao = menor_igual(qtd_poc, tam_gar[i], P);
        if (quantidade_pocao == -1) {
            printf("descartar\n");
        } else {
            printf("%d\n", quantidade_pocao);
        }
    }
    
    return 0;
}

// Implementação do algoritmo Selection Sort para ordenar o vetor
void selection_sort(int vetor[], int n) {
    for (int i = 0; i < (n - 1); i++) {
        int min = i;
        for (int j = (i + 1); j < n; j++) {
            if (vetor[j] < vetor[min]) {
                min = j;
            }
        }
        if (i != min) {
            swap(vetor, i, min);
        }
    }
}

// Função para trocar dois elementos de posição no vetor
void swap(int vetor[], int a, int b) {
    int t = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = t;
}

// Implementação da busca binária para encontrar a maior quantidade de poção menor ou igual a key
int menor_igual(int vetor[], int key, int n) {
    int imax = n - 1;
    int imin = 0, imid, elemento = -1;
    
    while (imax >= imin) {
        imid = (imax + imin) / 2;
        if (vetor[imid] == key) {
            return vetor[imid];
        } else if (key < vetor[imid]) {
            imax = imid - 1;
        } else {
            elemento = vetor[imid];
            imin = imid + 1;
        }
    }
    return elemento;
}