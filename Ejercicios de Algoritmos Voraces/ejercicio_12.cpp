/*
12. Igual que antes, tenemos un problema de asignación de recursos en el que una
tarea i requiere "ti" unidades de tiempo y ha de terminar, como muy tarde, en el
instante de tiempo "di". Ahora bien, podemos escoger la hora de inicio de la tarea
"si" de tal forma que fi=si+ti. Diseñe un algoritmo greedy que minimice el retraso
máximo con el que se completa una tarea (esto es, max{0,fi-di}).
*/
/*
Logaritmo de planificación de tareas
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Estructura para representar una tarea
struct Tarea {
    int tiempoInicio;       // Hora de inicio de la tarea
    int tiempoDuracion;     // Duración de la tarea
    int tiempoFinalizacion;     // Hora de finalización de la tarea (calculada)
    int tiempoLimite;       // Hora límite para terminar la tarea
};

// Función de comparación para ordenar las tareas por tiempo de finalización
bool compararPorFinalizacion( Tarea& tarea1,  Tarea& tarea2) {
    return tarea1.tiempoFinalizacion < tarea2.tiempoFinalizacion;
}

// Función para calcular el retraso máximo
int calcularRetrasoMaximo(vector<Tarea>& tareas) {
    // Ordenar las tareas por tiempo de finalización
    sort(tareas.begin(), tareas.end(), compararPorFinalizacion);
    
    int maxRetraso = 0;
    int tiempoActual = 0;
    
    // Iterar sobre cada tarea en orden de finalización
    for ( auto& tarea : tareas) {
        // Actualizar el tiempo actual al máximo entre el tiempo actual y el tiempo de inicio de la tarea
        tiempoActual = max(tiempoActual, tarea.tiempoInicio);
        
        // Calcular el retraso de la tarea (si es mayor a cero)
        int retraso = max(0, tiempoActual + tarea.tiempoDuracion - tarea.tiempoLimite);
        
        // Actualizar el máximo retraso si corresponde
        maxRetraso = max(maxRetraso, retraso);
        
        // Actualizar el tiempo actual sumando la duración de la tarea
        tiempoActual += tarea.tiempoDuracion;
    }
    
    return maxRetraso;
}

int main() {
    // Ejemplo de uso del algoritmo
    vector<Tarea> tareas = {
        {1, 4, 0, 4},
        {2, 3, 0, 5},
        {4, 2, 0, 6},
        {6, 5, 0, 7}
    };
    
    // Calcular el retraso máximo
    int retrasoMaximo = calcularRetrasoMaximo(tareas);
    
    // Imprimir el resultado
    cout << "Retraso maximo: " << retrasoMaximo << endl;
    
    return 0;
}
