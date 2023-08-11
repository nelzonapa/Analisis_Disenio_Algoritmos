/*
PUNTOS ADICIONALES

Tenemos un alfabeto Σ = {a,b,c.d} y una relación de orden total Φ definida sobre
los elementos del alfabeto Σ. Sea f(x,y) una función que recibe como entradas
dos elementos de Σ y nos indica si x es el elemento que precede inmediatamente
a y en Φ. Diseñe un algoritmo basado en programación dinámica que, dados dos
elementos cualesquiera del alfabeto, u y v, nos permita determinar si u precede a
v en el orden Φ.
*/

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Mapa para convertir caracteres a índices
unordered_map<char, int> charToIndex = {{'a', 0}, {'b', 1}, {'c', 2}, {'d', 3}};

// Función recursiva para determinar si u precede a v en el orden total Φ
bool precede(const string &ordenTotal, char u, char v, int nivel, int n) {
    // Si se alcanza el final de la cadena Φ
    if (nivel == n) {
        return ordenTotal[n - 1] == u && ordenTotal[n - 2] == v;
    }

    // Recorre todos los caracteres posibles
    for (char c : {'a', 'b', 'c', 'd'}) {
        // Salta si el carácter actual es el mismo que el de Φ
        if (ordenTotal[nivel] == c) {
            continue;
        }

        // Verifica si la combinación actual viola las restricciones de precedencia
        if ((c == u && ordenTotal[nivel] == v) || (c == v && ordenTotal[nivel] == u)) {
            return false;
        }

        // Llamada recursiva para explorar más combinaciones
        if (precede(ordenTotal, u, v, nivel + 1, n)) {
            return true;
        }
    }

    return false;
}

int main() {
    string ordenTotal;
    cout << "Ingrese el orden total Φ (cadena de a, b, c y d en orden): ";
    cin >> ordenTotal;

    char u, v;
    cout << "Ingrese los dos elementos u y v: ";
    cin >> u >> v;

    int n = ordenTotal.length();

    if (precede(ordenTotal, u, v, 0, n)) {
        cout << "u precede a v en el orden total Φ." << endl;
    } else {
        cout << "u no precede a v en el orden total Φ." << endl;
    }

    return 0;
}
