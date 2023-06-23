/*
for i = 0 to N: 
    if i % 2 == 0: 
        print i

for i = 0 to N: 
    if i % 2 != 0: 
        print i
*/
#include <iostream>
using namespace std;

void print_num_instruc_pares(int N)
{
    int count = 0; // Contador de instrucciones

    for (int i = 0; i <= N; i++)
    {
        count++; // Incrementar contador por la comparación de límite de bucle

        if (i % 2 == 0)
        {
            cout<<i<<endl;
            count++; // Incrementar contador por la impresión de número par
        }
    }

    cout<<"Número total de instrucciones: "<<count<<endl;
}

void print_num_instruc_impares(int N)
{
    int count = 0; // Contador de instrucciones

    for (int i = 0; i <= N; i++)
    {
        count++; // Incrementar contador por la comparación de límite de bucle

        if (i % 2 != 0)
        {
            cout<<i<<endl;
            count++; // Incrementar contador por la impresión de número impar
        }
    }

    cout<<"Número total de instrucciones: "<<count<<endl;
}

int main()
{
    int N;
    cout<<"Ingrese el valor de N: ";
    cin >> N;

    cout<<"Impresión de números pares:"<<endl;
    print_num_instruc_pares(N);

    cout<<"Impresión de números impares:"<<endl;
    print_num_instruc_impares(N);

    return 0;
}
