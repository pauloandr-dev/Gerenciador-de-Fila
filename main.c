#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

int main() {
    Fila* fila = criarFila();
    int opcao;

    while (1) {
        printf("\nSistema de Gerenciamento de Fila de Pacientes\n");
        printf("1. Adicionar paciente\n");
        printf("2. Chamar proximo paciente\n");
        printf("3. Exibir pacientes na fila\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarPaciente(fila);
                break;
            case 2:
                chamarProximoPaciente(fila);
                break;
            case 3:
                exibirFila(fila);
                break;
            case 4:
                liberarFila(fila);
                printf("Encerrando o sistema...\n");
                return 0;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }

    return 0;
}
