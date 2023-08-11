/*
PUNTOS ADICIONALES

Se tienen n unidades de un recurso que deben asignarse a r proyectos. Si se
asignan j, 0≤j≤n, unidades al proyecto i, se obtiene un beneficio Ni,j.
Diseñe un algoritmo que asigne recursos a los r proyectos maximizando el
beneficio total obtenido.
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Proyecto {
    int beneficio;
    int unidades;
};

// Función para comparar proyectos por su ratio de beneficio a unidades
bool compararPorRatio(const Proyecto &a, const Proyecto &b) {
    return static_cast<double>(a.beneficio) / a.unidades > static_cast<double>(b.beneficio) / b.unidades;
}

// Función para calcular el beneficio máximo utilizando el enfoque de ramificación y poda
int beneficioMaximo(int n, int r, vector<Proyecto> &proyectos, int indice, int unidadesRestantes, int beneficioActual) {
    // Si se han explorado todos los proyectos o se han utilizado todas las unidades
    if (indice == r || unidadesRestantes == 0) {
        return beneficioActual;
    }

    // Calcular el beneficio si no se selecciona el proyecto actual
    int beneficioSinSeleccionar = beneficioMaximo(n, r, proyectos, indice + 1, unidadesRestantes, beneficioActual);

    // Calcular el beneficio si se selecciona el proyecto actual
    int beneficioSeleccionar = 0;
    if (proyectos[indice].unidades <= unidadesRestantes) {
        beneficioSeleccionar = beneficioMaximo(n, r, proyectos, indice + 1, unidadesRestantes - proyectos[indice].unidades, beneficioActual + proyectos[indice].beneficio);
    }

    // Devolver el máximo entre los beneficios de las dos opciones
    return max(beneficioSinSeleccionar, beneficioSeleccionar);
}

int main() {
    int n, r;
    cout << "Ingrese el numero de unidades de recurso: ";
    cin >> n;
    cout << "Ingrese el numero de proyectos: ";
    cin >> r;

    vector<Proyecto> proyectos(r);
    for (int i = 0; i < r; ++i) {
        cout << "Ingrese el beneficio y las unidades para el proyecto " << i + 1 << ": ";
        cin >> proyectos[i].beneficio >> proyectos[i].unidades;
    }

    // Ordenar proyectos por ratio beneficio/unidades
    sort(proyectos.begin(), proyectos.end(), compararPorRatio);

    // Calcular el beneficio total máximo
    int beneficioTotal = beneficioMaximo(n, r, proyectos, 0, n, 0);
    cout << "El beneficio total maximo obtenido es: " << beneficioTotal << endl;

    return 0;
}
