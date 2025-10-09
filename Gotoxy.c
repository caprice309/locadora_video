/*Autor...: José Luiz Delgado Tavares
  Data....: 06/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Mostrar a tela
*/

#include "Funcoes.h"

void gotoxy(int x, int y){
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}