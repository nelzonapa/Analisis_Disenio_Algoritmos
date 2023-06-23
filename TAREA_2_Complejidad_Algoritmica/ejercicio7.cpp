/*
N = 1000
if N % 2 == 0:
    print "par"
else:
    print "impar"
*/

#include <iostream>
using namespace std;

void printParImpar(int N)
{
    if (N % 2 == 0)
    {
        cout<<"par"<<endl;
    }
    else
    {
        cout<<"impar"<<endl;
    }
}

int main()
{
    int N = 1000;
    printParImpar(N);
    return 0;
}


