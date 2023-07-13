/*
Given several segments of line (int the X axis) with coordinates [Li, Ri]. You are to choose the minimal
amount of them, such they would completely cover the segment [0, M ].
Input
The first line is the number of test cases, followed by a blank line.
Each test case in the input should contains an integer M (1 ≤ M ≤ 5000), followed by pairs “Li Ri”
(|Li|, |Ri| ≤ 50000, i ≤ 100000), each on a separate line. Each test case of input is terminated by pair
‘0 0’.
Each test case will be separated by a single line.
Output
For each test case, in the first line of output your programm should print the minimal number of line
segments which can cover segment [0, M ]. In the following lines, the coordinates of segments, sorted
by their left end (Li), should be printed in the same format as in the input. Pair ‘0 0’ should not be
printed. If [0, M ] can not be covered by given line segments, your programm should print ‘0’ (without
quotes).
Print a blank line between the outputs for two consecutive test cases.
Sample Input
2
1
-1 0
-5 -3
2 5
0 0
1
-1 0
0 1
0 0
Sample Output
0
1
0 1
*/

#include <iostream>
#include <algorithm>

using namespace std;

const int maxN = 100000 + 5;
int numCasos; // Número de casos de prueba
int limiteDerecho; // Valor del límite derecho del caso de prueba
int numIntervalos; // Número de intervalos válidos
int listaRespuestas[maxN]; // Lista para almacenar las respuestas

struct Intervalo {
    int izquierda, derecha;
};

Intervalo intervalo[maxN];

bool compararIntervalos(const Intervalo& lhs, const Intervalo& rhs) {
    return lhs.izquierda < rhs.izquierda;
}

int main() {
    cin >> numCasos;

    while (numCasos--) {
        cin >> limiteDerecho;
        numIntervalos = 0;

        int tmpX, tmpY;
        while (cin >> tmpX >> tmpY) {
            if (tmpX == 0 && tmpY == 0)
                break;

            intervalo[numIntervalos].izquierda = tmpX;
            intervalo[numIntervalos++].derecha = tmpY;
        }

        // Ordenar los intervalos según la coordenada izquierda de forma ascendente
        sort(intervalo, intervalo + numIntervalos, compararIntervalos);

        int cobertura = 0, actual = 0, siguienteCobertura, siguienteCoberturaNum, i, ans = 0;
        bool cubierto = false;

        // Realizar la selección y factibilidad de los intervalos
        while (actual < numIntervalos) {
            siguienteCobertura = cobertura;
            i = actual;

            // Buscar el intervalo que tiene la mayor cobertura
            while (i < numIntervalos && intervalo[i].izquierda <= cobertura) {
                if (intervalo[i].derecha > siguienteCobertura) {
                    siguienteCobertura = intervalo[i].derecha;
                    siguienteCoberturaNum = i;
                }
                ++i;
            }

            // Si no se encontró ningún intervalo válido, se termina el proceso
            if (i == actual)
                break;

            cobertura = siguienteCobertura;
            listaRespuestas[ans++] = siguienteCoberturaNum;
            actual = i;

            // Si se alcanza o supera el límite derecho, se marca como cubierto y se finaliza el proceso
            if (cobertura >= limiteDerecho) {
                cubierto = true;
                break;
            }
        }

        // Imprimir los resultados
        if (cubierto) {
            cout << ans << endl;
            for (int j = 0; j < ans; ++j) {
                cout << intervalo[listaRespuestas[j]].izquierda << " " << intervalo[listaRespuestas[j]].derecha << endl;
            }
        } else {
            cout << "0" << endl;
        }

        if (numCasos > 0)
            cout << endl;
    }

    return 0;
}
