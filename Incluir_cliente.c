/*
  Autor...: José Luiz Delgado Tavares
  Data....: 25/10/2025
  Membros.: 268322-2024 : Enzo Gati Barbaresco
            292595-2025 : Jose Luiz Delgado Tavares
  Objetivo: Incluir clientes
*/

#include "Funcoes.h"

void incluir_cliente() {
    //Verifica se o número de cliente é maior ou igual o maximo de cliente posivel (1000)
    if(n_clientes >= MAX_CLIENTES) { 
        printf("Limite de clientes atingido.\n");
        return;
    }

    //Começo da inclusão dos clientes
    Cliente c;
    //Código gerado automaticamente
    c.cd_cliente = gerar_id_cliente();
    gotoxy(10,7);
    printf("Codigo do cliente: %d\n", c.cd_cliente);
    //Inserir o nome do cliente (Rodney Carneiro)
    gotoxy(10,9);
    printf("Nome completo do cliente: ");
    ler_string(c.nm_cliente, sizeof c.nm_cliente);
    //Inserir o endereço do cliente (Avenida das flores)
    gotoxy(10,11);
    printf("Endereco do cliente: ");
    ler_string(c.ds_endereco, sizeof c.ds_endereco);
    //Inserir o número do endereço do cliente (1749)
    gotoxy(10,13);
    printf("Numero do endereco: ");
    c.nr_numero = ler_int();
    //Inserir o documento CPF do cliente (123.456.789-00)
    gotoxy(10,15);
    printf("Numero do documento (CPF): ");
    ler_string(c.nr_documento, sizeof c.nr_documento);
    //Inserir o nome da cidade do cliente (Maringá)
    gotoxy(10,17);
    printf("Cidade: ");
    ler_string(c.ds_cidade, sizeof c.ds_cidade);
    //Inserir a sigla do estado do cliente (PR)
    gotoxy(10,19);
    printf("Unidade Federativa (UF): ");
    ler_string(c.cd_uf, sizeof c.cd_uf);
    agora_str(c.dt_cadastro, sizeof c.dt_cadastro);
    //Inserir o número do telefone do cliente ((44) 91234-5678)
    gotoxy(10,21);
    printf("Telefone: ");
    ler_string(c.nr_telefone, sizeof c.nr_telefone);
    //Status base como ativado
    c.status = 0;
    //Confirmar os dados do cliente
    gotoxy(6,23);
    printf("CONFIRMA INCLUSÃO (S/N)? ");
    char opt[4]; ler_string(opt, sizeof opt);
    if(opt[0]=='S' || opt[0]=='s') {
        clientes[n_clientes++] = c;
        printf("Cliente incluido com sucesso.\n");
    } else printf("Inclusão cancelada.\n");
}