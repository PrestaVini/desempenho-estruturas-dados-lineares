#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "lista.h"

Lista l;

// Libera todos os nos (se houver) e deixa a lista vazia.
void inicializar() {
	No *atual = l.inicio;
	No *proximo;
	while (atual != NULL) {
		proximo = atual->proximo;
		free(atual);
		atual = proximo;
	}
	l.inicio = NULL;
	l.fim = NULL;
	l.quantidade = 0;
}

int verificarVazia() {
	if (l.inicio == NULL) {
		return 1;
	} else {
		return 0;
	}
}

int tamanho() {
	return l.quantidade;
}

// Insere no final da lista. Retorna 1 se inseriu e 0 se faltou memoria.
int inserirFim(int numero) {
	No *novo = (No *) malloc(sizeof(No));
	if (novo == NULL) {
		return 0;
	}
	novo->valor = numero;
	novo->proximo = NULL;
	if (verificarVazia()) {
		l.inicio = novo;
	} else {
		l.fim->proximo = novo;
	}
	l.fim = novo;
	l.quantidade++;
	return 1;
}

// Insere em qualquer posicao de 0 ate tamanho().
// Nenhum elemento e deslocado: so os ponteiros sao religados.
int inserirPosicao(int numero, int posicao) {
	No *novo, *anterior;
	int i;
	if (posicao < 0 || posicao > l.quantidade) {
		return 0;
	}
	if (posicao == l.quantidade) {
		return inserirFim(numero);
	}
	novo = (No *) malloc(sizeof(No));
	if (novo == NULL) {
		return 0;
	}
	novo->valor = numero;
	if (posicao == 0) {
		novo->proximo = l.inicio;
		l.inicio = novo;
	} else {
		anterior = l.inicio;
		for (i = 0; i < posicao - 1; i++) {
			anterior = anterior->proximo;
		}
		novo->proximo = anterior->proximo;
		anterior->proximo = novo;
	}
	l.quantidade++;
	return 1;
}

// Remove o elemento da posicao e devolve o valor por ponteiro.
int removerPosicao(int posicao, int *valor) {
	No *removido, *anterior;
	int i;
	if (verificarVazia() || posicao < 0 || posicao >= l.quantidade) {
		return 0;
	}
	if (posicao == 0) {
		removido = l.inicio;
		l.inicio = removido->proximo;
		if (l.inicio == NULL) {
			l.fim = NULL;
		}
	} else {
		anterior = l.inicio;
		for (i = 0; i < posicao - 1; i++) {
			anterior = anterior->proximo;
		}
		removido = anterior->proximo;
		anterior->proximo = removido->proximo;
		if (removido == l.fim) {
			l.fim = anterior;
		}
	}
	*valor = removido->valor;
	free(removido);
	l.quantidade--;
	return 1;
}

// Busca sequencial. Retorna a posicao do primeiro encontrado ou -1.
int buscar(int numero) {
	No *atual = l.inicio;
	int i = 0;
	while (atual != NULL) {
		if (atual->valor == numero) {
			return i;
		}
		atual = atual->proximo;
		i++;
	}
	return -1;
}

void imprimir() {
	No *atual;
	if (!verificarVazia()) {
		printf("\n\nValores: \n");
		for (atual = l.inicio; atual != NULL; atual = atual->proximo) {
			printf("\n%d\n", atual->valor);
		}
		printf("\n\nEnderecos: \n");
		for (int i = 0; i < l.quantidade; i++) {
			printf("\n%d\n", i);
		}
	} else {
		printf("A lista esta vazia!");
	}
}

//Funcoes para o relatorio

void limparTela() {
	printf("\033[2J\033[H");
}

int numeroAleatorio(int low, int high) {
	int k;
	double d;
	d = (double) rand () / ((double) TAM_MAX + 1);
	k = d * (high - low + 1);
	return low + k;
}

int obterDado() {
	return numeroAleatorio(0, TAM_MAX);
}

void exibirDado(int p) {
	printf("\nElemento: %i", p);
}
