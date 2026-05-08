#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

// Protótipos das funções principais do sistema
int Verificar_Sistema();          // Verifica se já existe um sistema salvo nos ficheiros
Sistema Carregar_Sistema();       // Carrega dados do sistema dos ficheiros
Sistema Criar_Sistema();          // Cria um novo sistema vazio
void Terminar_Sistema(Sistema sis); // Guarda dados e termina o programa
void Guardar_Dados(Sistema sis);  // Guarda dados do sistema nos ficheiros
void Adicionar_Empregado(Sistema *sis); // Adiciona um empregado ao sistema
void Ver_Clientes(Sistema sis);   // Mostra todos os clientes
void Ver_Empregados(Sistema sis); // Mostra todos os empregados
void Adicionar_Cliente(Sistema *sis); // Adiciona um cliente e coloca-o numa fila

// Funções para manipulação da árvore binária de clientes
NoCliente* inserir_cliente(NoCliente *raiz, Cliente c); // Insere um cliente na árvore (ordenada por ID)
Cliente* procurar_cliente(NoCliente *raiz, int id);     // Procura um cliente por ID na árvore
void imprimir_clientes(NoCliente *raiz);                // Imprime todos os clientes em ordem (in-order)
void liberar_arvore(NoCliente *raiz);                   // Liberta memória da árvore

// Funções para manipulação de listas de empregados
ListaEmpregados* inserir_empregado(ListaEmpregados *lista, Empregado e); // Insere empregado na lista
void imprimir_empregados(ListaEmpregados *lista);                        // Imprime lista de empregados
void liberar_lista_empregados(ListaEmpregados *lista);                  // Liberta memória da lista

// Funções para manipulação de filas de clientes nas caixas
void adicionar_cliente_fila(Caixa *caixa, Cliente c); // Adiciona cliente ao fim da fila
Cliente remover_cliente_fila(Caixa *caixa);           // Remove cliente do início da fila (FIFO)
void imprimir_fila(Caixa caixa);                      // Imprime a fila da caixa

#endif