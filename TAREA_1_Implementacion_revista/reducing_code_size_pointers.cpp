#include <iostream>

// Declaracion de las funciones de operaciones
float Addition(float a, float b) {
    return a + b;
}

float Subtraction(float a, float b) {
    return a - b;
}

float Multiplication(float a, float b) {
    return a * b;
}

float Division(float a, float b) {
    if (b == 0.0)
        throw std::runtime_error("Division por cero");
    return a / b;
}

typedef float (*lpfnOperation)(float, float);

int main() {
    lpfnOperation vpf[4] = {&Addition, &Subtraction, &Multiplication, &Division};

    float a, b, c;
    int opt;

    std::cout << "Ingrese los operandos: ";
    std::cin >> a >> b;

    std::cout << "Ingrese la operacion (0-Addition, 1-Subtraction, 2-Multiplication, 3-Division): ";
    std::cin >> opt;

    if (opt < 0 || opt >= 4) {
        std::cout << "Operacion invalida" << std::endl;
        return 0;
    }

    c = (*vpf[opt])(a, b);

    std::cout << "Resultado: " << c << std::endl;

    return 0;
}
