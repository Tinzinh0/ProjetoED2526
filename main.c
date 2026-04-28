#include <stdio.h>
#include <stlib.h>
#include <string.h>
#include "structs.h"

int main(){
    //ATENÇÂO:
    //O programa DEVE POR DEFAULT dar load dos ficheiros "Clientes.txt" e "funcionarios.txt"
    //Estamos a implementar estas funções extras para ter o programa mais completo
    // simplesmente porque quero fazer mais completo
    //quanto mais completo e próximo de um programa real melhor, que assim preparamos-nos para o mundo do trabalho



    //primeiro verificar se já existe um sistema
    Verificar_Sistema();
    //se existir dá load da informação existente
    if(opcao = 1){ 
    Carregar_Sistema();
    }
    //se não existir então cria um novo
    else{
    Criar_Sistema();
    Carregar_Sistema();
    }
    //funcao para terminar o programa
    //função também deve guardar automáticamente os dados
    Terminar_Sistema();//esta função precisa de guardar dados
}

int verificar(){
    //aqui devo procurar um ficheiro que guarde dados
    if(ficheiro != NULL){
        return 1;
    }
    else{ 
        return 0;
    }
}

Sistema Carregar_Sistema(){
    //este vai ser o default state
    //carregar os dados do sistema
}

Sistema Cria_Sistema(){
    //esta função é extra e serve apenas para completar o programa
    //criar um Sistema apartir da struct sistema
}

void Terminar_Sistema(){
    int opcao;
    //perguntar ao Utilizador se ele quer terminar o programa
    printf("Quer terminar o programa?\n");
    printf("1-Sim\n 2-Não\n");
    scanf("%d", opcao);
    //clear the cache

    //guardar informação
    Guardar_Dados();
    //nesta função vamos também guardar um histórico de tudo oque o utilizador faz no programa

    //terminar o Programa aqui
    //clear console
    Printf("Programa terminado");
}