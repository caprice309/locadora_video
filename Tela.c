/*
  Autor...: José Luiz Delgado Tavares
  Data....: 06/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Mostrar a tela
*/

#include "Funcoes.h"

void tela(){
    int i;
    system ("color 0a");
    system ("cls");
    gotoxy(2,2);
    printf("ENZO GATI BARBARESCO");
    gotoxy(2,3);
    printf("JOSE LUIZ DELGADO TAVARES");
    gotoxy(61,2);
    printf("ESTRUTURA DE DADOS");

    for(i = 1; i <=24; i++){
        gotoxy(1,i);
        printf("|");
        gotoxy(80,i);
        printf("|");
    }

    for(int i = 1; i <=80; i++){
        gotoxy(i,1);
        printf("-");
        gotoxy(i,4);
        printf("-");
        gotoxy(i,22);
        printf("-");
        gotoxy(i,24);
        printf("-");
    }

    gotoxy(1,1);
    printf("+");
    gotoxy(80,1);
    printf("+");
    gotoxy(1,4);
    printf("+");
    gotoxy(80,4);
    printf("+");
    gotoxy(1,22);
    printf("+");
    gotoxy(80,22);
    printf("+");
    gotoxy(1,24);
    printf("+");
    gotoxy(80,24);
    printf("+");

    gotoxy(2,23);
    printf("MSG.:");
}