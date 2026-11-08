#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fila.h"

Fila f;

void inicializar() {
	f.inicio = NULL;
	f.fim = NULL;
}

int verificarVazia() {
	if (f.inicio == NULL && f.fim == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void inserir(int valorInput) {
	No *novoNoh;
	novoNoh = malloc(sizeof(No));

	if(novoNoh != NULL) {
		novoNoh->valor = valorInput;
		novoNoh->proximoEndereco = NULL;

		if(f.inicio == NULL) {
			f.inicio = novoNoh;
			f.fim = novoNoh;
		} else {
			f.fim->proximoEndereco = novoNoh;
			f.fim = novoNoh;
		}
	} else {
		printf("A memoria estah cheia!");
	}
}

void imprimir() {
	if (!verificarVazia()) {
		No *noAux;
		noAux = f.inicio;
		do {
			printf("\nValor: %d Endereco: %p\n", noAux->valor, (void *)noAux);
			noAux = noAux->proximoEndereco;
		} while(noAux != NULL);
	} else {
		printf("A fila esta vazia!");
	}
}

int remover() {
	if (!verificarVazia()) {
		int dadoRemovido = f.inicio->valor;
		No *proximoEnderecoSalvo = f.inicio->proximoEndereco;
		free(f.inicio);
		f.inicio = proximoEnderecoSalvo;
		if (f.inicio == NULL) {
			f.fim = NULL;
		}
		return dadoRemovido;
	} else {
		return 0;
	}
}

//Funcoes para o relatorio

void limparTela() {
	printf("\033[2J\033[H");
}

int numeroAleatorio(int low, int high) {
	int k;
	double d;
	d = (double) rand () / ((double) RAND_MAX + 1);
	k = d * (high - low + 1);
	return low + k;
}

int obterDado() {
	return numeroAleatorio(0, TAM_MAX);
}

void exibirDado(int p) {
	printf("\nElemento: %i", p);
}

void calcularTempo(double finish, double start) {
	double elapsed = (finish - start);
	printf("\n\nForam utilizados %.2f clocks\n\n", elapsed);
}
