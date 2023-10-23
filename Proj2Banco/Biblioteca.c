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
