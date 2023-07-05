/*LOG CAMBIO DE MONEDAS EJEMPLO*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> cambioMonedas(int monto, vector<int>& denominaciones) {
    vector<int> solucion(denominaciones.size(), 0); // Vector para almacenar la cantidad de cada denominación

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

void imprimirCambio(vector<int>& solucion, vector<int>& denominaciones) {
    cout<<"Cambio: ";
    for (int i = 0; i < solucion.size(); i++) {
        if (solucion[i] > 0) {
            cout<<solucion[i]<<" x "<<denominaciones[i]<<" ";
        }
    }
    cout<<endl;
}

int main() {
    //EJEMPLO
    int monto = 78;
    vector<int> denominaciones = {1, 2, 5, 10, 20, 50};
    vector<int> solucion = cambioMonedas(monto, denominaciones);
    imprimirCambio(solucion, denominaciones);

    return 0;
}
