/*
for i = 0 to N: 
    if i % 2 == 0: 
        print i
*/
#include <iostream>
using namespace std;

void print_num_instrucciones(int N)
{
    int cont = 0; // Contador para el número de instrucciones

    for (int i = 0; i <= N; i++)
    {
        cont++; // Incrementar el contador por la instrucción de incremento del bucle

        if (i % 2 == 0)
        {
            cout<<i<<endl;
            cont++; // Incrementar el contador por la instrucción de impresión
        }
    }

    cout<<"Número total de instrucciones: "<<cont<<endl;
}

int main()
{
    int N;
    cout<<"Ingrese el valor de N: ";
    cin>>N;

    print_num_instrucciones(N);

    return 0;
}
