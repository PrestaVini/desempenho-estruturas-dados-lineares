#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "lista.h"

// Le um inteiro com seguranca: se digitarem letra, pede de novo.
int lerInteiro() {
	int n, c;
	while (scanf("%d", &n) != 1) {
		if (feof(stdin)) {
			exit(0);
		}
		while ((c = getchar()) != '\n' && c != EOF);
		printf("Entrada invalida. Digite um numero: ");
	}
	return n;
}

int lerQuantidade() {
	int q;
	printf("Digite a quantidade de elementos para testar: ");
	q = lerInteiro();
	while (q < 1 || q > TAM_MAX) {
		printf("Quantidade invalida (use de 1 a %d). Digite novamente: ", TAM_MAX);
		q = lerInteiro();
	}
	return q;
}

int main(int argc, char *argv[]) {
	double start, finish, elapsed;
	int quantidade;
	int opcao, p, posicao, indice, i;

	srand(time(NULL));
	quantidade = lerQuantidade();
	inicializar();
	limparTela();

	do {
		printf("\n\n     MENU");
		printf("\n1. Inserir %d elementos na lista", quantidade);
		printf("\n2. Remover %d elementos da lista", quantidade);
		printf("\n3. Imprimir a lista");
		printf("\n4. Inicializar lista");
		printf("\n5. Sair");
		printf("\n-- Operacoes extras da lista --");
		printf("\n6. Inserir um elemento em uma posicao");
		printf("\n7. Remover um elemento de uma posicao");
		printf("\n8. Buscar um valor");
		printf("\n9. Mudar quantidade de elementos");
		printf("\nDigite a opcao: ");
		opcao = lerInteiro();

		switch(opcao) {
			case 1:
				limparTela();
				inicializar();
				start = (double) clock();
				for (i = 0; i < quantidade; i++) {
					p = obterDado();
					inserirFim(p);
					exibirDado(p);
				}
				finish = (double) clock();
				elapsed = finish - start;
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 2:
				limparTela();
				inicializar();
				for (i = 0; i < quantidade; i++) {
					inserirFim(obterDado());
				}
				start = (double) clock();
				for (i = 0; i < quantidade; i++) {
					removerPosicao(0, &p);
					exibirDado(p);
				}
				finish = (double) clock();
				elapsed = finish - start;
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 3:
				limparTela();
				inicializar();
				for (i = 0; i < quantidade; i++) {
					inserirFim(obterDado());
				}
				start = (double) clock();
				imprimir();
				finish = (double) clock();
				elapsed = finish - start;
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 4:
				limparTela();
				inicializar();
				break;
			case 5:
				limparTela();
				printf("Encerrando o programa...");
				break;
			case 6:
				limparTela();
				printf("Posicao para inserir (0 a %d): ", tamanho());
				posicao = lerInteiro();
				p = obterDado();
				if (inserirPosicao(p, posicao)) {
					printf("\nElemento %d inserido na posicao %d.", p, posicao);
				} else {
					printf("\nNao foi possivel inserir (posicao invalida ou lista cheia).");
				}
				break;
			case 7:
				limparTela();
				if (verificarVazia()) {
					printf("A lista esta vazia!");
					break;
				}
				printf("Posicao para remover (0 a %d): ", tamanho() - 1);
				posicao = lerInteiro();
				if (removerPosicao(posicao, &p)) {
					printf("\nNumero removido: %d", p);
				} else {
					printf("\nPosicao invalida.");
				}
				break;
			case 8:
				limparTela();
				printf("Valor a buscar: ");
				p = lerInteiro();
				indice = buscar(p);
				if (indice == -1) {
					printf("\nValor %d nao encontrado.", p);
				} else {
					printf("\nValor %d encontrado na posicao %d.", p, indice);
				}
				break;
			case 9:
				limparTela();
				inicializar();
				printf("Quantidade atual: %d\n\n", quantidade);
				quantidade = lerQuantidade();
				break;
			default:
				limparTela();
				printf("\nOpcao invalida. Escolha um numero de 1 a 9.");
		}

	} while(opcao != 5);

	return 0;
}
