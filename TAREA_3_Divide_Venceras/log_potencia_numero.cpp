#include <iostream>

double power(double x, int n) {
    if (n == 0) {
        return 1.0;
    }
    
    double temp = power(x, n / 2);
    if (n % 2 == 0) {
        return temp * temp;
    } else {
        if (n > 0) {
            return x * temp * temp;
        } else {
            return (temp * temp) / x;
        }
    }
}

int main() {
    double base = 2.0;
    int exponent = 5;
    double result = power(base, exponent);

    std::cout << "El resultado de " << base << " elevado a la potencia " << exponent << " es: " << result << std::endl;

    return 0;
}
