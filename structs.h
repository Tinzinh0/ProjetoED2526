#ifndef MENUS_H
#define MENUS_H

#define Tempo_Min_Passagem 2
#define Tempo_Max_Passagem TEMPO_MAX_PASSAGEM
#define Preço_Min_Produto 0
#define Preço_Max_Prdotup MAX_PRECO

typedef struct{
    int NumeroCaixa;
    Empregado Empregado_Caixa;
    Produto Lista_Produtos;
    int Estado;
}Caixa;

typedef struct{
    int Id;
    char Nome[40];//isto de perferência faz-se com memória dinâmica por isso é que começa com 39 espaços livres
    int Idade;
    int Num_Items;
    int Tempo_Atendimento;
}Cliente;

typedef struct{
    int Id_Produto;//o ID já deve ser capás de nos indicar o resto das informações relevantes do produto
    int Preco_Produto;
    char Tipo[20];//isto de perferência faz-se com memória dinâmica por isso é que começa com 19 espaços livres
}Produto;

typedef struct{
    char Nome[40];//isto de perferência faz-se com memória dinâmica por isso é que começa com 39 espaços livres
    int Idade;
}Empregado;

typedef struct{
    //oque o sistema tem é essencialmente:
    //um Nome para tornar mais facil a organização de vários planos da empresa
    //uma maneira de rastrear as caixas e o numero de caixas existentes.
    //uma maneira de registar os empregados e o numero de empregados
    //uma maneira de registar os produtos e o numero de produto{
    //  quanto aos produto, convém que cada um deles seja dividido por tipos
    //}
    char Nome_Programa [40];//isto de perferência faz-se com memória dinâmica por isso é que começa com 39 espaços livres
    int Num_caixas;//se calhar para estes comvém mais tarde fazer uma tabela para facilitar a organização das caixas, empregados, produtos e clientes
    int Num_Empregados;
    int Num_produtos;
}Sistema;

#endif