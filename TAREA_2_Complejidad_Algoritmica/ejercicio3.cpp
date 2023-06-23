/*
for i = 0 to length(A): 
    for j = 0 to length(B): 
        print A[i] + "," + B[j]
*/
#include <iostream>
#include <vector>
using namespace std;
void print_num_instruc(const vector<int>& A, const vector<int>& B)
{
    int count = 0; // Contador para el conteo de instrucciones

    for (int i = 0; i < A.size(); i++)
    {
        for (int j = 0; j < B.size(); j++)
        {
            cout<<A[i]<<","<<B[j]<<" "; // Imprimir A[i] y B[j]
            count++; // Incrementar el contador de instrucciones
        }
    }

    cout<<endl;
    cout<<"Número de instrucciones: "<<count<<endl;
}

int main()
{
    vector<int> A = {13, 42, 1};
    vector<int> B = {4, 50, 8};

    print_num_instruc(A, B);

    return 0;
}

