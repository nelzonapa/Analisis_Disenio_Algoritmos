/*
for i = 0 to N: 
    for j = i to N: 
        print i + "," + j
*/
#include <iostream>
#include <string>
using namespace std;

void print_num_instruc(int N) {
    int count = 0; // Contador de instrucciones
    for (int i = 0; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            count++; // Incrementar el contador de instrucciones
            cout<<i<<","<<j<<endl; // Imprimir la secuencia i, j
        }
    }
    cout<<"Número total de instrucciones: "<<count<<endl;
}

int main() {
    int N;
    cout<<"Ingrese el valor de N: ";
    cin>>N;
    print_num_instruc(N);
    return 0;
}
