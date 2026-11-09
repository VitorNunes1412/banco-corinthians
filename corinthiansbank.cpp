#include <stdio.h>

int main() {
    int senha, tentativa, opcao;
    float saldo = 500.00;
    float valor, maiorDeposito = 0;

    // Criacao da senha
    do {
        printf("Crie uma senha de 4 digitos: ");
        scanf("%d", &senha);

        if (senha < 1000 || senha > 9999) {
            printf("A senha deve ter 4 digitos!\n");
        }
    } while (senha < 1000 || senha > 9999);

    // Menu principal
    do {
        printf("\n===== BANCO =====\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Consultar saldo e estatisticas\n");
        printf("4 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {

            case 1:
                printf("Valor do deposito: R$ ");
                scanf("%f", &valor);

                if (valor <= 0) {
                    printf("Valor inválido!\n");
                } else {
                    saldo += valor;

                    if (valor > maiorDeposito) {
                        maiorDeposito = valor;
                    }

                    printf("Deposito realizado!\n");
                }
                break;

            case 2:
                printf("Digite sua senha: ");
                scanf("%d", &tentativa);

                if (tentativa != senha) {
                    printf("Senha Incorreta. Operação cancelada.\n");
                } else {
                    printf("Valor do saque: R$ ");
                    scanf("%f", &valor);

                    if (valor <= 0) {
                        printf("Valor inválido!\n");
                    } else if (valor > saldo) {
                        printf("Saldo Insuficiente!\n");
                    } else {
                        saldo -= valor;
                        printf("Saque realizado!\n");
                    }
                }
                break;

            case 3:
                printf("\nSaldo atual: R$ %.2f\n", saldo);
                printf("Maior deposito: R$ %.2f\n", maiorDeposito);
                break;

            case 4:
                printf("Obrigado por usar nosso banco!\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 4);

    return 0;
}

