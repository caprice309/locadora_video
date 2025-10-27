/*
Data....: 16/10/2025
Membros.: 268322-2025 - Enzo Gati Barbaresco
          292595-2025 - José Luiz Delgado Tavares
Objetivo: Deixar todos os arquivos salvos aqui
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

//Definindo o maximo
#define MAX_CLIENTES 1000

typedef struct {
    int cd_cliente;           //Chave primária
    char nm_cliente[51];      //Nome do cliente
    char ds_endereco[51];     //Endereço
    int nr_numero;            //Número do endereço
    char nr_documento[21];    //Número do documento (CPF: 123.456.789-00)
    char ds_cidade[51];       //Nome da cidade
    char cd_uf[6];            //Sigla do estado
    char dt_cadastro[20];     // DD/MM/YYYY HH:MM:SS
    char nr_telefone[16];     //Número de telefone
    int status;               // 0 = ativo, 1 = desativado
} Cliente;

static Cliente clientes[MAX_CLIENTES];
static int n_clientes = 0;

//Declarar as voids aqui e e comentar o que cada uma faz

//Definir a linha do cursor no eixo X e Y
void gotoxy(int x, int y);

//Mostrar a Tela
void tela();

//Inserir o menu principal
void menu();

//Menu para controlar os arquivos do cliente
void menu_cliente();

//Função para incluir clientes
void incluir_cliente();

//Função para alterar clientes
void alterar_cliente();

//Função para consultar clientes
void consulta_cliente();

//Função para excluir clientes
void excluir_cliente();

//Fim do arquivo .h
#endif

//MSG: Nós estamos muito fudidos