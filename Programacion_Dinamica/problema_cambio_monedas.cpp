/*
Problema de Cambio de monedas - Programación Dinámica
Alumno: Nelzon Apaza
*/
#include <iostream>
#include <vector>
using namespace std;
int min(int a, int b);
int cambioMonedas(int P, vector<int>& monedas);

int main() 
{
    vector<int> monedas = {1, 4, 6}; // Tipos de monedas
    int P = 8; // Cantidad a obtener
    int numMonedas = cambioMonedas(P, monedas);
    cout<<"El numero minimo de monedas requeridas es: "<<numMonedas<<endl;

    return 0;
}

// Función para encontrar el mínimo entre dos valores
int min(int a, int b) 
{
    return (a < b) ? a : b;
}

// Función que implementa el algoritmo de cambio de monedas
int cambioMonedas(int P, vector<int>& monedas) 
{
    int n = monedas.size();
    vector<int> vect_valores(P + 1, INT16_MAX); // Inicializamos el vector vect_valores con valores infinitos (INT16_MAX)
    vect_valores[0] = 0; // La cantidad 0 se puede obtener con 0 monedas

    for (int i = 1; i <= P; i++) {
        for (int j = 0; j < n; j++) {
            if (monedas[j] <= i) {
                // Si el valor de la moneda es menor o igual a la cantidad actual
                // opciones: tomar la moneda o no tomarla
                vect_valores[i] = min(vect_valores[i], 1 + vect_valores[i - monedas[j]]);
            }
        }
    }

    // El resultado final se encuentra en la última posición del vector vect_valores
    return vect_valores[P];
}

