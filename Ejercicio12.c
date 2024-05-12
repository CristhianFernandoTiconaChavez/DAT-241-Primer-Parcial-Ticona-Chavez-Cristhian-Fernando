#include <stdio.h>
#include <mpi.h>

int fibonacci(int n) {
    int a = 0, b = 1, c;
    if (n == 0)
        return a;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int main(int argc, char *argv[]) {
    int rank, size;
    int term;
    int result;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0) { 
        printf("Ingrese el término de Fibonacci que desea calcular: ");
        scanf("%d", &term);

        for (int i = 1; i < size; i++) {
            MPI_Send(&term, 1, MPI_INT, i, 0, MPI_COMM_WORLD);
        }
    }

    MPI_Bcast(&term, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (rank != 0) { 
        result = fibonacci(term);
        MPI_Send(&result, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    } else { 
        for (int i = 1; i < size; i++) {
            MPI_Recv(&result, 1, MPI_INT, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("Procesador %d: Fibonacci(%d) = %d\n", i, term, result);
        }
    }

    MPI_Finalize();
    return 0;
}
