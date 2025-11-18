/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Mudar informações dos tipos
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"
#include <ctype.h>

void Alterar_tipoFilme() {

    int i;
    char codigo[10];
    char tipo[100];
    char relevancia[12];
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
        printf("ALTERAR TIPOS DE FILMES");

        gotoxy(7, 9);
        printf("1 - Codigo:.........");
        gotoxy(7, 11);
        printf("2 - Tipo:...........");
        gotoxy(7, 13);
        printf("3 - Relevancia:.....");

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

        // Relevância
        do {
            gotoxy(27, 13);
            printf("                    ");
            gotoxy(27, 13);
            fgets(relevancia, sizeof(relevancia), stdin);
            relevancia[strcspn(relevancia, "\n")] = '\0';
        } while (strlen(relevancia) == 0);

        // ===== Leitura e busca no arquivo =====
        FILE* arquivo = fopen("tipos.txt", "r");
        if (arquivo == NULL) {
            gotoxy(2, 23);
            printf("MSG.: Erro ao abrir o arquivo tipos.txt");
            getch();
            return;
        }

        encontrado = 0;
        while (fgets(linha, sizeof(linha), arquivo)) {

            char copy[512];
            strcpy(copy, linha);

            char* token = strtok(copy, ",");
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
                strcmp(t.relevancia, relevancia) == 0) {
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
            printf("ALTERACAO DE TIPO DE FILME");

            char tmp[256];

            // Código
            gotoxy(7, 8);
            printf("Codigo...................: %s", t.codigo);
            gotoxy(40, 8);
            printf("                    ");
            gotoxy(40, 8);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            int s = 0, e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(t.codigo, tmp + s, sizeof(t.codigo) - 1);
                t.codigo[sizeof(t.codigo) - 1] = '\0';
            }

            // Tipo
            gotoxy(7, 9);
            printf("Tipo.....................: %s", t.tipo);
            gotoxy(40, 9);
            printf("                                        ");
            gotoxy(40, 9);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(t.tipo, tmp + s, sizeof(t.tipo) - 1);
                t.tipo[sizeof(t.tipo) - 1] = '\0';
            }

            // Descrição
            gotoxy(7, 10);
            printf("Descricao................: %s", t.descricao);
            gotoxy(40, 10);
            printf("                                        ");
            gotoxy(40, 10);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(t.descricao, tmp + s, sizeof(t.descricao) - 1);
                t.descricao[sizeof(t.descricao) - 1] = '\0';
            }

            // Relevância
            gotoxy(7, 11);
            printf("Relevancia...............: %s", t.relevancia);
            gotoxy(40, 11);
            printf("       ");
            gotoxy(40, 11);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(t.relevancia, tmp + s, sizeof(t.relevancia) - 1);
                t.relevancia[sizeof(t.relevancia) - 1] = '\0';
            }

            // ===== Confirmação =====
            char confirma;
            do {
                gotoxy(2, 23);
                printf("CONFIRMA ALTERACAO ( S/N ) ? ");
                confirma = toupper(getchar());
            } while (confirma != 'S' && confirma != 'N');

            if (confirma == 'S') {

                // ===== Alteração direta no arquivo =====
                FILE* arquivo = fopen("tipos.txt", "r+");
                if (arquivo == NULL) {
                    gotoxy(2, 23);
                    printf("Erro ao abrir tipos.txt para alterar!");
                    getch();
                    return;
                }

                char linhaTemp[512];
                long posInicio = -1;

                // Procura a posição original
                while (!feof(arquivo)) {

                    long pos = ftell(arquivo);
                    if (fgets(linhaTemp, sizeof(linhaTemp), arquivo) == NULL) break;

                    TipoFilme temp;
                    char copyT[512];
                    strcpy(copyT, linhaTemp);

                    char* token = strtok(copyT, ",");
                    if (token) strcpy(temp.codigo, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.tipo, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.descricao, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.relevancia, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.dataHora, token);

                    if (strcmp(temp.codigo, codigo) == 0 &&
                        strcmp(temp.tipo, tipo) == 0 &&
                        strcmp(temp.relevancia, relevancia) == 0) {

                        posInicio = pos;
                        break;
                    }
                }

                if (posInicio == -1) {
                    fclose(arquivo);
                    gotoxy(2, 23);
                    printf("Registro nao encontrado para alteracao!");
                    getch();
                }
                else {
                    fseek(arquivo, posInicio, SEEK_SET);

                    fprintf(arquivo, "%s,%s,%s,%s,%s\n",
                        t.codigo,
                        t.tipo,
                        t.descricao,
                        t.relevancia,
                        t.dataHora);

                    fflush(arquivo);
                    fclose(arquivo);

                    gotoxy(2, 23);
                    printf("ALTERACAO CONFIRMADA COM SUCESSO!");
                    getch();
                }
            }

            // ===== Nova alteração =====
            char nova;
            do {
                gotoxy(2, 23);
                printf("                                                             ");
                gotoxy(2, 23);
                printf("NOVA ALTERACAO ( S/N ) ? ");
                nova = toupper(getchar());
            } while (nova != 'S' && nova != 'N');

            if (nova == 'S') {
                limparBuffer();
                Alterar_tipoFilme();
            }
            else {
                limparBuffer();
                menu_tipos_filme();
            }
        }
        else {
            gotoxy(7, 15);
            printf("Tipo de filme nao encontrado!");
            gotoxy(7, 17);
            printf("Pressione qualquer tecla para tentar novamente...");
            getch();
            continue;
        }

        getch();

    } while (1);
}
