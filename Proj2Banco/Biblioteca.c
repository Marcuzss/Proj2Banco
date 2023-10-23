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
