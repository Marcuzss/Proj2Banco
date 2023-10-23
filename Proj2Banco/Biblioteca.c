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
