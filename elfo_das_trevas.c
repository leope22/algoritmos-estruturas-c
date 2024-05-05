/* O Elfo das Trevas

Por Jean Bez, Beecrowd BR Brazil
O estábulo onde ficam as renas foi intencionalmente aberto pelo Elfo das Trevas,
permitindo que cada uma delas corresse e voasse livremente pela fábrica do Papai
Noel, causando o maior transtorno. Os elfos estão tentando desesperadamente fazer
o possível para deixar o trenó pronto para embarque. Você ficou responsável por
colocar cada rena na sua posição correta assim que ela é capturada por um dos
outros elfos. Você sabe que o estábulo segue uma organização baseada na ordem 
que as renas irão ocupar no trenó. Desta forma, na hora da partida todas podem
ser facilmente posicionadas. Diferentemente do que muitos pensam, as renas são
posicionadas em uma fila única à frente no trenó. Nem todas as renas do estábulo
são utilizadas em cada viagem, isto depende da carga total do trenó.

Você conseguiu a lista com as características que são utilizadas para determinar
a ordem de rena. Elas devem ser ordenadas primeiramente de forma decrescente por
peso. Caso duas ou mais apresentem o mesmo peso, elas devem ser ordenadas de forma
ascendente pela idade, após pela altura e, caso ainda persista empate, pelo nome.
Utilizando seu computador mágico de última geração, você quer escrever um programa
que ordene as renas, de acordo com as características informadas, e exiba somente
o número exato de renas que serão utilizadas no trenó (de forma ordenada).

Entrada
A primeira linha de cada caso de teste contém dois inteiros N e M que indicam
respectivamente o número total de renas e o número de renas que irão puxar o trenó.
Na sequência, serão informados uma string S seguida por 2 inteiros P e I e por um
número de ponto flutuante A, indicando respectivamente o nome, o peso, a idade e a
altura de cada uma das renas. O nome de cada uma das renas é composto somente por
uma palavra com até 100 caracteres.

Saída
Para cada caso de teste, você deverá exibir a mensagem "CENARIO", seguido da posição
e o nome de cada uma das M renas que irão puxar o trenó, ordenadas conforme descrito
acima.

Exemplo 1 Entrada
9 5
Rudolph 50 100 1.12
Dasher 10 121 1.98
Dancer 10 131 1.14
Prancer 7 142 1.36
Vixen 50 110 1.42
Comet 50 121 1.21
Cupid 50 107 1.45
Donner 30 106 1.23
Blitzen 50 180 1.84

Exemplo 1 Saída
CENARIO
1 - Rudolph
2 - Cupid
3 - Vixen
4 - Comet
5 - Blitzen

Exemplo 2 Entrada
3 1
Dasher 10 121 1.98
Dancer 10 131 1.14
Rudolph 50 100 1.12

Exemplo 2 Saída
CENARIO
1 - Rudolph */

#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char nome[MAX];
    long long int peso, idade;
    double altura;
} rena;

int main(int argc, char *argv[]) {
    long long int N, M;
    
    scanf("%lld %lld", &N, &M);
    
    rena aux, renas[N];
    
    for (long long int i = 0; i < N; i++) {
        scanf("%s %lld %lld %lf", renas[i].nome, &renas[i].peso, &renas[i].idade, &renas[i].altura);
    }
    
    long long int min;
    
    for (long long int i = N - 1; i >= 0; i--) {
        min = i;
        for (long long int j = i - 1; j >= 0; j--) {
            if (renas[min].peso > renas[j].peso) {
                min = j;
            }
        }
        if (i != min) {
            aux = renas[i];
            renas[i] = renas[min];
            renas[min] = aux;
        }
    }
    
    for (long long int i = 0; i < N; i++) {
        min = i;
        for (long long int j = i + 1; j < N; j++) {
            if (renas[i].peso == renas[j].peso) {
                if (renas[i].idade > renas[j].idade) {
                    min = j;
                }
            }
        }
        if (i != min) {
            aux = renas[i];
            renas[i] = renas[min];
            renas[min] = aux;
        }
    }
    
    for (long long int i = 0; i < N; i++) {
        min = i;
        for (long long int j = i + 1; j < N; j++) {
            if (renas[i].peso == renas[j].peso && renas[i].idade == renas[j].idade) {
                if (renas[i].altura < renas[j].altura) {
                    min = j;
                }
            }
        }
        if (i != min) {
            aux = renas[i];
            renas[i] = renas[min];
            renas[min] = aux;
        }
    }
    
    for (long long int i = 0; i < N; i++) {
        for (long long int j = i + 1; j < N; j++) {
            if (renas[i].peso == renas[j].peso && renas[i].idade == renas[j].idade && renas[i].altura == renas[j].altura) {
                if (strcmp(renas[i].nome, renas[j].nome) > 0) {
                    aux = renas[i];
                    renas[i] = renas[j];
                    renas[j] = aux;
                }
            }
        }
    }
    
    printf("CENARIO\n");
        
    for (long long int i = 0; i < M; i++) {
        printf("%lld - %s\n", (i + 1), renas[i].nome);
    }

    return 0;
}