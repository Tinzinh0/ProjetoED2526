#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"

// Protótipos das funções
int Verificar_Sistema();
Sistema Carregar_Sistema();
Sistema Criar_Sistema();
void Terminar_Sistema(Sistema sis);
void Guardar_Dados(Sistema sis);
void Adicionar_Empregado(Sistema *sis);
void Ver_Clientes(Sistema sis);
void Ver_Empregados(Sistema sis);

#endif