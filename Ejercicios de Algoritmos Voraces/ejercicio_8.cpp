/*
8. Supongamos que el coste de tender una red de fibra óptica entre dos ciudades es
proporcional a la distancia euclídea entre ellas.
a. Diseñe un algoritmo que permita interconectar un conjunto de ciudades
minimizando el coste de la red de interconexión.
b. Busque un ejemplo en el que se demuestre que puede resultar más
económico instalar una centralita entre ciudades que utilizar solamente
conexiones directas entre ciudades.
*/

/*
algoritmo voraz de Kruskall
MST: Este algoritmo se basa en seleccionar las aristas de menor coste
 y añadirlas al árbol de expansión mínimo (MST, por sus siglas en inglés) 
*/

#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Estructura para representar una arista
struct Arista {
    int origen;
    int destino;
    double costo;
};

// Función de comparación para ordenar las aristas por su costo de manera ascendente
bool compararAristas(Arista a, Arista b) {
    return a.costo < b.costo;
}

// Función para encontrar el representante de un conjunto
int encontrarRepresentante(vector<int>& padres, int nodo) {
    if (padres[nodo] == nodo)
        return nodo;
    return encontrarRepresentante(padres, padres[nodo]);
}

// Función para unir dos conjuntos
void unirConjuntos(vector<int>& padres, int conjunto1, int conjunto2) {
    int representante1 = encontrarRepresentante(padres, conjunto1);
    int representante2 = encontrarRepresentante(padres, conjunto2);
    padres[representante1] = representante2;
}

// Función para encontrar el MST utilizando el algoritmo de Kruskal
void encontrarMST(vector<Arista>& aristas, int numCiudades) {
    // Ordenar las aristas por su costo de manera ascendente
    sort(aristas.begin(), aristas.end(), compararAristas);

    // Vector para almacenar los representantes de los conjuntos
    vector<int> padres(numCiudades);

    // Inicializar los representantes de los conjuntos
    for (int i = 0; i < numCiudades; i++) {
        padres[i] = i;
    }

    // Vector para almacenar las aristas seleccionadas en el MST
    vector<Arista> mst;

    // Variables para contar el número de aristas seleccionadas y el costo total del MST
    int numAristas = 0;
    double costoTotal = 0;

    // Iterar sobre todas las aristas
    for (Arista arista : aristas) {
        int origen = arista.origen;
        int destino = arista.destino;

        // Verificar si las ciudades están en conjuntos diferentes
        if (encontrarRepresentante(padres, origen) != encontrarRepresentante(padres, destino)) {
            // Unir los conjuntos
            unirConjuntos(padres, origen, destino);

            // Agregar la arista al MST
            mst.push_back(arista);

            // Incrementar el número de aristas y el costo total
            numAristas++;
            costoTotal += arista.costo;
        }

        // Terminar si todas las ciudades están interconectadas
        if (numAristas == numCiudades - 1)
            break;
    }

    // Imprimir el costo total del MST
    cout<<"El costo total de la red de interconexión es: "<<costoTotal<<endl;
}

int main() {
    int numCiudades;
    cout<<"Ingrese el número de ciudades: ";
    cin >> numCiudades;

    // Vector para almacenar las coordenadas de las ciudades
    vector<pair<double, double>> coordenadas(numCiudades);

    cout<<"Ingrese las coordenadas de las ciudades:"<<endl;
    for (int i = 0; i < numCiudades; i++) {
        double x, y;
        cout<<"Ciudad "<<i + 1<<": ";
        cin >> x >> y;
        coordenadas[i] = make_pair(x, y);
    }

    // Vector para almacenar las aristas (conexiones) entre ciudades
    vector<Arista> aristas;

    // Calcular las distancias euclídeas entre todas las ciudades
    for (int i = 0; i < numCiudades; i++) {
        for (int j = i + 1; j < numCiudades; j++) {
            double distancia = sqrt(pow(coordenadas[i].first - coordenadas[j].first, 2) +
                                    pow(coordenadas[i].second - coordenadas[j].second, 2));
            aristas.push_back({i, j, distancia});
        }
    }

    // Encontrar el MST utilizando el algoritmo de Kruskal
    encontrarMST(aristas, numCiudades);

    return 0;
}
