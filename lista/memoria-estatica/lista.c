#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "lista.h"

Lista l;

void inicializar() {
	l.fim = -1;
}

int verificarVazia() {
	if (l.fim == -1) {
		return 1;
	} else {
		return 0;
	}
}

int verificarCheia() {
	if (l.fim == TAM_MAX - 1) {
		return 1;
	} else {
		return 0;
	}
}

int tamanho() {
	return l.fim + 1;
}

// Insere no final da lista. Retorna 1 se inseriu e 0 se nao coube.
int inserirFim(int numero) {
	if (!verificarCheia()) {
		l.fim++;
		l.vetor[l.fim] = numero;
		return 1;
	} else {
		return 0;
	}
}

// Insere em qualquer posicao de 0 ate tamanho().
// Os elementos da posicao em diante sao deslocados para a direita.
int inserirPosicao(int numero, int posicao) {
	int i;
	if (verificarCheia() || posicao < 0 || posicao > tamanho()) {
		return 0;
	}
	for (i = l.fim; i >= posicao; i--) {
		l.vetor[i + 1] = l.vetor[i];
	}
	l.vetor[posicao] = numero;
	l.fim++;
	return 1;
}

// Remove o elemento da posicao e devolve o valor por ponteiro.
// Os elementos seguintes sao deslocados para a esquerda.
int removerPosicao(int posicao, int *valor) {
	int i;
	if (verificarVazia() || posicao < 0 || posicao > l.fim) {
		return 0;
	}
	*valor = l.vetor[posicao];
	for (i = posicao; i < l.fim; i++) {
		l.vetor[i] = l.vetor[i + 1];
	}
	l.fim--;
	return 1;
}

// Busca sequencial. Retorna a posicao do primeiro encontrado ou -1.
int buscar(int numero) {
	int i;
	for (i = 0; i <= l.fim; i++) {
		if (l.vetor[i] == numero) {
			return i;
		}
	}
	return -1;
}

void imprimir() {
	if (!verificarVazia()) {
		printf("\n\nValores: \n");
		for (int i = 0; i <= l.fim; i++) {
			printf("\n%d\n", l.vetor[i]);
		}
		printf("\n\nEnderecos: \n");
		for (int i = 0; i <= l.fim; i++) {
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
