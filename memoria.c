#include "memoria.h"

void inicializarGerenciador(BlocoMemoria vetor[], int *contadorId) {
    *contadorId = 1;
    for (int i = 0; i < MAX_BLOCOS; i++) {
        vetor[i].id = 0;
        vetor[i].endereco = NULL;
        vetor[i].tamanho = 0;
        vetor[i].ocupado = 0;
    }
}

void alocarBloco(BlocoMemoria vetor[], int *totalRegistros, int *contadorId, size_t tamanho) {
    if (tamanho == 0) {
        printf("\nErro: O tamanho do bloco deve ser maior que zero.\n");
        return;
    }

    if (*totalRegistros >= MAX_BLOCOS) {
        printf("\nErro: Limite máximo de registros de blocos atingido.\n");
        return;
    }

    void *ptr = malloc(tamanho);
    if (ptr == NULL) {
        printf("\nErro: Falha na alocação dinâmica de memória.\n");
        return;
    }

    int indice = *totalRegistros;
    vetor[indice].id = (*contadorId)++;
    vetor[indice].endereco = ptr;
    vetor[indice].tamanho = tamanho;
    vetor[indice].ocupado = 1;

    (*totalRegistros)++;

    printf("\nBloco alocado com sucesso!\n");
    printf("Identificador: %d\n", vetor[indice].id);
    printf("Endereço: %p\n", vetor[indice].endereco);
    printf("Tamanho: %u bytes\n", (unsigned int)vetor[indice].tamanho);
    printf("Estado: OCUPADO\n");
}

void liberarBloco(BlocoMemoria vetor[], int totalRegistros, int idBuscado) {
    int encontrado = 0;

    for (int i = 0; i < totalRegistros; i++) {
        if (vetor[i].id == idBuscado) {
            encontrado = 1;
            if (vetor[i].ocupado == 0) {
                printf("\nErro: O bloco %d já foi liberado anteriormente.\n", idBuscado);
                return;
            }

            free(vetor[i].endereco);
            vetor[i].endereco = NULL;
            vetor[i].ocupado = 0;
            printf("\nBloco %d liberado com sucesso.\n", idBuscado);
            return;
        }
    }

    if (!encontrado) {
        printf("\nErro: Bloco com identificador %d não foi encontrado.\n", idBuscado);
    }
}

void exibirEstadoMemoria(BlocoMemoria vetor[], int totalRegistros) {
    if (totalRegistros == 0) {
        printf("\nNenhum bloco registrado na memória.\n");
        return;
    }

    printf("\n%-5s %-18s %-12s %-10s\n", "ID", "ENDEREÇO", "TAMANHO", "ESTADO");
    for (int i = 0; i < totalRegistros; i++) {
        if (vetor[i].ocupado) {
            printf("%-5d %-18p %-10u bytes  OCUPADO\n", vetor[i].id, vetor[i].endereco, (unsigned int)vetor[i].tamanho);
        } else {
            printf("%-5d %-18s %-10u bytes  LIVRE\n", vetor[i].id, "(liberado)", (unsigned int)vetor[i].tamanho);
        }
    }
}

void exibirResumoMemoria(BlocoMemoria vetor[], int totalRegistros) {
    int blocosOcupados = 0;
    int blocosLivres = 0;
    size_t totalBytes = 0;

    for (int i = 0; i < totalRegistros; i++) {
        if (vetor[i].ocupado) {
            blocosOcupados++;
            totalBytes += vetor[i].tamanho;
        } else {
            blocosLivres++;
        }
    }

    printf("\n--- Resumo da Memória ---\n");
    printf("Total de registros: %d\n", totalRegistros);
    printf("Blocos ocupados: %d\n", blocosOcupados);
    printf("Blocos livres: %d\n", blocosLivres);
    printf("Bytes atualmente alocados: %u\n", (unsigned int)totalBytes);
}

void encerrarPrograma(BlocoMemoria vetor[], int totalRegistros) {
    int liberados = 0;
    for (int i = 0; i < totalRegistros; i++) {
        if (vetor[i].ocupado) {
            free(vetor[i].endereco);
            vetor[i].endereco = NULL;
            vetor[i].ocupado = 0;
            liberados++;
        }
    }
    if (liberados > 0) {
        printf("\nLiberando blocos restantes...\n");
    }
    printf("Todos os recursos foram liberados.\n");
    printf("Programa encerrado.\n");
}