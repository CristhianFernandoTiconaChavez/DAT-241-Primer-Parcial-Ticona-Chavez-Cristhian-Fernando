// g++ Ejercicio2.cpp -o Ejercicio2
// ./Ejercicio2

#include <iostream>

void suma(float &a, float &b) {
    a = a + b;
}

void resta(float &a, float &b) {
    a = a - b;
}

void multiplicacion(float &a, float &b) {
    float c = a;
    for (float i = 0; i < b - 1; ++i) {
        if (b - (i + 1) < 1)
        {
            a = a + (c * (b - (i + 1)));
        }
        else {
            a = a + c;
        }    
        
    }
}

void division(float &a, float &b) {
    int cociente = 0;
    while (a >= b) {
        a -= b;
        cociente++;
    }
    b = a / b;
    a = cociente;
    a = a + b;
}

int main() {

    float a, b;
    int opcion;

    do
    {
        std::cout << "\n\n EJERCICIO 2. \n\n";
        std::cout << "\n   1. Suma.";
        std::cout << "\n   2. Resta.";
        std::cout << "\n   3. Multiplicación.";
        std::cout << "\n   4. División." ;
        std::cout << "\n   5. Salir." ;
        std::cout << "\n\n Introduzca opción.\n";

        std::cin >> opcion;

        switch ( opcion )
        {
            case 1: std::cout << "SUMA\n";
                    std::cin >> a;
                    std::cin >> b;
                    suma(a, b);
                    std::cout << "La suma es: " << a << std::endl;
                    break;

            case 2: std::cout << "RESTA\n";
                    std::cin >> a;
                    std::cin >> b;
                    resta(a, b);
                    std::cout << "La resta es: " << a << std::endl;
                    break;

            case 3: std::cout << "MULTIPLICACIÓN\n";
                    std::cin >> a;
                    std::cin >> b;
                    multiplicacion(a, b);
                    std::cout << "La multiplicación es: " << a << std::endl;
                    break;

            case 4: std::cout << "DIVISIÓN\n";
                    std::cin >> a;
                    std::cin >> b;
                    division(a, b);
                    std::cout << "La división es: " << a << std::endl;
                    break;
         }

    } while ( opcion < 5 );

    return 0;
}
