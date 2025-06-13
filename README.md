#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000  // Tamanho do vetor

// Função para gerar um vetor dinamicamente e preenchê-lo com valores aleatórios
int* gerarVetor() {
    int* v = (int*)malloc(N * sizeof(int));
    if (v == NULL) {
        printf("Erro ao alocar memória!\n");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        v[i] = rand() % 10000;
    }
    return v;
}

// Função para copiar um vetor
int* copiarVetor(int* origem) {
    int* copia = (int*)malloc(N * sizeof(int));
    if (copia == NULL) {
        printf("Erro ao alocar memória para cópia!\n");
        exit(1);
    }
    for (int i = 0; i < N; i++) {
        copia[i] = origem[i];
    }
    return copia;
}

// Função para imprimir os primeiros e últimos 10 elementos do vetor
void imprimirVetor(int* v) {
    printf("Início: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("\nFim:    ");
    for (int i = N - 10; i < N; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

// Bubble Sort com ponteiros
void bubbleSort(int* v, int crescente) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if ((crescente && v[j] > v[j + 1]) || (!crescente && v[j] < v[j + 1])) {
                int temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// Selection Sort com ponteiros
void selectionSort(int* v, int crescente) {
    for (int i = 0; i < N - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < N; j++) {
            if ((crescente && v[j] < v[idx]) || (!crescente && v[j] > v[idx])) {
                idx = j;
            }
        }
        int temp = v[i];
        v[i] = v[idx];
        v[idx] = temp;
    }
}

int main() {
    srand(time(NULL));

    // Gerar vetor original
    int* original = gerarVetor();
    printf("Vetor Original:\n");
    imprimirVetor(original);

    // Bubble Sort Crescente
    int* v1 = copiarVetor(original);
    bubbleSort(v1, 1);
    printf("\nBubble Sort Crescente:\n");
    imprimirVetor(v1);
    free(v1);

    // Bubble Sort Decrescente
    v1 = copiarVetor(original);
    bubbleSort(v1, 0);
    printf("\nBubble Sort Decrescente:\n");
    imprimirVetor(v1);
    free(v1);

    // Selection Sort Crescente
    int* v2 = copiarVetor(original);
    selectionSort(v2, 1);
    printf("\nSelection Sort Crescente:\n");
    imprimirVetor(v2);
    free(v2);

    // Selection Sort Decrescente
    v2 = copiarVetor(original);
    selectionSort(v2, 0);
    printf("\nSelection Sort Decrescente:\n");
    imprimirVetor(v2);
    free(v2);

    // Liberar vetor original
    free(original);

    return 0;
}
