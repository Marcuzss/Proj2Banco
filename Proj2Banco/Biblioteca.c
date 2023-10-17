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
            fprintf(arquivo, "--------------------\n");

            fclose(arquivo);
            printf("Extrato salvo com sucesso.\n");
            return;
        }
    }

    printf("CPF ou senha incorretos.\n");
}
