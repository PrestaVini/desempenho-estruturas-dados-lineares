#define TAM_MAX 50000

typedef struct _no {
    int valor;
    struct _no *proximoEndereco;
} No;

typedef struct _fila {
	No *inicio;
	No *fim;
} Fila;

void inicializar();
int verificarVazia();
void inserir(int valorInput);
void imprimir();
int remover();

//Funcoes para o relatorio

void limparTela();
int numeroAleatorio(int low, int high);
int obterDado();
void exibirDado(int p);
void calcularTempo(double finish, double start);
