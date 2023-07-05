#include <iostream>
#include <vector>
/*Implementación posible de Matrices_Strassen*/
using namespace std;

// Función para imprimir una matriz
void imprimir_Matriz(const vector<vector<int>>& matrix)
{
    for (const auto& row:matrix)
    {
        for (int num:row)
        {
            cout<<num<<" ";
        }
        cout<<endl;
    }
}

// Función para sumar dos matrices
vector<vector<int>> Adicion_Matriz(const vector<vector<int>>& A,const vector<vector<int>>& B)
{
    int n=A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i=0; i < n; i++)
    {
        for (int j=0; j < n; j++)
        {
            result[i][j]=A[i][j] + B[i][j];
        }
    }

    return result;
}

// Función para restar dos matrices
vector<vector<int>> matrixSubtraction(const vector<vector<int>>& A,const vector<vector<int>>& B)
{
    int n=A.size();
    vector<vector<int>> result(n, vector<int>(n));

    for (int i=0; i < n; i++)
    {
        for (int j=0; j < n; j++)
        {
            result[i][j]=A[i][j] - B[i][j];
        }
    }

    return result;
}

// Función para multiplicar dos matrices utilizando el algoritmo de Strassen
vector<vector<int>> Multi_Mat_Strassen(const vector<vector<int>>& A,const vector<vector<int>>& B)
{
    int n=A.size();

    // Caso base: Matrices 1x1
    if (n == 1)
    {
        vector<vector<int>> result(1, vector<int>(1));
        result[0][0]=A[0][0] * B[0][0];
        return result;
    }

    // División de las matrices en submatrices más pequeñas
    int mid=n / 2;

    vector<vector<int>> A11(mid, vector<int>(mid));
    vector<vector<int>> A12(mid, vector<int>(mid));
    vector<vector<int>> A21(mid, vector<int>(mid));
    vector<vector<int>> A22(mid, vector<int>(mid));

    vector<vector<int>> B11(mid, vector<int>(mid));
    vector<vector<int>> B12(mid, vector<int>(mid));
    vector<vector<int>> B21(mid, vector<int>(mid));
    vector<vector<int>> B22(mid, vector<int>(mid));

    for (int i=0; i < mid; i++)
    {
        for (int j=0; j < mid; j++)
        {
            A11[i][j]=A[i][j];
            A12[i][j]=A[i][j + mid];
            A21[i][j]=A[i + mid][j];
            A22[i][j]=A[i + mid][j + mid];

            B11[i][j]=B[i][j];
            B12[i][j]=B[i][j + mid];
            B21[i][j]=B[i + mid][j];
            B22[i][j]=B[i + mid][j + mid];
        }
    }

    // Cálculo de los productos intermedios
    vector<vector<int>> P1=Multi_Mat_Strassen(Adicion_Matriz(A11, A22), Adicion_Matriz(B11, B22));
    vector<vector<int>> P2=Multi_Mat_Strassen(Adicion_Matriz(A21, A22), B11);
    vector<vector<int>> P3=Multi_Mat_Strassen(A11, matrixSubtraction(B12, B22));
    vector<vector<int>> P4=Multi_Mat_Strassen(A22, matrixSubtraction(B21, B11));
    vector<vector<int>> P5=Multi_Mat_Strassen(Adicion_Matriz(A11, A12), B22);
    vector<vector<int>> P6=Multi_Mat_Strassen(matrixSubtraction(A21, A11), Adicion_Matriz(B11, B12));
    vector<vector<int>> P7=Multi_Mat_Strassen(matrixSubtraction(A12, A22), Adicion_Matriz(B21, B22));

    // Cálculo de las submatrices del resultado
    vector<vector<int>> C11=matrixSubtraction(Adicion_Matriz(Adicion_Matriz(P1, P4), P7), P5);
    vector<vector<int>> C12=Adicion_Matriz(P3, P5);
    vector<vector<int>> C21=Adicion_Matriz(P2, P4);
    vector<vector<int>> C22=matrixSubtraction(matrixSubtraction(Adicion_Matriz(P1, P3), P2), P6);

    // Combinación de las submatrices del resultado en una matriz
    vector<vector<int>> result(n, vector<int>(n));

    for (int i=0; i < mid; i++)
    {
        for (int j=0; j < mid; j++)
        {
            result[i][j]=C11[i][j];
            result[i][j + mid]=C12[i][j];
            result[i + mid][j]=C21[i][j];
            result[i + mid][j + mid]=C22[i][j];
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> A={ {1, 2}, {3, 4} };
    vector<vector<int>> B={ {5, 6}, {7, 8} };
    cout<<"Matriz A:"<<endl;
    imprimir_Matriz(A);
    cout<<"Matriz B:"<<endl;
    imprimir_Matriz(B);
    vector<vector<int>> result=Multi_Mat_Strassen(A, B);
    cout<<"Resultado de la multiplicacion:"<<endl;
    imprimir_Matriz(result);

    return 0;
}
