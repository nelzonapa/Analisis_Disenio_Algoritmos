/*
4. Consideremos un grafo no dirigido G = (V, E). Un conjunto de nodos U se dice
que es un recubrimiento de G si U es un subconjunto de V tal que cada arista en
E incide en, al menos, un vértice de U. Un conjunto de nodos es un
recubrimiento minimal de G si es un recubrimiento con el número mínimo
posible de nodos.
a. Diseñe un algoritmo greedy para obtener un recubrimiento de G.
b. Indique si el algoritmo greedy devuelve un recubrimiento minimal para
cualquier grafo si, como función de selección, se escoge el nodo con
mayor grado de incidencia de entre los nodos aún no seleccionados.
NOTA:
El grado de incidencia de un vértice es el número de aristas que inciden en él.
*/

/*Usando Heuristica Voraz Arista*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//Usamos estrcutura 
struct Arista {
    int u;
    int v;
    int weight;
};

// Función de comparación para ordenar las aristas en orden no decreciente de peso
bool compareAristas(Arista& a, Arista& b) {
    return a.weight < b.weight;
}

// Algoritmo voraz de Heurística de Aristas para obtener un recubrimiento minimal del grafo
vector<int> obtenerRecubrimiento(vector<Arista>& aristas, int numNodos) {
    // Ordenar las aristas en orden no decreciente de peso
    sort(aristas.begin(), aristas.end(), compareAristas);

    unordered_set<int> nodosSeleccionados;
    vector<int> recubrimiento;

    // Iterar sobre las aristas ordenadas
    for (Arista& arista : aristas) {
        if (nodosSeleccionados.find(arista.u) == nodosSeleccionados.end() ||
            nodosSeleccionados.find(arista.v) == nodosSeleccionados.end()) {
            // Si alguno de los extremos de la arista no está en el recubrimiento,
            // agregar ambos extremos al recubrimiento y marcarlos como seleccionados
            recubrimiento.push_back(arista.u);
            recubrimiento.push_back(arista.v);
            nodosSeleccionados.insert(arista.u);
            nodosSeleccionados.insert(arista.v);
        }
    }

    return recubrimiento;
}

int main() {
    int numNodos = 6;
    vector<Arista> aristas = {
        {0, 1, 2},
        {0, 2, 1},
        {1, 3, 4},
        {2, 3, 5},
        {2, 4, 3},
        {3, 4, 6},
        {3, 5, 7}
    };

    vector<int> recubrimiento = obtenerRecubrimiento(aristas, numNodos);

    cout<<"Recubrimiento del grafo: ";
    for (int nodo : recubrimiento) {
        cout<<nodo<<" ";
    }
    cout<<endl;

    return 0;
}

