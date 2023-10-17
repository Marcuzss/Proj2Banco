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
