/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: ver disponibilidade e lista de filmes da locadora
*/

#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)
#endif

#include "Funcoes.h"
#include <time.h>

void balanco_acervo() {

    system("color 0a");

    // ====== CARREGAR TODOS OS FILMES PARA MEM�RIA ======
    FILE* arq = fopen("filmes.txt", "r");
    if (!arq) {
        gotoxy(7, 12);
        printf("ERRO AO ABRIR filmes.txt");
        getch();
        return;
    }

    Filme lista[500];
    int total = 0;
    char linha[512];

    while (fgets(linha, sizeof(linha), arq)) {

        // Ignorar linhas vazias
        int vazio = 1;
        for (int i = 0; linha[i] != '\0'; i++) {
            if (linha[i] != ' ' && linha[i] != '\t' && linha[i] != '\n' && linha[i] != '\r') {
                vazio = 0;
                break;
            }
        }
        if (vazio) continue;

        Filme f;
        sscanf(linha, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%d",
            f.codigo, f.titulo, f.genero, f.diretor,
            f.ano, f.classificacao, f.dataHora, &f.alugado);

        lista[total++] = f;
    }
    fclose(arq);

    if (total == 0) {
        gotoxy(7, 12);
        printf("Nenhum filme cadastrado!");
        getch();
        return;
    }

    // ====== CONFIG PAGINACAO ======
    int pagina = 0;
    int porPagina = 6;
    int totalPaginas = (total - 1) / porPagina;

    while (1) {
        system("cls");

        // ====== DATA ======
        time_t agora = time(NULL);
        struct tm* data = localtime(&agora);
        char dataFormatada[20];
        strftime(dataFormatada, sizeof(dataFormatada), "%d/%m/%Y", data);

        // ====== CABE�ALHO ======
        gotoxy(2, 2);  printf("ENZO GATI BARBARESCO");
        gotoxy(2, 3);  printf("JOSE LUIZ DELGADO TAVARES");
        gotoxy(61, 2); printf("ESTRUTURA DE DADOS");

        gotoxy(7, 7);
        printf("BALANCO DO ACERVO - %s", dataFormatada);

        gotoxy(7, 9);  printf("Cod.");
        gotoxy(14, 9); printf("Titulo");
        gotoxy(35, 9); printf("Disp.");
        gotoxy(45, 9); printf("qntd.");

        // ====== MOLDURA ======
        for (int i = 1; i <= 24; i++) {
            gotoxy(1, i);  printf("|");
            gotoxy(80, i); printf("|");
        }
        for (int j = 1; j <= 80; j++) {
            gotoxy(j, 1);  printf("-");
            gotoxy(j, 4);  printf("-");
            gotoxy(j, 22); printf("-");
            gotoxy(j, 24); printf("-");
        }
        gotoxy(1, 1);  printf("+");  gotoxy(80, 1); printf("+");
        gotoxy(1, 4);  printf("+");  gotoxy(80, 4); printf("+");
        gotoxy(1, 22); printf("+");  gotoxy(80, 22); printf("+");
        gotoxy(1, 24); printf("+");  gotoxy(80, 24); printf("+");

        // EXIBIR FILMES DA P�GINA 
        int inicio = pagina * porPagina;
        int fim = inicio + porPagina;
        if (fim > total) fim = total;

        int posY = 11;
        for (int i = inicio; i < fim; i++) {
            int qntdTotal = atoi(lista[i].genero);
            int disp = qntdTotal - lista[i].alugado;

            gotoxy(7, posY);  printf("%s", lista[i].codigo);
            gotoxy(14, posY); printf("%s", lista[i].titulo);
            gotoxy(35, posY); printf("%d", disp);
            gotoxy(45, posY); printf("%d", qntdTotal);

            posY++;
        }

        // ====== CONTROLE DE P�GINAS ======
        gotoxy(7, 21);
        printf("Pagina %d de %d", pagina + 1, totalPaginas + 1);

        gotoxy(2, 23);
        printf("ESC = voltar pagina | DIR = proxima pagina | ESC = voltar ao menu");

        // ====== TECLA ======
        int tecla = getch();

        if (tecla == 27) { // ESC
            return;
        }

        if (tecla == 0 || tecla == 224) {
            tecla = getch();

            if (tecla == 77) { // seta direita
                if (pagina < totalPaginas)
                    pagina++;
                else
                    pagina = 0; // voltou para a 1� p�gina
            }
            else if (tecla == 75) { // seta esquerda
                if (pagina > 0)
                    pagina--;
                else
                    pagina = totalPaginas; // foi para a �ltima p�gina
            }
        }

    }
}


