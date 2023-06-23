#include <iostream>
#include <cstring>

// Definicion del espacio de nombres MyNS

namespace MyNS {
    long factorial(int n);

    class CTest {
    public:
        CTest();
        void Method1();
    };

    template <typename T>
    class CArray {
    private:
        T* m_pData;
        int m_nSize;
    public:
        CArray() : m_pData(nullptr), m_nSize(0) {}
        ~CArray() { delete[] m_pData; }
        void Insert(T elem) {
            T* newData = new T[m_nSize + 1];
            for (int i = 0; i < m_nSize; i++) {
                newData[i] = m_pData[i];
            }
            newData[m_nSize] = elem;
            delete[] m_pData;
            m_pData = newData;
            m_nSize++;
        }
        int GetSize() const { return m_nSize; }
    };

    const unsigned long max = 500 * 1000 * 1000;
    const unsigned long step = 100 * 1000 * 1000;

    void PrintSomeText() {
        unsigned long count;
        for (count = 0L; count < max; count++) {
            if (count % step == 0L) {
                std::cout << "some text ..." << std::endl;
            }
        }
    }

    class CVector {
    private:
        void** m_pVect;
        int m_nCount;
        int m_nMax;
        int m_nDelta;
        int m_nElemSize;
        int (*m_lpfnCompare)(void*, void*);

        void Init(int delta);
        void Resize();
        void* DupBlock(void* pElem);

    public:
        CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta = 10);
        ~CVector();
        void Insert(void* elem);
    };

    CVector::CVector(int (*lpfnCompare)(void*, void*), int nElemSize, int delta) {
        Init(delta);
        m_lpfnCompare = lpfnCompare;
        m_nElemSize = nElemSize;
    }

    CVector::~CVector() {
        for (int i = 0; i < m_nCount; i++) {
            delete[] static_cast<char*>(m_pVect[i]);
        }
        delete[] m_pVect;
    }

    void CVector::Init(int delta) {
        m_pVect = nullptr;
        m_nCount = 0;
        m_nMax = 0;
        m_nDelta = delta;
    }

    void CVector::Resize() {
        void** newVect = new void*[m_nMax + m_nDelta];
        for (int i = 0; i < m_nCount; i++) {
            newVect[i] = m_pVect[i];
        }
        delete[] m_pVect;
        m_pVect = newVect;
        m_nMax += m_nDelta;
    }

    void* CVector::DupBlock(void* pElem) {
        void* p = new char[m_nElemSize];
        return memcpy(p, pElem, m_nElemSize);
    }

    void CVector::Insert(void* pElem) {
        if (m_nCount == m_nMax) {
            Resize();
        }
        m_pVect[m_nCount++] = DupBlock(pElem);
    }

    long factorial(int n) {
        if (n == 0) {
            return 1;
        }
        else {
            return n * factorial(n - 1);
        }
    }

    CTest::CTest() {
        // Inicializar algo
    }

    void CTest::Method1() {
        // Debes escribir tu codigo aquí
    }

    int fnIntCompare(void* pVar1, void* pVar2) {
        return *(int*)pVar1 - *(int*)pVar2;
    }
}

// Implementacion del programa principal

int main() {
    int option;
    std::cout << "Ingrese una opcion: ";
    std::cin >> option;

    switch (option) {
    case INT_TYPE_ENUM: {
        MyNS::CArray<int> a;
        int element;
        std::cout << "Ingrese un entero: ";
        std::cin >> element;
        a.Insert(element);
        std::cout << "Tamaño del array: " << a.GetSize() << std::endl;
        break;
    }
    case DOUBLE_TYPE_ENUM: {
        MyNS::CArray<double> a;
        double element;
        std::cout << "Ingrese un número decimal: ";
        std::cin >> element;
        a.Insert(element);
        std::cout << "Tamaño del array: " << a.GetSize() << std::endl;
        break;
    }
    // Mas casos para otros tipos aquí
    }

    MyNS::PrintSomeText();

    return 0;
}
