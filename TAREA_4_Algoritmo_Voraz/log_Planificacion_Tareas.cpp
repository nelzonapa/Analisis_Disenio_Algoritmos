/*LOGARITMO PLANIFICACIÓN DE TAREAS CON EJEMPLO*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//Usamos un struct
struct Tarea {
    int id;
    int plazoLimite;
    int duracion;
};

bool compararTareas(Tarea& tarea1, Tarea& tarea2) {
    return tarea1.plazoLimite < tarea2.plazoLimite;
}

vector<int> planificarTareas(vector<Tarea>& tareas) {
    sort(tareas.begin(), tareas.end(), compararTareas);

    int n = tareas.size();
    vector<int> planificacion(n,-1);  // Vector para almacenar el orden de ejecución de las tareas
    vector<bool> slot(n, false);  // Vector para controlar los slots de tiempo ocupados

    for (int i = 0; i < n; i++) {
        int j = min(n, tareas[i].plazoLimite) - 1;
        while (j >= 0) {
            if (!slot[j]) {
                planificacion[j] = tareas[i].id;
                slot[j] = true;
                break;
            }
            j--;
        }
    }

    return planificacion;
}

void imprimirPlanificacion(vector<int>& planificacion) {
    cout<<"Orden de ejecución de las tareas: ";
    for (int i = 0; i < planificacion.size(); i++) {
        if (planificacion[i] != -1) {
            cout<<planificacion[i]<<" ";
        }
    }
    cout<<endl;
}

int main() {
    //Como ejemplo
    vector<Tarea> tareas = { {1, 5, 2}, {2, 2, 1}, {3, 4, 3}, {4, 3, 2}, {5, 7, 1} };
    vector<int> planificacion = planificarTareas(tareas);
    imprimirPlanificacion(planificacion);

    return 0;
}
