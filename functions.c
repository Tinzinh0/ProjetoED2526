// Nota: Sistema usa árvore binária para clientes (ordenada por ID) para acesso eficiente.
// Empregados e produtos usam listas ligadas.
// Filas das caixas são listas ligadas.
// Para melhorar, pode-se usar hashing para produtos ou balancear a árvore.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "functions.h"

// Função para verificar se já existe um sistema salvo
// Abre os ficheiros clientes.txt e funcionarios.txt e verifica se têm dados
int Verificar_Sistema(){
    FILE *f1 = fopen("clientes.txt", "r");
    FILE *f2 = fopen("funcionarios.txt", "r");
    int existe = 0;
    if(f1 != NULL && f2 != NULL){
        // Verificar se há pelo menos uma linha em cada arquivo
        char linha[200];
        int tem_dados1 = (fgets(linha, sizeof(linha), f1) != NULL);
        int tem_dados2 = (fgets(linha, sizeof(linha), f2) != NULL);
        if(tem_dados1 && tem_dados2){
            existe = 1;
        }
        fclose(f1);
        fclose(f2);
    }
    else{
        if(f1) fclose(f1);
        if(f2) fclose(f2);
    }
    return existe;
}

// Funções para árvore de clientes
// Insere um cliente na árvore binária, mantendo ordenação por ID
// Se ID já existe, não insere (pode ser melhorado para atualizar)
NoCliente* inserir_cliente(NoCliente *raiz, Cliente c) {
    if (raiz == NULL) {
        NoCliente *novo = (NoCliente*)malloc(sizeof(NoCliente));
        if (novo == NULL) {
            printf("Erro de memória\n");
            exit(1);
        }
        novo->cliente = c;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    if (c.Id < raiz->cliente.Id) {
        raiz->esq = inserir_cliente(raiz->esq, c);
    } else if (c.Id > raiz->cliente.Id) {
        raiz->dir = inserir_cliente(raiz->dir, c);
    } // if equal, do nothing or handle duplicate
    return raiz;
}

// Procura um cliente por ID na árvore
// Retorna ponteiro para o cliente ou NULL se não encontrado
Cliente* procurar_cliente(NoCliente *raiz, int id) {
    if (raiz == NULL) return NULL;
    if (raiz->cliente.Id == id) return &raiz->cliente;
    if (id < raiz->cliente.Id) return procurar_cliente(raiz->esq, id);
    return procurar_cliente(raiz->dir, id);
}

// Imprime todos os clientes em ordem crescente de ID (in-order traversal)
void imprimir_clientes(NoCliente *raiz) {
    if (raiz != NULL) {
        imprimir_clientes(raiz->esq);
        printf("Cliente ID: %d, Nome: %s, Idade: %d\n", raiz->cliente.Id, raiz->cliente.Nome, raiz->cliente.Idade);
        imprimir_clientes(raiz->dir);
    }
}

// Liberta memória da árvore recursivamente
void liberar_arvore(NoCliente *raiz) {
    if (raiz != NULL) {
        liberar_arvore(raiz->esq);
        liberar_arvore(raiz->dir);
        free(raiz);
    }
}

// Funções para listas de empregados
// Insere um empregado no início da lista ligada
ListaEmpregados* inserir_empregado(ListaEmpregados *lista, Empregado e) {
    ListaEmpregados *novo = (ListaEmpregados*)malloc(sizeof(ListaEmpregados));
    if (novo == NULL) {
        printf("Erro de memória\n");
        exit(1);
    }
    novo->empregado = e;
    novo->proximo = lista;
    return novo;
}

// Imprime todos os empregados da lista
void imprimir_empregados(ListaEmpregados *lista) {
    ListaEmpregados *atual = lista;
    while (atual != NULL) {
        printf("Empregado ID: %d, Nome: %s\n", atual->empregado.Id, atual->empregado.Nome);
        atual = atual->proximo;
    }
}

// Liberta memória da lista de empregados
void liberar_lista_empregados(ListaEmpregados *lista) {
    ListaEmpregados *atual = lista;
    while (atual != NULL) {
        ListaEmpregados *temp = atual;
        atual = atual->proximo;
        free(temp);
    }
}

// Cria um novo sistema vazio, inicializando todas as estruturas
Sistema Criar_Sistema() {
    Sistema sis;
    strcpy(sis.Nome_Programa, "Sistema de Atendimento");
    sis.empregados = NULL;
    sis.produtos = NULL;
    sis.raiz_clientes = NULL;
    for (int i = 0; i < N_CAIXAS; i++) {
        sis.caixas[i].NumeroCaixa = i + 1;
        sis.caixas[i].inicio_fila = NULL;
        sis.caixas[i].empregado = NULL;
        sis.caixas[i].Estado = 0; // fechada
    }
    return sis;
}

// Carrega dados do sistema dos ficheiros
// Carrega empregados e clientes; produtos e caixas podem ser adicionados
Sistema Carregar_Sistema() {
    Sistema sis = Criar_Sistema();
    // Carregar empregados
    FILE *f = fopen("funcionarios.txt", "r");
    if (f) {
        char linha[100];
        while (fgets(linha, sizeof(linha), f)) {
            Empregado e;
            if (sscanf(linha, "%d,%39[^\n]", &e.Id, e.Nome) == 2) {
                sis.empregados = inserir_empregado(sis.empregados, e);
            }
        }
        fclose(f);
    }
    // Carregar clientes (simplificado, assumir formato id,nome,idade)
    f = fopen("clientes.txt", "r");
    if (f) {
        char linha[100];
        while (fgets(linha, sizeof(linha), f)) {
            Cliente c;
            c.produtos = NULL; // simplificado
            c.Total_Produtos = 0;
            c.Tempo_Atendimento = 0;
            if (sscanf(linha, "%d,%39[^,],%d", &c.Id, c.Nome, &c.Idade) == 3) {
                sis.raiz_clientes = inserir_cliente(sis.raiz_clientes, c);
            }
        }
        fclose(f);
    }
    // Nota: Carregar produtos e caixas pode ser adicionado posteriormente
    return sis;
}

// Guarda dados do sistema nos ficheiros
void Guardar_Dados(Sistema sis) {
    // Guardar empregados
    FILE *f = fopen("funcionarios.txt", "w");
    if (f) {
        ListaEmpregados *atual = sis.empregados;
        while (atual != NULL) {
            fprintf(f, "%d,%s\n", atual->empregado.Id, atual->empregado.Nome);
            atual = atual->proximo;
        }
        fclose(f);
    }
    // Guardar clientes (in-order traversal)
    f = fopen("clientes.txt", "w");
    if (f) {
        // Nota: Para guardar em ordem, implementar função auxiliar
        // Por simplicidade, não implementado completamente
        fclose(f);
    }
    // Nota: Guardar produtos e caixas pode ser adicionado
}

// Adiciona um empregado ao sistema via input do utilizador
void Adicionar_Empregado(Sistema *sis) {
    Empregado e;
    printf("ID do empregado: ");
    scanf("%d", &e.Id);
    printf("Nome: ");
    scanf("%s", e.Nome);
    sis->empregados = inserir_empregado(sis->empregados, e);
    printf("Empregado adicionado.\n");
}

// Mostra todos os clientes do sistema
void Ver_Clientes(Sistema sis) {
    printf("Clientes:\n");
    imprimir_clientes(sis.raiz_clientes);
}

// Mostra todos os empregados do sistema
void Ver_Empregados(Sistema sis) {
    printf("Empregados:\n");
    imprimir_empregados(sis.empregados);
}

// Imprime a fila de uma caixa específica
void imprimir_fila(Caixa caixa) {
    FilaCliente *atual = caixa.inicio_fila;
    printf("Fila da Caixa %d:\n", caixa.NumeroCaixa);
    while (atual != NULL) {
        printf("Cliente ID: %d, Nome: %s\n", atual->cliente.Id, atual->cliente.Nome);
        atual = atual->proximo;
    }
}

// Adiciona um cliente ao fim da fila de uma caixa
void adicionar_cliente_fila(Caixa *caixa, Cliente c) {
    FilaCliente *novo = (FilaCliente*)malloc(sizeof(FilaCliente));
    if (novo == NULL) {
        printf("Erro de memória\n");
        return;
    }
    novo->cliente = c;
    novo->proximo = NULL;
    if (caixa->inicio_fila == NULL) {
        caixa->inicio_fila = novo;
    } else {
        FilaCliente *atual = caixa->inicio_fila;
        while (atual->proximo != NULL) {
            atual = atual->proximo;
        }
        atual->proximo = novo;
    }
}

// Remove o cliente do início da fila (FIFO) e retorna-o
Cliente remover_cliente_fila(Caixa *caixa) {
    if (caixa->inicio_fila == NULL) {
        Cliente vazio = {0, "", 0, NULL, 0, 0};
        return vazio;
    }
    FilaCliente *temp = caixa->inicio_fila;
    Cliente c = temp->cliente;
    caixa->inicio_fila = temp->proximo;
    free(temp);
    return c;
}

// Adiciona um cliente ao sistema e coloca-o numa fila de caixa
void Adicionar_Cliente(Sistema *sis) {
    Cliente c;
    printf("ID do cliente: ");
    scanf("%d", &c.Id);
    printf("Nome: ");
    scanf("%s", c.Nome);
    printf("Idade: ");
    scanf("%d", &c.Idade);
    c.produtos = NULL; // simplificado
    c.Total_Produtos = 0;
    c.Tempo_Atendimento = 0;
    // Inserir na árvore
    sis->raiz_clientes = inserir_cliente(sis->raiz_clientes, c);
    // Escolher caixa
    int num_caixa;
    printf("Número da caixa (1-%d): ", N_CAIXAS);
    scanf("%d", &num_caixa);
    if (num_caixa >= 1 && num_caixa <= N_CAIXAS) {
        adicionar_cliente_fila(&sis->caixas[num_caixa - 1], c);
        printf("Cliente adicionado à fila da caixa %d.\n", num_caixa);
    } else {
        printf("Caixa inválida.\n");
    }
}

// Termina o sistema, guardando dados e libertando memória
void Terminar_Sistema(Sistema sis) {
    Guardar_Dados(sis);
    liberar_arvore(sis.raiz_clientes);
    liberar_lista_empregados(sis.empregados);
    // Liberar outras listas se necessário
    printf("Sistema terminado.\n");
    exit(0);
}
