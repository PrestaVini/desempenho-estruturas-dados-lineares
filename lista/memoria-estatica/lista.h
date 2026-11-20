#ifndef LISTA_H
#define LISTA_H

#define TAM_MAX 50000

typedef struct lista {
	int vetor[TAM_MAX];
	int fim;
} Lista;

void inicializar();
int verificarVazia();
int verificarCheia();
int tamanho();
int inserirFim(int numero);
int inserirPosicao(int numero, int posicao);
int removerPosicao(int posicao, int *valor);
int buscar(int numero);
void imprimir();

//Funcoes para o relatorio

void limparTela();
int numeroAleatorio(int low, int high);
int obterDado();
void exibirDado(int p);

#endif
