/*HEURISTICA DE VERTICES - EJEMPLO DE VIAJANTE*/
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

//Usamos struct 
struct Ciudad {
    int id;
    int x;
    int y;
};

// Calcula la distancia euclidiana entre dos ciudades
double calcularDistancia(Ciudad& ciudad1, Ciudad& ciudad2) {
    int dx = ciudad1.x - ciudad2.x;
    int dy = ciudad1.y - ciudad2.y;
    return sqrt(dx*dx + dy*dy);
}

// Función de comparación para ordenar las ciudades según su ID
bool compararCiudades(Ciudad& ciudad1, Ciudad& ciudad2) {
    return ciudad1.id < ciudad2.id;
}

// Heurística de vértices para resolver el problema del viajante
vector<int> resolverViajante(vector<Ciudad>& ciudades, int ciudadInicial) {
    int n = ciudades.size();

    // Ordenar las ciudades según su ID
    vector<Ciudad> ciudadesOrdenadas = ciudades;
    sort(ciudadesOrdenadas.begin(), ciudadesOrdenadas.end(), compararCiudades);

    // Crear un vector para almacenar el recorrido óptimo
    vector<int> recorrido;
    recorrido.push_back(ciudadInicial); // Añadir la ciudad inicial al recorrido

    // Crear un vector para controlar las ciudades visitadas
    vector<bool> visitado(n, false);
    visitado[ciudadInicial] = true;

    // Iterar hasta visitar todas las ciudades
    while (recorrido.size() < n) {
        int ciudadActual = recorrido.back(); // Obtener la última ciudad del recorrido
        double distanciaMinima = numeric_limits<double>::max();
        int ciudadSiguiente = -1;

        // Encontrar la ciudad más cercana no visitada
        for (int i = 0; i < n; i++) {
            if (!visitado[ciudadesOrdenadas[i].id]) {
                double distancia = calcularDistancia(ciudades[ciudadActual], ciudades[ciudadesOrdenadas[i].id]);
                if (distancia < distanciaMinima) {
                    distanciaMinima = distancia;
                    ciudadSiguiente = ciudadesOrdenadas[i].id;
                }
            }
        }

        recorrido.push_back(ciudadSiguiente); // Añadir la ciudad más cercana al recorrido
        visitado[ciudadSiguiente] = true; // Marcar la ciudad como visitada
    }

    return recorrido;
}

int main() {
    vector<Ciudad> ciudades = {{0, 2, 3},{1, 4, 1},{2, 5, 5},{3, 7, 2},{4, 6, 6}};
    int ciudadInicial = 0;
    vector<int> recorridoOptimo = resolverViajante(ciudades, ciudadInicial);
    cout<<"Mejor recorrido: ";
    for (int ciudad : recorridoOptimo) {
        cout<<ciudad<<" ";
    }
    cout<<endl;

    return 0;
}
