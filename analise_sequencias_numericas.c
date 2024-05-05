/* Faça um programa que receba a entrada especificada a seguir e calcule as saídas
solicitadas. Implemente uma solução recursiva para cada informação definida como saída.

Entrada
Serão fornecidas duas linhas na entrada padrão. A primeira contendo apenas um número,
representando o total de números inteiros fornecidos na segunda linha. Os números
estarão separados por um espaço. Não serão fornecidos mais do que 500 números. Pelo
menos 1 número é fornecido.

Saída
Imprima na saída padrão seis linhas, contendo:
- a soma dos números fornecidos;
- o maior elemento;
- o menor elemento;
- se a sequência é estritamente crescente, ou não;
- se a sequência é estritamente decrescente, ou não;
- se a sequência é espelhada (“vetor palíndromo”, números iguais se lidos da
esquerda para a direita ou da direita para a esquerda), ou não;

Exemplo 1 Entrada
10
3 21 -3 5 8 3 5 0 2 1

Exemplo 1 Saída
Soma: 45
Maior: 21
Menor: -3
Crescente: nao
Decrescente: nao
Espelhada: nao

Exemplo 2 Entrada
4
3 10 10 3

Exemplo 2 Saída
Soma: 26
Maior: 10
Menor: 3
Crescente: nao
Decrescente: nao
Espelhada: sim */

#include <stdio.h>

long long int soma(long long int vetor[], long long int tam);
long long int maior(long long int vetor[], long long int indice, long long int tam);
long long int menor(long long int vetor[], long long int tam);
int crescente(long long int vetor[], long long int tam);
int decrescente(long long int vetor[], long long int tam);
int espelhada(long long int vetor[], long long int inicio, long long int fim);

int main(int argc, char *argv[]) {
    long long int qtdnumeros;
    scanf("%lld", &qtdnumeros);
    long long int numeros[qtdnumeros];

    for (long long int i = 0; i < qtdnumeros; i++) {
        scanf("%lld", &numeros[i]);
    }

    printf("Soma: %lld\n", soma(numeros, qtdnumeros));
    printf("Maior: %lld\n", maior(numeros, 0, qtdnumeros));
    printf("Menor: %lld\n", menor(numeros, qtdnumeros));
    printf("Crescente: %s\n", crescente(numeros, qtdnumeros) ? "sim" : "nao");
    printf("Decrescente: %s\n", decrescente(numeros, qtdnumeros) ? "sim" : "nao");
    printf("Espelhada: %s\n", espelhada(numeros, 0, qtdnumeros - 1) ? "sim" : "nao");
    return 0;
}

long long int soma(long long int vetor[], long long int tam) {
    long long int soma = 0;
    for (long long int i = 0; i < tam; i++) {
        soma += vetor[i];
    }
    return soma;
}

long long int maior(long long int vetor[], long long int indice, long long int tam) {
    if (indice == tam - 1) {
        return vetor[indice];
    }
    long long int prox_maior = maior(vetor, indice + 1, tam);
    return (vetor[indice] > prox_maior) ? vetor[indice] : prox_maior;
}

long long int menor(long long int vetor[], long long int tam) {
    if (tam == 1) {
        return vetor[0];
    }
    long long int menor_elemento = menor(vetor, tam - 1);
    return (menor_elemento < vetor[tam - 1]) ? menor_elemento : vetor[tam - 1];
}

int crescente(long long int vetor[], long long int tam) {
    for (long long int i = 1; i < tam; i++) {
        if (vetor[i] < vetor[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int decrescente(long long int vetor[], long long int tam) {
    for (long long int i = 1; i < tam; i++) {
        if (vetor[i] > vetor[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int espelhada(long long int vetor[], long long int inicio, long long int fim) {
    if (inicio >= fim) {
        return 1;
    }
    if (vetor[inicio] == vetor[fim]) {
        return espelhada(vetor, inicio + 1, fim - 1);
    } else {
        return 0;
    }
}