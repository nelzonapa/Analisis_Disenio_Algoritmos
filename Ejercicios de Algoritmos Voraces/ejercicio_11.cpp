/*
11. Deseamos optimizar el uso de las aulas de un centro educativo. Dados un
conjunto de aulas y un conjunto de clases con un horario preestablecido (la clase
i empieza a la hora "si" y termina a la hora "fi"), diseñe un algoritmo greedy que
minimice el número de aulas necesario para impartir toda la docencia del centro.
*/

/*
algoritmo de planeación de tareas
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Clase {
    int inicio;
    int fin;
};

bool num_aula(int aula){
    return aula != 0;
}

bool compararClases(Clase& clase1, Clase& clase2) {
    return clase1.fin < clase2.fin;
}

int minimizarAulas(vector<Clase>& clases) {
    // Ordenar las clases por el tiempo de finalización en orden ascendente
    sort(clases.begin(), clases.end(), compararClases);

    vector<int> aulas(clases.size(), 0);  // Inicialmente todas las aulas están vacías

    for (int i = 0; i < clases.size(); i++) {
        int aulaDisponible = -1;

        // Buscar un aula disponible para la clase actual
        for (int j = 0; j <= i; j++) {
            if (aulas[j] <= clases[i].inicio) {
                aulaDisponible = j;
                break;
            }
        }

        if (aulaDisponible == -1) {
            // No se encontró un aula disponible, se necesita una nueva aula
            aulas[i] = clases[i].fin;
        } else {
            // Se asigna la clase al aula disponible
            aulas[aulaDisponible] = clases[i].fin;
        }
    }

    // Contar el número de aulas utilizadas
    int numAulas = count_if(aulas.begin(), aulas.end(), num_aula);

    return numAulas;
}

int main() {
    // Ejemplo de uso
    vector<Clase> clases = {{9, 10}, {10, 12}, {11, 13}, {14, 15}, {14, 16}};
    int numAulas = minimizarAulas(clases);
    cout << "Numero minimo de aulas necesarias: " << numAulas << endl;

    return 0;
}
