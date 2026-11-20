# Desempenho de Estruturas de Dados Lineares

Trabalho em grupo da disciplina de **Estrutura de Dados I**, desenvolvido no curso de Análise e Desenvolvimento de Sistemas do IFSP durante o segundo semestre de 2026.

## Enunciado da atividade

Implementar e comparar três estruturas de dados lineares:

- Fila;
- Pilha;
- Lista.

Cada estrutura possui duas versões:

- **Memória sequencial (estática):** utiliza vetores com capacidade máxima definida;
- **Memória dinâmica:** utiliza nós ligados por ponteiros e alocação com `malloc`.

O trabalho mede o tempo das operações de inserção, remoção e listagem para comparar o comportamento das duas formas de armazenamento.

## Integrantes e responsabilidades

| Integrante | Responsabilidade | Status |
| --- | --- | --- |
| Vinicius | Implementações estática e dinâmica da fila | Concluído |
| Kevyn | Implementações estática e dinâmica da lista | Concluído |
| Enzo | Implementações estática e dinâmica da pilha | Concluído |
| Matheus | Execução dos programas e registro dos resultados | Concluído |

## Metodologia

Os testes foram realizados com:

- 1.000 elementos;
- 3.000 elementos;
- 5.000 elementos;
- 10.000 elementos;
- 50.000 elementos.

Cada operação foi executada quatro vezes para cada quantidade. O primeiro ciclo foi descartado e os três resultados seguintes formaram a média aritmética apresentada na planilha.

Todos os testes foram executados na mesma máquina e no mesmo ambiente para manter a comparação consistente.

## Ambiente dos testes

| Item | Configuração |
| --- | --- |
| Sistema operacional | Microsoft Windows 11 Pro |
| Editor | Visual Studio Code |
| Compilador | GCC 16.1.0 — MSYS2/MinGW-w64 |
| Processador | Intel Core i5-1334U de 13ª geração |
| Memória RAM | 8 GB |
| `CLOCKS_PER_SEC` | 1.000 |
| Data dos testes | 18/11/2026 |

Nesse ambiente, 1 clock corresponde a 1 milissegundo. Os tempos representam o comportamento executado pelos programas, incluindo a exibição dos elementos nas operações medidas.

## Resultados

A planilha [`Testes_Estruturas.xlsx`](resultados/Testes_Estruturas.xlsx) contém:

- As três baterias válidas de cada teste;
- O cálculo automático das médias;
- A verificação de discrepâncias entre as baterias;
- A comparação entre memória estática e dinâmica;
- A identificação automática da implementação mais rápida;
- As informações do ambiente de execução.

Os resultados mostram comportamentos diferentes conforme a estrutura e a operação:

- Na **fila**, a memória dinâmica apresentou vantagem principalmente nas remoções com grandes quantidades;
- Na **pilha**, a memória estática foi mais rápida na maioria dos testes;
- Na **lista**, a memória dinâmica apresentou vantagem nas remoções e em grande parte das listagens;
- As diferenças menores devem ser interpretadas como variações normais do ambiente de execução.

## Estrutura do repositório

```text
.
├── fila/
│   ├── memoria-estatica/
│   │   ├── fila.c
│   │   ├── fila.h
│   │   └── main.c
│   └── memoria-dinamica/
│       ├── fila.c
│       ├── fila.h
│       └── main.c
├── pilha/
│   ├── memoria-estatica/
│   │   ├── pilha.c
│   │   ├── pilha.h
│   │   └── main.c
│   └── memoria-dinamica/
│       ├── pilha.c
│       ├── pilha.h
│       └── main.c
├── lista/
│   ├── memoria-estatica/
│   │   ├── lista.c
│   │   ├── lista.h
│   │   └── main.c
│   └── memoria-dinamica/
│       ├── lista.c
│       ├── lista.h
│       └── main.c
└── resultados/
    └── Testes_Estruturas.xlsx
```

## Tecnologias utilizadas

- Linguagem C;
- Vetores;
- Ponteiros;
- Estruturas (`struct`);
- Alocação dinâmica com `malloc` e `free`;
- Biblioteca `time.h` e função `clock()`;
- Microsoft Excel;
- Visual Studio Code;
- GCC;
- OnlineGDB.

## Como executar

Entre na pasta da estrutura e da implementação que deseja testar. Compile o arquivo principal junto com o arquivo da estrutura.

### Fila

```bash
gcc main.c fila.c -o fila
```

### Pilha

```bash
gcc main.c pilha.c -o pilha
```

### Lista

```bash
gcc main.c lista.c -o lista
```

No Linux ou macOS:

```bash
./nome-do-programa
```

No Windows:

```powershell
.\nome-do-programa.exe
```

Também é possível executar cada versão no OnlineGDB, adicionando o arquivo `main.c`, o arquivo `.c` da estrutura e o respectivo arquivo `.h`.

## Validação

As seis implementações foram compiladas com GCC. Os testes automatizados das pilhas foram executados sem resultados `RED`, e as operações principais de fila e lista foram verificadas. A planilha não apresenta erros de fórmula e seus cálculos foram conferidos.

## Observação

O projeto foi desenvolvido para fins acadêmicos. Os resultados podem variar conforme o sistema operacional, o compilador e o hardware utilizados.
