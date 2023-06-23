#include <iostream>

class CVector
{
private:
    int* m_pVect; // Puntero al búfer
    int m_nCount; // Controla la cantidad de elementos utilizados
    int m_nMax; // Controla la cantidad maxima de elementos
    int m_nDelta; // Para controlar el crecimiento

    void Init(int delta); // Inicializa las variables privadas
    void Resize(); // Redimensiona el vector cuando hay desbordamiento

public:
    CVector(int delta = 10); // Constructor
    void Insert(int elem); // Inserta un nuevo elemento
    // Otros métodos van aquí
};

CVector::CVector(int delta)
{
    Init(delta);
}

void CVector::Init(int delta)
{
    m_pVect = new int[delta];
    m_nCount = 0;
    m_nMax = delta;
    m_nDelta = delta;
}

void CVector::Insert(int elem)
{
    if (m_nCount == m_nMax) // Verifica el desbordamiento
        Resize(); // Redimensiona el vector antes de insertar el elemento

    m_pVect[m_nCount++] = elem; // Inserta el elemento al final
    std::cout << "Elemento " << elem << " insertado correctamente." << std::endl;
}

void CVector::Resize()
{
    int* pTemp = new int[m_nMax + m_nDelta]; // Aloja un nuevo vector

    for (int i = 0; i < m_nMax; i++) // Transfiere los elementos
        pTemp[i] = m_pVect[i];

    delete[] m_pVect; // Libera el vector antiguo
    m_pVect = pTemp; // Actualiza el puntero
    m_nMax += m_nDelta; // Incrementa la capacidad maxima

    std::cout << "Vector redimensionado. Nuevo tamaño: " << m_nMax << std::endl;
}

int main()
{
    CVector vec(10);

    vec.Insert(10);
    vec.Insert(20);
    vec.Insert(30);
    vec.Insert(40);
    vec.Insert(50);

    return 0;
}
