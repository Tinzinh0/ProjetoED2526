#ifndef MENUS_H
#define MENUS_H

#define MAX_ESPERA 120 
#define N_CAIXAS 6 
#define TEMPO_ATENDIMENTO_PRODUTO  6 
#define MAX_PRECO 40 
#define MAX_FILA 7 
#define MIN_FILA 3
#define Tempo_Min_Passagem 2
#define Tempo_Max_Passagem TEMPO_MAX_PASSAGEM
#define Preço_Min_Produto 0.01
#define Preço_Max_Produto MAX_PRECO



typedef struct{
    int Id;//fazer um formato para o ID "PX" com X=número de cliente
    char *Nome[40];//isto de perferência faz-se com memória dinâmica por isso é que começa com 39 espaços livres
    int Idade;//só para tornar completo. Se for menor não pode comprar certos tipos de produto
    Produto *Produtos;
    int Total_Produtos;//para sabermos o numero de items que um cliente trás.
    int Tempo_Atendimento;//calculo do tempo médio que cada item demora a ser registado * quantidade de items
    //este tempo tem que ser menor que MSX_ESPERA (que neste caso é 120)
}Cliente;

typedef struct{
    Cliente *Cliente;
    int Total_Clientes;
    struct FilaCliente *proximo;
}FilaCliente, *PTR_FilaCliente;

typedef struct{
    int Id_Produto;//o ID já deve ser capás de nos indicar o resto das informações relevantes do produto
    int Preco_Produto;
    char Tipo[20];
    // o tipo vai funcionar da seguinte maneira: 
    //vamos ter presets. se o tipo não corresponder a algum dos presets o código avisa e dá a oportunidade ao utilizador de corrigir
}Produto, *PTR_Produto;

typedef struct{
    char *Nome[40];//isto de perferência faz-se com memória dinâmica por isso é que começa com 39 espaços livres
    //não sei que caracteristicas colocar a mais que sejam uteis e façam sentido neste contexto
}Empregado;

typedef struct{
    int NumeroCaixa;
    FilaCliente *Fila;
    Empregado *Empregado_Caixa;
    int Estado;//0=fechada, 1=aberta, 2=ocupada
}Caixa, *PTR_Caixa;

typedef struct{
    char Nome_Programa [40];
    int Num_Empregados;
    Empregado Sis_Empregados[MAX_EMPREGADOS];
    Caixa Sis_Caixas[N_CAIXAS];
    //como os empregados são uma variavel menos complexa, podemos só fazer listas para este
    int N_Produtos;
    Produto Sis_Produtos[a/*produtos em outlet*/];
    //os produtos já são maiscomplexos e ligados ao cliente portanto podemos utilizar outros metodos como hashing
    int Num_Clientes;
    Cliente Sis_clientes[total_Clientes];
    //os clientes são provavelmente a variavel mais complexa que temos aqui portanto vou precisar do melhor uso de metodos de organização possível.
}Sistema;

#endif