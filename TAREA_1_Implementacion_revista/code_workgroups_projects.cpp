#include <iostream>
#include <vector>
using namespace std;

class CMyComplexDataStructure
{
    vector<float> m_container;
public:
    void Insert(float fVal) { m_container.push_back(fVal); }

    template <typename objclass>
    void sumone(objclass funobj)
    {
        vector<float>::iterator iter = m_container.begin();
        for (; iter != m_container.end(); iter++)
            funobj(*iter);
    }
};

template <typename objclass>
class funcobjclass
{
public:
    void operator()(objclass& objinstance)
    {
        objinstance++;
    }
};

int main(int argc, char* argv[])
{
    CMyComplexDataStructure ds;
    ds.Insert(3.5);
    ds.Insert(4.5);
    ds.Insert(6.5);
    ds.Insert(3.9);

    funcobjclass<float> x;
    ds.sumone(x);

    return 0;
}

// Codigo para el estudiante que implementa una lista enlazada
// Archivo LinkedList.h

// Estructura para los nodos de una lista enlazada
template <typename T>
struct NODE
{
    T m_data; // Los datos se almacenan aquí
    struct NODE<T>* m_pNext; // Puntero al siguiente nodo
    static long id; // Identificador del nodo

    NODE() // Constructor
        : m_data(0), m_pNext(NULL) {}
    // Mas métodos van aquí
};

template <typename T>
long NODE<T>::id = 0; // Inicializacion del identificador del nodo

template <typename T>
class CLinkedList
{
private:
    NODE<T>* m_pRoot; // Puntero a la raíz

public:
    // Mas métodos van aquí
};

// Codigo para el estudiante que implementa una lista enlazada
// Archivo LinkedList.h
template <typename T>
class CLinkedList
{
private:
    // Estructura para los nodos de una lista enlazada
    struct NODE
    {
        T m_data; // Los datos se almacenan aquí
        struct NODE* m_pNext; // Puntero al siguiente nodo
        // Algunos métodos van aquí
    };

    NODE* m_pRoot; // Puntero a la raíz

public:
    // Mas métodos van aquí
};

// Codigo para el estudiante que implementa un arbol binario
// Archivo BinaryTree.h
template <typename T>
class CBinaryTree
{
private:
    // Estructura para los nodos de un arbol binario
    struct NODE
    {
        T m_data; // Los datos se almacenan aquí
        struct NODE* m_pLeft, * m_pRight; // Puntero al nodo izquierdo y derecho
        // Algunos métodos van aquí
    };

    NODE* m_pRoot; // Puntero a la raíz

public:
    // Mas métodos van aquí
};
