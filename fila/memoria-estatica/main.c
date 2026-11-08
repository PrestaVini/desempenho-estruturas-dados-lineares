#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fila.h"

extern Fila f;

int main(int argc, char *argv[]) {
	int temp;
	int opcao;
	double start, finish, elapsed;
	int quantidade;
	inicializar();

	do {
		printf("Digite a quantidade de elementos para testar: ");
		scanf("%d", &quantidade);
		limparTela();
		if(quantidade <= 0 || quantidade > TAM_MAX) {
			printf("\nQuantidade invalida! O numero deve estar entre 1 e %d\n\n", TAM_MAX);
		}
	} while(quantidade <= 0 || quantidade > TAM_MAX);

	do {
		printf("\n\nQUANTIDADE: %d\n\n", quantidade);
		printf("\n    MENU");
		printf("\n1. Limpar fila");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Mudar quantidade de elementos");
		printf("\n0. Sair");
		printf("\nDigite a opcao desejada: ");

		scanf("%d", &opcao);

		switch(opcao) {
		case 1:
			limparTela();
			inicializar();
			break;
		case 2:
			limparTela();
			if(f.fim + quantidade < TAM_MAX) {
				start = (double) clock();
				for(int i = 0; i < quantidade; i++) {
					temp = obterDado();
					inserir(temp);
					exibirDado(temp);
				}
				finish = (double) clock();
				calcularTempo(finish, start);
			} else {
				printf("A fila nao possui espaco suficiente para essa quantidade de elementos!");
			}
			break;
		case 3:
			limparTela();
			if(!verificarVazia()) {
				start = (double) clock();
				for(int i = 0; i < quantidade; i++) {
					if(!verificarVazia()) {
						temp = remover();
						printf("\nNumero removido: %d", temp);
					}
				}
				finish = (double) clock();
				calcularTempo(finish, start);
			} else {
				printf("\nA fila estah vazia!\n");
			}
			break;
		case 4:
			limparTela();
			start = (double) clock();
			imprimir();
			finish = (double) clock();
			calcularTempo(finish, start);
			break;
		case 5:
			limparTela();
			inicializar();
			printf("Quantidade atual: %d\n\n", quantidade);
			do {
				printf("Digite a nova quantidade de elementos para testar: ");
				scanf("%d", &quantidade);
				if (quantidade <= 0 || quantidade > TAM_MAX) {
					printf("\nQuantidade invalida! O numero deve estar entre 1 e %d\n\n", TAM_MAX);
				}
			} while (quantidade <= 0 || quantidade > TAM_MAX);
			break;
		case 0:
			limparTela();
			printf("Encerrando o programa...");
			break;
		default:
			limparTela();
			printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}

	} while(opcao != 0);
}

