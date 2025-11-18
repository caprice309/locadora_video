/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Consultar clientes
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"
#include <ctype.h>


void Consultar_cliente() {

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
        printf("CONSULTAR CLIENTES");

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
            // Quebra a linha nos campos
            char* token = strtok(linha, ",");
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
            printf("CADASTRO DE CLIENTE");

            gotoxy(7, 8);
            printf("Codigo do cliente........: %s", c.codigo);
            gotoxy(7, 9);
            printf("Nome completo do cliente.: %s", c.nome);
            gotoxy(7, 10);
            printf("Endereco do cliente......: %s", c.endereco);
            gotoxy(7, 11);
            printf("Numero do documento (CPF): %s", c.cpf);
            gotoxy(7, 12);
            printf("Cidade do cliente........: %s", c.cidade);
            gotoxy(7, 13);
            printf("Unidade Federativa (UF)..: %s", c.uf);
            gotoxy(7, 14);
            printf("Data e hora do cadastro..: %s", c.dataHora);

            char nova;
            do {
                gotoxy(2, 23);
                printf("NOVA CONSULTA ( S/N ) ? ");
                nova = toupper(getchar());
            } while (nova != 'S' && nova != 'N');

            if (nova == 'S') {
                limparBuffer();
                Consultar_cliente();
            };

            if (nova == 'N') {
                limparBuffer();
                menu_cliente();
            };
        }
        else {
            gotoxy(7, 15);
            printf("MSG.: Cliente nao encontrado!");

            char nova;
            do {
                gotoxy(2, 23);
                printf("NOVA CONSULTA ( S/N ) ? ");
                nova = toupper(getchar());
            } while (nova != 'S' && nova != 'N');

            if (nova == 'S') {
                limparBuffer();
                Consultar_cliente();
            };

            if (nova == 'N') {
                limparBuffer();
                menu_cliente();
            };
        }

        getch();

    } while (1);
}
