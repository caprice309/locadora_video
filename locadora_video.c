/*
Data....: 16/10/2025
Membros.: 268322-2025 - Enzo Gati Barbaresco
          292595-2025 - José Luiz Delgado Tavares
Objetivo: Função main
*/

#include "Funcoes.h"

int main (){
    system("color 0d");
    int opcao;

    gotoxy(18,9); printf("1. Locacoes");
    gotoxy(18,10); printf("2. Menu de Clientes");
    gotoxy(18,11); printf("3. Menu de Filmes");
    gotoxy(18,12); printf("4. Relatorios");
    gotoxy(18,13); printf("5. Sair");

    gotoxy(3,23); printf("Digite a opcao: ");
    scanf("%d", &opcao);

    gotoxy(81,25);
    return 0;
}
