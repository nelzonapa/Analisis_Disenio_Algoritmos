/*HEURISTICA DE ARISTAS - EJEMPLO DE VIAJANTE*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Usamos struct
struct Ciudad {
    int id;
    vector<int> distancias;
};

// Función para comparar las distancias entre ciudades
bool compararDistancias(const Ciudad& ciudad1, const Ciudad& ciudad2) {
    return ciudad1.distancias.size() < ciudad2.distancias.size();
}

// Función para obtener el índice de la ciudad más cercana que no haya sido visitada
int obtenerCiudadMasCercana(const vector<Ciudad>& ciudades, const vector<bool>& visitadas, int ciudadActual) {
    int distanciaMinima = INT16_MAX;//No puede ser 0
    int ciudadMasCercana = -1;

    for (int i = 0; i < ciudades.size(); i++) {
        if (!visitadas[i] && ciudades[ciudadActual].distancias[i] < distanciaMinima) {
            distanciaMinima = ciudades[ciudadActual].distancias[i];
            ciudadMasCercana = i;
        }
    }

    return ciudadMasCercana;
}

// Función para resolver el Problema del Viajante usando la Heurística de Aristas
vector<int> resolverProblemaViajante(const vector<Ciudad>& ciudades) {
    // Ordenar las ciudades por cantidad de distancias en orden ascendente
    vector<Ciudad> ciudadesOrdenadas = ciudades;
    sort(ciudadesOrdenadas.begin(), ciudadesOrdenadas.end(), compararDistancias);

    int numCiudades = ciudades.size();
    vector<bool> visitadas(numCiudades, false);  // Vector para marcar las ciudades visitadas
    vector<int> recorrido;  // Vector para almacenar el recorrido óptimo

    // Empezar desde la primera ciudad
    int ciudadActual = 0;
    visitadas[ciudadActual] = true;
    recorrido.push_back(ciudadActual);

    // Visitar todas las ciudades restantes
    for (int i = 1; i < numCiudades; i++) {
        ciudadActual = obtenerCiudadMasCercana(ciudadesOrdenadas, visitadas, ciudadActual);
        visitadas[ciudadActual] = true;
        recorrido.push_back(ciudadActual);
    }

    // Volver a la primera ciudad para cerrar el ciclo
    recorrido.push_back(0);

    return recorrido;
}

int main() {
    vector<Ciudad> ciudades = {{0, {0, 2, 9, 10}},{1, {2, 0, 6, 4}},{2, {9, 6, 0, 8}},{3, {10, 4, 8, 0}}};

    vector<int> recorrido = resolverProblemaViajante(ciudades);
    cout<<"Mejor Recoorrido: ";
    for (int ciudad : recorrido) {
        cout<<ciudad<<" ";
    }
    cout<<endl;

    return 0;
}
