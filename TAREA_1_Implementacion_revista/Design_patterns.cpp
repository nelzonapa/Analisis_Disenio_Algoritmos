#include <vector> // sin .h
#include <list>
#include <iostream>
using namespace std;

// Funcion genérica para escribir los elementos de un contenedor en un flujo de salida
template <typename Contenedor>
void Escribir(Contenedor& ds, ostream& os)
{
    typename Contenedor::iterator iter = ds.begin();
    for (; iter != ds.end(); ++iter)
        os << *iter << "\n";
}

int main(int argc, char* argv[])
{
    list<float> miLista;
    vector<float> miVector;

    // Llenar la lista y el vector con elementos
    for (int i = 0; i < 10; ++i)
    {
        miLista.push_back(i);
        miVector.push_back(i + 50);
    }

    // Escribir los elementos de la lista y el vector en la salida estandar
    Escribir(miLista, cout);
    Escribir(miVector, cout);

    return 0;
}
