#include <iostream>
#include <vector>
using namespace std;
// Function to add two matrices
vector<vector<int>> addMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
    return result;
}
// Function to subtract two matrices
vector<vector<int>> subtractMatrix(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            result[i][j] = A[i][j] - B[i][j];
        }
    }
    return result;
}
// Function to perform Strassen's matrix multiplication
vector<vector<int>> strassenMultiply(const vector<vector<int>> &A, const vector<vector<int>> &B)
{
    int n = A.size();
    // Base case: If the matrices are 2x2, perform a simple multiplication
    if (n == 2)
    {
        vector<vector<int>> C(2, vector<int>(2));
        C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0];
        C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1];
        C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0];
        C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1];
        return C;
    }
    // Divide the matrices into four submatrices
    int halfSize = n / 2;
    vector<vector<int>> A11(halfSize, vector<int>(halfSize));
    vector<vector<int>> A12(halfSize, vector<int>(halfSize));
    vector<vector<int>> A21(halfSize, vector<int>(halfSize));
    vector<vector<int>> A22(halfSize, vector<int>(halfSize));
    vector<vector<int>> B11(halfSize, vector<int>(halfSize));
    vector<vector<int>> B12(halfSize, vector<int>(halfSize));
    vector<vector<int>> B21(halfSize, vector<int>(halfSize));
    vector<vector<int>> B22(halfSize, vector<int>(halfSize));
    for (int i = 0; i < halfSize; ++i)
    {
        for (int j = 0; j < halfSize; ++j)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];
            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }
    // Recursively compute seven products
     vector<vector<int>> P1 = strassenMultiply(A11, subtractMatrix(B12, B22));
    vector<vector<int>> P2 = strassenMultiply(addMatrix(A11, A12), B22);
    vector<vector<int>> P3 = strassenMultiply(addMatrix(A21, A22), B11);
    vector<vector<int>> P4 = strassenMultiply(A22, subtractMatrix(B21, B11));
    vector<vector<int>> P5 = strassenMultiply(addMatrix(A11, A22), addMatrix(B11,
                                                                             B22));
    vector<vector<int>> P6 = strassenMultiply(subtractMatrix(A12, A22), addMatrix(B21,
                                                                                  B22));
    vector<vector<int>> P7 = strassenMultiply(subtractMatrix(A11, A21), addMatrix(B11,
                                                                                  B12));
    // Compute the result submatrices
    vector<vector<int>> C11 = addMatrix(subtractMatrix(addMatrix(P5, P4), P2), P6);
    vector<vector<int>> C12 = addMatrix(P1, P2);
    vector<vector<int>> C21 = addMatrix(P3, P4);
    vector<vector<int>> C22 = subtractMatrix(subtractMatrix(addMatrix(P5, P1), P3), P7);
    // Print 2x2 submatrices
    cout << "P1:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << P1[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "P2:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)

        {
            cout << P2[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "P3:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << P3[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "P4:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << P4[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "P5:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << P5[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "P6:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << P6[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "P7:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << P7[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "C11:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << C11[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "C12:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << C12[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "C21:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << C21[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    cout << "C22:" << endl;
    for (int i = 0; i < 2; ++i)
    {
        for (int j = 0; j < 2; ++j)
        {
            cout << C22[i][j] << " ";
        }
        cout << endl;
    }
    cout << '\n';
    // Combine the submatrices to get the result
    vector<vector<int>> result(n, vector<int>(n));
    for (int i = 0; i < halfSize; ++i)
    {
        for (int j = 0; j < halfSize; ++j)
        {
            result[i][j] = C11[i][j];
            result[i][j + halfSize] = C12[i][j];
            result[i + halfSize][j] = C21[i][j];
            result[i + halfSize][j + halfSize] = C22[i][j];
        }
    }
    return result;
}
int main()
{
    int n;
    cout << "Enter the size of the matrices (power of 2): ";
    cin >> n;
    vector<vector<int>> A(n, vector<int>(n));
    vector<vector<int>> B(n, vector<int>(n));
    cout << "Enter matrix A:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> A[i][j];
        }
    }
    cout << '\n';
    cout << "Enter matrix B:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> B[i][j];
        }
    }
    cout << '\n';
    vector<vector<int>> C = strassenMultiply(A, B);
    cout << "Resultant matrix C:" << endl;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}