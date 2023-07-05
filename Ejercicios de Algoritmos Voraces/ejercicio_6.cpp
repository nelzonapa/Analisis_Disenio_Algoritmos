/*
6. Supongamos que disponemos de n trabajadores y n tareas. Sea cij > 0 el coste de
asignarle el trabajo j al trabajador i. Una asignación válida es aquélla en la que a
cada trabajador le corresponde una tarea y cada tarea la realiza un trabajador
diferente. Dada una asignación válida, definimos el coste de dicha asignación
como la suma total de los costes individuales.
a. Diseñe distintas estrategias greedy para asignar tareas.
b. Encuentre contrajemplos que demuestren que ninguna de ellas nos
permite encontrar la solución óptima con un algoritmo greedy.
*/

/*
Usando Planificación de Tareas
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Asignacion {
    int trabajador;
    int tarea;
    int costo;
};

// Función de comparación para ordenar las asignaciones por menor costo
bool compararCosto(Asignacion& a, Asignacion& b) {
    return a.costo < b.costo;
}

void asignarTareas(int n, vector<vector<int>>& costos) {
    vector<Asignacion> asignaciones;

    // Generar todas las posibles asignaciones
    for (int trabajador = 0; trabajador < n; trabajador++) {
        for (int tarea = 0; tarea < n; tarea++) {
            Asignacion asignacion;
            asignacion.trabajador = trabajador;
            asignacion.tarea = tarea;
            asignacion.costo = costos[trabajador][tarea];
            asignaciones.push_back(asignacion);
        }
    }

    // Ordenar las asignaciones por menor costo
    sort(asignaciones.begin(), asignaciones.end(), compararCosto);

    vector<int> tareasTrabajador(n, -1); // Vector para almacenar las tareas asignadas a cada trabajador
    vector<int> trabajadorTarea(n, -1); // Vector para almacenar los trabajadores asignados a cada tarea

    // Asignar tareas a los trabajadores según el orden de menor costo
    for (int i = 0; i < asignaciones.size(); i++) {
        int trabajador = asignaciones[i].trabajador;
        int tarea = asignaciones[i].tarea;
        // Si tanto el trabajador como la tarea están disponibles, se realiza la asignación
        if (tareasTrabajador[trabajador] == -1 && trabajadorTarea[tarea] == -1) {
            tareasTrabajador[trabajador] = tarea;
            trabajadorTarea[tarea] = trabajador;
        }
    }

    // Imprimir la asignación resultante
    cout<<"Asignacion de tareas:\n";
    for (int trabajador = 0; trabajador < n; trabajador++) {
        cout<<"Trabajador "<<trabajador + 1<<" -> Tarea "<<tareasTrabajador[trabajador] + 1<<"\n";
    }
}

int main() {
    int n; // Número de trabajadores y tareas
    cout<<"Ingrese el numero de trabajadores y tareas: ";
    cin >> n;

    vector<vector<int>> costos(n, vector<int>(n));

    // Ingresar los costos de asignación
    cout<<"Ingrese los costos de asignacion:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout<<"Costo de asignar tarea "<<j + 1<<" al trabajador "<<i + 1<<": ";
            cin >> costos[i][j];
        }
    }

    asignarTareas(n, costos);

    return 0;
}
