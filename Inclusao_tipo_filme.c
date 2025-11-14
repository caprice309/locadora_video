/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Cadastrar Tipos
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"
#include <time.h>
#include <string.h>
#include <ctype.h>

// Salva um TipoFilme em mem�ria e no arquivo "tipos.txt"
void salvar_tipo(TipoFilme t) {
    // Adiciona no array de tipos em mem�ria
    if (n_tipos < MAX_TIPOS) {
        tipos[n_tipos++] = t;
    }
    else {
        printf("Limite m�ximo de tipos atingido!\n");
        return;
    }

    // Abre o arquivo para acrescentar o tipo
    FILE* arquivo = fopen("tipos.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar o tipo.\n");
        return;
    }

    fprintf(arquivo, "%s,%s,%s,%s,%s\n",
        t.codigo,
        t.tipo,
        t.descricao,
        t.relevancia,
        t.dataHora
    );

    fclose(arquivo); // Fecha o arquivo
}

void inclusao_tipo() {
    int i;
    char confirma, nova;
    char codigo[10];
    char tipo[50];
    char descricao[200];
    char relevancia[10];
    char dataHora[20];
    time_t agora;
    struct tm infoTempo;
    struct tm* ptrTempo;

    system("color 0a");
    system("cls");
    gotoxy(2, 2);
    printf("ENZO GATI BARBARESCO");
    gotoxy(2, 3);
    printf("JOSE LUIZ DELGADO TAVARES");
    gotoxy(61, 2);
    printf("ESTRUTURA DE DADOS");

    gotoxy(7, 6);
    printf("CADASTRO DE TIPOS DE FILME");
    gotoxy(7, 8);
    printf("Codigo...................:");
    gotoxy(7, 9);
    printf("Tipo.....................:");
    gotoxy(7, 10);
    printf("Descricao................:");
    gotoxy(7, 11);
    printf("Relevancia...............:");
    gotoxy(7, 12);
    printf("Data e hora do cadastro.:");

    gotoxy(7, 14);
    printf("CONFIRMA INCLUSAO ( S/N ) ?");
    gotoxy(7, 16);
    printf("NOVA INCLUSAO( S/N ) ?");

    for (i = 1; i <= 24; i++) {
        gotoxy(1, i); printf("|");
        gotoxy(80, i); printf("|");
    }

    for (int i = 1; i <= 80; i++) {
        gotoxy(i, 1); printf("-");
        gotoxy(i, 4); printf("-");
        gotoxy(i, 22); printf("-");
        gotoxy(i, 24); printf("-");
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

    // C�digo
    do {
        gotoxy(37, 8);
        printf("                 ");
        gotoxy(37, 8);
        fgets(codigo, sizeof(codigo), stdin);
        codigo[strcspn(codigo, "\n")] = '\0';
    } while (strlen(codigo) == 0);

    // Tipo
    do {
        gotoxy(37, 9);
        printf("                                        ");
        gotoxy(37, 9);
        fgets(tipo, sizeof(tipo), stdin);
        tipo[strcspn(tipo, "\n")] = '\0';
    } while (strlen(tipo) == 0);

    // Descricao
    do {
        gotoxy(37, 10);
        printf("                                        ");
        gotoxy(37, 10);
        fgets(descricao, sizeof(descricao), stdin);
        descricao[strcspn(descricao, "\n")] = '\0';
    } while (strlen(descricao) == 0);

    // Relevancia
    do {
        gotoxy(37, 11);
        printf("     ");
        gotoxy(37, 11);
        fgets(relevancia, sizeof(relevancia), stdin);
        relevancia[strcspn(relevancia, "\n")] = '\0';
    } while (strlen(relevancia) == 0);

    // ===== Data e hora =====
    time(&agora);
    ptrTempo = localtime(&agora);
    if (ptrTempo != NULL) {
        infoTempo = *ptrTempo;
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", &infoTempo);
        gotoxy(37, 12);
        printf("%s", dataHora);
    }
    else {
        gotoxy(37, 12);
        printf("Erro ao obter data/hora");
    }

    // ===== Confirma��o =====
    do {
        gotoxy(37, 14);
        confirma = getchar();
        confirma = toupper(confirma);
    } while (confirma != 'S' && confirma != 'N');

    if (confirma == 'N') {
        do {
            gotoxy(37, 16);
            nova = getchar();
            nova = toupper(nova);
        } while (nova != 'S' && nova != 'N');

        if (nova == 'N') { limparBuffer(); menu_tipos_filme(); }
        if (nova == 'S') inclusao_tipo();
    }

    if (confirma == 'S') {
        TipoFilme t;

        strcpy(t.codigo, codigo);
        strcpy(t.tipo, tipo);
        strcpy(t.descricao, descricao);
        strcpy(t.relevancia, relevancia);
        strcpy(t.dataHora, dataHora);

        // ===== Verifica duplicados =====
        FILE* arquivo = fopen("tipos.txt", "r");
        int duplicado = 0;
        char linha[512];

        if (arquivo != NULL) {
            while (fgets(linha, sizeof(linha), arquivo)) {
                TipoFilme temp;
                char* token = strtok(linha, ",");
                if (token) strcpy(temp.codigo, token);

                if (strcmp(temp.codigo, t.codigo) == 0) {
                    duplicado = 1;
                    break;
                }
            }
            fclose(arquivo);
        }

        if (duplicado) {
            gotoxy(7, 18);
            printf("MSG.: Ja existe um tipo com esse CODIGO!");
            getch();

            do {
                gotoxy(37, 16);
                nova = getchar();
                nova = toupper(nova);
            } while (nova != 'S' && nova != 'N');

            if (nova == 'N') { limparBuffer(); menu_tipos_filme(); }
            if (nova == 'S') inclusao_tipo();
        }
        else {
            salvar_tipo(t);

            gotoxy(7, 18);
            printf("Tipo cadastrado com sucesso!");
            getch();

            do {
                gotoxy(37, 16);
                nova = getchar();
                nova = toupper(nova);
            } while (nova != 'S' && nova != 'N');

            if (nova == 'N') { limparBuffer(); menu_tipos_filme(); }
            if (nova == 'S') inclusao_tipo();
        }
    }
}
