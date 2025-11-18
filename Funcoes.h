/*
  Autor...: Enzo Gati Barbaresco
  Data....: 16/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Mostrar a tela
*/


//Começo do arquivo .h
#ifndef FUNCOES_H
#define FUNCOES_H

//Bibliotecas utilizadas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>

#define MAX_CLIENTES 1000
#define MAX_FILMES 1000
#define MAX_TIPOS 1000
#define MAX_HISTORICO 5000

//Estrutura clientes
typedef struct {
    char confirma, nova;
    char codigo[10];
    char nome[100];
    char endereco[200];
    char cpf[11];
    char cidade[100];
    char uf[3];
    char dataHora[20];

    int filmesAlugados;
} Cliente;

//Estrutura filmes
typedef struct {
    char codigo[10];
    char titulo[100];
    char genero[50];
    char diretor[100];
    char ano[5];
    char classificacao[10];
    char dataHora[20];

    int alugado;
} Filme;

//Estrutura Tipos
typedef struct {
    char codigo[10];
    char tipo[50];
    char descricao[200];
    char relevancia[10];
    char dataHora[20];
} TipoFilme;

// Estrutura histórico de locações
typedef struct {
    // Dados do filme
    char codigoFilme[10];
    char tituloFilme[100];
    int vezesAlugadoFilme;

    // Dados do cliente
    char codigoCliente[10];
    char nomeCliente[100];
    int vezesAlugouCliente;

    // Datas
    char dataAluguel[20];
    char dataDevolucao[20];

} HistoricoLocacao;


//Máximo etc etc
static Cliente clientes[MAX_CLIENTES];
static int n_clientes = 0;

static Filme filmes[MAX_FILMES];
static int n_filmes = 0;

static TipoFilme tipos[MAX_TIPOS];
static int n_tipos = 0;

static HistoricoLocacao historico[MAX_HISTORICO];
static int n_historico = 0;

//Declarar as voids aqui e e comentar o que cada uma faz

//Definir a linha do cursor no eixo X e Y
void gotoxy(int x, int y);

//Limpar buffer do teclado
void limparBuffer();

// Função para salvar um cliente no arquivo
void salvar_cliente(Cliente c);

// Função para salvar um filme no arquivo
void salvar_filmes(Filme f);

// Função para salvar um tipo
void salvar_tipo(TipoFilme t);

// Função para detectar linhas vazias no TXT onde os dados tão salvos e ignorar elas
int linha_vazia(const char* s);

//Usado para evitar um erro estranho de recursão que é bem meh pra falar a real
void menu_movimentacao();
int perguntarNovaDevolucao();
int perguntarNovoEmprestimo();

//Fim do arquivo .h
#endif

