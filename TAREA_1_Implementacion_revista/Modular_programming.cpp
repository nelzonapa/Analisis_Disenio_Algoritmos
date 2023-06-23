#include <iostream>
#include <cstdlib>

void Insert(int*& rpVect, int& rnCount, int& rnMax, int elem)
{
    if (rnCount == rnMax) // Verificar el desbordamiento
        Resize(rpVect, rnMax); // Redimensionar el vector antes de insertar elem

    rpVect[rnCount++] = elem; // Insertar el elemento al final de la secuencia
    std::cout << "Elemento " << elem << " insertado exitosamente." << std::endl;
}

void Resize(int*& rpVect, int& rnMax)
{
    const int delta = 10; // Utilizado para aumentar el tamaño del vector
    rpVect = static_cast<int*>(std::realloc(rpVect, sizeof(int) * (rnMax + delta)));

    rnMax += delta; // El valor máximo debe incrementarse por delta
    std::cout << "Vector redimensionado. Nuevo tamaño: " << rnMax << std::endl;
}

struct Vector
{
    int* m_pVect; // Puntero al búfer
    int m_nCount; // Controla cuántos elementos se están utilizando
    int m_nMax; // Controla cuántos están asignados como máximo
    int m_nDelta; // Para controlar el crecimiento
};

void Insert(Vector* pThis, int elem)
{
    if (pThis->m_nCount == pThis->m_nMax) // Verificar el desbordamiento
        Resize(pThis); // Redimensionar el vector antes de insertar elem

    // Insertar el elemento al final de la secuencia
    pThis->m_pVect[pThis->m_nCount++] = elem;
    std::cout << "Elemento " << elem << " insertado exitosamente." << std::endl;
}

void Resize(Vector* pThis)
{
    pThis->m_pVect = static_cast<int*>(std::realloc(pThis->m_pVect, sizeof(int) * (pThis->m_nMax + pThis->m_nDelta)));

    // El valor máximo debe incrementarse por delta
    pThis->m_nMax += pThis->m_nDelta;
    std::cout << "Vector redimensionado. Nuevo tamaño: " << pThis->m_nMax << std::endl;
}

int main()
{
    int* gpVect = nullptr; // Búfer dinámico para guardar los elementos
    int gnCount = 0; // Contador para conocer el número de elementos utilizados
    int gnMax = 0; // Controla cuántos están asignados como máximo

    Insert(gpVect, gnCount, gnMax, 10);
    Insert(gpVect, gnCount, gnMax, 20);
    Insert(gpVect, gnCount, gnMax, 30);
    Insert(gpVect, gnCount, gnMax, 40);
    Insert(gpVect, gnCount, gnMax, 50);

    Vector vec;
    vec.m_pVect = nullptr;
    vec.m_nCount = 0;
    vec.m_nMax = 0;
    vec.m_nDelta = 10;

    Insert(&vec, 10);
    Insert(&vec, 20);
    Insert(&vec, 30);
    Insert(&vec, 40);
    Insert(&vec, 50);

    return 0;
}
