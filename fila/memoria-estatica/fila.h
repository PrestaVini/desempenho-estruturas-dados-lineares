#define TAM_MAX 50000

typedef struct fila {
	int vetor[TAM_MAX];
	int fim;
} Fila;

void inicializar();
int verificarVazia();
int verificarCheia();
void inserir(int numero);
void imprimir();
int remover();

//Funcoes para o relatorio

void limparTela();
int numeroAleatorio(int low, int high);
int obterDado();
void exibirDado(int p);
void calcularTempo(double finish, double start);


