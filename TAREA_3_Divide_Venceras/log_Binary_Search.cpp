#include <iostream>
#include <vector>
/*Implementación posible de Bynary_Search*/
using namespace std;

int Busqueda_Binaria(vector<int>& array, int a_buscar)
{
    int izq=0;
    int dere=array.size()-1;
    while (izq <= dere)
    {
        int mid=izq +(dere-izq) / 2;

        if (array[mid] == a_buscar)
        {
            return mid;
        }
        else if (array[mid] < a_buscar)
        {
            izq=mid + 1;
        }
        else
        {
            dere=mid - 1;
        }
    }

    return -1; // Elemento no encontrado
}

int main()
{
    vector<int> array={1, 3, 5, 7, 9, 11, 13, 15};
    int a_buscar=7;
    int aux=Busqueda_Binaria(array, a_buscar);
    if (aux != -1)
    {
        cout<<"El elemento "<<a_buscar<<" se encuentra en el indice "<<aux<<endl;
    }
    else
    {
        cout<<"El elemento "<<a_buscar<<" no se encuentra en el array."<<endl;
    }

    return 0;
}
