/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Consultar tipos de filmes
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"

void Consultar_tipoFilme() {

    int i;
    char codigo[10];
    char tipo[50];
    char descricao[200];
    char linha[512];
    TipoFilme t;
    int encontrado = 0;

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
        printf("CONSULTAR TIPOS DE FILMES");

        gotoxy(7, 9);
        printf("1 - Codigo:.........");
        gotoxy(7, 11);
        printf("2 - Tipo:...........");
        gotoxy(7, 13);
        printf("3 - Descricao:......");

        // Moldura
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

        gotoxy(1, 1);  printf("+");
        gotoxy(80, 1); printf("+");
        gotoxy(1, 4);  printf("+");
        gotoxy(80, 4); printf("+");
        gotoxy(1, 22); printf("+");
        gotoxy(80, 22); printf("+");
        gotoxy(1, 24); printf("+");
        gotoxy(80, 24); printf("+");

        // ===== Entrada dos campos =====

        // Código
        do {
            gotoxy(27, 9);
            printf("                    ");
            gotoxy(27, 9);
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = '\0';
        } while (strlen(codigo) == 0);

        // Tipo
        do {
            gotoxy(27, 11);
            printf("                                        ");
            gotoxy(27, 11);
            fgets(tipo, sizeof(tipo), stdin);
            tipo[strcspn(tipo, "\n")] = '\0';
        } while (strlen(tipo) == 0);

        // Descrição
        do {
            gotoxy(27, 13);
            printf("                                        ");
            gotoxy(27, 13);
            fgets(descricao, sizeof(descricao), stdin);
            descricao[strcspn(descricao, "\n")] = '\0';
        } while (strlen(descricao) == 0);

        // ===== Leitura e busca no arquivo =====
        FILE* arquivo = fopen("tipos.txt", "r");
        if (arquivo == NULL) {
            gotoxy(2, 23);
            printf("MSG.: Erro ao abrir o arquivo tiposFilmes.txt");
            getch();
            return;
        }

        encontrado = 0;
        while (fgets(linha, sizeof(linha), arquivo)) {

            // Quebra a linha nos campos
            char* token = strtok(linha, ",");
            if (token) strcpy(t.codigo, token);
            token = strtok(NULL, ",");
            if (token) strcpy(t.tipo, token);
            token = strtok(NULL, ",");
            if (token) strcpy(t.descricao, token);
            token = strtok(NULL, ",");
            if (token) strcpy(t.relevancia, token);
            token = strtok(NULL, ",");
            if (token) strcpy(t.dataHora, token);

            // Verifica correspondência
            if (strcmp(t.codigo, codigo) == 0 &&
                strcmp(t.tipo, tipo) == 0 &&
                strcmp(t.descricao, descricao) == 0) {
                encontrado = 1;
                break;
            }
        }

        fclose(arquivo);

        if (encontrado) {

            // Limpa área central
            for (int y = 6; y <= 20; y++) {
                gotoxy(5, y);
                printf("                                                                               ");
            }

            gotoxy(7, 6);
            printf("CADASTRO DE TIPO DE FILME");

            gotoxy(7, 8);
            printf("Codigo do tipo............: %s", t.codigo);
            gotoxy(7, 9);
            printf("Tipo......................: %s", t.tipo);
            gotoxy(7, 10);
            printf("Descricao.................: %s", t.descricao);
            gotoxy(7, 11);
            printf("Relevancia................: %s", t.relevancia);
            gotoxy(7, 12);
            printf("Data e hora do cadastro..: %s", t.dataHora);

            char nova;
            do {
                gotoxy(2, 23);
                printf("NOVA CONSULTA ( S/N ) ? ");
                nova = toupper(getchar());
            } while (nova != 'S' && nova != 'N');

            if (nova == 'S') {
                limparBuffer();
                Consultar_tipoFilme();
            }
            if (nova == 'N') {
                limparBuffer();
                menu_tipos_filme();
            }
        }
        else {

            gotoxy(7, 15);
            printf("MSG.: Tipo de filme nao encontrado!");

            char nova;
            do {
                gotoxy(2, 23);
                printf("NOVA CONSULTA ( S/N ) ? ");
                nova = toupper(getchar());
            } while (nova != 'S' && nova != 'N');

            if (nova == 'S') {
                limparBuffer();
                Consultar_tipoFilme();
            }
            if (nova == 'N') {
                limparBuffer();
                menu_tipos_filme();
            }
        }

        getch();

    } while (1);
}

