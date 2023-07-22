/*
Problema 0/1 mochila - Programación Dinámica
Alumno: Nelzon Apaza
*/
#include <iostream>
using namespace std;

int max(int a, int b);
int mochila_0_1(int M, int pesos[], int beneficios[], int n);

int main() {
    int n = 3; // Número de objetos
    int M = 6; // Capacidad máxima de la mochila
    int pesos[] = {2, 3, 4}; // Pesos de los objetos
    int beneficios[] = {1, 2, 5}; // Beneficios de los objetos
    int maxBeneficio = mochila_0_1(M, pesos, beneficios, n);

    cout<<"El beneficio maximo que se puede obtener es: "<<maxBeneficio<<endl;

    return 0;
}

// Función para encontrar el máximo entre dos valores
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Función que implementa el algoritmo de la mochila 0/1
int mochila_0_1(int M, int pesos[], int beneficios[], int n) {
    // Creamos una matriz para almacenar los resultados intermedios
    int matriz[n + 1][M + 1];

    // Llenamos la matriz de abajo hacia arriba
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= M; w++) {
            if (i == 0 || w == 0) {
                // Caso base: si no hay objetos o la capacidad es cero
                matriz[i][w] = 0;
            } else if (pesos[i - 1] <= w) {
                // Si el peso del objeto actual es menor o igual a la capacidad actual de la mochila
                // opciones: tomar el objeto o no tomarlo
                matriz[i][w] = max(beneficios[i - 1] + matriz[i - 1][w - pesos[i - 1]], matriz[i - 1][w]);
            } else {
                // Si el peso del objeto actual es mayor que la capacidad actual de la mochila
                // No tomamos el objeto actual y el beneficio es el mismo que en el paso anterior
                matriz[i][w] = matriz[i - 1][w];
            }
            // Imprimimos el estado actual de la matriz
            cout<<matriz[i][w]<<" ";
        }
        cout<<endl;
    }

    // El resultado final se encuentra en la última celda de la matriz
    return matriz[n][M];
}

