/*
2. Sean n programas P1, ..., Pn que hay que almacenar en un disco. El programa Pi
requiere Si megabytes de espacio y la capacidad del disco es D megabytes, 
siendo D < ΣSi. Resuelva las siguientes cuestiones:

a. Diseñe un algoritmo greedy que maximice el número de programas
almacenados en el disco (existe un algoritmo que proporciona una
solución óptima).
b. Diseñe un algoritmo greedy que intente aprovechar al máximo la
capacidad del disco (demuestre que podemos utilizar un algoritmo
greedy que seleccione los programas por orden no creciente para obtener
la solución exacta o encuentre un contraejemplo de lo contrario).
*/
/*Algoritmo voraz de Mochila*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Programa {   //Suamos un struct simple
    int tamano;
};

// Función de comparación para ordenar los programas de forma descendente por tamaño
bool comparar(Programa p1, Programa p2) {
    return p1.tamano > p2.tamano;
}

// Algoritmo voraz para maximizar el número de programas almacenados en el disco
int maximizarProgramas(vector<Programa>& programas, int capacidadDisco) {
    // Ordenar los programas en orden descendente por tamaño
    sort(programas.begin(), programas.end(), comparar);//ordenamos comparando
    
    int tamanoTotal = 0;
    int programasAlmacenados = 0;
    
    // Iterar sobre los programas hasta que se llene la capacidad del disco o no haya más programas
    for (const Programa& programa : programas) {
        if (tamanoTotal + programa.tamano <= capacidadDisco) {
            tamanoTotal += programa.tamano;
            programasAlmacenados++;
        }
    }
    
    return programasAlmacenados;
}

// Algoritmo voraz para aprovechar al máximo la capacidad del disco
int aprovecharCapacidad(vector<Programa>& programas, int capacidadDisco) {
    // Ordenar los programas en orden descendente por tamaño
    sort(programas.begin(), programas.end(), comparar);//ordenamos comparando
    
    int tamanoTotal = 0;
    
    // Iterar sobre los programas hasta que se llene la capacidad del disco o no haya más programas
    for (const Programa& programa : programas) {
        if (tamanoTotal + programa.tamano <= capacidadDisco) {
            tamanoTotal += programa.tamano;
        }
    }
    
    return tamanoTotal;
}

int main() {
    int capacidadDisco = 10; // Capacidad del disco en megabytes
    
    vector<Programa> programas = {{3}, {5}, {2}, {4}, {1}}; // Ejemplo de programas y sus tamaños
    
    int opcion;
    
    do {
        cout<<"Menú:\n";
        cout<<"1. Maximizar el numero de programas almacenados en el disco\n";
        cout<<"2. Aprovechar al maximo la capacidad del disco\n";
        cout<<"0. Salir\n";
        cout<<"Ingrese su elección: ";
        cin >> opcion;
        
        switch (opcion) {
            case 1: {
                int programasAlmacenados = maximizarProgramas(programas, capacidadDisco);
                cout<<"Numero de programas almacenados: "<<programasAlmacenados<<endl;
                break;
            }
            case 2: {
                int capacidadUtilizada = aprovecharCapacidad(programas, capacidadDisco);
                cout<<"Capacidad utilizada del disco: "<<capacidadUtilizada<<" megabytes"<<endl;
                break;
            }
            case 0:
                cout<<"Saliendo del programa...\n";
                break;
            default:
                cout<<"Opcion inválida. Por favor, seleccione una opcion válida.\n";
                break;
        }
        
        cout<<endl;
        
    } while (opcion != 0);
    
    return 0;
}
