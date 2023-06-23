#include <iostream>
#include <vector>

// Función para combinar dos subarreglos ordenados en uno solo
void merge(std::vector<int>& arr, int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;

    // Crear arreglos temporales
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Copiar datos a los arreglos temporales
    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[middle + 1 + j];

    // Combinar los arreglos temporales en uno solo en orden ascendente
    int i = 0; // Índice inicial del primer subarreglo
    int j = 0; // Índice inicial del segundo subarreglo
    int k = left; // Índice inicial del arreglo combinado

    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            ++i;
        }
        else
        {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Copiar los elementos restantes del subarreglo izquierdo, si hay alguno
    while (i < n1)
    {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    // Copiar los elementos restantes del subarreglo derecho, si hay alguno
    while (j < n2)
    {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }
}

// Función principal del algoritmo Merge Sort
void mergeSort(std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        // Dividir el arreglo en dos partes y aplicar Merge Sort en cada parte
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);

        // Combinar las dos partes ordenadas
        merge(arr, left, middle, right);
    }
}

// Función de utilidad para imprimir un arreglo
void printArray(const std::vector<int>& arr)
{
    int size = arr.size();
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = { 12, 11, 13, 5, 6, 7 };
    int size = arr.size();

    std::cout << "Arreglo original: ";
    printArray(arr);

    mergeSort(arr, 0, size - 1);

    std::cout << "Arreglo ordenado: ";
    printArray(arr);

    return 0;
}
