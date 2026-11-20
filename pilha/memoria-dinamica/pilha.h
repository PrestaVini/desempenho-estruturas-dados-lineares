#define TAM_MAX 50000

typedef struct _No{
    int dado;
    struct _No *prox;
}No;

typedef struct _Pilha {
     No *topo;
}Pilha;

extern Pilha *p;


void inicializar();
int verificarVazia();
void push(int dado);
void imprimir();
int pop();
int numeroAleatorio(int low, int high);
int obterDado();
void exibirDado(int p);

//Funcoes para testes automatizados
void testar1_VaziaPilha();
void testar3_RemoverPilha();
void testar4_RemoverPilha(int quant);
