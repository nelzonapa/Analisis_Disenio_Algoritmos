#include <iostream>
#include <vector>

// Función para imprimir una matriz
void printMatrix(const std::vector<std::vector<int>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (int num : row)
        {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

// Función para sumar dos matrices
std::vector<std::vector<int>> matrixAddition(const std::vector<std::vector<int>>& A,
                                             const std::vector<std::vector<int>>& B)
{
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Función para restar dos matrices
std::vector<std::vector<int>> matrixSubtraction(const std::vector<std::vector<int>>& A,
                                                const std::vector<std::vector<int>>& B)
{
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Función para multiplicar dos matrices utilizando el algoritmo de Strassen
std::vector<std::vector<int>> strassenMultiply(const std::vector<std::vector<int>>& A,
                                               const std::vector<std::vector<int>>& B)
{
    int n = A.size();

    // Caso base: Matrices 1x1
    if (n == 1)
    {
        std::vector<std::vector<int>> result(1, std::vector<int>(1));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    // División de las matrices en submatrices más pequeñas
    int mid = n / 2;

    std::vector<std::vector<int>> A11(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A12(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A21(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> A22(mid, std::vector<int>(mid));

    std::vector<std::vector<int>> B11(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B12(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B21(mid, std::vector<int>(mid));
    std::vector<std::vector<int>> B22(mid, std::vector<int>(mid));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + mid];
            A21[i][j] = A[i + mid][j];
            A22[i][j] = A[i + mid][j + mid];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + mid];
            B21[i][j] = B[i + mid][j];
            B22[i][j] = B[i + mid][j + mid];
        }
    }

    // Cálculo de los productos intermedios
    std::vector<std::vector<int>> P1 = strassenMultiply(matrixAddition(A11, A22), matrixAddition(B11, B22));
    std::vector<std::vector<int>> P2 = strassenMultiply(matrixAddition(A21, A22), B11);
    std::vector<std::vector<int>> P3 = strassenMultiply(A11, matrixSubtraction(B12, B22));
    std::vector<std::vector<int>> P4 = strassenMultiply(A22, matrixSubtraction(B21, B11));
    std::vector<std::vector<int>> P5 = strassenMultiply(matrixAddition(A11, A12), B22);
    std::vector<std::vector<int>> P6 = strassenMultiply(matrixSubtraction(A21, A11), matrixAddition(B11, B12));
    std::vector<std::vector<int>> P7 = strassenMultiply(matrixSubtraction(A12, A22), matrixAddition(B21, B22));

    // Cálculo de las submatrices del resultado
    std::vector<std::vector<int>> C11 = matrixSubtraction(matrixAddition(matrixAddition(P1, P4), P7), P5);
    std::vector<std::vector<int>> C12 = matrixAddition(P3, P5);
    std::vector<std::vector<int>> C21 = matrixAddition(P2, P4);
    std::vector<std::vector<int>> C22 = matrixSubtraction(matrixSubtraction(matrixAddition(P1, P3), P2), P6);

    // Combinación de las submatrices del resultado en una matriz
    std::vector<std::vector<int>> result(n, std::vector<int>(n));

    for (int i = 0; i < mid; i++)
    {
        for (int j = 0; j < mid; j++)
        {
            result[i][j] = C11[i][j];
            result[i][j + mid] = C12[i][j];
            result[i + mid][j] = C21[i][j];
            result[i + mid][j + mid] = C22[i][j];
        }
    }

    return result;
}

int main()
{
    std::vector<std::vector<int>> A = { {1, 2}, {3, 4} };
    std::vector<std::vector<int>> B = { {5, 6}, {7, 8} };

    std::cout << "Matriz A:" << std::endl;
    printMatrix(A);

    std::cout << "Matriz B:" << std::endl;
    printMatrix(B);

    std::vector<std::vector<int>> result = strassenMultiply(A, B);

    std::cout << "Resultado de la multiplicación:" << std::endl;
    printMatrix(result);

    return 0;
}
