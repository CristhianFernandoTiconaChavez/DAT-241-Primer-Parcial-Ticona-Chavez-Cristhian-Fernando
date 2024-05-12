// gcc Ejercicio1.c -o Ejercicio1 -fopenmp
// ./Ejercicio1

#include <stdio.h>

void suma(float *a, float *b) {
    *a = *a + *b;
}

void resta(float *a, float *b) {
    *a = *a - *b;
}

void multiplicacion(float *a, float *b) {
    float c = *a;
    for (float i = 0; i < *b - 1; ++i) {
        if (*b - (i + 1) < 1)
        {
            *a = *a + (c * (*b - (i + 1)));
        }
        else {
            *a = *a + c;
        }    
        
    }
}

void division(float *a, float *b) {
    int cociente = 0;
    while (*a >= *b) {
        *a -= *b;
        cociente++;
    }
    *b = *a / *b;
    *a = cociente;
    *a = *a + *b;
}

void main() {

    float a, b;
    int opcion;

    do
    {
    	printf( "\n\n EJERCICIO 1. \n\n");
        printf( "\n   1. Suma.");
        printf( "\n   2. Resta.");
        printf( "\n   3. Multiplicación.");
        printf( "\n   4. División." );
        printf( "\n   5. Salir." );
        printf( "\n\n Introduzca opción.\n");

        scanf( "%d", &opcion );

        switch ( opcion )
        {
            case 1: printf("SUMA\n");
    				scanf("%e", &a);
    				scanf("%e", &b);
                    suma(&a, &b);
    				printf("La suma es: %g\n", a);
                    break;

            case 2: printf("RESTA\n");
    				scanf("%e", &a);
    				scanf("%e", &b);
                    resta(&a, &b);
    				printf("La resta es: %g\n", a);
                    break;

            case 3: printf("MULTIPLICACIÓN\n");
    				scanf("%e", &a);
    				scanf("%e", &b);
                    multiplicacion(&a, &b);
    				printf("La multiplicación es: %g\n", a);
    				break;

    		case 4: printf("DIVISIÓN\n");
    				scanf("%e", &a);
    				scanf("%e", &b);
                    division(&a, &b);
    				printf("La división es: %g\n", a);

         }

    } while ( opcion < 5 );
    
}