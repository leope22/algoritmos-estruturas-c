/* Poção (Embalagem)
Encontre a embalagem mais apropriada, ou seja, a menor embalagem maior ou igual, para armazenar
cada uma das garrafas de poções mágicas fornecidas. Considere que existe um número ilimitado de
embalagem de cada tamanho.

Entrada
A primeira linha contém um inteiro E (1 ≤ E ≤ 10.000) que indica a quantidade de tamanhos diferentes
de embalagens. Na segunda linha são fornecidos os E tamanhos de embalagens, separados por um espaço.
Na terceira linha é fornecido o número de garrafas G (1 ≤ G < 1.000.000), e na linha seguinte os
tamanhos de cada garrafa, também separados por um espaço. Todos os tamanhos, de embalagens e garrafas,
são números inteiros positivos e menores ou iguais a 10.000.

Saída
Você deverá imprimir uma linha para cada garrafa fornecida. Nesta linha exiba o tamanho da menor
embalagem que pode ser utilizada (maior ou igual). Quando não for possível encontrar um tamanho
de embalagem, imprima a palavra “descartar”.

Exemplo Entrada
5
6 3 4 2 7
6
2 3 1 8 7 5

Exemplo Saída
2
3
2
descartar
7
6

Restrições
Documente adequadamente o código, incluindo a identificação do autor;
Utilize a busca binária;
Implemente um dos algoritmos de ordenação - InsertionSort, SelectionSort ou BubbleSort. */

#include <stdio.h>

// Função de ordenação bubble sort
void bubble(int vetor[], int n);

// Função para trocar dois elementos de posição no vetor
void swap(int vetor[], int a, int b);

// Função para encontrar o menor elemento no vetor maior ou igual a key usando busca binária
int maior_igual(int vetor[], int key, int n);

int main(int argc, char *argv[]) {
    int E, G;
    
    // Leitura do número de tamanhos diferentes de embalagens
    scanf("%d", &E);
    
    int tam_emb[E];
    
    // Leitura dos tamanhos de embalagens
    for (int i = 0; i < E; i++) {
        scanf("%d", &tam_emb[i]);
    }
    
    // Ordenação dos tamanhos de embalagens usando Bubble Sort
    bubble(tam_emb, E);
    
    // Leitura do número de garrafas
    scanf("%d", &G);
    
    int tam_gar[G];
    
    // Leitura dos tamanhos das garrafas
    for (int i = 0; i < G; i++) {
        scanf("%d", &tam_gar[i]);
    }
    
    // Verificação do tamanho da embalagem mais apropriada para cada garrafa
    for (int i = 0; i < G; i++) {
        int tamanho_embalagem = maior_igual(tam_emb, tam_gar[i], E);
        if (tamanho_embalagem == -1) {
            printf("descartar\n");
        } else {
            printf("%d\n", tamanho_embalagem);
        }
    }
    
    return 0;
}

// Implementação do algoritmo Bubble Sort para ordenar o vetor
void bubble(int vetor[], int n) {
    int swapped;
    int i = 0;
    do {
        swapped = 0;
        for (int j = n - 1; j > i; j--) {
            if (vetor[j - 1] > vetor[j]) {
                swap(vetor, j - 1, j);
                swapped = 1;
            }
        }
        i++;
    } while (swapped && i < n);
}

// Função para trocar dois elementos de posição no vetor
void swap(int vetor[], int a, int b) {
    int t = vetor[a];
    vetor[a] = vetor[b];
    vetor[b] = t;
}

// Implementação da busca binária para encontrar o menor elemento no vetor maior ou igual a key
int maior_igual(int vetor[], int key, int n) {
    int imax = n - 1;
    int imin = 0;
    int imid, elemento = -1;
    
    while (imax >= imin) {
        imid = (imax + imin) / 2;
        if (vetor[imid] == key) {
            return vetor[imid];
        } else if (key < vetor[imid]) {
            elemento = vetor[imid];
            imax = imid - 1;
        } else {
            imin = imid + 1;
        }
    }
    return elemento;
}