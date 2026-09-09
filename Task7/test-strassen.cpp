#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "strassen.cpp"   // Include the implementation

using namespace std;

// Helper to print a matrix
void printMatrix(const Matrix& M, const string& name) {
    cout << name << ":\n";
    for (const auto& row : M) {
        for (int val : row)
            cout << val << "\t";
        cout << "\n";
    }
    cout << "\n";
}

// Check if two matrices are equal
bool areEqual(const Matrix& A, const Matrix& B) {
    if (A.size() != B.size()) return false;
    for (size_t i = 0; i < A.size(); i++)
        for (size_t j = 0; j < A[i].size(); j++)
            if (A[i][j] != B[i][j]) return false;
    return true;
}

int main() {
    srand(time(0));

    // ===================== Test Case 1: 2×2 =====================
    cout << "========== Test Case 1: 2×2 Matrix ==========\n";
    Matrix A2 = {{1, 2},
                 {3, 4}};
    Matrix B2 = {{5, 6},
                 {7, 8}};

    Matrix naive2   = naiveMultiply(A2, B2);
    Matrix strassen2 = strassen(A2, B2);

    printMatrix(A2, "Matrix A");
    printMatrix(B2, "Matrix B");
    printMatrix(naive2, "Naive Result");
    printMatrix(strassen2, "Strassen Result");

    cout << (areEqual(naive2, strassen2) ? "Results MATCH\n\n" : "Results DO NOT MATCH\n\n");

    // ===================== Test Case 2: 4×4 =====================
    cout << "========== Test Case 2: 4×4 Matrix ==========\n";
    Matrix A4 = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12},
        {13,14, 15, 16}
    };
    Matrix B4 = {
        {16,15, 14, 13},
        {12,11, 10,  9},
        { 8, 7,  6,  5},
        { 4, 3,  2,  1}
    };

    Matrix naive4   = naiveMultiply(A4, B4);
    Matrix strassen4 = strassen(A4, B4);

    printMatrix(naive4, "Naive Result (4x4)");
    printMatrix(strassen4, "Strassen Result (4x4)");

    cout << (areEqual(naive4, strassen4) ? "Results MATCH\n\n" : "Results DO NOT MATCH\n\n");

    // ===================== Test Case 3: Random 4×4 =====================
    cout << "========== Test Case 3: Random 4×4 Matrices ==========\n";
    Matrix A_rand(4, vector<int>(4));
    Matrix B_rand(4, vector<int>(4));

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            A_rand[i][j] = rand() % 10;   // values 0-9
            B_rand[i][j] = rand() % 10;
        }
    }

    Matrix naive_rand   = naiveMultiply(A_rand, B_rand);
    Matrix strassen_rand = strassen(A_rand, B_rand);

    printMatrix(A_rand, "Random Matrix A");
    printMatrix(B_rand, "Random Matrix B");
    printMatrix(naive_rand, "Naive Result");
    printMatrix(strassen_rand, "Strassen Result");

    cout << (areEqual(naive_rand, strassen_rand) ? "Results MATCH\n" : "Results DO NOT MATCH\n");

    return 0;
}