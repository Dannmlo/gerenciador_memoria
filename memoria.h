#ifndef MEMORIA_H
#define MEMORIA_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_BLOCOS 100

typedef struct {
    int id;
    void *endereco;
    size_t tamanho;
    int ocupado; // 1 para OCUPADO, 0 para LIVRE
} BlocoMemoria;

void inicializarGerenciador(BlocoMemoria vetor[], int *contadorId);
void alocarBloco(BlocoMemoria vetor[], int *totalRegistros, int *contadorId, size_t tamanho);
void liberarBloco(BlocoMemoria vetor[], int totalRegistros, int idBuscado);
void exibirEstadoMemoria(BlocoMemoria vetor[], int totalRegistros);
void exibirResumoMemoria(BlocoMemoria vetor[], int totalRegistros);
void encerrarPrograma(BlocoMemoria vetor[], int totalRegistros);

#endif