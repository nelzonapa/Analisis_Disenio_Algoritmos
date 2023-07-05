/*
7. Un autobús realiza una ruta determinada entre dos ciudades. Con el tanque de
gasolina lleno, el autobús puede recorrer n kilómetros sin parar. El conductor
dispone de un mapa de carreteras que le indica las gasolineras que hay en su
ruta. Para minimizar el tiempo empleado en recorrer su ruta, el conductor desea
pararse a repostar el menor número posible de veces. Diseñe un algoritmo
greedy que determine en qué gasolineras tiene que repostar y demuestre que su
algoritmo encuentra siempre la solución óptima.
*/
/*
Usamos una Heurística Voraz
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Gasolinera {
    int posicion;
    int distancia;
};

//Comparador de distancias
bool compararDistancia(Gasolinera& a, Gasolinera& b) {
    return (a.distancia < b.distancia);
}

vector<int> seleccionarGasolineras(int capacidadTanque, vector<Gasolinera>& gasolineras) {
    vector<int> gasolinerasSeleccionadas;
    int distanciaRecorrida = 0;

    while (distanciaRecorrida < capacidadTanque) {
        sort(gasolineras.begin(), gasolineras.end(), compararDistancia);

        if (gasolineras.empty()) {
            // No hay más gasolineras disponibles
            break;
        }

        Gasolinera gasolinera = gasolineras.front();
        gasolinerasSeleccionadas.push_back(gasolinera.posicion);
        distanciaRecorrida += gasolinera.distancia;

        gasolineras.erase(gasolineras.begin());
    }

    return gasolinerasSeleccionadas;
}

int main() {
    int capacidadTanque = 400; // Capacidad del tanque de gasolina del autobús en kilómetros

    vector<Gasolinera> gasolineras = {{1, 100},{2, 80},{3, 120},{4, 150},{5, 200},{6, 180},{7, 250},{8, 300},};
    vector<int> gasolinerasSeleccionadas = seleccionarGasolineras(capacidadTanque, gasolineras);

    cout<<"Gasolineras seleccionadas: ";
    for (int i = 0; i < gasolinerasSeleccionadas.size(); i++) {
        cout<<gasolinerasSeleccionadas[i]<<" ";
    }
    cout<<endl;

    return 0;
}
