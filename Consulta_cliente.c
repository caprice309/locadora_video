/*
  Autor...: José Luiz Delgado Tavares
  Data....: 26/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Consultar clientes
*/

#include "Funcoes.h"

void consulta_cliente() {
    gotoxy(6, 23);
    printf("Digite um codigo: "); 
    int cd = ler_int();
    int idx = buscar_cliente_index(cd);
    if(idx < 0) { 
        gotoxy(6,23);
        printf("Cliente nao encontrado.\n"); 
        return; 
    }
    Cliente *c = &clientes[idx];
    gotoxy(10,5);
    printf("Código: %d", c->cd_cliente);
    gotoxy(10,7);
    printf("Nome: %s", c->nm_cliente);
    gotoxy(10,9);
    printf("Endereco: %s, %d", c->ds_endereco, c->nr_numero);
    gotoxy(10,11);
    printf("Documento: %s", c->nr_documento);
    gotoxy(10,13);
    printf("Cidade: %s", c->ds_cidade);
    gotoxy(10,15);
    printf("UF: %s", c->cd_uf);
    gotoxy(10,17);
    printf("Cadastro: %s", c->dt_cadastro);
    gotoxy(10,19);
    printf("Telefone: %s", c->nr_telefone);
    gotoxy(10,21);
    printf("Status: %d", c->status);
}