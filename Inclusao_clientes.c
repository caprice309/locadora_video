/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Cadastrar clientes
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"
#include <time.h>
#include <string.h>

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
};

void salvar_cliente(Cliente c) {
    // Adiciona no array de clientes em memória
    if (n_clientes < MAX_CLIENTES) {
        clientes[n_clientes++] = c;
    }
    else {
        printf("Limite máximo de clientes atingido!\n");
        return;
    }

    // Abre o arquivo para acrescentar o cliente
    FILE* arquivo = fopen("clientes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para salvar o cliente.\n");
        return;
    }

    // Salva os dados no arquivo em formato texto, separados por vírgula
    fprintf(arquivo, "%s,%s,%s,%s,%s,%s,%s,%d\n",
        c.codigo,
        c.nome,
        c.endereco,
        c.cpf,
        c.cidade,
        c.uf,
        c.dataHora,
        c.filmesAlugados
    );

    fclose(arquivo); // Fecha o arquivo
}


void inclusao_cliente() {
    int i;
    char confirma, nova;
    char codigo[10];
    char nome[100];
    char endereco[200];
    char cpf[11];
    char cidade[100];
    char uf[3];
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
        printf("CADASTRO DE CLIENTE");
        gotoxy(7, 8);
        printf("Codigo do cliente........:");
        gotoxy(7, 9);
        printf("Nome completo do cliente.:");
        gotoxy(7, 10);
        printf("Endereco do cliente......:");
        gotoxy(7, 11);
        printf("Numero do documento (CPF):");
        gotoxy(7, 12);
        printf("Cidade do cliente........:");
        gotoxy(7, 13);
        printf("Unidade Federativa (UF)..:");
        gotoxy(7, 14);
        printf("Data e hora do cadastro..:");

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

        // Nome
        do {
            gotoxy(37, 9);
            printf("                                        ");
            gotoxy(37, 9);
            fgets(nome, sizeof(nome), stdin);
            nome[strcspn(nome, "\n")] = '\0';
        } while (strlen(nome) == 0);

        // Endereço
        do {
            gotoxy(37, 10);
            printf("                                        ");
            gotoxy(37, 10);
            fgets(endereco, sizeof(endereco), stdin);
            endereco[strcspn(endereco, "\n")] = '\0';
        } while (strlen(endereco) == 0);

        // CPF
        do {
            gotoxy(37, 11);
            printf("                 ");
            gotoxy(37, 11);
            fgets(cpf, sizeof(cpf), stdin);
            cpf[strcspn(cpf, "\n")] = '\0';
        } while (strlen(cpf) == 0);

        // Cidade
        do {
            gotoxy(37, 12);
            printf("                                        ");
            gotoxy(37, 12);
            fgets(cidade, sizeof(cidade), stdin);
            cidade[strcspn(cidade, "\n")] = '\0';
        } while (strlen(cidade) == 0);

        // UF
        do {
            gotoxy(37, 13);
            printf("     ");
            gotoxy(37, 13);
            fgets(uf, sizeof(uf), stdin);
            uf[strcspn(uf, "\n")] = '\0';
        } while (strlen(uf) == 0);

        // ===== Data e hora do cadastro =====
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
        
        // Confirmação do cadastro
        do {
            gotoxy(37, 16);
            confirma = getchar();
            confirma = toupper(confirma);
        } while (confirma != 'S' && confirma != 'N');
        
        if (confirma == 'N') { 
            // Pergunta se quer nova inclusão
            do {
                gotoxy(37, 18);
                nova = getchar();
                nova = toupper(nova);
            } while (nova != 'S' && nova != 'N');

            if (nova == 'N') {
                limparBuffer();
                menu_cliente();
            };

            if (nova == 'S') {
                inclusao_cliente();
            };
        };

        if (confirma == 'S') {
            // === salva os dados ===
            Cliente c;

            strcpy(c.codigo, codigo);
            strcpy(c.nome, nome);
            strcpy(c.endereco, endereco);
            strcpy(c.cpf, cpf);
            strcpy(c.cidade, cidade);
            strcpy(c.uf, uf);
            strcpy(c.dataHora, dataHora);
            c.filmesAlugados = 0;

            // Chama a função para salvar na memória e no arquivo
            // ===== Verifica se já existe cliente com o mesmo código ou CPF =====
            FILE* arquivo = fopen("clientes.txt", "r");
            int duplicado = 0;
            char linha[512];

            if (arquivo != NULL) {
                while (fgets(linha, sizeof(linha), arquivo)) {
                    Cliente temp;
                    char* token = strtok(linha, ",");
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

                    // Verifica se já existe código ou CPF igual
                    if (strcmp(temp.codigo, c.codigo) == 0 || strcmp(temp.cpf, c.cpf) == 0) {
                        duplicado = 1;
                        break;
                    }
                }
                fclose(arquivo);
            }

            if (duplicado) {
                gotoxy(7, 20);
                printf("MSG.: Ja existe um cliente com esse CODIGO ou CPF!");
                getch();

                // Pergunta se quer nova inclusão
                do {
                    gotoxy(37, 18);
                    nova = getchar();
                    nova = toupper(nova);
                } while (nova != 'S' && nova != 'N');

                if (nova == 'N') {
                    limparBuffer();
                    menu_cliente();
                }

                if (nova == 'S') {
                    inclusao_cliente();
                }
            }
            else {
                // ===== Nenhum duplicado encontrado, pode salvar normalmente =====
                salvar_cliente(c);

                gotoxy(7, 20);
                printf("Cliente cadastrado com sucesso!");
                getch();

                // Pergunta se quer nova inclusão
                do {
                    gotoxy(37, 18);
                    nova = getchar();
                    nova = toupper(nova);
                } while (nova != 'S' && nova != 'N');

                if (nova == 'N') {
                    limparBuffer();
                    menu_cliente();
                }

                if (nova == 'S') {
                    inclusao_cliente();
                }
            }
        }

}
