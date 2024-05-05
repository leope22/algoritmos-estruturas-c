/* Deque
Faça um programa que utilize a mesma API de deque definida anteriormente, apenas
alterando a sua implementação. Este programa irá ler uma entrada de comandos, conforme
especificado abaixo, e gerar a saída correspondente.

Entrada
A primeira linha contém dois números N (1 ≤ N ≤ 550.000) e M, representando o número
de comandos e o número máximo de elementos que podem ser armazenados na deque, respectivamente.
Em seguida, temos N linhas. Cada linha é iniciada pela palavra “insereI”, “insereF”, “removeI”
ou “removeF”, representando a operação que deve ser executada na deque (“I” indica início e
“F” indica fim). Caso a operação seja “insereI” ou “insereF”, teremos logo em seguida o número
inteiro a ser inserido, na mesma linha. Esse número deve ser inserido na deque se esta não
tiver atingido sua capacidade máxima. Caso tenha atingido a capacidade máxima definida, o
programa deve imprimir uma linha contendo a palavra “cheia”. Caso a operação seja “removeI”
ou “removeF”, o programa deve imprimir na tela o número inteiro que saiu da deque ou a
palavra “vazia”.

Saída
Imprima uma linha para cada operação “removeI” ou “removeF”, contendo o número inteiro que
saiu da deque devido à operação. Caso a deque esteja vazia no momento, imprima na linha a
palavra “vazia”. Imprima uma linha contendo a palavra “cheia” para cada operação “insereI”
ou “insereF” que tenha a deque cheia no momento. */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deque.h"

/* São implementadas as funções do deque em alocação dinâmica e encadeamento duplo,
assim como uma lista encadeada. Como a lista encadeada não assume um tamanho máximo
em sua alocação dinâmica, foi necessário alterar a função de verificação se o deque
está cheio na própria função principal (main). Além disso, as operações com o tamanho
máximo anteriormente utilizadas para evitar que o deque ultrapassasse o tamanho do
vetor já não são mais necessárias. Por isso, essas mudanças foram feitas. */

/* int main()
{
	deque q;
	int op;
	int item;
	for(int i = 0; i < 13; i++){
		scanf("%d", &op);
		switch(op){
			case 1:
				scanf("%d", &item);
				inserirI(&q, item);
				break;
			case 2:
				scanf("%d", &item);
				inserirF(&q, item);
				break;
			case 3:
				removerI(&q);
				break;
			case 4:
				removerF(&q);
				break;
			case 5:
				mostrar();
				break;
			default:
				break;
		}
	}
	return 0;
} */

int main(int argc,char *argv[])
{
	int N, M, num, item;
	
	scanf("%d %d", &N, &M);
	
	int tam = 0;
	
	deque q;
	
	char op[7];
	char iI[] = "insereI";
	char iF[] = "insereF";
	char rI[] = "removeI";
	char rF[] = "removeF";
	char m[] = "mostra";
	
	for(int i = 0; i < N; i++){
		
		scanf("%s", op);
		
		if(strcmp(iI, op) == 0){
			scanf("%d", &num);
			if(tam == M){
				printf("cheia\n");
			}else{
				inserirI(&q, num);
				tam++;
			}
		}
		if(strcmp(iF, op) == 0){
			scanf("%d", &num);
			if(tam == M){
				printf("cheia\n");
			}else{
				inserirF(&q, num);
				tam++;
			}
		}
		if(strcmp(rI, op) == 0){
			if(vazia()){
				printf("vazia\n");
			}else{
				item = removerI(&q);
				printf("%d\n", item);
				tam--;
			}
		}
		if(strcmp(rF, op) == 0){
			if(vazia()){
				printf("vazia\n");
			}else{
				item = removerF(&q);
				printf("%d\n", item);
				tam--;
			}
		}
		if(strcmp(m, op) == 0){
			mostrar();
		}
	}
	return 0;
}