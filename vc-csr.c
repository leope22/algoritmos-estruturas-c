/* VC-CSR
Uma matriz m x n é considerada esparsa se ela contiver proporcionalmente muitos zeros.
"Muitos" não é uma quantidade claramente definida, mas geralmente, se o número de entradas
não-zero na matriz for proporcional a m + n, então ela é considerada esparsa. Por exemplo,
suponha uma matriz de inteiros 1.000 x 3.000 que tenha 3.000 entradas não-zero. Essa matriz
é esparsa, ocupando 12.000.000 bytes na memória, mas apenas 12.000 bytes não são zeros.

Uma maneira mais econômica de armazenar uma matriz esparsa é utilizando o vetor de coordenadas.
Nessa representação, cada entrada não-zero é representada por uma tripla (i, j, M[i,j]) e essas
triplas são armazenadas em um vetor. Tipicamente (mas não obrigatoriamente), o vetor de coordenadas
é mantido ordenado por i e, para o mesmo i, ordenado por j. A matriz previamente mencionada, com
3.000 não-zeros, seria armazenada em um vetor de 36.000 bytes. Para recuperar a entrada M[i,j], é
necessário realizar uma busca no vetor de coordenadas para encontrar a linha i e, em seguida,
fazer outra busca para encontrar a coluna j.

Outra forma de representação de matrizes esparsas que permite uma recuperação mais rápida do que
o vetor de coordenadas é a CSR (compressed sparse row). Seja M uma matriz m x n com k células
diferentes de zero, com linhas e colunas indexadas a partir de 0. A representação CSR utiliza
3 vetores:
- A, de tamanho k, armazena as células não-zero de M por linhas.
- C, de tamanho k, armazena a coluna de cada elemento de A.
- R, de tamanho m+1, armazena a posição em A do primeiro elemento em cada linha não-vazia de M.
R[m] é igual a k.

Se a linha i estiver vazia, então R[i] será igual a R[t], onde t é a primeira linha após a linha
i que não é vazia. Se não houver tal t, então R[i]=R[m]. R[i+1]-R[i] é o número de células não-zero
na linha i. Um elemento M[i,j] pode ser recuperado da seguinte forma:
1. Inspecciona-se R[i] e R[i+1] para determinar o intervalo ocupado pelos elementos da linha i em C
(e também em A).
2. Se R[i] é igual a R[i+1], então M[i,j] é igual a zero.
3. Senão, j é procurado em C[R[i]], ..., C[R[i+1]-1].
4. Se j existe em [C[R[i]], ..., C[R[i+1]-1]], então o valor de A na mesma posição de C onde j foi
encontrado é M[i,j]. Senão, M[i,j] é igual a zero.

Por exemplo, a matriz 4 x 8:
0 0 0 0 2 0 6 5
4 0 0 0 0 1 0 0
0 0 0 0 0 0 0 0
0 0 0 0 3 0 8 1

É representada como um vetor de coordenadas da seguinte forma:
(0,4,2) (0,6,6) (0,7,5) (1,0,4) (1,5,1) (3,4,3) (3,6,8) (3,7,1)

E é representada da seguinte forma em CSR:
A = 2 6 5 4 1 3 8 1
C = 4 6 7 0 5 4 6 7
R = 0 3 5 5 8

Escreva um programa para manipular uma matriz esparsa de inteiros M. Inicialmente, seu programa
deve ler um conjunto de k triplas (i,j,dado) e armazená-las em um vetor de coordenadas. Em seguida,
deve converter o vetor de coordenadas em CSR. Finalmente, o programa deve usar a representação CSR
para recuperar entradas da matriz esparsa. A entrada começa com uma linha contendo o valor inteiro
k, onde k > 0. Em seguida, seguem-se k linhas contendo i, j e dado, onde i, j ≥ 0. 

As linhas seguintes contêm i e j, onde i, j ≥ 0, e formam uma sequência de coordenadas que devem
ser usadas como consulta para recuperar um dado da matriz. A sequência de consultas é terminada por
valores -1. Para cada linha de consulta, o programa deve imprimir o valor na célula correspondente,
formatado como no exemplo abaixo.

Entrada
9
4 4 9
4 5 8
2 3 6
2 4 5
0 4 3
0 5 7
1 0 1
2 2 2
4 1 4
3 3
1 1
5 5
6 6
2 2
4 4
7 7
-1 -1

Saída
(3,3) = 0
(1,1) = 0
(5,5) = 0
(6,6) = 0
(2,2) = 2
(4,4) = 9
(7,7) = 0 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int i;
    int j;
    int valor;
} vetor;

void bubbleSort_j(vetor *v, int k) {
    int i, j;
    int swapped;

    for (i = 0; i < k-1; i++) {
        swapped = 0;
        for (j = 0; j < k-i-1; j++) {
            if (v[j].j > v[j+1].j) {
                vetor aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

void bubbleSort_i(vetor *v, int k) {
    int i, j;
    int swapped;

    for (i = 0; i < k-1; i++) {
        swapped = 0;
        for (j = 0; j < k-i-1; j++) {
            if (v[j].i > v[j+1].i) {
                vetor aux = v[j];
                v[j] = v[j+1];
                v[j+1] = aux;

                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}

int main() {
    vetor *vc;
    int k;
    scanf("%d", &k);
    vc = (vetor*)malloc(k * sizeof(vetor));
    int i, j, valor;

    for (int a = 0; a < k; ++a) {
        scanf("%d %d %d", &i, &j, &valor);
        vc[a].i = i;
        vc[a].j = j;
        vc[a].valor = valor;
    }
    bubbleSort_i(vc, k);
    int m = vc[k - 1].i + 1;
    int *R;
    R = (int*) malloc((m + 1) * sizeof(int));
    bubbleSort_j(vc, k);
    bubbleSort_i(vc, k);
    int A[k], C[k];

    for (int a = 0; a < k; ++a) {
        A[a] = vc[a].valor;
        C[a] = vc[a].j;
    }
    int maior;

    for (int a = 0; a < k; a++) {
        if (a == 0) {
            C[a] = maior;
        }
        if (C[a] > maior) {
            maior = C[a];
        }
    }
    R[0] = 0;
    R[m] = k;
    int aux = 0;

    for (int a = 1; a < m; a++) {
        R[a] =  R[a - 1];
        for (int b = 0; b < k; b++) {
            if(vc[b].i == a - 1) {
                aux++;
            }
        }
        R[a] = aux;
    }
    free(vc);
    int lin, col;

    do {
        scanf("%d %d", &lin, &col);
        if (lin == -1 && col == -1) {
            break;
        }
        int flag = 0;
        for (int a = 0; a < k; a++) {
            if (col == C[a]) {
                flag = 1;
            }
        }
        if (flag == 1) {
            if (lin >= m) {
                printf("(%d,%d) = 0\n", lin, col);
            } else {
                if (R[lin] == R[lin + 1]) {
                    printf("(%d,%d) = 0\n", lin, col);
                } else {
                    flag = 0;
                    for (int b = R[lin]; b < R[lin+1]; b++) {
                        if ((R[lin+1] - R[lin]) != 0) {
                            if (col == C[b]) {
                                printf("(%d,%d) = %d\n", lin, col, A[b]);
                                flag = 1;
                            }
                            if (col != C[b] && b == R[lin+1] - 1 && flag == 0) {
                                printf("(%d,%d) = 0\n", lin, col);
                            }
                        } else {
                            printf("(%d,%d) = 0\n", lin, col);
                        }
                    }
                }
            }
        } else {
            printf("(%d,%d) = 0\n", lin, col);
        }
    } while (lin != -1 && col != -1);
    
    free(R);
    return 0;
}