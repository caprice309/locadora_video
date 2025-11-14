/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Mudar informa��es de filmes
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"

void Alterar_filme() {

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
        printf("ALTERAR FILMES");

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

        // C�digo
        do {
            gotoxy(27, 9);
            printf("                    ");
            gotoxy(27, 9);
            fgets(codigo, sizeof(codigo), stdin);
            codigo[strcspn(codigo, "\n")] = '\0';
        } while (strlen(codigo) == 0);

        // T�tulo
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
            char linhaCopy[512];
            strcpy(linhaCopy, linha); // strtok modifica a string
            char* token = strtok(linhaCopy, ",");
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
            token = strtok(NULL, ",");
            if (token) f.alugado = atoi(token); // l� o campo alugado (0 ou 1)

            // Verifica correspond�ncia
            if (strcmp(f.codigo, codigo) == 0 &&
                strcmp(f.titulo, titulo) == 0 &&
                strcmp(f.diretor, diretor) == 0) {
                encontrado = 1;
                break;
            };
        };

        fclose(arquivo);

        if (encontrado) {
            // Limpa �rea central
            for (int y = 6; y <= 20; y++) {
                gotoxy(5, y);
                printf("                                                                               ");
            }

            gotoxy(7, 6);
            printf("ALTERACAO DE CADASTRO DE FILME");

            char tmp[256];

            // C�digo
            gotoxy(7, 8);
            printf("Codigo do filme.........: %s", f.codigo);
            gotoxy(40, 8);
            printf("                    ");
            gotoxy(40, 8);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            int s = 0, e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) strncpy(f.codigo, tmp + s, sizeof(f.codigo) - 1);

            // T�tulo
            gotoxy(7, 9);
            printf("Titulo do filme.........: %s", f.titulo);
            gotoxy(40, 9);
            printf("                                        ");
            gotoxy(40, 9);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) strncpy(f.titulo, tmp + s, sizeof(f.titulo) - 1);

            // G�nero
            gotoxy(7, 10);
            printf("Genero do filme.........: %s", f.genero);
            gotoxy(40, 10);
            printf("                                        ");
            gotoxy(40, 10);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) strncpy(f.genero, tmp + s, sizeof(f.genero) - 1);

            // Diretor
            gotoxy(7, 11);
            printf("Diretor do filme........: %s", f.diretor);
            gotoxy(40, 11);
            printf("                                        ");
            gotoxy(40, 11);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) strncpy(f.diretor, tmp + s, sizeof(f.diretor) - 1);

            // Ano
            gotoxy(7, 12);
            printf("Ano de lancamento.......: %s", f.ano);
            gotoxy(40, 12);
            printf("     ");
            gotoxy(40, 12);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            if (strlen(tmp) > 0) strncpy(f.ano, tmp, sizeof(f.ano) - 1);

            // Classifica��o
            gotoxy(7, 13);
            printf("Classificacao indicativa: %s", f.classificacao);
            gotoxy(40, 13);
            printf("     ");
            gotoxy(40, 13);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            if (strlen(tmp) > 0) strncpy(f.classificacao, tmp, sizeof(f.classificacao) - 1);

            // ===== Confirma��o =====
            char confirma;
            do {
                gotoxy(2, 23);
                printf("CONFIRMA ALTERACAO ( S/N ) ? ");
                confirma = toupper(getchar());
            } while (confirma != 'S' && confirma != 'N');

            if (confirma == 'S') {
                FILE* arquivo = fopen("filmes.txt", "r+");
                if (arquivo == NULL) {
                    gotoxy(2, 23);
                    printf("Erro ao abrir o arquivo para alterar o filme!");
                    getch();
                    return;
                }

                char linhaTemp[512];
                long posInicio = -1;

                // Procura a posi��o do cliente no arquivo 
                while (!feof(arquivo)) {
                    long pos = ftell(arquivo);
                    if (fgets(linhaTemp, sizeof(linhaTemp), arquivo) == NULL) break;

                    Filme temp;
                    char tempLine[512];
                    strcpy(tempLine, linhaTemp);

                    char* token = strtok(tempLine, ",");
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

                    if (strcmp(temp.codigo, codigo) == 0 ||
                        strcmp(temp.titulo, titulo) == 0 ||
                        strcmp(temp.diretor, diretor) == 0) {
                        posInicio = pos;
                        f.alugado = temp.alugado;
                        break;
                    }
                }


                if (posInicio == -1) {
                    fclose(arquivo);
                    gotoxy(2, 23);
                    printf("Filme nao encontrado para alteracao!");
                    getch();
                }
                else {
                    fseek(arquivo, posInicio, SEEK_SET);
                    fprintf(arquivo, "%s,%s,%s,%s,%s,%s,%s,%d\n",
                        f.codigo,
                        f.titulo,
                        f.genero,
                        f.diretor,
                        f.ano,
                        f.classificacao,
                        f.dataHora,
                        f.alugado);

                    fflush(arquivo);
                    fclose(arquivo);

                    gotoxy(2, 23);
                    printf("ALTERACAO CONFIRMADA COM SUCESSO!");
                    getch();
                }
            }

            // ===== Nova altera��o =====
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
                Alterar_filme();
            }
            else {
                limparBuffer();
                menu_filmes();
            }
        }
        else {
            gotoxy(7, 15);
            printf("Filme nao encontrado!");
            gotoxy(7, 17);
            printf("Pressione qualquer tecla para tentar novamente...");
            getch();
            continue;
        }

        getch();

    } while (1);
}
