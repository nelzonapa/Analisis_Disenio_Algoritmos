/*
Median plays an important role in the world of statistics. By definition, it is a value which divides
an array into two equal parts. In this problem you are to determine the current median of some long
integers. Suppose, we have five numbers {1,3,6,2,7}. In this case, 3 is the median as it has exactly two
numbers on its each side. {1,2} and {6,7}. If there are even number of values like {1,3,6,2,7,8}, only
one value cannot split this array into equal two parts, so we consider the average of the middle values
{3,6}. Thus, the median will be (3+6)/2 = 4.5. In this problem, you have to print only the integer
part, not the fractional. As a result, according to this problem, the median will be 4 !
Input
The input file consists of series of integers X (0 ≤ X < 231) and total number of integers N is less than
10000. The numbers may have leading or trailing spaces.
Output
For each input print the current value of the median.
Sample Input
1
3
4
60
70
50
2
Sample Output
1
2
3
3
4
27
4
*/
#include <iostream>

void ordenamientoInsercion();

using namespace std;

int arreglo[10000]; // arreglo
int indice;

int main()
{
    int n, i, posicion, mediana;
    indice = 0;

    while (scanf("%ld", &n) == 1)
    {
        if (n == 0)
            break;

        mediana = 0;
        indice = indice + 1;
        arreglo[indice] = n;

        ordenamientoInsercion();

        if (indice % 2 == 0)
        {
            posicion = indice / 2;
            mediana = (arreglo[posicion] + arreglo[posicion + 1]) / 2;
        }
        else
        {
            posicion = (indice + 1) / 2;
            mediana = arreglo[posicion];
        }

        printf("%ld\n", mediana);
    }

    return 0;
}

void ordenamientoInsercion()
{
    int k, ptr, temp, j;

    if (indice < 2)
        return;

    for (k = 2; k <= indice; k++)
    {
        temp = arreglo[k];
        ptr = k - 1;

        // Inserta el elemento en la posición correcta dentro del subarreglo ordenado
        while (temp < arreglo[ptr])
        {
            arreglo[ptr + 1] = arreglo[ptr];
            ptr = ptr - 1;
        }

        arreglo[ptr + 1] = temp;
    }
}
