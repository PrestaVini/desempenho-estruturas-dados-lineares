#include <stdio.h>
#include "pilha.h"
#include <time.h>
#include <math.h>

int main(int argc, char *argv[]) {
	int temp;
	int opcao;
	int i;
	double start, finish, elapsed;
	int quantidade;
	inicializar();

	printf("Digite a quantidade de elementos para testar: ");
	scanf("%d", &quantidade);

	do {
		//exibir o menu
		printf("\n    MENU");
		printf("\n1. Inicializar");
		printf("\n2. Inserir");
		printf("\n3. Remover");
		printf("\n4. Imprimir");
		printf("\n5. Realizar teste completo da pilha");
		printf("\n8. Sair");
		printf("\nDigite a opcao desejada: ");
		
		//ler a opcao desejada pelo usuario
		scanf("%d", &opcao);
		
		//processar a funcionalidade
		switch(opcao) {
			case 1:
				inicializar();
				break;
			case 2:
				//guarda o valor do clock antes de executar as chamadas da funcao
				start = (double) clock();
				for(i = 0; i < quantidade; i++) {
					temp = obterDado();
					push(temp);
					exibirDado(temp);
				}
				//guarda o valor do clock apos executar as chamadas da funcao
				finish = (double) clock();
				//calcula a diferenca de clocks entre o depois e antes das chamadas
				elapsed = finish - start;
				//imprime na tela a quantidade de clocks gastos
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 3:
				start = (double) clock();
				for(i = 0; i < quantidade; i++) {
					temp = pop();
					printf("\nNumero removido: %d", temp);
				}
				finish = (double) clock();
				elapsed = finish - start;
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 4:
				start = (double) clock();
				imprimir();
				finish = (double) clock();
				elapsed = finish - start;
				printf("\nForam utilizados %.2f clocks", elapsed);
				break;
			case 5:
				testar1_VaziaPilha();
				testar3_RemoverPilha();
				testar4_RemoverPilha(1);
				testar4_RemoverPilha(2);
				testar4_RemoverPilha(3);
				testar4_RemoverPilha(4);
				testar4_RemoverPilha(5);
				testar4_RemoverPilha(6);
				break;
			case 8:
				inicializar();
				printf("Encerrando o programa...");
				break;
			default:
				printf("\nOpcao invalida. Escolha um numero valido de opcao.");
		}
		
	} while(opcao != 8);
}
