// gcc Ejercicio4.c -o Ejercicio4 -fopenmp
// ./Ejercicio4

#include <stdio.h>
#include <omp.h>

#define N 4

void multiplicar_matriz_con_vector(int matriz[N][N], int vector[N], int resultado[N]) {
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        resultado[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado[i] = resultado[i] + (matriz[j][i] * vector[j]);
        }
    }
}

void main() {
    int matriz[N][N] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
    int vector[N] = {1, 2, 3, 4};
    int resultado[N];

    multiplicar_matriz_con_vector(matriz, vector, resultado);

    printf("Resultado de la multiplicación:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

}
