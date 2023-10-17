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
            printf("Depósito realizado com sucesso.\n");
            return;
        }
    }

    printf("CPF não encontrado.\n");
}

