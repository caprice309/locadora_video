/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Excluir Tipos de filme
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"

void Deletar_tipoFilme() {

    int i;
    char codigo[10];
    char tipo[50];
    char relevancia[10];
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
        printf("EXCLUIR TIPOS DE FILMES");

        gotoxy(7, 9);
        printf("1 - Codigo:.........");
        gotoxy(7, 11);
        printf("2 - Nome do Tipo:...");
        gotoxy(7, 13);
        printf("3 - Categoria:......");

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

        // ===== Entrada =====

        // C�digo
        do {
            gotoxy(27, 9);
            printf("                    ");
            gotoxy(27, 9);
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = '\0';
        } while (strlen(codigo) == 0);

        // Tipo (nome do tipo)
        do {
            gotoxy(27, 11);
            printf("                                        ");
            gotoxy(27, 11);
            fgets(tipo, sizeof(tipo), stdin);
            tipo[strcspn(tipo, "\n")] = '\0';
        } while (strlen(tipo) == 0);

        // Relevancia (categoria)
        do {
            gotoxy(27, 13);
            printf("                    ");
            gotoxy(27, 13);
            fgets(relevancia, sizeof(relevancia), stdin);
            relevancia[strcspn(relevancia, "\n")] = '\0';
        } while (strlen(relevancia) == 0);

        // ===== Leitura e busca =====
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

            if (strcmp(t.codigo, codigo) == 0 &&
                strcmp(t.tipo, tipo) == 0 &&
                strcmp(t.relevancia, relevancia) == 0) {
                encontrado = 1;
                break;
            }
        }

        fclose(arquivo);

        if (encontrado) {

            // Limpa �rea onde aparecem os dados
            for (int y = 6; y <= 20; y++) {
                gotoxy(5, y);
                printf("                                                                               ");
            }

            gotoxy(7, 6);
            printf("CADASTRO DO TIPO DE FILME");

            gotoxy(7, 8);
            printf("Codigo....................: %s", t.codigo);
            gotoxy(7, 9);
            printf("Nome do tipo..............: %s", t.tipo);
            gotoxy(7, 10);
            printf("Relevancia (categoria)....: %s", t.relevancia);
            gotoxy(7, 11);
            printf("Data e hora do cadastro...: %s", t.dataHora);

            // ===== Confirma exclus�o =====
            char confirma;
            do {
                gotoxy(2, 23);
                printf("CONFIRMA EXCLUSAO ( S/N ) ? ");
                confirma = toupper(getchar());
            } while (confirma != 'S' && confirma != 'N');

            if (confirma == 'S') {

                FILE* arq = fopen("tipos.txt", "r+");
                if (arq == NULL) {
                    gotoxy(2, 23);
                    printf("Erro ao abrir arquivo para exclusao!");
                    getch();
                    return;
                }

                char linhaTemp[512];
                long posInicio = -1;
                long tamLinha = 0;

                while (!feof(arq)) {
                    long pos = ftell(arq);

                    if (fgets(linhaTemp, sizeof(linhaTemp), arq) == NULL) break;
                    tamLinha = strlen(linhaTemp);

                    char copy2[512];
                    strcpy(copy2, linhaTemp);

                    TipoFilme temp;
                    char* token = strtok(copy2, ",");
                    if (token) strcpy(temp.codigo, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.tipo, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.descricao, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.relevancia, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.dataHora, token);

                    if (strcmp(temp.codigo, t.codigo) == 0 &&
                        strcmp(temp.tipo, t.tipo) == 0 &&
                        strcmp(temp.relevancia, t.relevancia) == 0) {
                        posInicio = pos;
                        break;
                    }
                }

                if (posInicio == -1) {
                    fclose(arq);
                    gotoxy(2, 23);
                    printf("Tipo nao encontrado para exclusao!");
                    getch();
                }
                else {
                    fseek(arq, posInicio, SEEK_SET);

                    for (int j = 0; j < tamLinha - 1; j++) fputc(' ', arq);
                    fputc('\n', arq);
                    fflush(arq);
                    fclose(arq);

                    gotoxy(2, 23);
                    printf("TIPO DE FILME EXCLUIDO COM SUCESSO!");
                    getch();
                }
            }

            // ===== Nova exclus�o =====
            char nova;
            do {
                gotoxy(2, 23);
                printf("                                                             ");
                gotoxy(2, 23);
                printf("NOVA EXCLUSAO ( S/N ) ? ");
                nova = toupper(getchar());
            } while (nova != 'S' && nova != 'N');

            if (nova == 'S') {
                limparBuffer();
                Deletar_tipoFilme();
            }
            else {
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
                printf("NOVA EXCLUSAO ( S/N ) ? ");
                nova = toupper(getchar());
            } while (nova != 'S' && nova != 'N');

            if (nova == 'S') {
                limparBuffer();
                Deletar_tipoFilme();
            }
            else {
                limparBuffer();
                menu_tipos_filme();
            }
        }

        getch();

    } while (1);
}
