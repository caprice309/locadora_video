/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Ser a base de transição entre os diferentes menus de relatorios
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"
#include <conio.h>
#include <ctype.h>


void menu_relatorios() {
    int i;
    int opcao;

    do {
        system("color 0a");
        system("cls");
        gotoxy(2, 2);
        printf("ENZO GATI BARBARESCO");
        gotoxy(2, 3);
        printf("JOSE LUIZ DELGADO TAVARES");
        gotoxy(61, 2);
        printf("ESTRUTURA DE DADOS");

        gotoxy(7, 7);
        printf("MENU MOVIMENTACAO");
        gotoxy(7, 9);
        printf("1 - Balanco do acervo");
        gotoxy(7, 11);
        printf("2 - Balanco de movimentacoes");
        gotoxy(7, 13);
        printf("3 - Retornar");

        for (i = 1; i <= 24; i++) {
            gotoxy(1, i);
            printf("|");
            gotoxy(80, i);
            printf("|");
        }

        for (int i = 1; i <= 80; i++) {
            gotoxy(i, 1);
            printf("-");
            gotoxy(i, 4);
            printf("-");
            gotoxy(i, 22);
            printf("-");
            gotoxy(i, 24);
            printf("-");
        }

        gotoxy(1, 1);
        printf("+");
        gotoxy(80, 1);
        printf("+");
        gotoxy(1, 4);
        printf("+");
        gotoxy(80, 4);
        printf("+");
        gotoxy(1, 22);
        printf("+");
        gotoxy(80, 22);
        printf("+");
        gotoxy(1, 24);
        printf("+");
        gotoxy(80, 24);
        printf("+");

        gotoxy(2, 23);
        printf("MSG.: ");
        char entrada[10];
        int valido = 0;

        while (!valido || strlen(entrada) == 0) {
            // lê a entrada como texto
            fgets(entrada, sizeof(entrada), stdin);
            entrada[strcspn(entrada, "\n")] = '\0'; // remove o Enter

            // verifica se a entrada contém apenas números
            valido = 1;
            for (int i = 0; i < strlen(entrada); i++) {
                if (!isdigit((unsigned char)entrada[i])) {
                    valido = 0;
                    break;
                }
            }

            if (!valido || strlen(entrada) == 0) {
                gotoxy(8, 23);
                printf("                                             ");
                gotoxy(10, 23);
                printf("Opcao invalida! Pressione qualquer tecla...");
                getch();

                // limpa mensagem de erro e reseta prompt
                gotoxy(8, 23);
                printf("                                             ");
                gotoxy(2, 23);
                printf("MSG.: ");
            }
        }

        // converte para inteiro apenas se for válido
        opcao = atoi(entrada);

        switch (opcao) {
        case 1:
            balanco_acervo();
        break;

        case 2:
            balanco_movimentacoes();
        break;

        case 3:
            tela();
            break;

        default:
            gotoxy(8, 23);
            printf("                                             ");
            gotoxy(10, 23);
            printf("Opcao invalida! Pressione qualquer tecla...");
            getch();
            break;
        }
    } while (opcao != 5);
}