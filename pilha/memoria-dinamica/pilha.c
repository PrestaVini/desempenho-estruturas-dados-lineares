#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#include <time.h>
#include <math.h>


Pilha pilha;
Pilha *p = &pilha;

void inicializar() {
	No *aux;

	while (p->topo != NULL) {
		aux = p->topo;
		p->topo = p->topo->prox;
		free(aux);
	}
}

int verificarVazia() {
	if(p->topo == NULL){
		return 1;
	}else {
		return 0;
	}
}

void push(int dado) {
    No *novoNo = malloc(sizeof(No));

    if(novoNo != NULL) {
        novoNo->dado = dado;
        novoNo->prox = p->topo;
        p->topo = novoNo;
    } else {
        printf("Acabou a memoria");
    }
}

void imprimir() {
	if(!verificarVazia()){
		No *aux;

		aux = p->topo;
		while(aux != NULL){
			printf("\n%d", aux->dado);
			aux = aux->prox;
		}
	}else{
		printf("A pilha esta vazia");
		return;
	}
    //verificar se a pilha nao estah vazia
	    //Declara uma variavel ponteiro auxiliar para percorrer os nohs da pilha
        //comeca a percorrer a partir do topo, enquanto nao chegar no fim, 
		//processa e vai para o noh anterior
 	        //imprimir o dado do noh apontado por aux
    //se estiver vazia, informa o usuario
}

int pop () {
	if(!verificarVazia()){
		No *aux;
		aux = p->topo;
		int dadoRemo = aux->dado;
		p->topo = aux->prox;
		free(aux);
		return dadoRemo;
	}else{
		printf("A pilha esta vazia");
		return 0;
	}
     //verificar se a pilha não estah vazia
        //cria variavel que vai apontar para o noh a ser removido
        //cria variavel para guardar o dado do noh a ser removido
        //aux aponta para o noh do topo
        //dado ira guardar o elemento do topo da pilha
        //atualizar o topo da pilha
        //libera a memoria ocupada pelo noh removido
        //retorna o valor do noh removido
    //se a fila estiver vazia, informa o usuario
}


int numeroAleatorio(int low, int high) {
    int k;
    double d;
    d = (double) rand() / ((double) TAM_MAX + 1);
    k = d * (high - low + 1);
    return low + k;
}

int obterDado() {
    return numeroAleatorio(0, TAM_MAX);
}

void exibirDado(int p) {
    printf("\nElemento: %i", p);
}


//Funcoes para testes automatizados
void emitirResultado(int resultado) {
	if(resultado) 
		printf("\nGREEN: Passou!");
	else printf("\nRED: Nao passou!");
}

void testar1_VaziaPilha(){
	printf("\nTeste 1: Este teste irah verificar a pilha vazia");
	inicializar();
	if(verificarVazia()) {
		emitirResultado(1);
	} else emitirResultado(0);
}

void testar3_RemoverPilha(){
	int removido = 0;
	printf("\nTeste 3: Este teste irah tentar remover de uma pilha vazia");
	inicializar();
	removido = pop();
	if(verificarVazia())
		emitirResultado(1);
	else emitirResultado(0);
}

void testar4_RemoverPilha(int quant){
	int removido = 0, i, numeros[quant];
	printf("\nTeste 4: Este teste irah inserir %d elemento na pilha e remove-lo, deixando a pilha vazia", quant);
	for(i = 0; i < quant; i++)
		numeros[i] = i+1;
	
	inicializar();
	for(i = 0; i < quant; i++) {
		push(numeros[i]);
	}
	
	for(i = 0; i < quant; i++) {
		removido = pop();
		if(removido != numeros[quant-i-1]) {
			emitirResultado(0);
			return;
		}
	}
	//verifica se a pilha ficou vazia
	if(verificarVazia())
		emitirResultado(1);
	else emitirResultado(0);
}
