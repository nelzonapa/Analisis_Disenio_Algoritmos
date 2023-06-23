#include <iostream>
#include <cstdlib>

int* gpVect = nullptr; // Búfer dinámico para guardar los elementos
int gnCount = 0; // Contador para conocer el número de elementos utilizados
int gnMax = 0; // Variable

void Insert(int elem)
{
    if (gnCount == gnMax) // No hay espacio en este momento para elem
        Resize(); // Redimensionar el vector antes de insertar elem

    gpVect[gnCount++] = elem; // Insertar el elemento al final de la secuencia
    std::cout << "Elemento " << elem << " insertado exitosamente." << std::endl;
}

void Resize()
{
    const int delta = 10; // Utilizado para aumentar el tamaño del vector

    int* pTemp = static_cast<int*>(std::realloc(gpVect, sizeof(int) * (gnMax + delta)));
    if (pTemp == nullptr)
    {
        std::cout << "Error al asignar memoria para redimensionar el vector." << std::endl;
        return;
    }

    gpVect = pTemp; // Actualizar el puntero
    gnMax += delta; // El valor máximo tiene que incrementarse en delta
    std::cout << "Vector redimensionado. Nuevo tamaño: " << gnMax << std::endl;
}

int main()
{
    Insert(10);
    Insert(20);
    Insert(30);
    Insert(40);
    Insert(50);
    Insert(60);

    return 0;
}
