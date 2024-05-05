/* Em certos casos, a abordagem iterativa pode ser a escolha preferida para resolver um problema,
seja pela elegância ou pela eficiência computacional. Contudo, nesta atividade, você descobrirá
que a versão recursiva pode se tornar a sua preferida. Mesmo que não seja o caso, resolva-o de
forma recursiva.

Problema: Marcação de régua inglesa (polegadas)
Cada polegada é marcada por uma linha seguida de um número. Internamente, as frações são indicadas
por linhas menores, cujo tamanho diminui à medida que dividem o espaço pela metade. Assim, são
formadas frações como 1/2, 1/4, 1/8 e assim por diante, dependendo do número de subdivisões
desejadas. Para as subdivisões das polegadas, é comum não marcar os números ou frações, pois
o tamanho da linha já indica isso. Abaixo estão exemplos usando uma combinação de traços "-"
para representar o tamanho de cada linha. Foram utilizadas quantidades diferentes de subdivisões
em cada exemplo, resultando em escalas diferentes.

Entrada:
Serão fornecidos dois números, um em cada linha. O primeiro número representa o tamanho total da
régua (0 ≤ tamanho ≤ 100). O segundo número representa o tamanho, em quantidade de traços "-", da
marcação da polegada inteira (1 ≤ quantidade ≤ 15). Para os exemplos acima, as entradas seriam
2 e 4, 1 e 5, e por fim, 4 e 3.

Saída:
Imprima a régua completa, criando as divisões necessárias para representar apenas um traço "-" na
menor marcação.

Observações:
- Submeta o código-fonte completo, contendo todas as funções implementadas;
- Documente adequadamente o seu código, incluindo sua identificação;
- Evite o uso de variáveis globais;
- Você também pode optar por usar iterações. */

#include <stdio.h>

void linhas(long long int comprimento, long long int rotulo);
void ciclo(long long int comprimento);
void regua(long long int tam_regua, long long int qtd_tracos);

int main(int argc, char *argv[]) {
    long long int tam_regua, qtd_tracos;
	
    scanf("%lld", &tam_regua);
    scanf("%lld", &qtd_tracos);
	
    regua(tam_regua, qtd_tracos);
	
    return 0;
}

// Função que imprime uma linha de tamanho dado e, se o rótulo for não negativo,
// imprime também o rótulo
void linhas(long long int comprimento, long long int rotulo) {
    for (long long int j = 0; j < comprimento; j++) {
        printf("-");
    }
    if (rotulo >= 0) {
        printf(" %lld", rotulo);
    }
    printf("\n");
}

// Função recursiva que desenha uma série de ciclos de subdivisões
void ciclo(long long int comprimento) {
    if (comprimento >= 1) {
        ciclo(comprimento - 1); 
        linhas(comprimento, -1);
        ciclo(comprimento - 1);
    }
}

// Função principal que desenha a régua completa
void regua(long long int tam_regua, long long int qtd_tracos) {
    linhas(qtd_tracos, 0); // Primeira linha da régua
    for (long long int j = 1; j <= tam_regua; j++) {
        ciclo(qtd_tracos - 1); // Desenha as subdivisões
        linhas(qtd_tracos, j); // Desenha a linha principal
    }
}