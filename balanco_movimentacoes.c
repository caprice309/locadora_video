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
#include <time.h>

int linha_vazia(const char* s) {
    while (*s != '\0') {
        if (*s != ' ' && *s != '\n' && *s != '\r' && *s != '\t')
            return 0; // achou caractere então não está vazia
        s++;
    }
    return 1; // só tinha espaços/brancos então vazia :D
}

void extrairMesAno(const char* data, int* dia, int* mes, int* ano) {
    // data no formato:  dd/mm/yyyy hh:mm:ss
    sscanf(data, "%d/%d/%d", dia, mes, ano);
}

void balanco_movimentacoes() {

    system("color 0a");

    while (1) {
        system("cls");

        // ====== DATA ======
        time_t agora = time(NULL);
        struct tm* data = localtime(&agora);
        char dataFormatada[20];
        strftime(dataFormatada, sizeof(dataFormatada), "%d/%m/%Y", data);

        // ====== CABEÇALHO ======
        gotoxy(2, 2);  printf("ENZO GATI BARBARESCO");
        gotoxy(2, 3);  printf("JOSE LUIZ DELGADO TAVARES");
        gotoxy(61, 2); printf("ESTRUTURA DE DADOS");

        gotoxy(7, 7);
        printf("BALANCO DAS MOVIMENTACOES - %s", dataFormatada);

        // ====== CONTAR CLIENTES ======
        int totalClientes = 0;
        FILE* arqClientes = fopen("clientes.txt", "r");

        if (arqClientes != NULL) {
            char linha[600];
            while (fgets(linha, sizeof(linha), arqClientes)) {
                if (!linha_vazia(linha))   
                    totalClientes++;
            }
            fclose(arqClientes);
        }

        // ====== CONTAR FILMES ======
        int totalFilmes = 0;
        FILE* arqFilmes = fopen("filmes.txt", "r");

        if (arqFilmes != NULL) {
            char linha[600];
            while (fgets(linha, sizeof(linha), arqFilmes)) {
                if (!linha_vazia(linha))  
                    totalFilmes++;
            }
            fclose(arqFilmes);
        }

        // ====== MOSTRAR RESULTADOS ======
        gotoxy(7, 9);
        printf("Total de clientes....: %d", totalClientes);

        gotoxy(7, 10);
        printf("Total de filmes......: %d", totalFilmes);

        // ====== CONTAR LOCAÇÕES ======
        int totalLocacoesMes = 0;
        int loc24 = 0;
        int loc48 = 0;
        int totalLocacoes = 0;

        // ====== FILMES MAIS LOCADOS ======
        char codFilmes[2000][20];
        char tituloFilmes[2000][100];
        int contFilmes[2000];
        int totalFilmesDistintos = 0;

        // ====== MÉDIA + MLEHORES ======
        char clientes[2000][20];        // código do cliente
        char nomeClientes[2000][100];   // nome do cliente
        int locacoesCliente[2000];      // quantidade de locações
        int totalClientesDistintos = 0;


        // ====== MÉDIA DE ATRASO ======
        double somaAtrasos = 0;
        int qtdAtrasos = 0;

        FILE* arqHist = fopen("historico.txt", "r");

        if (arqHist != NULL) {
            char linha[600];

            int diaAtual = data->tm_mday;
            int mesAtual = data->tm_mon + 1;
            int anoAtual = data->tm_year + 1900;

            while (fgets(linha, sizeof(linha), arqHist)) {
                if (linha_vazia(linha)) continue;

                HistoricoLocacao h;
                char* token = strtok(linha, ",");

                if (!token) continue; strcpy(h.codigoFilme, token);
                token = strtok(NULL, ","); if (!token) continue; strcpy(h.tituloFilme, token);
                token = strtok(NULL, ","); if (!token) continue; h.vezesAlugadoFilme = atoi(token);
                token = strtok(NULL, ","); if (!token) continue; strcpy(h.codigoCliente, token);
                token = strtok(NULL, ","); if (!token) continue; strcpy(h.nomeCliente, token);
                token = strtok(NULL, ","); if (!token) continue; h.vezesAlugouCliente = atoi(token);
                token = strtok(NULL, ","); if (!token) continue; strcpy(h.dataAluguel, token);
                token = strtok(NULL, ","); if (!token) continue; strcpy(h.dataDevolucao, token);

                int d, m, a;
                extrairMesAno(h.dataAluguel, &d, &m, &a);

                // ====== CONTAGEM DOS FILMES ======
                int achouFilme = 0;
                for (int i = 0; i < totalFilmesDistintos; i++) {
                    if (strcmp(codFilmes[i], h.codigoFilme) == 0) {
                        contFilmes[i]++;
                        achouFilme = 1;
                        break;
                    }
                }
                if (!achouFilme) {
                    strcpy(codFilmes[totalFilmesDistintos], h.codigoFilme);
                    strcpy(tituloFilmes[totalFilmesDistintos], h.tituloFilme);
                    contFilmes[totalFilmesDistintos] = 1;
                    totalFilmesDistintos++;
                }

                // TOTAL GERAL
                totalLocacoes++;

                // ====== CONTAGEM DOS CLIENTES ======
                int achouCliente = 0;

                for (int i = 0; i < totalClientesDistintos; i++) {
                    if (strcmp(clientes[i], h.codigoCliente) == 0) {
                        locacoesCliente[i]++;
                        achouCliente = 1;
                        break;
                    }
                }

                if (!achouCliente) {
                    strcpy(clientes[totalClientesDistintos], h.codigoCliente);
                    strcpy(nomeClientes[totalClientesDistintos], h.nomeCliente);
                    locacoesCliente[totalClientesDistintos] = 1;
                    totalClientesDistintos++;
                }

                // ====== MÉDIA DE ATRASO ======
                struct tm al = { 0 }, dev = { 0 };
                int dia, mes, ano;

                sscanf(h.dataAluguel, "%d/%d/%d", &dia, &mes, &ano);
                al.tm_mday = dia; al.tm_mon = mes - 1; al.tm_year = ano - 1900;

                sscanf(h.dataDevolucao, "%d/%d/%d", &dia, &mes, &ano);
                dev.tm_mday = dia; dev.tm_mon = mes - 1; dev.tm_year = ano - 1900;

                time_t t1 = mktime(&al);
                time_t t2 = mktime(&dev);

                int diff = difftime(t2, t1) / 86400; // dias
                int atraso = diff - 2;               // 2 dias = prazo

                if (atraso > 0) {
                    somaAtrasos += atraso;
                    qtdAtrasos++;
                }

                // ====== LOC 24H ======
                if (d == diaAtual && m == mesAtual && a == anoAtual)
                    loc24++;

                // ====== LOC 48H ======
                if ((d == diaAtual - 1 || d == diaAtual - 2) &&
                    m == mesAtual && a == anoAtual)
                    loc48++;

                // ====== LOCAÇÕES DO MÊS ======
                if (m == mesAtual && a == anoAtual)
                    totalLocacoesMes++;
            }

            fclose(arqHist);
        }

        // ====== ORDENAR TOP 3 FILMES MAIS LOCADOS ======
        for (int i = 0; i < totalFilmesDistintos - 1; i++) {
            for (int j = i + 1; j < totalFilmesDistintos; j++) {
                if (contFilmes[j] > contFilmes[i]) {

                    int tempCount = contFilmes[i];
                    contFilmes[i] = contFilmes[j];
                    contFilmes[j] = tempCount;

                    char tempCod[20];
                    strcpy(tempCod, codFilmes[i]);
                    strcpy(codFilmes[i], codFilmes[j]);
                    strcpy(codFilmes[j], tempCod);

                    char tempTitulo[100];
                    strcpy(tempTitulo, tituloFilmes[i]);
                    strcpy(tituloFilmes[i], tituloFilmes[j]);
                    strcpy(tituloFilmes[j], tempTitulo);
                }
            }
        }

        // ====== ORDENAR TPO 3 CLIENTES ======
        for (int i = 0; i < totalClientesDistintos - 1; i++) {
            for (int j = i + 1; j < totalClientesDistintos; j++) {
                if (locacoesCliente[j] > locacoesCliente[i]) {

                    int tempCount = locacoesCliente[i];
                    locacoesCliente[i] = locacoesCliente[j];
                    locacoesCliente[j] = tempCount;

                    char tempCod[20];
                    strcpy(tempCod, clientes[i]);
                    strcpy(clientes[i], clientes[j]);
                    strcpy(clientes[j], tempCod);

                    char tempNome[100];
                    strcpy(tempNome, nomeClientes[i]);
                    strcpy(nomeClientes[i], nomeClientes[j]);
                    strcpy(nomeClientes[j], tempNome);
                }
            }
        }

        // ====== CÁLCULOS FINAIS ======
        double mediaLocUsuario = 0;
        if (totalClientesDistintos > 0)
            mediaLocUsuario = (double)totalLocacoes / totalClientesDistintos;

        double mediaAtraso = 0;
        if (qtdAtrasos > 0)
            mediaAtraso = somaAtrasos / qtdAtrasos;

        gotoxy(7, 12); printf("Total de locacoes mes: %d", totalLocacoesMes);
        gotoxy(7, 13); printf("24 horas: %d", loc24);
        gotoxy(7, 14); printf("48 horas: %d", loc48);
        gotoxy(7, 15); printf("Total: %d", totalLocacoes);

        gotoxy(7, 19); printf("Media locacao por usuario: %.2f", mediaLocUsuario);
        gotoxy(7, 20); printf("Media tempo de atraso: %.2f dias", mediaAtraso);

        gotoxy(40, 9);
        printf("Filmes mais locados:");

        if (totalFilmesDistintos > 0) {
            gotoxy(40, 10);
            printf("1) %s (%d)", tituloFilmes[0], contFilmes[0]);
        }
        else {
            gotoxy(40, 10);
            printf("1) N/A");
        }

        if (totalFilmesDistintos > 1) {
            gotoxy(40, 11);
            printf("2) %s (%d)", tituloFilmes[1], contFilmes[1]);
        }
        else {
            gotoxy(40, 11);
            printf("2) N/A");
        }

        if (totalFilmesDistintos > 2) {
            gotoxy(40, 12);
            printf("3) %s (%d)", tituloFilmes[2], contFilmes[2]);
        }
        else {
            gotoxy(40, 12);
            printf("3) N/A");
        }

        gotoxy(40, 14);
        printf("Melhores clientes:");

        if (totalClientesDistintos > 0) {
            gotoxy(40, 15);
            printf("1) %s (%d)", nomeClientes[0], locacoesCliente[0]);
        }
        else {
            gotoxy(40, 15); printf("1) N/A");
        }

        if (totalClientesDistintos > 1) {
            gotoxy(40, 16);
            printf("2) %s (%d)", nomeClientes[1], locacoesCliente[1]);
        }
        else {
            gotoxy(40, 16); printf("2) N/A");
        }

        if (totalClientesDistintos > 2) {
            gotoxy(40, 17);
            printf("3) %s (%d)", nomeClientes[2], locacoesCliente[2]);
        }
        else {
            gotoxy(40, 17); printf("3) N/A");
        }

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

        gotoxy(2, 23);
        printf("ESC = voltar pagina");

        int tecla = getch();
        if (tecla == 27) {   // ESC
            menu_relatorios();
            return;
        }
    }
}


