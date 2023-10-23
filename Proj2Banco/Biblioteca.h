#ifndef CABECALHO_H
#define CABECALHO_H
typedef struct {
    char nome[100];
    char cpf[12];
    char tipoConta[10];
    double saldo;
    char senha[20];

struct Operacao {
    char tipo[20];
    double valor;
     double tarifa;
    double saldoApos;
    } operacoes[100];
    int numOperacoes; 
} Cliente;

void novoCliente(Cliente *clientes, int *numClientes);
void apagaCliente(Cliente *clientes, int *numClientes);
void listarClientes(Cliente *clientes, int numClientes);
void debito(Cliente *clientes, int numClientes);
void deposito(Cliente *clientes, int numClientes);
void extrato(Cliente *clientes, int numClientes);
void transferencia(Cliente *clientes, int numClientes);

#endif

//A biblioteca "CABECALHO_H" contém a definição de uma struct chamada "Cliente" e uma série de funções relacionada de controle de clientes
//e suas contas. Essas funções permitem adicionar um novo cliente, remover um cliente, listar todos os clientes, etc.
