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
