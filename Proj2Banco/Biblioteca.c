#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Biblioteca.h"

void transferencia(Cliente *clientes, int numClientes) {
    char cpfOrigem[12], senhaOrigem[20], cpfDestino[12];
    double valor;

    printf("Digite o CPF da conta de origem: ");
    scanf(" %[^\n]", cpfOrigem);
    printf("Digite a senha da conta de origem: ");
    scanf(" %[^\n]", senhaOrigem);
    printf("Digite o CPF da conta de destino: ");
    scanf(" %[^\n]", cpfDestino);
    printf("Digite o valor: ");
    scanf("%lf", &valor);

    int i, indexOrigem = -1, indexDestino = -1;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpfOrigem) == 0 && strcmp(clientes[i].senha, senhaOrigem) == 0) {
            indexOrigem = i;
        }
        if (strcmp(clientes[i].cpf, cpfDestino) == 0) {
            indexDestino = i;
        }
    }

    if (indexOrigem != -1 && indexDestino != -1) {
        if (clientes[indexOrigem].saldo >= valor) {
            clientes[indexOrigem].saldo -= valor;
            clientes[indexDestino].saldo += valor;
            printf("Transferência realizada com sucesso.\n");
        } else {
            printf("Saldo insuficiente na conta de origem.\n");
        }
    } else {
        printf("CPF ou senha da conta de origem ou CPF da conta de destino incorretos.\n");
    }
}

//Esta função recebe o CPF do destinatário e remetente e recebe o valor desejado a ser tranferido para a outra conta, e caso o CPF
//esteja errado ou não tenha o valor na conta para fazer a tranferência exibe a mensagem de erro.

void deposito(Cliente *clientes, int numClientes) {
    char cpf[12];
    double valor;

    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);
    printf("Digite o valor: ");
    scanf("%lf", &valor);

    int i;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            clientes[i].saldo += valor;
            
            strcpy(clientes[i].operacoes[clientes[i].numOperacoes].tipo, "Depósito");
            clientes[i].operacoes[clientes[i].numOperacoes].valor = valor;
            clientes[i].operacoes[clientes[i].numOperacoes].tarifa = 0.0;
            clientes[i].operacoes[clientes[i].numOperacoes].saldoApos = clientes[i].saldo;
            clientes[i].numOperacoes++;
            printf("Depósito realizado com sucesso.\n");
            return;
        }
    }

    printf("CPF não encontrado.\n");
}

//Esta função recebe o CPF do cliente desejado para realizar o depósito, e seu valor de depósito desejado.

void listarClientes(Cliente *clientes, int numClientes) {
    int i;
    for (i = 0; i < numClientes; i++) {
        printf("Nome: %s\n", clientes[i].nome);
        printf("CPF: %s\n", clientes[i].cpf);
        printf("Tipo de conta: %s\n", clientes[i].tipoConta);
        printf("Saldo: %.2lf\n", clientes[i].saldo);
        printf("---------------\n");
    }
}
// A função tem a finalidade de exibir as informações de todos os clientes cadastrados no sistema.

void apagaCliente(Cliente *clientes, int *numClientes) {
    char cpf[12];
    printf("Digite o CPF do cliente a ser apagado: ");
    scanf(" %[^\n]", cpf);

    int i;
    for (i = 0; i < *numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0) {
            int j;
            for (j = i; j < *numClientes - 1; j++) {
                clientes[j] = clientes[j + 1];
            }
            (*numClientes)--;
            printf("Cliente apagado com sucesso.\n");
            return;
        }
    }


    printf("CPF não encontrado.\n");
}
//Esta função remove um cliente com base no CPF fornecido pelo usuário. 
//A função procura pelo array do CPF, encontra  e remove o cliente e atualiza a lista de clientes

void debito(Cliente *clientes, int numClientes) {
    char cpf[12], senha[20];
    double valor;

    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);
    printf("Digite a senha: ");
    scanf(" %[^\n]", senha);
    printf("Digite o valor: ");
    scanf("%lf", &valor);

    int i;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            if (strcmp(clientes[i].tipoConta, "comum") == 0) {
                if (valor <= clientes[i].saldo + 1000) {
                    double tarifa = valor * 0.05;
                    clientes[i].saldo -= (valor + tarifa);
                    
                    strcpy(clientes[i].operacoes[clientes[i].numOperacoes].tipo, "Débito");
                    clientes[i].operacoes[clientes[i].numOperacoes].valor = valor;
                    clientes[i].operacoes[clientes[i].numOperacoes].tarifa = tarifa;
                    clientes[i].operacoes[clientes[i].numOperacoes].saldoApos = clientes[i].saldo;
                    clientes[i].numOperacoes++;
                      printf("Débito realizado com sucesso.\n");
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else if (strcmp(clientes[i].tipoConta, "plus") == 0) {
                if (valor <= clientes[i].saldo + 5000) {
                    double tarifa = valor * 0.03;
                    clientes[i].saldo -= (valor + tarifa);
                    
                    strcpy(clientes[i].operacoes[clientes[i].numOperacoes].tipo, "Débito");
                    clientes[i].operacoes[clientes[i].numOperacoes].valor = valor;
                    clientes[i].operacoes[clientes[i].numOperacoes].tarifa = tarifa;
                    clientes[i].operacoes[clientes[i].numOperacoes].saldoApos = clientes[i].saldo;
                    clientes[i].numOperacoes++;
                      printf("Débito realizado com sucesso.\n");
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else {
                printf("Tipo de conta inválido.\n");
            }
            return;
        }
    }

    printf("CPF ou senha incorretos.\n");
}

// Tem o objetivo de permitir que os clientes realizem retiradas de dinheiro (débitos) de suas contas, diferenciando os tipos de contas
//e dependendo do tipo a função desconta um valor respectivo a sua variante de conta.
   
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

void extrato(Cliente *clientes, int numClientes) {
    char cpf[12], senha[20];
    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf);
    printf("Digite a senha: ");
    scanf(" %[^\n]", senha);

    int i;
    for (i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].cpf, cpf) == 0 && strcmp(clientes[i].senha, senha) == 0) {
            char nomeArquivo[100];
            printf("Digite o nome do arquivo para salvar o extrato: ");
            scanf(" %[^\n]", nomeArquivo);

            FILE *arquivo = fopen(nomeArquivo, "w");
            if (arquivo == NULL) {
                printf("Erro ao abrir o arquivo.\n");
                return;
            }

            fprintf(arquivo, "Extrato do cliente: %s\n", clientes[i].nome);
              for (int j = 0; j < clientes[i].numOperacoes; j++) {
                fprintf(arquivo, "Operação %d\n", j + 1);
                fprintf(arquivo, "Tipo: %s\n", clientes[i].operacoes[j].tipo);
                fprintf(arquivo, "Valor: %.2lf\n", clientes[i].operacoes[j].valor);
                fprintf(arquivo, "Tarifa: %.2lf\n", clientes[i].operacoes[j].tarifa);
                fprintf(arquivo, "Saldo após operação: %.2lf\n", clientes[i].operacoes[j].saldoApos);
                
            }

            fclose(arquivo);
            printf("Extrato salvo com sucesso.\n");
            return;
        }
    }

    printf("CPF ou senha incorretos.\n");
}
// Valida CPF e senha, salva extrato.

