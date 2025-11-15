/*
  Autor...: José Luiz Delgado Tavares
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Cadastrar filmes
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"
#include <time.h>
#include <string.h>
#include <ctype.h>

void salvar_filmes(Filme f) {
    // Adiciona no array de filmes em memória
    if (n_filmes < MAX_FILMES) {
        filmes[n_filmes++] = f;
    }
    else {
        printf("Limite máximo de filmes atingido!\n");
        return;
    }

    // Abre o arquivo para acrescentar o filme
    FILE* arquivo = fopen("filmes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar o filme.\n");
        return;
    }

    // Salva os dados no arquivo em formato texto, separados por vírgula
    fprintf(arquivo, "%s,%s,%s,%s,%s,%s,%s,%d\n",
        f.codigo,
        f.titulo,
        f.genero,
        f.diretor,
        f.ano,
        f.classificacao,
        f.dataHora,
        f.alugado
    );

    fclose(arquivo);
}

void inclusao_filme() {
    int i;
    char confirma, nova;
    char codigo[10];
    char titulo[100];
    char genero[50];
    char diretor[100];
    char ano[5];
    char classificacao[10];
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
    printf("CADASTRO DE FILMES");
    gotoxy(7, 8);
    printf("Codigo do filme.........:");
    gotoxy(7, 9);
    printf("Titulo do filme.........:");
    gotoxy(7, 10);
    printf("Genero..................:");
    gotoxy(7, 11);
    printf("Diretor.................:");
    gotoxy(7, 12);
    printf("Ano de lancamento.......:");
    gotoxy(7, 13);
    printf("Classificacao indicativa:");
    gotoxy(7, 14);
    printf("Data e hora do cadastro.:");

    gotoxy(7, 16);
    printf("CONFIRMA INCLUSAO ( S/N ) ?");
    gotoxy(7, 18);
    printf("NOVA INCLUSAO( S/N ) ?");

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

    // ===== Entrada dos campos =====

    // Código
    do {
        gotoxy(37, 8);
        printf("                 ");
        gotoxy(37, 8);
        fgets(codigo, sizeof(codigo), stdin);
        codigo[strcspn(codigo, "\n")] = '\0';
    } while (strlen(codigo) == 0);

    // Título
    do {
        gotoxy(37, 9);
        printf("                                        ");
        gotoxy(37, 9);
        fgets(titulo, sizeof(titulo), stdin);
        titulo[strcspn(titulo, "\n")] = '\0';
    } while (strlen(titulo) == 0);

    // Gênero
    do {
        gotoxy(37, 10);
        printf("                                        ");
        gotoxy(37, 10);
        fgets(genero, sizeof(genero), stdin);
        genero[strcspn(genero, "\n")] = '\0';
    } while (strlen(genero) == 0);

    // Diretor
    do {
        gotoxy(37, 11);
        printf("                                        ");
        gotoxy(37, 11);
        fgets(diretor, sizeof(diretor), stdin);
        diretor[strcspn(diretor, "\n")] = '\0';
    } while (strlen(diretor) == 0);

    // Ano
    do {
        gotoxy(37, 12);
        printf("     ");
        gotoxy(37, 12);
        fgets(ano, sizeof(ano), stdin);
        ano[strcspn(ano, "\n")] = '\0';
    } while (strlen(ano) == 0);

    // Classificação
    do {
        gotoxy(37, 13);
        printf("     ");
        gotoxy(37, 13);
        fgets(classificacao, sizeof(classificacao), stdin);
        classificacao[strcspn(classificacao, "\n")] = '\0';
    } while (strlen(classificacao) == 0);

    // ===== Data e hora =====
    time(&agora);
    ptrTempo = localtime(&agora);
    if (ptrTempo != NULL) {
        infoTempo = *ptrTempo;
        strftime(dataHora, sizeof(dataHora), "%d/%m/%Y %H:%M:%S", &infoTempo);
        gotoxy(37, 14);
        printf("%s", dataHora);
    }
    else {
        gotoxy(37, 14);
        printf("Erro ao obter data/hora");
    };

    // ===== Confirmação =====
    do {
        gotoxy(37, 16);
        confirma = getchar();
        confirma = toupper(confirma);
    } while (confirma != 'S' && confirma != 'N');

    if (confirma == 'N') {
        do {
            gotoxy(37, 18);
            nova = getchar();
            nova = toupper(nova);
        } while (nova != 'S' && nova != 'N');

        if (nova == 'N') limparBuffer(); menu_filmes();
        if (nova == 'S') inclusao_filme();
    }

    if (confirma == 'S') {
        Filme f;

        strcpy(f.codigo, codigo);
        strcpy(f.titulo, titulo);
        strcpy(f.genero, genero);
        strcpy(f.diretor, diretor);
        strcpy(f.ano, ano);
        strcpy(f.classificacao, classificacao);
        strcpy(f.dataHora, dataHora);
        f.alugado = 0;

        // ===== Verifica duplicados =====
        FILE* arquivo = fopen("filmes.txt", "r");
        int duplicado = 0;
        char linha[512];

        if (arquivo != NULL) {
            while (fgets(linha, sizeof(linha), arquivo)) {
                Filme temp;
                char* token = strtok(linha, ",");
                if (token) strcpy(temp.codigo, token);
                token = strtok(NULL, ",");
                if (token) strcpy(temp.titulo, token);
                token = strtok(NULL, ",");
                if (token) strcpy(temp.genero, token);
                token = strtok(NULL, ",");
                if (token) strcpy(temp.diretor, token);
                token = strtok(NULL, ",");
                if (token) strcpy(temp.ano, token);
                token = strtok(NULL, ",");
                if (token) strcpy(temp.classificacao, token);
                token = strtok(NULL, ",");
                if (token) strcpy(temp.dataHora, token);
                token = strtok(NULL, ",");
                if (token) temp.alugado = atoi(token);

                // Verifica se já existe código igual
                if (strcmp(temp.codigo, f.codigo) == 0) {
                    duplicado = 1;
                    break;
                }
            }
            fclose(arquivo);
        }

        if (duplicado) {
            gotoxy(7, 20);
            printf("MSG.: Ja existe um filme com esse CODIGO!");
            getch();

            do {
                gotoxy(37, 18);
                nova = getchar();
                nova = toupper(nova);
            } while (nova != 'S' && nova != 'N');

            if (nova == 'N') limparBuffer(); menu_filmes();
            if (nova == 'S') inclusao_filme();
        }
        else {
            salvar_filmes(f);

            gotoxy(7, 20);
            printf("Filme cadastrado com sucesso!");
            getch();

            do {
                gotoxy(37, 18);
                nova = getchar();
                nova = toupper(nova);
            } while (nova != 'S' && nova != 'N');

            if (nova == 'N') limparBuffer(); menu_filmes();
            if (nova == 'S') inclusao_filme();
        }
    }
}
