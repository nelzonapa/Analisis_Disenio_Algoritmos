/*

- TAREA:
Algoritmo para: Arbol combinatorio para mochila 

*/

#include <iostream>
#include <vector>
using namespace std;

// Número de objetos disponibles
const int numObjetos = 4; 
const int mochila = 7; // Capacidad de la mochila

vector<int> pesosObject = {5, 6, 7, 8};
vector<int> beneficiosObject = {9, 10, 11, 12};

vector<int> solActual(numObjetos, 0);
vector<int> solOptima(numObjetos, 0);

int valueOptimoAct = 0;
int pesoActual = 0;
int benefiActual = 0;
int count = 1;

void GenerarArbolCombinatorio(int nivel) 
{
    if (nivel == numObjetos) 
    {
        // Verificar si se alcanzó la solución esperada, que esta sea completa
        if (pesoActual <= mochila && benefiActual > valueOptimoAct) 
        {
            valueOptimoAct = benefiActual;
            solOptima = solActual;
        }

        cout << count << " => ";
        count++;

        for (int i = 0; i < solActual.size(); i++) 
        {
            if (solActual[i] == 1) 
            {
                cout << i + 1 << " ";
            }
        }
        cout << endl;

        return;
    }

    // Generar combinaciones con el objeto no seleccionado (0)
    solActual[nivel] = 0;
    GenerarArbolCombinatorio(nivel + 1);

    // Generar combinaciones con el objeto seleccionado (1)
    solActual[nivel] = 1;
    pesoActual += pesosObject[nivel];
    benefiActual += beneficiosObject[nivel];
    GenerarArbolCombinatorio(nivel + 1);

    // Deshacer cambios para volver atrás en las combinaciones
    pesoActual -= pesosObject[nivel];
    benefiActual -= beneficiosObject[nivel];
}

int main() {
    GenerarArbolCombinatorio(0);
    cout << "La solucion optima es: ";
    for (int i = 0; i < numObjetos; i++) 
    {
        if (solOptima[i] == 1) 
        {
            cout << "Obj " << i + 1 << " ";
        }
    }
    cout << "\nEl Valor optimo es: " << valueOptimoAct << endl;
    return 0;
}