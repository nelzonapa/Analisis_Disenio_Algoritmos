#include <iostream>
#include <vector>
/*Implementación posible de Merge Sort*/
using namespace std;

// Función para combinar dos subarreglos ordenados en uno solo
void Merge(vector<int>& arr, int izq, int medio, int dere)
{
    int n1=medio-izq + 1;
    int n2=dere-medio;

    // Crear arreglos temporales
    vector<int> izqArr(n1);
    vector<int> dereArr(n2);

    // Copiar datos a los arreglos temporales
    for (int i=0; i<n1; ++i)
        izqArr[i]=arr[izq + i];
    for (int j=0; j<n2; ++j)
        dereArr[j]=arr[medio + 1 + j];

    // Combinar los arreglos temporales en uno solo en orden ascendente
    int i=0; // Índice inicial del primer subarreglo
    int j=0; // Índice inicial del segundo subarreglo
    int k=izq; // Índice inicial del arreglo combinado

    while (i<n1 && j<n2)
    {
        if (izqArr[i] <= dereArr[j])
        {
            arr[k]=izqArr[i];
            ++i;
        }
        else
        {
            arr[k]=dereArr[j];
            ++j;
        }
        ++k;
    }

    // Copiar los elementos restantes del subarreglo izquierdo, si hay alguno
    while (i<n1)
    {
        arr[k]=izqArr[i];
        ++i;
        ++k;
    }

    // Copiar los elementos restantes del subarreglo derecho, si hay alguno
    while (j<n2)
    {
        arr[k]=dereArr[j];
        ++j;
        ++k;
    }
}

// Función principal del algoritmo Merge Sort
void MergeSort(vector<int>& arr, int izq, int dere)
{
    if (izq<dere)
    {
        int medio=izq+(dere - izq)/2;

        // Dividir el arreglo en dos partes y aplicar Merge Sort en cada parte
        MergeSort(arr,izq, medio);
        MergeSort(arr,medio + 1,dere);

        // Combinar las dos partes ordenadas
        Merge(arr, izq, medio,dere);
    }
}

// Función de utilidad para imprimir un arreglo
void printArray(const vector<int>& arr)
{
    int size=arr.size();
    for (int i=0; i<size; ++i)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main()
{
    vector<int> arr={ 12, 11, 13, 5, 6, 7 };
    int size=arr.size();
    cout<<"Arreglo original: ";
    printArray(arr);
    MergeSort(arr, 0, size - 1);
    cout<<"Arreglo ordenado: ";
    printArray(arr);
    return 0;
}
