/*

1. Se tiene un buque mercante cuya capacidad de carga es de k toneladas y un
conjunto de contenedores c1, ..., cn cuyos pesos respectivos son p1, ..., pn
(expresados también en toneladas). Teniendo en cuenta que la capacidad del
buque es menor que la suma total de los pesos de los contenedores:
a. Diseñe un algoritmo que maximice el número de contenedores cargados.
b. Diseñe un algoritmo que intente maximizar el número de toneladas cargadas.

*/

/*Usando algoritmo de la mochila*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Contenedor {
    int peso;
};

// Función de comparación para ordenar los contenedores de forma descendente por peso
bool comparar_contenedores(Contenedor c1, Contenedor c2) {
    return c1.peso > c2.peso;
}

// Algoritmo para maximizar el número de contenedores cargados
int maximizar_num_contenedores(int capacidad, vector<Contenedor>& vec_contendores) {
    // Ordenar los contenedores en orden descendente por peso
    sort(vec_contendores.begin(), vec_contendores.end(), comparar_contenedores);    //usamos el sort de vector<>
    
    int contenedores_cargados = 0;
    int peso_actual = 0;
    int i = 0;
    
    // Iterar sobre los contenedores hasta que se llene la capacidad o no haya más contenedores
    while (peso_actual < capacidad && i < vec_contendores.size()) {
        if (peso_actual + vec_contendores[i].peso <= capacidad) {
            cout<<"contenedor: "<<i+1<<endl;
            peso_actual= peso_actual+ vec_contendores[i].peso;  //pone el peso
            contenedores_cargados++;    //Pone los contenedores cargados
        }
        i++;
    }
    cout<<"contenedores_cargados: "<<contenedores_cargados<<endl;
    
    return contenedores_cargados;
}

// Algoritmo para maximizar el número de toneladas cargadas
int maximizar_num_toneladas(int capacidad, vector<Contenedor>& vec_contendores) {
    // Ordenar los contenedores en orden descendente por peso
    sort(vec_contendores.begin(), vec_contendores.end(), comparar_contenedores);    //usamos el sort de vector<>
    
    int contenedores_cargados=0;
    int peso_actual = 0;
    int i = 0;
    
    // Iterar sobre los contenedores hasta que se llene la capacidad o no haya más contenedores
    while (peso_actual < capacidad && i < vec_contendores.size()) {
        if (peso_actual + vec_contendores[i].peso <= capacidad) {
            cout<<"contenedor: "<<i+1<<endl;
            peso_actual=peso_actual+ vec_contendores[i].peso;   //Va acumulando el peso
            contenedores_cargados++;
        }
        i++;
    }
    cout<<"contenedores_cargados: "<<contenedores_cargados<<endl;

    return peso_actual;
}

int main() {
    int capacidad = 20; // Capacidad del buque en toneladas
    
    vector<Contenedor> vec_contendores = {{2}, {14}, {3}, {1}, {10}}; // Ejemplo de contenedores y sus pesos
    
    // Parte a: Maximizar el número de contenedores cargados
    int contenedores_cargados = maximizar_num_contenedores(capacidad, vec_contendores);
    cout<<"Numero de contenedores cargados: "<<contenedores_cargados<<endl;
    
    // Parte b: Maximizar el número de toneladas cargadas
    int peso_cargado = maximizar_num_toneladas(capacidad, vec_contendores);
    cout<<"Numero de toneladas cargadas: "<<peso_cargado<<endl;
    
    return 0;
}
