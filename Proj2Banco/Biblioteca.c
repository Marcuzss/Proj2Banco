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

