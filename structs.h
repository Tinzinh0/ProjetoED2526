#ifndef STRUCTS_H
#define STRUCTS_H

// Definições de constantes para o sistema
#define MAX_ESPERA 120  // Tempo máximo de espera para um cliente
#define N_CAIXAS 6      // Número de caixas no sistema
#define TEMPO_ATENDIMENTO_PRODUTO 6  // Tempo para atender um produto
#define MAX_PRECO 40    // Preço máximo de um produto
#define MAX_FILA 7      // Tamanho máximo da fila
#define MIN_FILA 3      // Tamanho mínimo da fila
#define Tempo_Min_Passagem 2  // Tempo mínimo para passagem
#define Tempo_Max_Passagem 10  // Tempo máximo para passagem (corrigido)
#define Preço_Min_Produto 0.01  // Preço mínimo de um produto
#define Preço_Max_Produto MAX_PRECO  // Preço máximo de um produto
#define MAX_EMPREGADOS 100  // Número máximo de empregados
#define MAX_CLIENTES 1000  // Número máximo de clientes

// Estrutura para representar um produto
typedef struct Produto {
    int Id_Produto;      // Identificador único do produto
    float Preco_Produto; // Preço do produto
    char Tipo[20];       // Tipo do produto (e.g., "alimento", "bebida")
} Produto;

// Lista ligada para produtos (usada para listas de produtos de um cliente)
typedef struct ListaProdutos {
    Produto produto;              // Dados do produto
    struct ListaProdutos *proximo; // Ponteiro para o próximo produto na lista
} ListaProdutos;

// Estrutura para representar um cliente
typedef struct Cliente {
    int Id;                    // Identificador único do cliente
    char Nome[40];             // Nome do cliente
    int Idade;                 // Idade do cliente
    ListaProdutos *produtos;   // Lista de produtos que o cliente tem
    int Total_Produtos;        // Número total de produtos
    int Tempo_Atendimento;     // Tempo estimado para atendimento
} Cliente;

// Estrutura para a fila de clientes numa caixa (lista ligada FIFO)
typedef struct FilaCliente {
    Cliente cliente;              // Dados do cliente na fila
    struct FilaCliente *proximo;  // Ponteiro para o próximo cliente na fila
} FilaCliente;

// Estrutura para representar um empregado
typedef struct Empregado {
    int Id;         // Identificador único do empregado
    char Nome[40];  // Nome do empregado
} Empregado;

// Lista ligada para empregados
typedef struct ListaEmpregados {
    Empregado empregado;              // Dados do empregado
    struct ListaEmpregados *proximo;  // Ponteiro para o próximo empregado
} ListaEmpregados;

// Estrutura para representar uma caixa
typedef struct Caixa {
    int NumeroCaixa;         // Número da caixa (1 a N_CAIXAS)
    FilaCliente *inicio_fila; // Início da fila de clientes
    Empregado *empregado;     // Empregado atribuído à caixa
    int Estado;               // Estado: 0=fechada, 1=aberta, 2=ocupada
} Caixa;

// Nó da árvore binária para clientes (ordenada por ID para busca eficiente)
typedef struct NoCliente {
    Cliente cliente;           // Dados do cliente
    struct NoCliente *esq;     // Subárvore esquerda (IDs menores)
    struct NoCliente *dir;     // Subárvore direita (IDs maiores)
} NoCliente;

// Estrutura principal do sistema
typedef struct Sistema {
    char Nome_Programa[40];       // Nome do programa
    ListaEmpregados *empregados;  // Lista de empregados
    Caixa caixas[N_CAIXAS];       // Array de caixas
    ListaProdutos *produtos;      // Lista de produtos disponíveis
    NoCliente *raiz_clientes;     // Raiz da árvore de clientes
} Sistema;

#endif