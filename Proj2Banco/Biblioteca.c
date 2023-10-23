#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

void novoCliente(Cliente *clientes, int *numClientes) {
    if (*numClientes == 1000) {
        printf("Número máximo de clientes atingido.\n");
        return;
    }

    Cliente cliente;
    printf("Digite o nome do cliente: ");
    scanf(" %[^\n]", cliente.nome);
    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cliente.cpf);
    printf("Digite o tipo de conta (comum ou plus): ");
    scanf(" %[^\n]", cliente.tipoConta);
    printf("Digite o valor inicial da conta: ");
    scanf("%lf", &cliente.saldo);
    printf("Digite a senha do cliente: ");
    scanf(" %[^\n]", cliente.senha);

    clientes[*numClientes] = cliente;
    (*numClientes)++;

    printf("Novo cliente cadastrado com sucesso.\n");
}

//A função `novoCliente` recebe dois parâmetros: - `Cliente *clientes`: Um ponteiro para uma matriz de estruturas do tipo `Cliente`,
//que contém informações sobre os clientes, como nome, CPF, saldo , tipo de conta e senha.
