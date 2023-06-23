/*
i = 1
while (i < N):
    print i
    i = 1*2
*/

#include <iostream>
using namespace std;

void print_num_instruc(int N)
{
    int i = 1;
    int count = 0;

    while (i < N)
    {
        cout<<i<<endl;
        i = i * 2;
        count++;
    }

    cout<<"Número de instrucciones ejecutadas: "<<count<<endl;
}

int main()
{
    int N;
    cout<<"Ingrese el valor de N: ";
    cin>>N;

    print_num_instruc(N);

    return 0;
}
