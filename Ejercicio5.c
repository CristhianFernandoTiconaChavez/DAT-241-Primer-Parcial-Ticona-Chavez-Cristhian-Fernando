// mpicc -o Ejercicio5 Ejercicio5.c
// mpiexec -n 4 ./Ejercicio5

#include <stdio.h>
#include <mpi.h>

#define N 4

void multiplicar_matriz_con_vector(int matriz[N][N], int vector[N], int resultado[N], int procesador, int cantidad) {
    int resultado_local[N] = {0};

    for (int i = 0; i < N; i++) {
        resultado_local[i] = 0;
        for (int j = 0; j < N; j++) {
            resultado_local[i] += matriz[j][i] * vector[j];
        }
    }
    
    MPI_Gather(resultado_local, N, MPI_INT, resultado, N, MPI_INT, 0, MPI_COMM_WORLD);
}

int main(int argc, char *argv[]) {
    int procesador, cantidad;
    int matriz[N][N] = {{1, 2, 3, 4},
                        {5, 6, 7, 8},
                        {9, 10, 11, 12},
                        {13, 14, 15, 16}};
    int vector[N] = {1, 2, 3, 4};
    int resultado[N];

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);

    multiplicar_matriz_con_vector(matriz, vector, resultado, procesador, cantidad);

    if (procesador == 0) {
        printf("Resultado de la multiplicación:\n");
        for (int i = 0; i < N; i++) {
            printf("%d ", resultado[i]);
        }
        printf("\n");
    }

    MPI_Finalize();

}