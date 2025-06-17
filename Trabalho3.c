#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAMANHO_VETOR 100
#define MAX_VALOR 9999

// Protótipos
int* gerar_vetor(int tamanho);
void imprimir_vetor(int *vetor, int tamanho, int mostrar_limite);
void copiar_vetor(int *origem, int *destino, int tamanho);
void bubble_sort(int *vetor, int tamanho, int crescente);
void selection_sort(int *vetor, int tamanho, int crescente);

int main() {
    srand(time(NULL));

    // 1. Gerar vetor dinamicamente
    int *vetor_original = gerar_vetor(TAMANHO_VETOR);

    // 2. Criar cópias para cada ordenação
    int *vetor_bubble = malloc(TAMANHO_VETOR * sizeof(int));
    int *vetor_selection = malloc(TAMANHO_VETOR * sizeof(int));
    if (!vetor_bubble || !vetor_selection) {
        printf("Erro na alocação de memória.\n");
        free(vetor_original);
        return 1;
    }

    // Imprimir vetor original (exibir 20 primeiros e 20 últimos)
    printf("Vetor Original (20 primeiros e 20 últimos elementos):\n");
    imprimir_vetor(vetor_original, TAMANHO_VETOR, 20);
    printf("\n");

    // Bubble Sort crescente
    copiar_vetor(vetor_original, vetor_bubble, TAMANHO_VETOR);
    bubble_sort(vetor_bubble, TAMANHO_VETOR, 1);
    printf("Bubble Sort - Ordem Crescente:\n");
    imprimir_vetor(vetor_bubble, TAMANHO_VETOR, 20);
    printf("\n");

    // Bubble Sort decrescente
    copiar_vetor(vetor_original, vetor_bubble, TAMANHO_VETOR);
    bubble_sort(vetor_bubble, TAMANHO_VETOR, 0);
    printf("Bubble Sort - Ordem Decrescente:\n");
    imprimir_vetor(vetor_bubble, TAMANHO_VETOR, 20);
    printf("\n");

    // Selection Sort crescente
    copiar_vetor(vetor_original, vetor_selection, TAMANHO_VETOR);
    selection_sort(vetor_selection, TAMANHO_VETOR, 1);
    printf("Selection Sort - Ordem Crescente:\n");
    imprimir_vetor(vetor_selection, TAMANHO_VETOR, 20);
    printf("\n");

    // Selection Sort decrescente
    copiar_vetor(vetor_original, vetor_selection, TAMANHO_VETOR);
    selection_sort(vetor_selection, TAMANHO_VETOR, 0);
    printf("Selection Sort - Ordem Decrescente:\n");
    imprimir_vetor(vetor_selection, TAMANHO_VETOR, 20);
    printf("\n");

    // Liberar memória
    free(vetor_original);
    free(vetor_bubble);
    free(vetor_selection);

    return 0;
}

// Função que gera um vetor de inteiros aleatórios dinamicamente
int* gerar_vetor(int tamanho) {
    int *vetor = malloc(tamanho * sizeof(int));
    if (!vetor) {
        printf("Erro ao alocar memória para o vetor.\n");
        exit(1);
    }
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % (MAX_VALOR + 1); // entre 0 e MAX_VALOR
    }
    return vetor;
}

// Função que imprime o vetor, mostrando até 'mostrar_limite' elementos do início e fim
void imprimir_vetor(int *vetor, int tamanho, int mostrar_limite) {
    if (tamanho <= 2 * mostrar_limite) {
        for (int i = 0; i < tamanho; i++) {
            printf("%d ", vetor[i]);
        }
    } else {
        // imprime primeiros 'mostrar_limite'
        for (int i = 0; i < mostrar_limite; i++) {
            printf("%d ", vetor[i]);
        }
        printf("... ");
        // imprime últimos 'mostrar_limite'
        for (int i = tamanho - mostrar_limite; i < tamanho; i++) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

// Função para copiar vetor origem para destino
void copiar_vetor(int *origem, int *destino, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

// Bubble Sort adaptado para ordem crescente ou decrescente
// crescente = 1 para ordem crescente, 0 para decrescente
void bubble_sort(int *vetor, int tamanho, int crescente) {
    for (int i = 0; i < tamanho -1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            int condicao = crescente ? (vetor[j] > vetor[j+1]) : (vetor[j] < vetor[j+1]);
            if (condicao) {
                int temp = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = temp;
            }
        }
    }
}

// Selection Sort adaptado para ordem crescente ou decrescente
void selection_sort(int *vetor, int tamanho, int crescente) {
    for (int i = 0; i < tamanho - 1; i++) {
        int indice_extremo = i;
        for (int j = i + 1; j < tamanho; j++) {
            int condicao = crescente ? (vetor[j] < vetor[indice_extremo]) : (vetor[j] > vetor[indice_extremo]);
            if (condicao) {
                indice_extremo = j;
            }
        }
        if (indice_extremo != i) {
            int temp = vetor[i];
            vetor[i] = vetor[indice_extremo];
            vetor[indice_extremo] = temp;
        }
    }
}
