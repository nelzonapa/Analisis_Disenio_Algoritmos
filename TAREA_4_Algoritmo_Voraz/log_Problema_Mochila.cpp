/* LOGARITMO MOCHILA EJEMPLO*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Objeto {
    int peso;
    int valor;
};

bool compararObjetos( Objeto& objeto1,  Objeto& objeto2) {
    // Comparar los objetos según la relación valor/peso de forma descendente
    double valorPorPeso1 = static_cast<double>(objeto1.valor) / objeto1.peso;
    double valorPorPeso2 = static_cast<double>(objeto2.valor) / objeto2.peso;
    return valorPorPeso1 > valorPorPeso2;
}

double mochilaVoraz( vector<Objeto>& objetos, int capacidad) {
    vector<Objeto> objetosOrdenados = objetos;
    sort(objetosOrdenados.begin(), objetosOrdenados.end(), compararObjetos);

    double valorTotal = 0.0;
    int capacidadActual = capacidad;

    for ( Objeto& objeto : objetosOrdenados) {
        if (capacidadActual >= objeto.peso) {
            // Se puede añadir el objeto completo a la mochila
            valorTotal += objeto.valor;
            capacidadActual -= objeto.peso;
        } else {
            // Solo se añade una fracción del objeto a la mochila para aprovechar el espacio disponible
            double fraccion = static_cast<double>(capacidadActual) / objeto.peso;
            valorTotal += fraccion * objeto.valor;
            break;
        }
    }

    return valorTotal;
}

int main() {
    vector<Objeto> objetos = {{2, 10},{5, 25},{10, 40},{3, 12},{7, 30}};
    int capacidad = 15;
    double valorMaximo = mochilaVoraz(objetos, capacidad);
    cout<<"Valor maximo obtenido: "<<valorMaximo<<endl;

    return 0;
}
