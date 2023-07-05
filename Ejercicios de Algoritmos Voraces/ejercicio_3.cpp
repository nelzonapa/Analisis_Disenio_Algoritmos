/*
3. Tenemos que completar un conjunto de n tareas con plazos límite. Cada una de
las tareas consume la misma cantidad de tiempo (una unidad) y, en un instante
determinado, podemos realizar únicamente una tarea. La tarea i tiene como
plazo límite di y produce un beneficio gi(gi> 0) sólo si la tarea se realiza 
en un instante de tiempo t ≤ di.

a. Diseñe un algoritmo greedy que nos permita seleccionar el conjunto de
tareas que nos asegure el mayor beneficio posible.
b. Aplique su algoritmo a la siguiente instancia del problema:
Tarea           i   1   2   3   4
Beneficio       gi  50  10  15  30
Plazo límite    di  2   1   2   1
*/
/*
Usando Planifiación de Tareas
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Tarea {
    int beneficio;
    int plazoLimite;
};

// Función de comparación para ordenar las tareas por beneficio de forma descendente
bool compararTareas(Tarea tarea1, Tarea tarea2) {
    return (tarea1.beneficio > tarea2.beneficio);
}

// Algoritmo voraz de planificación de tareas
vector<int> planificarTareas(vector<Tarea>& tareas) {
    // Ordenar las tareas por beneficio de forma descendente
    sort(tareas.begin(), tareas.end(), compararTareas);

    int maxPlazoLimite = 0;
    for (int i = 0; i < tareas.size(); i++) {
        maxPlazoLimite = max(maxPlazoLimite, tareas[i].plazoLimite);
    }

    vector<int> planificacion(maxPlazoLimite, -1); // Inicializar la planificación con valores inválidos

    for (int i = 0; i < tareas.size(); i++) {
        int plazoLimite = min(maxPlazoLimite, tareas[i].plazoLimite) - 1;
        while (plazoLimite >= 0 && planificacion[plazoLimite] != -1) {
            plazoLimite--;
        }
        if (plazoLimite >= 0) {
            planificacion[plazoLimite] = tareas[i].beneficio;
        }
    }

    return planificacion;
}

int main() {
    vector<Tarea> tareas = {//sS}}Según lo dado
        {50, 2},
        {10, 1},
        {15, 2},
        {30, 1}
    };

    vector<int> planificacion = planificarTareas(tareas);

    cout<<"Planificación de tareas: ";
    for (int i = 0; i < planificacion.size(); i++) {
        if (planificacion[i] != -1) {
            cout<<planificacion[i]<<" ";
        }
    }
    cout<<endl;

    return 0;
}
