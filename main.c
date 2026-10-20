#include <stdio.h>
#include "memoria.h"

int main() {
    BlocoMemoria blocos[MAX_BLOCOS];
    int totalRegistros = 0;
    int contadorId = 1;
    int opcao;

    inicializarGerenciador(blocos, &contadorId);

    do {
        printf("\n========== GERENCIADOR DE MEMÓRIA ==========\n");
        printf("1 - Alocar bloco de memória\n");
        printf("2 - Liberar bloco de memória\n");
        printf("3 - Exibir estado da memória\n");
        printf("4 - Exibir resumo da memória\n");
        printf("0 - Encerrar o programa\n");
        printf("Escolha uma opção: ");
        
        if (scanf("%d", &opcao) != 1) {
            printf("\nEntrada inválida. Por favor, digite um número.\n");
            while (getchar() != '\n'); // Limpa o buffer do teclado
            continue;
        }

        switch (opcao) {
            case 1: {
                size_t tamanho;
                printf("Informe o tamanho do bloco em bytes: ");
                if (scanf("%zu", &tamanho) != 1) {
                    printf("\nValor inválido.\n");
                    while (getchar() != '\n');
                    break;
                }
                alocarBloco(blocos, &totalRegistros, &contadorId, tamanho);
                break;
            }
            case 2: {
                int id;
                printf("Informe o identificador do bloco: ");
                if (scanf("%d", &id) != 1) {
                    printf("\nIdentificador inválido.\n");
                    while (getchar() != '\n');
                    break;
                }
                liberarBloco(blocos, totalRegistros, id);
                break;
            }
            case 3:
                exibirEstadoMemoria(blocos, totalRegistros);
                break;
            case 4:
                exibirResumoMemoria(blocos, totalRegistros);
                break;
            case 0:
                encerrarPrograma(blocos, totalRegistros);
                break;
            default:
                printf("\nOpção inválida! Escolha uma opção entre 0 e 4.\n");
        }
    } while (opcao != 0);

    return 0;
}