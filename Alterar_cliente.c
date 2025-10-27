/*
  Autor...: José Luiz Delgado Tavares
  Data....: 25/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Incluir clientes
*/

#include "Funcoes.h"

void alterar_cliente() {
    //Inserir o código do cliente
    gotoxy(10,5);
    printf("Código: ");
    //Verifica se o código existe
    int cd = ler_int();
    int idx = buscar_cliente_index(cd);
    if(idx < 0) { 
        printf("Cliente não encontrado.\n"); 
        return; 
    }
    //Começa a alteração
    Cliente *c = &clientes[idx];
    //Mostra o nome
    gotoxy(10,6);
    printf("Nome atual: %s\n", c->nm_cliente);
    //Altera o nome
    gotoxy(10,7);
    printf("Novo nome (enter para manter): ");
    char buff[128]; 
    ler_string(buff, sizeof buff); 
    if(strlen(buff)) strncpy(c->nm_cliente, buff, sizeof c->nm_cliente);
    //Mostra o endereço
    gotoxy(10,8);
    printf("Endereco atual: %s\n", c->ds_endereco);
    //Altera o endereço
    gotoxy(10,9);
    printf("Novo endereco (enter para manter): "); 
    ler_string(buff, sizeof buff); 
    if(strlen(buff)) strncpy(c->ds_endereco, buff, sizeof c->ds_endereco);
    //Mostra o número do endereço
    gotoxy(10,10);
    printf("Número atual: %d\n", c->nr_numero);
    //Altera o número do endereço
    gotoxy(10,11);
    printf("Novo número (enter para manter): "); 
    ler_string(buff, sizeof buff); 
    if(strlen(buff)) c->nr_numero = atoi(buff);
    //Mostra o número do documento (CPF)
    gotoxy(10,12);
    printf("Documento atual: %s\n", c->nr_documento);
    //Altera o número do documento (CPF)
    gotoxy(10,13);
    printf("Novo documento (enter para manter): "); 
    ler_string(buff, sizeof buff); 
    if(strlen(buff)) strncpy(c->nr_documento, buff, sizeof c->nr_documento);
    //Mostra a cidade que o cliente mora 
    gotoxy(10,14);
    printf("Cidade atual: %s\n", c->ds_cidade);
    //Altera a cidade que o cliente mora
    gotoxy(10,15);
    printf("Nova cidade (enter para manter): "); 
    ler_string(buff, sizeof buff); 
    if(strlen(buff)) strncpy(c->ds_cidade, buff, sizeof c->ds_cidade);
    //Mostra a sigla do estado onde o cliente mora
    gotoxy(10,16);
    printf("UF atual: %s\n", c->cd_uf);
    //Altera a sigla do estado onde o cliente mora
    gotoxy(10,17);
    printf("Nova UF (enter para manter): "); 
    ler_string(buff, sizeof buff);
     if(strlen(buff)) strncpy(c->cd_uf, buff, sizeof c->cd_uf);
    //Mostra o número telefonico do cliente
    gotoxy(10,18);
    printf("Telefone atual: %s\n", c->nr_telefone);
    //Altera o número telefonico do cliente
    gotoxy(10,19);
    printf("Novo telefone (enter para manter): "); 
    ler_string(buff, sizeof buff); 
    if(strlen(buff)) strncpy(c->nr_telefone, buff, sizeof c->nr_telefone);
    //Mostra o status do cliente
    gotoxy(10,20);
    printf("Status atual: %d (0=Ativo,1=Desativado)\n", c->status);
    //Altera o status do cliente
    gotoxy(10,21);
    printf("Novo status (enter para manter): "); 
    ler_string(buff, sizeof buff); 
    if(strlen(buff)) c->status = atoi(buff);
    //Confirma as alterações
    gotoxy(6,23);
    printf("CONFIRMA ALTERAÇÃO (S/N)? "); 
    char opt[4]; 
    ler_string(opt, sizeof opt);
    if(opt[0]=='S' || opt[0]=='s') printf("Alteração concluída.\n"); 
    else printf("Alteração cancelada.\n");
}