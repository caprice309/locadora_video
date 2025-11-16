/*
  Autor...: José Luiz Delgado Tavares
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Devolver filmes alugados
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"
#include <conio.h>

int perguntarNovaDevolucao() {
    char novo;
    do {
        gotoxy(2, 23);
        printf("                                   ");
        gotoxy(2, 23);
        printf("NOVA DEVOLUCAO ( S/N ) ? ");
        novo = toupper(getchar());
    } while (novo != 'S' && novo != 'N');

    limparBuffer();

    return (novo == 'S'); 
}



void devolver_movimentacao() {

    while (1) {     //Pq só essa tela ta dando erro de recursão mds

        int i;
        system("color 0a");
        system("cls");

        gotoxy(2, 2);  printf("ENZO GATI BARBARESCO");
        gotoxy(2, 3);  printf("JOSE LUIZ DELGADO TAVARES");
        gotoxy(61, 2); printf("ESTRUTURA DE DADOS");

        gotoxy(7, 7);  printf("DEVOLVER FILME");

        gotoxy(7, 9);  printf("FILME");
        gotoxy(7, 10); printf("Codigo:........");
        gotoxy(7, 11); printf("Titulo:........");
        gotoxy(7, 12); printf("Tipo:..........");

        gotoxy(7, 14); printf("CLIENTE");
        gotoxy(7, 15); printf("Codigo:........");
        gotoxy(7, 16); printf("Nome:..........");

        for (i = 1; i <= 24; i++) {
            gotoxy(1, i);  printf("|");
            gotoxy(80, i); printf("|");
        }

        for (i = 1; i <= 80; i++) {
            gotoxy(i, 1);  printf("-");
            gotoxy(i, 4);  printf("-");
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

        // ---- ENTRADA DE DADOS ----

        char codFilme[10];
        do {
            gotoxy(25, 10); printf("                ");
            gotoxy(25, 10);
            fgets(codFilme, sizeof(codFilme), stdin);
            codFilme[strcspn(codFilme, "\n")] = '\0';
        } while (strlen(codFilme) == 0);

        char titulo[50];
        do {
            gotoxy(25, 11); printf("                                        ");
            gotoxy(25, 11);
            fgets(titulo, sizeof(titulo), stdin);
            titulo[strcspn(titulo, "\n")] = '\0';
        } while (strlen(titulo) == 0);


        // --- VERIFICAR FILME ----

        FILE* arq = fopen("filmes.txt", "r");
        if (!arq) {
            gotoxy(2, 23); printf("ERRO AO ABRIR ARQUIVO DE FILMES!");
            getch();
            continue;   // volta
        }

        Filme filmes[500];
        int totalFilmes = 0;
        int indiceFilme = -1;

        char linha[500];

        while (fgets(linha, sizeof(linha), arq)) {
            Filme f;
            sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d",
                f.codigo, f.titulo, f.genero, f.diretor,
                f.ano, f.classificacao, f.dataHora, &f.alugado);

            filmes[totalFilmes] = f;

            if (strcmp(f.codigo, codFilme) == 0 &&
                strcmp(f.titulo, titulo) == 0) {
                indiceFilme = totalFilmes;
            }

            totalFilmes++;
        }
        fclose(arq);

        // --- filme não encontrado ---
        if (indiceFilme == -1) {
            gotoxy(2, 23); printf("FILME NAO ENCONTRADO!");
            getch();

            if (!perguntarNovaDevolucao()) {
                menu_movimentacao();
                return;
            }
            continue;
        }

        // --- filme não alugado ---
        if (filmes[indiceFilme].alugado == 0) {
            gotoxy(2, 23); printf("FILME NAO ESTA ALUGADO!");
            getch();

            if (!perguntarNovaDevolucao()) {
                menu_movimentacao();
                return;
            }
            continue;
        }

        // --- TIPO ---
        char tipo[20];
        do {
            gotoxy(25, 12); printf("                    ");
            gotoxy(25, 12);
            fgets(tipo, sizeof(tipo), stdin);
            tipo[strcspn(tipo, "\n")] = '\0';
        } while (strlen(tipo) == 0);


        // ---- VERIFICAR TIPO ----

        FILE* arqTipos = fopen("tipos.txt", "r");
        if (!arqTipos) {
            gotoxy(2, 23); printf("ERRO AO ABRIR TIPOS!");
            getch();
            continue;
        }

        int tipoEncontrado = 0;
        char linhaTipo[400], codigoT[10], tipoT[50];

        while (fgets(linhaTipo, sizeof(linhaTipo), arqTipos)) {
            sscanf(linhaTipo, "%[^,],%[^,],", codigoT, tipoT);

            if (strcmp(tipoT, tipo) == 0) {
                tipoEncontrado = 1;
                break;
            }
        }
        fclose(arqTipos);

        if (!tipoEncontrado) {
            gotoxy(2, 23); printf("TIPO INVALIDO!");
            getch();
            continue;
        }


        // ---- CLIENTE ----

        char codCliente[10];
        do {
            gotoxy(25, 15); printf("                ");
            gotoxy(25, 15);
            fgets(codCliente, sizeof(codCliente), stdin);
            codCliente[strcspn(codCliente, "\n")] = '\0';
        } while (strlen(codCliente) == 0);

        char nomeCliente[100];
        do {
            gotoxy(25, 16); printf("                                        ");
            gotoxy(25, 16);
            fgets(nomeCliente, sizeof(nomeCliente), stdin);
            nomeCliente[strcspn(nomeCliente, "\n")] = '\0';
        } while (strlen(nomeCliente) == 0);


        // ---- VERIFICAR CLIENTE ----

        FILE* arqClientes = fopen("clientes.txt", "r");
        if (!arqClientes) {
            gotoxy(2, 23); printf("ERRO AO ABRIR CLIENTES!");
            getch();
            continue;
        }

        int clienteEncontrado = 0;
        char linhaCliente[600], codC[10], nomeC[100];

        while (fgets(linhaCliente, sizeof(linhaCliente), arqClientes)) {
            sscanf(linhaCliente, "%[^,],%[^,],", codC, nomeC);

            if (strcmp(codC, codCliente) == 0 &&
                strcmp(nomeC, nomeCliente) == 0) {
                clienteEncontrado = 1;
                break;
            }
        }
        fclose(arqClientes);

        if (!clienteEncontrado) {
            gotoxy(2, 23); printf("CLIENTE INVALIDO!");
            getch();
            continue;
        }


        // ===== CONFIRMA DEVOLUÇÃO =====

        char confirma;
        do {
            gotoxy(2, 23);
            printf("CONFIRMA DEVOLUCAO ( S/N ) ? ");
            confirma = toupper(getchar());
        } while (confirma != 'S' && confirma != 'N');

        limparBuffer();

        if (confirma == 'N') {
            if (!perguntarNovaDevolucao()) {
                menu_movimentacao();
                return;
            }
            continue;
        }

        // ---- ATUALIZAR ARQUIVO ----

        FILE* arqUpdate = fopen("filmes.txt", "r+");
        if (!arqUpdate) {
            gotoxy(2, 23); printf("ERRO AO ATUALIZAR!");
            getch();
            continue;
        }

        long posInicio = -1;
        char linhaF[500];
        Filme temp;

        while (!feof(arqUpdate)) {
            long pos = ftell(arqUpdate);

            if (!fgets(linhaF, sizeof(linhaF), arqUpdate)) break;

            sscanf(linhaF, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d",
                temp.codigo, temp.titulo, temp.genero,
                temp.diretor, temp.ano, temp.classificacao,
                temp.dataHora, &temp.alugado);

            if (strcmp(temp.codigo, codFilme) == 0 &&
                strcmp(temp.titulo, titulo) == 0) {

                posInicio = pos;
                break;
            }
        }

        if (posInicio == -1) {
            fclose(arqUpdate);
            gotoxy(2, 23); printf("ERRO INTERNO: FILME SUMIU!");
            getch();
            continue;
        }

        // diminuir quantidade alugada
        filmes[indiceFilme].alugado--;

        // salvar filme atualizado no arquivo
        fseek(arqUpdate, posInicio, SEEK_SET);

        fprintf(arqUpdate, "%s,%s,%s,%s,%s,%s,%s,%d\n",
            filmes[indiceFilme].codigo,
            filmes[indiceFilme].titulo,
            filmes[indiceFilme].genero,
            filmes[indiceFilme].diretor,
            filmes[indiceFilme].ano,
            filmes[indiceFilme].classificacao,
            filmes[indiceFilme].dataHora,
            filmes[indiceFilme].alugado
        );

        fflush(arqUpdate);
        fclose(arqUpdate);

        gotoxy(2, 23); printf("                                       ");
        gotoxy(2, 23); printf("FILME DEVOLVIDO COM SUCESSO!");
        getch();


        // ===== PERGUNTAR NOVA DEVOLUÇÃO =====

        if (!perguntarNovaDevolucao()) {
            menu_movimentacao();
            return;
        }

    } // fim do while(1)
}
