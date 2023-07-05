/*
10. Nuestra empresa desarrolla software para terminales de puntos de venta [TPV] y
desea que le añadamos la siguiente funcionalidad a nuestro sistema:
a. En su versión para máquinas expendedoras, se pretende minimizar el
número de monedas empleado para darle el cambio al cliente. Diseñe un
algoritmo greedy que devuelva un número mínimo de monedas (de 0.01,
0.02, 0.05, 0.10, 0.20, 0.50 y 1 euro).
b. Nuestra empresa también distribuye máquinas expendedoras de sellos de
correos (de 0.54, 0.32, 0.17 y 0.01 euros) y decidimos reutilizar nuestro
algoritmo greedy para decidir qué sellos ha de devolver la máquina.
Demuestre que el algoritmo greedy no proporciona necesariamente una
solución óptima, aun disponiendo de un suministro inagotable de sellos
de cada valor.
*/

/*
algoritmo voraz de cambio de moneda
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool comparar_moneda(float moneda1,float moneda2){
    return moneda1>moneda2;
}

// Función para dar el cambio utilizando el algoritmo voraz de cambio de moneda
void darCambio(float cambio, vector<float>& monedas) {
    //numero de moneda usada para dar el cambio
    vector<int> contador_x(monedas.size(), 0);    

    // Ordena las monedas de monedas de mayor a menor valor
    sort(monedas.begin(), monedas.end(), comparar_moneda);//si MONEDA 1 > MONEDA 2

    for (int i = 0; i < monedas.size(); ++i) {
        while (cambio >= monedas[i]) {
            cambio=cambio-monedas[i];
            contador_x[i]=contador_x[i]+1;
        }
    }

    // Mostrar el resultado
    for (int i = 0; i < monedas.size(); ++i) {
        if (contador_x[i] > 0) {
            cout<<"Monedas de "<<monedas[i]<<" euros: "<<contador_x[i]<<endl;
        }
    }
}

int main() {
    float cambio;
    cout<<"Ingrese el cambio a dar: ";
    cin>>cambio;
    vector<float> monedas = {1.0, 0.5, 0.20, 0.10, 0.05, 0.02, 0.01};
    darCambio(cambio, monedas);

    return 0;
}
