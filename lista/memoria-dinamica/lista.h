#ifndef LISTA_H
#define LISTA_H

// Na memoria dinamica a lista nao tem tamanho maximo.
// TAM_MAX so limita a quantidade de elementos usada nos testes.
#define TAM_MAX 50000

typedef struct no {
	int valor;
	struct no *proximo;
} No;

typedef struct lista {
	No *inicio;
	No *fim;
	int quantidade;
} Lista;

void inicializar();
int verificarVazia();
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
