/*
PUNTOS ADICIONALES

Un instructor de esquí dispone de n pares de esquís para sus n alumnos.
Obligatoriamente, cada alumno debe recibir un par de esquís, que han de
adecuarse lo máximo posible a su altura. El problema del instructor es asignar
los esquís a los alumnos de forma que se minimice la suma de los valores
absolutos de las diferencias entre las alturas de los alumnos y las longitudes de
los respectivos esquís asignados. Proponga un algoritmo que resuelva este
problema de forma óptima y aplíquelo sobre el siguiente ejemplo:

        Altura      178 168 190 170
        Longitud    183 188 168 175

Resolviendo 
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

struct ParEsquis {
    int altura;
    int longitud;
};

bool compararPorLongitud(const ParEsquis &a, const ParEsquis &b) {
    return a.longitud < b.longitud;
}

int sumaMinimaDiferenciasAbsolutas(const vector<ParEsquis> &paresEsquis, int indice, int sumaActual, int sumaObjetivo, int diferenciaActual) {
    if (indice == paresEsquis.size()) {
        return diferenciaActual;
    }

    // Opción 1: Asignar el esquí al alumno actual
    int opcion1 = sumaMinimaDiferenciasAbsolutas(paresEsquis, indice + 1, sumaActual + paresEsquis[indice].longitud, sumaObjetivo, diferenciaActual);

    // Opción 2: No asignar el esquí al alumno actual
    int opcion2 = sumaMinimaDiferenciasAbsolutas(paresEsquis, indice + 1, sumaActual, sumaObjetivo, diferenciaActual);

    // Actualizar la diferencia mínima si es necesario
    diferenciaActual = min(diferenciaActual, abs(sumaActual - sumaObjetivo));

    // Podar la rama si la diferencia actual supera la mejor diferencia encontrada
    if (diferenciaActual + sumaActual > sumaObjetivo) {
        return diferenciaActual;
    }

    return min(opcion1, opcion2);
}

int main() {
    int n;
    cout << "Ingrese el numero de alumnos: ";
    cin >> n;

    vector<ParEsquis> paresEsquis(n);
    for (int i = 0; i < n; ++i) {
        cout << "Ingrese la altura del alumno " << i + 1 << ": ";
        cin >> paresEsquis[i].altura;
        cout << "Ingrese la longitud del esqui correspondiente: ";
        cin >> paresEsquis[i].longitud;
    }

    sort(paresEsquis.begin(), paresEsquis.end(), compararPorLongitud);

    int sumaTotal = 0;
    for (const ParEsquis &par : paresEsquis) {
        sumaTotal += par.longitud;
    }

    int resultado = sumaMinimaDiferenciasAbsolutas(paresEsquis, 0, 0, sumaTotal, sumaTotal);

    cout << "La suma minima de diferencias absolutas es: " << resultado << endl;

    return 0;
}
