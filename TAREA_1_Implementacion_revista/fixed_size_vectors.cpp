#include <iostream>

int gVect[100]; // Búfer para guardar los elementos
int gnCount = 0; // Contador para conocer el número de elementos utilizados

void Insert(int elem)
{
    if (gnCount < 100) // Solo podemos insertar si hay espacio
    {
        gVect[gnCount++] = elem; // Insertar el elemento al final
        std::cout << "Elemento " << elem << " insertado exitosamente." << std::endl;
    }
    else
    {
        std::cout << "El búfer está lleno. No se puede insertar el elemento " << elem << "." << std::endl;
    }
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
