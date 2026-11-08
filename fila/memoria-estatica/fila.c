#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "fila.h"

Fila f;

void inicializar() {

	f.fim = -1;

}

int verificarVazia() {

	if (f.fim == -1) {
		return 1;
	} else {
		return 0;
	}

}

int verificarCheia() {
	if (f.fim == TAM_MAX - 1) {
		return 1;
	} else {
		return 0;
	}
}

void inserir(int numero) {
	if (!verificarCheia()) {
		f.fim++;
		f.vetor[f.fim] = numero;
	}
}

void imprimir() {
	if (!verificarVazia()) {
		for (int i = 0; i <= f.fim; i++) {
			printf("\nValor: %d Endereco: %d\n", f.vetor[i], i);
		}
	}
}

int remover() {
	if (!verificarVazia()) {
		int aux, i;
		aux = f.vetor[0];
		for (i = 0; i < f.fim; i++) {
			f.vetor[i] = f.vetor[i + 1];
		}
		f.fim--;
		return aux;
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


