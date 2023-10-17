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
                    clientes[i].saldo -= valor * 1.05;
                    printf("Débito realizado com sucesso.\n");
                } else {
                    printf("Saldo insuficiente.\n");
                }
            } else if (strcmp(clientes[i].tipoConta, "plus") == 0) {
                if (valor <= clientes[i].saldo + 5000) {
                    clientes[i].saldo -= valor * 1.03;
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
