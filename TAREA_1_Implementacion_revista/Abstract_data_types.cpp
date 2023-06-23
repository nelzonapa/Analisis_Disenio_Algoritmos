#include <iostream>
using namespace std;

typedef int T;

class CVector
{
private:
    T* m_pVect; // Puntero al búfer
    int m_nCount; // Controla la cantidad de elementos utilizados
    int m_nMax; // Controla la cantidad maxima de elementos
    int m_nDelta; // Para controlar el crecimiento

    void Init(int delta); // Inicializa las variables privadas, etc
    void Resize(); // Redimensiona el vector cuando hay desbordamiento

public:
    CVector(int delta = 10); // Constructor
    void Insert(T elem); // Inserta un nuevo elemento
    // ...
};

template <typename T>
class CVector
{
private:
    T* m_pVect; // Puntero al búfer
    int m_nCount; // Controla la cantidad de elementos utilizados
    int m_nMax; // Controla la cantidad maxima de elementos
    int m_nDelta; // Para controlar el crecimiento

    void Init(int delta); // Inicializa las variables privadas, etc
    void Resize(); // Redimensiona el vector cuando hay desbordamiento

public:
    CVector(int delta = 10); // Constructor
    void Insert(T elem); // Inserta un nuevo elemento
    // ...
};

// Implementacion de la clase CVector
template <typename T>
CVector<T>::CVector(int delta)
{
    Init(delta);
}

template <typename T>
void CVector<T>::Insert(T elem)
{
    if (m_nCount == m_nMax) // Verifica el desbordamiento
        Resize(); // Redimensiona el vector antes de insertar el elemento

    m_pVect[m_nCount++] = elem; // Inserta el elemento al final
    std::cout << "Elemento " << elem << " insertado correctamente." << std::endl;
}

int main()
{
    CVector<T> vec(10);

    vec.Insert(10);
    vec.Insert(20);
    vec.Insert(30);
    vec.Insert(40);
    vec.Insert(50);

    return 0;
}
