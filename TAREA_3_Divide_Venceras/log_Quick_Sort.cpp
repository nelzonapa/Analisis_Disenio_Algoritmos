
#include <iostream>
#include <vector>

/*Implementación del Quick Sort*/
using namespace std;

// Función para intercambiar dos elementos
void swap(int& a, int& b)
{
    int temp=a;
    a=b;
    b=temp;
}

// Función para colocar el pivote en la posición correcta y dividir el arreglo en dos subarreglos
int partition(vector<int>& arr, int low, int high)
{
    int pivot=arr[high]; // seleccionamos el último elemento como pivote
    int i=(low - 1); // índice del elemento más pequeño

    for (int j=low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// Función recursiva para aplicar Quick Sort en un arreglo
void quickSort(vector<int>& arr, int low, int high)
{
    if (low < high)
    {
        // Obtener la posición del pivote
        int pi=partition(arr, low, high);

        // Ordenar los elementos antes y después del pivote
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función para imprimir el arreglo
void printArray(const vector<int>& arr)
{
    for (int i=0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr={ 64, 25, 12, 22, 11 };
    int n=arr.size();
    cout<<"Arreglo original: ";
    printArray(arr);
    quickSort(arr, 0, n - 1);
    cout<<"Arreglo ordenado: ";
    printArray(arr);
    return 0;
}
