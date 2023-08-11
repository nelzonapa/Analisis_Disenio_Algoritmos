/*
PUNTOS ADICIONALES

Diseñe un algoritmo eficiente que compruebe si un grafo es bipartido o no.
NOTA: Un grafo es bipartido si su conjunto de vértices V puede dividirse en dos
conjuntos disjuntos X e Y de tal forma que todas las aristas del grafo van de un
vértice en X a un vértice en Y.
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

//función
bool esBipartito(vector<vector<int>> &grafo, int nodoInicial) {
    int numNodos = grafo.size();
    vector<int> colores(numNodos, -1);

    queue<int> cola;
    cola.push(nodoInicial);
    colores[nodoInicial] = 0;

    while (!cola.empty()) {//hasta vaciar la cola
        int nodoActual = cola.front();
        cola.pop();

        for (int vecino : grafo[nodoActual]) {
            if (colores[vecino] == -1) {
                colores[vecino] = 1 - colores[nodoActual];
                cola.push(vecino);
            } else if (colores[vecino] == colores[nodoActual]) {
                return false; // Los nodos adyacentes tienen el mismo color, no es bipartito
            }
        }
    }

    return true; // No se encontraron nodos adyacentes del mismo color
}

int main() {
    int numNodos, numAristas;
    cout << "Ingrese el numero de nodos: ";
    cin >> numNodos;
    cout << "Ingrese el numero de aristas: ";
    cin >> numAristas;

    vector<vector<int>> grafo(numNodos);

    for (int i = 0; i < numAristas; ++i) {
        int u, v;
        cout << "Ingrese los nodos de la arista " << i + 1 << ": ";
        cin >> u >> v;
        grafo[u].push_back(v);
        grafo[v].push_back(u);
    }

    bool bipartito = true;
    for (int i = 0; i < numNodos; ++i) {
        if (esBipartito(grafo, i) == false) {
            bipartito = false;
            break;
        }
    }

    if (bipartito) {
        cout << "El grafo es bipartito." << endl;
    } else {
        cout << "El grafo no es bipartito." << endl;
    }

    return 0;
}
