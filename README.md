# Desempenho de Estruturas de Dados Lineares

Trabalho em grupo da disciplina de **Estrutura de Dados I (ED1)**, realizado no segundo semestre de 2026 no curso de Análise e Desenvolvimento de Sistemas do IFSP.

## Sobre a atividade

O trabalho compara o tempo de execução das operações básicas de três estruturas de dados lineares:

- Fila;
- Lista;
- Pilha.

Cada estrutura deverá possuir duas versões: uma implementação com **memória sequencial (estática)** e outra com **memória dinâmica**. O desempenho será medido em clocks do processador nas operações de inserção, remoção e listagem.

## Integrantes e responsabilidades

| Integrante | Responsabilidade | Status |
|---|---|---|
| Vinicius | Implementações estática e dinâmica da fila | Concluído |
| Kevyn | Implementações estática e dinâmica da lista | Pendente |
| Enzo | Implementações estática e dinâmica da pilha | Pendente |
| Matheus | Execução dos programas e registro dos resultados | Pendente |

## Situação atual

O trabalho **ainda está em desenvolvimento**. Até o momento, somente as duas implementações da fila foram concluídas. Os códigos de lista e pilha, a coleta dos tempos e o relatório final ainda serão adicionados.

## Metodologia dos testes

Os testes serão feitos com as seguintes quantidades de elementos:

- 1.000;
- 3.000;
- 5.000;
- 10.000;
- 50.000.

Para cada quantidade, as operações de inserção, remoção e listagem deverão ser executadas quatro vezes. O primeiro resultado será descartado; os três seguintes serão anotados e utilizados para calcular a média aritmética.

Todos os testes deverão ser executados na mesma máquina para que a comparação seja coerente.

## Implementações da fila

### Memória sequencial

A fila estática utiliza um vetor com capacidade máxima de 50.000 elementos. Ao remover um elemento, os valores seguintes são deslocados para manter o início da fila na primeira posição do vetor.

### Memória dinâmica

A fila dinâmica utiliza nós ligados por ponteiros. Cada nó armazena um número inteiro e o endereço do próximo elemento. A memória de cada nó removido é liberada com `free`.

As duas versões possuem um menu para inserir, remover, listar, limpar a fila, alterar a quantidade de elementos e exibir o tempo gasto em clocks.

## Estrutura do repositório

```text
fila/
├── memoria-estatica/
│   ├── fila.c
│   ├── fila.h
│   └── main.c
└── memoria-dinamica/
    ├── fila.c
    ├── fila.h
    └── main.c
lista/
└── README.md
pilha/
└── README.md
resultados/
└── README.md
```

## Tecnologias utilizadas

- Linguagem C;
- Estruturas de dados lineares;
- Vetores e memória sequencial;
- Ponteiros e alocação dinâmica com `malloc` e `free`;
- Biblioteca `time.h` para medição em clocks;
- OnlineGDB para compilação e execução dos testes.

## Como executar os códigos da fila

### Pelo OnlineGDB

1. Acesse o OnlineGDB e selecione a linguagem C.
2. Adicione os arquivos `main.c`, `fila.c` e `fila.h` da versão desejada.
3. Clique em **Run**.
4. Informe uma quantidade entre 1 e 50.000 elementos.
5. Utilize o menu para executar as operações e anotar os clocks apresentados.

### Pelo terminal

Entre na pasta da versão desejada e compile:

```bash
gcc main.c fila.c -o fila
```

Execute no Linux ou macOS:

```bash
./fila
```

No Windows:

```powershell
.\fila.exe
```
