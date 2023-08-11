/*
PUNTOS ADICIONALES

Sea V un vector con n valores enteros distintos. Diseñe un algoritmo eficiente
basado en programación dinámica para encontrar la secuencia creciente de
máxima longitud en V. Por ejemplo si el vector de entrada es (11, 17, 5, 8, 6, 4,
7, 12, 3), la secuencia creciente de máxima longitud es (5, 6, 7, 12).

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int maxLongitud = 0; // Almacena la longitud máxima encontrada
vector<int> secuenciaMaxima; // Almacena la secuencia de máxima longitud

// Función recursiva para encontrar la secuencia creciente de máxima longitud
void encontrarSecuencia(const vector<int> &V, vector<int> &secuenciaActual, int indiceActual) {
    // Actualiza la secuencia de máxima longitud si es necesario
    if (secuenciaActual.size() > maxLongitud) {
        maxLongitud = secuenciaActual.size();
        secuenciaMaxima = secuenciaActual;
    }

    // Explora las combinaciones posibles a partir del índice actual
    for (int i = indiceActual + 1; i < V.size(); ++i) {
        // Agrega el valor a la secuencia si cumple con la condición de crecimiento
        if (secuenciaActual.empty() || V[i] > secuenciaActual.back()) {
            secuenciaActual.push_back(V[i]);
            encontrarSecuencia(V, secuenciaActual, i); // Llamada recursiva
            secuenciaActual.pop_back(); // Deshace la elección
        }
    }
}

int main() {
    int n;
    cout << "Ingrese la cantidad de valores en el vector: ";
    cin >> n;

    vector<int> V(n);
    cout << "Ingrese los valores del vector: ";
    for (int i = 0; i < n; ++i) {
        cin >> V[i];
    }

    vector<int> secuenciaActual;
    for (int i = 0; i < n; ++i) {
        secuenciaActual.push_back(V[i]);
        encontrarSecuencia(V, secuenciaActual, i); // Inicia la búsqueda desde el índice actual
        secuenciaActual.pop_back(); // Deshace la elección
    }

    cout << "La secuencia creciente de maxima longitud es:";
    for (int num : secuenciaMaxima) {
        cout << " " << num;
    }
    cout << endl;

    return 0;
}
