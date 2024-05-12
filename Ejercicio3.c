// gcc Ejercicio3.c -o Ejercicio3 -fopenmp
// ./Ejercicio3

#include <stdio.h>
#include <omp.h>

int multiplicacion(int a, int b) {
    int resultado = 0;
    #pragma omp parallel for reduction(+:resultado)
    for (int i = 0; i < b; ++i) {
        resultado += a;
    }
    return resultado;
}

int division(int *a, int b) {
    int cociente = 0;
    #pragma omp parallel shared(a)
    {
        while (*a >= b) {
            #pragma omp critical
            {
                *a -= b;
                cociente++;
            }
        }
    }
    return cociente;
}

void main() {

    int a, b, opcion;
    do {

        printf("\n\n EJERCICIO 3. \n\n");
        printf("\n 1. Multiplicación.");
        printf("\n 2. División.");
        printf("\n 3. Salir \n\n");
        printf("\n Elija una opción\n");
        scanf("%d", &opcion);

        switch( opcion )
        {
            case 1: printf("MULTIPLICACIÓN\n");
                    printf("Primer número: ");
                    scanf("%d", &a);
                    printf("Segundo número: ");
                    scanf("%d", &b);
                    int resultado_mult = multiplicacion(a, b);
                    printf("La multiplicación es: %d\n", resultado_mult);
                    break;
            case 2: printf("DIVISIÓN\n");
                    printf("Primer número: ");
                    scanf("%d", &a);
                    printf("Segundo número: ");
                    scanf("%d", &b);
                    int resultado_div = division(&a, b);
                    printf("La división es: %d\n", resultado_div);
        }

    } while(opcion < 3);
        
