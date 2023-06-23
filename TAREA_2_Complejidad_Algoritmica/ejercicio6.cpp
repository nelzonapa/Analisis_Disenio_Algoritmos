/*
for i = 0 to N: 
    j = 1 
    while j < N:
        print j 
        j=j*2
*/

#include <iostream>

using namespace std;

void cont_num_instruc(int N) {
    int count = 0; // Contador de instrucciones
    
    for (int i = 0; i <= N; i++) {
        int j = 1;
        while (j < N) {
            cout<<j<<endl;
            j = j * 2;
            count++; // Incrementar el contador de instrucciones
        }
    }
    
    cout<<"Número total de instrucciones: "<<count<<endl;
}

int main() {
    int N;
    cout<<"Ingrese el valor de N: ";
    std::cin >> N;
    cont_num_instruc(N);
    
    return 0;
}
