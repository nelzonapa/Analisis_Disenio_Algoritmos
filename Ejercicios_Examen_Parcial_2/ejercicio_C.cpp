/*
Our dear Sultan is visiting a country where there are n different types of coin. He wants to collect
as many different types of coin as you can. Now if he wants to withdraw X amount of money from a
Bank, the Bank will give him this money using following algorithm.
withdraw(X){
if( X == 0) return;
Let Y be the highest valued coin that does not exceed X.
Give the customer Y valued coin.
withdraw(X-Y);
}
Now Sultan can withdraw any amount of money from the Bank. He should maximize the number
of different coins that he can collect in a single withdrawal.
Input
First line of the input contains T the number of test cases. Each of the test cases starts with n
(1 ≤ n ≤ 1000), the number of different types of coin. Next line contains n integers C1, C2, . . . , Cn
the value of each coin type. C1 < C2 < C3 < . . . < Cn < 1000000000. C1 equals to 1.
Output
For each test case output one line denoting the maximum number of coins that Sultan can collect in a
single withdrawal. He can withdraw in nite amount of money from the Bank.
Sample Input
2
6
1 2 4 8 16 32
6
1 3 6 8 15 20
Sample Output
6
4
*/
#include <iostream>

using namespace std;

int main()
{
    int T;
    cin >> T; // Leer el número de casos de prueba

    while (T--)
    {
        int N;
        cin >> N; // Leer el tamaño del arreglo

        int Array[N];
        for (int i = 0; i < N; i++)
        {
            cin >> Array[i]; // Leer los elementos del arreglo
        }

        int Biggest = Array[0]; // Variable para almacenar el valor más grande encontrado
        int coin = 1;           // Variable para contar el número de monedas necesarias

        for (int i = 1; i < N - 1; i++)
        {
            // Comprobar si el valor acumulado más el elemento actual es menor que el siguiente elemento
            if (Biggest + Array[i] < Array[i + 1])
            {
                Biggest += Array[i]; // Incrementar el valor acumulado
                coin++;              // Incrementar el número de monedas
            }
        }

        coin++;               // Incrementar el número de monedas para incluir el último elemento del arreglo
        cout << coin << endl; // Imprimir el resultado
    }

    return 0;
}
