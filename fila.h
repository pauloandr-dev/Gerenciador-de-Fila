#ifndef FILA_H
#define FILA_H

typedef struct Paciente {
    char nome[50];
    struct Paciente* prox;
} Paciente;

typedef struct Fila {
    Paciente* inicio;
    Paciente* fim;
    int tamanho;
} Fila;

Fila* criarFila();
void adicionarPaciente(Fila* fila);
void chamarProximoPaciente(Fila* fila);
void exibirFila(Fila* fila);
void liberarFila(Fila* fila);

#endif
