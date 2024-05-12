#include <stdio.h>
#include <omp.h>

void main() {
    int N = 80; 
    int M = 4;
    int terminos_por_procesador = N / M;

    #pragma omp parallel num_threads(M)
    {
        int proceso = omp_get_thread_num();
        int primer_termino = proceso * terminos_por_procesador + 2;
        int ultimo_termino = primer_termino + terminos_por_procesador;

        printf("Proceso %d: ", proceso);
        for (int i = primer_termino; i < ultimo_termino; i += 2) 
        { 
            printf("%d ", i);
        }
        printf("\n");
    }

}

