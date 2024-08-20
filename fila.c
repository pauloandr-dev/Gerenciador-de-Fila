#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

Fila* criarFila() {
    Fila* fila = (Fila*)malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
    return fila;
}

void adicionarPaciente(Fila* fila) {
    Paciente* novoPaciente = (Paciente*)malloc(sizeof(Paciente));

    printf("Digite o nome do paciente: ");
    scanf(" %[^\n]", novoPaciente->nome);
    novoPaciente->prox = NULL;

    if (fila->fim == NULL) {
        fila->inicio = novoPaciente;
        fila->fim = novoPaciente;
    } else {
        fila->fim->prox = novoPaciente;
        fila->fim = novoPaciente;
    }

    fila->tamanho++;
    printf("Paciente %s adicionado a fila.\n", novoPaciente->nome);
}

void chamarProximoPaciente(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("A fila esta vazia! Nenhum paciente para chamar.\n");
        return;
    }

    Paciente* pacienteRemovido = fila->inicio;
    printf("Chamando paciente: %s\n", pacienteRemovido->nome);

    fila->inicio = fila->inicio->prox;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(pacienteRemovido);
    fila->tamanho--;
}

void exibirFila(Fila* fila) {
    if (fila->inicio == NULL) {
        printf("A fila está vazia.\n");
        return;
    }

    Paciente* atual = fila->inicio;
    printf("Pacientes na fila:\n");
    while (atual != NULL) {
        printf("%s\n", atual->nome);
        atual = atual->prox;
    }
}

void liberarFila(Fila* fila) {
    Paciente* atual = fila->inicio;
    while (atual != NULL) {
        Paciente* proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(fila);
}
