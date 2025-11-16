/*
  Autor...: José Luiz Delgado Tavares
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Excluir filmes
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"

void Deletar_filme() {

    int i;
    char codigo[10];
    char titulo[100];
    char diretor[100];
    char linha[512];
    Filme f;
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
        printf("EXCLUIR FILMES");

        gotoxy(7, 9);
        printf("1 - Codigo:.........");
        gotoxy(7, 11);
        printf("2 - Titulo:.........");
        gotoxy(7, 13);
        printf("3 - Diretor:........");

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

        // Título
        do {
            gotoxy(27, 11);
            printf("                                        ");
            gotoxy(27, 11);
            fgets(titulo, sizeof(titulo), stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
        } while (strlen(titulo) == 0);

        // Diretor
        do {
            gotoxy(27, 13);
            printf("                                        ");
            gotoxy(27, 13);
            fgets(diretor, sizeof(diretor), stdin);
            diretor[strcspn(diretor, "\n")] = '\0';
        } while (strlen(diretor) == 0);

        // ===== Leitura e busca no arquivo =====
        FILE* arquivo = fopen("filmes.txt", "r");
        if (arquivo == NULL) {
            gotoxy(2, 23);
            printf("MSG.: Erro ao abrir o arquivo filmes.txt");
            getch();
            return;
        }

        encontrado = 0;
        while (fgets(linha, sizeof(linha), arquivo)) {
            // Quebra a linha nos campos
            char* token = strtok(linha, ",");
            if (token) strcpy(f.codigo, token);
            token = strtok(NULL, ",");
            if (token) strcpy(f.titulo, token);
            token = strtok(NULL, ",");
            if (token) strcpy(f.genero, token);
            token = strtok(NULL, ",");
            if (token) strcpy(f.diretor, token);
            token = strtok(NULL, ",");
            if (token) strcpy(f.ano, token);
            token = strtok(NULL, ",");
            if (token) strcpy(f.classificacao, token);
            token = strtok(NULL, ",");
            if (token) strcpy(f.dataHora, token);

            // Verifica correspondência
            if (strcmp(f.codigo, codigo) == 0 &&
                strcmp(f.titulo, titulo) == 0 &&
                strcmp(f.diretor, diretor) == 0) {
                encontrado = 1;
                break;
            }
        }

        fclose(arquivo);

        if (encontrado) {
            // Limpa área central e mostra dados do filme
            for (int y = 6; y <= 20; y++) {
                gotoxy(5, y);
                printf("                                                                               ");
            }

            gotoxy(7, 6);
            printf("CADASTRO DE FILME");

            gotoxy(7, 8);
            printf("Codigo do filme.........: %s", f.codigo);
            gotoxy(7, 9);
            printf("Titulo..................: %s", f.titulo);
            gotoxy(7, 10);
            printf("Quantidade disponivel...: %s", f.genero);
            gotoxy(7, 11);
            printf("Diretor.................: %s", f.diretor);
            gotoxy(7, 12);
            printf("Ano.....................: %s", f.ano);
            gotoxy(7, 13);
            printf("Classificacao...........: %s", f.classificacao);
            gotoxy(7, 14);
            printf("Data e hora do cadastro.: %s", f.dataHora);

            // ===== Confirma exclusão =====
            char confirma;
            do {
                gotoxy(2, 23);
                printf("CONFIRMA EXCLUSAO ( S/N ) ? ");
                confirma = toupper(getchar());
            } while (confirma != 'S' && confirma != 'N');

            if (confirma == 'S') {
                // ===== Exclusão direta no arquivo =====
                FILE* arq = fopen("filmes.txt", "r+");
                if (arq == NULL) {
                    gotoxy(2, 23);
                    printf("Erro ao abrir o arquivo para exclusao!");
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

                    Filme temp;
                    char* token = strtok(linhaTemp, ",");
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

                    if (strcmp(temp.codigo, f.codigo) == 0 &&
                        strcmp(temp.titulo, f.titulo) == 0 &&
                        strcmp(temp.diretor, f.diretor) == 0) {
                        posInicio = pos;
                        break;
                    }
                }

                if (posInicio == -1) {
                    fclose(arq);
                    gotoxy(2, 23);
                    printf("Filme nao encontrado para exclusao!");
                    getch();
                }
                else {
                    fseek(arq, posInicio, SEEK_SET);
                    for (int j = 0; j < tamLinha - 1; j++) fputc(' ', arq);
                    fputc('\n', arq);
                    fflush(arq);
                    fclose(arq);

                    gotoxy(2, 23);
                    printf("                                     ");
                    gotoxy(2, 23);
                    printf("FILME EXCLUIDO COM SUCESSO!");
                    getch();
                }
            }

            // ===== Nova exclusão =====
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
                Deletar_filme();
            }
            else {
                limparBuffer();
                menu_filmes();
            }
        }
        else {
            gotoxy(7, 15);
            printf("MSG.: Filme nao encontrado!");

            char nova;
            do {
                gotoxy(2, 23);
                printf("NOVA EXCLUSAO ( S/N ) ? ");
                nova = toupper(getchar());
            } while (nova != 'S' && nova != 'N');

            if (nova == 'S') {
                limparBuffer();
                Deletar_filme();
            }
            else {
                limparBuffer();
                menu_filmes();
            }
        }

        getch();

    } while (1);
}
