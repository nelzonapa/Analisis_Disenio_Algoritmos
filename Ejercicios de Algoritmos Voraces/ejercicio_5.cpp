/*
5. Supongamos que un único camarero debe atender a n clientes de un restaurante
y atender al cliente i-ésimo requiere un tiempo ti. La satisfacción de un cliente es
inversamente proporcional a su tiempo de espera y la propina que recibirá el
camarero dependerá de la satisfacción del cliente (si el cliente i espera wi
minutos, la propina que dará al camarero será pi=1/wi).
a. Diseñe un algoritmo greedy para maximizar las ganancias del camarero y
demuestre si el algoritmo diseñado devuelve siempre la solución óptima
[o encuentre un contraejemplo que muestre que no lo hace].
b. Nuestro restaurante toma la decisión de contratar a más camareros para
reducir el tiempo de espera de sus clientes. Modifique el algoritmo
anterior para maximizar las propinas de k camareros.

*/

/*Usando planificación de tareas*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Cliente {
    int tiempoAtencion;
};

// Función de comparación para ordenar los clientes por tiempo de atención de forma descendente
bool compararClientes(Cliente& a, Cliente& b) {
    return a.tiempoAtencion > b.tiempoAtencion;
}

// Función para maximizar las ganancias del camarero atendiendo a todos los clientes
double maximizarGananciasCamarero(vector<Cliente>& clientes) {
    sort(clientes.begin(), clientes.end(), compararClientes);

    int tiempoTotalEspera = 0;
    double gananciasCamarero = 0.0;

    // Calcular las ganancias acumuladas del camarero atendiendo a los clientes en el orden óptimo
    for (int i = 0; i < clientes.size(); i++) {
        tiempoTotalEspera += clientes[i].tiempoAtencion;
        double propina = 1.0 / tiempoTotalEspera; // La propina es inversamente proporcional al tiempo de espera acumulado
        gananciasCamarero += propina;
    }

    return gananciasCamarero;
}

// Función para maximizar las ganancias de los camareros atendiendo a los clientes con k camareros
double maximizarPropinasCamareros(vector<Cliente>& clientes, int k) {
    sort(clientes.begin(), clientes.end(), compararClientes);

    vector<int> tiemposEsperaCamareros(k, 0);
    double gananciasTotales = 0.0;

    // Asignar cada cliente al camarero con el menor tiempo de espera acumulado
    for (int i = 0; i < clientes.size(); i++) {
        int menorTiempoEspera = tiemposEsperaCamareros[0];
        int idxMenorTiempoEspera = 0;

        // Encontrar el camarero con el menor tiempo de espera acumulado
        for (int j = 1; j < k; j++) {
            if (tiemposEsperaCamareros[j] < menorTiempoEspera) {
                menorTiempoEspera = tiemposEsperaCamareros[j];
                idxMenorTiempoEspera = j;
            }
        }

        // Asignar el cliente al camarero con el menor tiempo de espera y actualizar su tiempo de espera acumulado
        tiemposEsperaCamareros[idxMenorTiempoEspera] += clientes[i].tiempoAtencion;
        double propina = 1.0 / tiemposEsperaCamareros[idxMenorTiempoEspera]; // La propina es inversamente proporcional al tiempo de espera acumulado
        gananciasTotales += propina;
    }

    return gananciasTotales;
}

int main() {
    vector<Cliente> clientes = {
        {5},
        {3},
        {7},
        {2},
        {6}
    };

    // Obtener ganancias del camarero único atendiendo a los clientes en el orden óptimo
    double gananciasCamarero = maximizarGananciasCamarero(clientes);

    // Obtener ganancias de los camareros (con k=2) atendiendo a los clientes en el orden óptimo para maximizar las propinas
    double gananciasCamareros = maximizarPropinasCamareros(clientes, 2);

    // Mostrar las ganancias obtenidas
    cout << "Ganancias del camarero unico: " << gananciasCamarero << endl;
    cout << "Ganancias de los camareros (k = 2): " << gananciasCamareros << endl;

    return 0;
}

