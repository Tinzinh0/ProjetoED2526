#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "functions.h"

int main(){
    Sistema sis;
    int opcao;

    //primeiro verificar se já existe um sistema
    opcao = Verificar_Sistema();
    //se existir dá load da informação existente
    if(opcao == 1){ 
        sis = Carregar_Sistema();
    }
    //se não existir então cria um novo
    else{
        sis = Criar_Sistema();
    }

    // Menu principal
    int escolha;
    do {
        printf("\n--- Sistema de Atendimento ---\n");
        printf("1. Adicionar Empregado\n");
        printf("2. Ver Clientes\n");
        printf("3. Ver Empregados\n");
        printf("4. Terminar Programa\n");
        printf("Escolha: ");
        scanf("%d", &escolha);

        switch(escolha) {
            case 1:
                Adicionar_Empregado(&sis);
                break;
            case 2:
                Ver_Clientes(sis);
                break;
            case 3:
                Ver_Empregados(sis);
                break;
            case 4:
                Terminar_Sistema(sis);
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while(escolha != 4);

    return 0;
}