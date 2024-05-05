/* Times

Nome do arquivo fonte: times.c, times.cpp ou times.pas
As aulas de educação física, em muitas escolas, acontecem da seguinte maneira:
o professor entrega uma bola aos alunos (geralmente de futebol) e estes se dividem
em times, onde jogam partidas alternadamente. A maneira como os times são escolhidos
também é semelhante em todas as escolas: decide-se quantos times serão formados, e uma
pessoa para montar cada um dos times. Cada pessoa vai escolher, alternadamente, um dos
alunos restantes para fazer parte de sua equipe. Como todos querem ter uma boa equipe,
a pessoa que vai escolher o próximo membro do time escolhe aquele, dentre os ainda
disponíveis, que possui o melhor nível de habilidade. Assim, os times acabam ficando
relativamente equilibrados na soma do nível de habilidade dos jogadores.

Tarefa
Dada uma lista de alunos que serão escolhidos e seus respectivos níveis de habilidade
para os times e a quantidade de times que serão formados, mostre como ficarão os times
ao final do processo de montagem dos mesmos.

Entrada
A primeira linha da entrada contém dois inteiros N (2 ≤ N ≤ 10.000) e T (2 ≤ T ≤ 1000),
representando respectivamente a quantidade de alunos e o número de times a serem formados,
sendo T ≤ N. As N linhas seguintes descrevem, cada uma, um aluno disponível para escolha
de times. Cada uma dessas linhas possui o nome do aluno (composto apenas por letras
minúsculas) e um inteiro H (0 ≤ H ≤ 1.000.000) descrevendo seu nível de habilidade. Não
existem dois alunos com o mesmo nível de habilidade, e todos eles possuem nomes diferentes.
É possível que alguns times acabem ficando com menos jogadores do que os outros.

Saída
Seu programa deve imprimir a lista de times que será formada ao final do processo de seleção.
Para cada time, você deverá mostrar o termo “Time N”, onde N é o número do time (1 para o
primeiro, 2 para o segundo, e assim por diante) seguido de K linhas, onde K é a quantidade de
jogadores do time, mostrando o nome de cada um dos jogadores do time, em ordem alfabética.
Imprima uma linha em branco após cada descrição de time (inclusive do último).

Os times serão escolhidos pelo computador, então não é necessário considerar o aluno que irá
fazer a escolha dos times. */

#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    char nome[MAX];
    int nivelhab;
    int time;
} aluno;

int main() {
    long int qtdalunos, qtdtimes;

    scanf("%ld %ld", &qtdalunos, &qtdtimes);

    aluno aux, alunos[qtdalunos];

    // Ler os dados dos alunos
    for (long int i = 0; i < qtdalunos; i++) {
        scanf("%s %d", alunos[i].nome, &alunos[i].nivelhab);
    }

    // Ordenar os alunos por nível de habilidade
    for (long int i = 0; i < qtdalunos - 1; i++) {
        for (long int j = i + 1; j < qtdalunos; j++) {
            if (alunos[j].nivelhab > alunos[i].nivelhab) {
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }

    // Atribuir times aos alunos
    for (long int i = 0; i < qtdalunos; i++) {
        alunos[i].time = (i % qtdtimes) + 1;
    }

    // Ordenar os alunos por nome
    for (long int i = 0; i < qtdalunos - 1; i++) {
        for (long int j = i + 1; j < qtdalunos; j++) {
            if (strcmp(alunos[i].nome, alunos[j].nome) > 0) {
                aux = alunos[i];
                alunos[i] = alunos[j];
                alunos[j] = aux;
            }
        }
    }

    // Imprimir os times
    for (long int i = 1; i <= qtdtimes; i++) {
        printf("Time %ld\n", i);
        for (long int j = 0; j < qtdalunos; j++) {
            if (alunos[j].time == i) {
                printf("%s\n", alunos[j].nome);
            }
        }
        printf("\n");
    }

    return 0;
}