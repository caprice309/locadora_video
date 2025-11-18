/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Mudar informações de clientes
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"

void Alterar_cliente() {

    int i;
    char codigo[10];
    char nome[100];
    char cpf[12];
    char linha[512];
    Cliente c;
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
        printf("ALTERAR CLIENTES");

        gotoxy(7, 9);
        printf("1 - Codigo:.........");
        gotoxy(7, 11);
        printf("2 - Nome Completo:..");
        gotoxy(7, 13);
        printf("3 - CPF:............");

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

        // Nome
        do {
            gotoxy(27, 11);
            printf("                                        ");
            gotoxy(27, 11);
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
        } while (strlen(nome) == 0);

        // CPF
        do {
            gotoxy(27, 13);
            printf("                    ");
            gotoxy(27, 13);
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf, "\n")] = '\0';
        } while (strlen(cpf) == 0);

        // ===== Leitura e busca no arquivo =====
        FILE* arquivo = fopen("clientes.txt", "r");
        if (arquivo == NULL) {
            gotoxy(2, 23);
            printf("MSG.: Erro ao abrir o arquivo clientes.txt");
            getch();
            return;
        }

        encontrado = 0;
        while (fgets(linha, sizeof(linha), arquivo)) {

            char copy[512];
            strcpy(copy, linha);

            char* token = strtok(copy, ",");
            if (token) strcpy(c.codigo, token);
            token = strtok(NULL, ",");
            if (token) strcpy(c.nome, token);
            token = strtok(NULL, ",");
            if (token) strcpy(c.endereco, token);
            token = strtok(NULL, ",");
            if (token) strcpy(c.cpf, token);
            token = strtok(NULL, ",");
            if (token) strcpy(c.cidade, token);
            token = strtok(NULL, ",");
            if (token) strcpy(c.uf, token);
            token = strtok(NULL, ",");
            if (token) strcpy(c.dataHora, token);
            token = strtok(NULL, ",");
            if (token) c.filmesAlugados = atoi(token);

            // Verifica correspondência
            if (strcmp(c.codigo, codigo) == 0 &&
                strcmp(c.nome, nome) == 0 &&
                strcmp(c.cpf, cpf) == 0) {
                encontrado = 1;
                break;
            }
        }

        fclose(arquivo);

        if (encontrado) {
            // Limpa área central e mostra dados do cliente
            for (int y = 6; y <= 20; y++) {
                gotoxy(5, y);
                printf("                                                                               ");
            }

            gotoxy(7, 6);
            printf("ALTERACAO DE CADASTRO DE CLIENTE");

            // ===== Entrada dos campos =====
            char tmp[256];

            // Código
            gotoxy(7, 8);
            printf("Codigo do cliente........: %s", c.codigo);
            gotoxy(40, 8);
            printf("                    ");
            gotoxy(40, 8);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            // Trim 
            int s = 0, e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                // copia valor novo (a partir de tmp+s) para c.codigo
                strncpy(c.codigo, tmp + s, sizeof(c.codigo) - 1);
                c.codigo[sizeof(c.codigo) - 1] = '\0';
            }

            // Nome
            gotoxy(7, 9);
            printf("Nome completo do cliente.: %s", c.nome);
            gotoxy(40, 9);
            printf("                                        ");
            gotoxy(40, 9);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(c.nome, tmp + s, sizeof(c.nome) - 1);
                c.nome[sizeof(c.nome) - 1] = '\0';
            }

            // Endereço
            gotoxy(7, 10);
            printf("Endereco do cliente......: %s", c.endereco);
            gotoxy(40, 10);
            printf("                                        ");
            gotoxy(40, 10);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(c.endereco, tmp + s, sizeof(c.endereco) - 1);
                c.endereco[sizeof(c.endereco) - 1] = '\0';
            }

            // CPF
            gotoxy(7, 11);
            printf("Numero do documento (CPF): %s", c.cpf);
            gotoxy(40, 11);
            printf("                    ");
            gotoxy(40, 11);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(c.cpf, tmp + s, sizeof(c.cpf) - 1);
                c.cpf[sizeof(c.cpf) - 1] = '\0';
            }

            // Cidade
            gotoxy(7, 12);
            printf("Cidade do cliente........: %s", c.cidade);
            gotoxy(40, 12);
            printf("                                        ");
            gotoxy(40, 12);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(c.cidade, tmp + s, sizeof(c.cidade) - 1);
                c.cidade[sizeof(c.cidade) - 1] = '\0';
            }

            // UF
            gotoxy(7, 13);
            printf("Unidade Federativa (UF)..: %s", c.uf);
            gotoxy(40, 13);
            printf("     ");
            gotoxy(40, 13);
            fgets(tmp, sizeof(tmp), stdin);
            tmp[strcspn(tmp, "\n")] = '\0';
            s = 0; e = (int)strlen(tmp) - 1;
            while (tmp[s] == ' ' || tmp[s] == '\t') s++;
            while (e >= s && (tmp[e] == ' ' || tmp[e] == '\t')) tmp[e--] = '\0';
            if (strlen(tmp + s) > 0) {
                strncpy(c.uf, tmp + s, sizeof(c.uf) - 1);
                c.uf[sizeof(c.uf) - 1] = '\0';
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
                FILE* arquivo = fopen("clientes.txt", "r+");
                if (arquivo == NULL) {
                    gotoxy(2, 23);
                    printf("Erro ao abrir o arquivo para alterar o cliente!");
                    getch();
                    return;
                }

                char linhaTemp[512];
                long posInicio = -1;

                // Procura a posição do cliente no arquivo
                while (!feof(arquivo)) {
                    long pos = ftell(arquivo);
                    if (fgets(linhaTemp, sizeof(linhaTemp), arquivo) == NULL) break;

                    Cliente temp;
                    char copyT[512];
                    strcpy(copyT, linhaTemp);

                    char* token = strtok(copyT, ",");
                    if (token) strcpy(temp.codigo, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.nome, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.endereco, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.cpf, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.cidade, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.uf, token);
                    token = strtok(NULL, ",");
                    if (token) strcpy(temp.dataHora, token);
                    token = strtok(NULL, ",");
                    if (token) temp.filmesAlugados = atoi(token);

                    if (strcmp(temp.codigo, codigo) == 0 ||
                        strcmp(temp.cpf, cpf) == 0 ||
                        strcmp(temp.nome, nome) == 0) {

                        posInicio = pos;
                        c.filmesAlugados = temp.filmesAlugados;
                        break;
                    }
                }

                if (posInicio == -1) {
                    fclose(arquivo);
                    gotoxy(2, 23);
                    printf("Cliente nao encontrado para alteracao!");
                    getch();
                }
                else {
                    // Move o cursor de volta pro início da linha
                    fseek(arquivo, posInicio, SEEK_SET);

                    // Regrava a linha com os novos dados
                    fprintf(arquivo, "%s,%s,%s,%s,%s,%s,%s,%d\n",
                        c.codigo,
                        c.nome,
                        c.endereco,
                        c.cpf,
                        c.cidade,
                        c.uf,
                        c.dataHora,
                        c.filmesAlugados);


                    fflush(arquivo); // força escrita imediata
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
                Alterar_cliente();
            }
            else {
                limparBuffer();
                menu_cliente();
            }
        }
        else {
            gotoxy(7, 15);
            printf("Cliente nao encontrado!");
            gotoxy(7, 17);
            printf("Pressione qualquer tecla para tentar novamente...");
            getch();
            continue;
        }

        getch();

    } while (1);
}

