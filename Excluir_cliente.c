/*
  Autor...: José Luiz Delgado Tavares
  Data....: 26/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Excluir clientes
*/

#include "Funcoes.h"

void excluir_cliente() {
    void consulta_cliente();
    gotoxy(6,23);
    printf("Confirma exclusão (S/N)? ");
    char opt[4]; 
    ler_string(opt, sizeof opt);
    if(opt[0]=='S' || opt[0]=='s') {
        // Procura o código na lista
        for(int i=idx; i<n_clientes-1; i++) clientes[i]=clientes[i+1];
        n_clientes--;
        gotoxy(6,23);
        printf("Cliente excluído.\n");
    } else 
    gotoxy(6,23);
    printf("Exclusão cancelada.\n");
}