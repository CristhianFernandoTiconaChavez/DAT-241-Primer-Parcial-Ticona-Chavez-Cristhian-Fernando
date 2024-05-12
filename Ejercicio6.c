// mpicc -o Ejercicio6 Ejercicio6.c 
// mpiexec -n 4 ./Ejercicio6

#include <stdio.h>
#include <mpi.h>
#include <math.h>

double funcion(double x) {
    return 4.0 / (1.0 + x * x);
}

int main(int argc, char *argv[]) {
    int procesador, cantidad, i;
    double suma_parcial = 0.0;
    double suma_total = 0.0;
    double ancho = 1.0 / 1000000; 
    double x, pi;
    int iteraciones = 0;
    double epsilon = 1e-10; 

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &procesador);
    MPI_Comm_size(MPI_COMM_WORLD, &cantidad);

    do {
        suma_parcial = 0.0;

        for (i = procesador + 1; i <= 1000000; i += cantidad) {
            x = (i - 0.5) * ancho;
            suma_parcial += funcion(x);
        }

        MPI_Reduce(&suma_parcial, &suma_total, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

        if (procesador == 0) {
            suma_total *= ancho;
            pi = suma_total;
            iteraciones++;
        }

        MPI_Barrier(MPI_COMM_WORLD);

        MPI_Bcast(&pi, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

        if (procesador == 0 && iteraciones > 1) {
            if (fabs(pi - M_PI) < epsilon) {
                break;
            }
        }

        iteraciones++;
    } while (1);

    if (procesador == 0) {
        printf("Estimación de PI: %f\n", pi);
        printf("Número de iteraciones: %d\n", iteraciones);
    }

    MPI_Finalize();

    return 0;
}
