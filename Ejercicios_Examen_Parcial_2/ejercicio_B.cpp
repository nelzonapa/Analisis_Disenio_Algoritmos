/*
Given a set of points in a two dimensional space, you will have to find the distance between the closest
two points.
Input
The input file contains several sets of input. Each set of input starts with an integer N (0 ≤ N ≤ 10000),
which denotes the number of points in this set. The next N line contains the coordinates of N two-
dimensional points. The first of the two numbers denotes the X-coordinate and the latter denotes the
Y -coordinate. The input is terminated by a set whose N = 0. This set should not be processed. The
value of the coordinates will be less than 40000 and non-negative.
Output
For each set of input produce a single line of output containing a floating point number (with four
digits after the decimal point) which denotes the distance between the closest two points. If there is
no such two points in the input whose distance is less than 10000, print the line ‘INFINITY’.
Sample Input
3
0 0
10000 10000
20000 20000
5
0 2
6 67
43 71
39 107
189 140
0
Sample Output
INFINITY
36.2215
*/
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

struct punto
{
    double x;
    double y;
};

// Función de comparación para ordenar los puntos según la coordenada x de forma ascendente
bool cmp(punto a, punto b)
{
    return a.x < b.x;
}

// Función para calcular la distancia entre dos puntos utilizando el teorema de Pitágoras
double distancia(punto a, punto b);

// Función recursiva para dividir y conquistar el conjunto de puntos
double dividir(punto a[], int bajo, int alto);

// Función para combinar las soluciones de los subconjuntos izquierdo y derecho
double combinar(punto a[], int bajo, int medio, int alto, double min_izquierda, double min_derecha);

int main()
{
    int N;
    punto puntos[10001];

    while (scanf("%d", &N))
    {
        if (N == 0)
            break;

        // Lectura de los puntos
        for (int i = 0; i < N; i++)
            scanf("%lf %lf", &puntos[i].x, &puntos[i].y);

        // Ordenar los puntos según la coordenada x
        sort(puntos, puntos + N, cmp);

        // Calcular la distancia mínima utilizando el enfoque de divide y conquista
        double distancia_minima = dividir(puntos, 0, N - 1);

        // Imprimir el resultado
        if (distancia_minima >= 10000.0)
            printf("INFINITY\n");
        else
            printf("%.4lf\n", distancia_minima);
    }

    return 0;
}

// Función para calcular la distancia entre dos puntos utilizando el teorema de Pitágoras
double distancia(punto a, punto b)
{
    return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

// Función recursiva para dividir y conquistar el conjunto de puntos
double dividir(punto a[], int bajo, int alto)
{
    if (bajo >= alto)
        return 99999; // Cuando solo queda un punto, se retorna infinito como caso base

    int medio = (bajo + alto) / 2;

    // Calcular la distancia mínima en el subconjunto izquierdo
    double min_izquierda = dividir(a, bajo, medio);

    // Calcular la distancia mínima en el subconjunto derecho
    double min_derecha = dividir(a, medio + 1, alto);

    // Combinar las soluciones de los subconjuntos izquierdo y derecho
    return combinar(a, bajo, medio, alto, min_izquierda, min_derecha);
}

// Función para combinar las soluciones de los subconjuntos izquierdo y derecho
double combinar(punto a[], int bajo, int medio, int alto, double min_izquierda, double min_derecha)
{
    // Determinar la distancia mínima entre las soluciones de los subconjuntos izquierdo y derecho
    double d = (min_izquierda < min_derecha) ? min_izquierda : min_derecha;

    // Calcular la línea vertical que divide el conjunto izquierdo y derecho
    double linea = (a[medio].x + a[medio + 1].x) * 0.5;

    // Inicializar la distancia mínima en el conjunto combinado
    double min_D = d;

    // Verificar si hay puntos cercanos a la línea de separación que pueden formar una distancia menor
    for (int i = medio + 1; a[i].x < linea + d && i <= alto; i++)
    {
        for (int j = medio; a[j].x > linea - d && j >= bajo; j--)
        {
            // Calcular la distancia entre los puntos i y j
            double temp = distancia(a[i], a[j]);

            // Actualizar la distancia mínima si se encuentra una distancia menor
            if (temp < min_D)
                min_D = temp;
        }
    }

    // Retornar la distancia mínima en el conjunto combinado
    return min_D;
}
