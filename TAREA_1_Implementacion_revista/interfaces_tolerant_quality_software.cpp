#include <iostream>
#include <stdlib.h>
using namespace std;

// Definicion de la clase CArithmetic

class CArithmetic {
public:
    static double Addition(double a, double b);
    static double Substraction(double a, double b);
    static double Multiplication(double a, double b);
    static double Division(double a, double b);
};

double CArithmetic::Addition(double a, double b) {
    return a + b;
}

double CArithmetic::Substraction(double a, double b) {
    return a - b;
}

double CArithmetic::Multiplication(double a, double b) {
    return a * b;
}

double CArithmetic::Division(double a, double b) {
    if (b == 0.0)
        throw 0;
    return a / b;
}

int main() {
    double x, y, z;
    // ...
    try {
        z = CArithmetic::Division(x, y);
        std::cout << z << std::endl;
    }
    catch (int errorcode) {
        std::cout << "Error: Division por cero" << std::endl;
    }

    unsigned long fibo_recursive(unsigned n) {
        if (n < 2)
            return 1;
        return fibo_recursive(n - 1) + fibo_recursive(n - 2);
    }

    unsigned long fibo_iterative(unsigned n) {
        if (n < 2)
            return 1;
        unsigned long f1 = 0, f2 = 1;
        unsigned long output;
        do {
            output = f1 + f2;
            f1 = f2;
            f2 = output;
        } while (--n >= 2);
        return output;
    }

    unsigned long result_recursive = fibo_recursive(10);
    unsigned long result_iterative = fibo_iterative(10);

    std::cout << "Resultado (recursivo): " << result_recursive << std::endl;
    std::cout << "Resultado (iterativo): " << result_iterative << std::endl;

    return 0;
}
