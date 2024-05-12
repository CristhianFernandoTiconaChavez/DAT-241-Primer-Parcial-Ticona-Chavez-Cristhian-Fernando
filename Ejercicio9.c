#include <stdio.h>
#include <mpi.h>

int main() {
    MPI_Init(NULL, NULL); 

    int proceso, cantidad;
    MPI_Comm_rank(MPI_COMM_WORLD, &proceso); 
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);

    int N = 100; 
    int M = 4;   
    int termino_por_proceso = N / M;

    int primer_termino = proceso * termino_por_proceso + 2; 
    int ultimo_termino = primer_termino + termino_por_proceso;

    printf("Proceso %d: ", proceso);
    for (int i = primer_termino; i < ultimo_termino; i += 2) { 
        printf("%d ", i);
    }
    printf("\n");

    MPI_Finalize(); 

    return 0;
}
