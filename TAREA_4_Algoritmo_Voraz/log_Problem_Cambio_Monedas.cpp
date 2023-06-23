#include <iostream>
#include <vector>

std::vector<int> cambioMonedas(int monto, const std::vector<int>& denominaciones) {
    std::vector<int> solucion(denominaciones.size(), 0); // Vector para almacenar la cantidad de cada denominación

    int i = denominaciones.size() - 1; // Índice para recorrer las denominaciones en orden descendente

    while (monto > 0 && i >= 0) {
        if (denominaciones[i] <= monto) {
            int cantidad = monto / denominaciones[i]; // Cantidad de monedas de la denominación actual
            solucion[i] = cantidad; // Almacenar la cantidad en el vector solución
            monto -= cantidad * denominaciones[i]; // Actualizar el monto restante
        }
        i--;
    }

    return solucion;
}

void imprimirCambio(const std::vector<int>& solucion, const std::vector<int>& denominaciones) {
    std::cout << "Cambio: ";
    for (int i = 0; i < solucion.size(); i++) {
        if (solucion[i] > 0) {
            std::cout << solucion[i] << " x " << denominaciones[i] << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int monto = 78;
    std::vector<int> denominaciones = {1, 2, 5, 10, 20, 50};

    std::vector<int> solucion = cambioMonedas(monto, denominaciones);
    imprimirCambio(solucion, denominaciones);

    return 0;
}
