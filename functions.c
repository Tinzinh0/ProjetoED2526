#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "functions.h"

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
