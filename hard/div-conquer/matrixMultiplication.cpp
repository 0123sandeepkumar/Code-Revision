#include <iostream>
#include <vector>

// Function to add two matrices
std::vector<std::vector<int>> addMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Function to subtract two matrices
std::vector<std::vector<int>> subtractMatrices(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Function to multiply two matrices using Strassen's algorithm
std::vector<std::vector<int>> strassenMatrixMultiplication(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();

    if (n == 1) {
        std::vector<std::vector<int>> result(1, std::vector<int>(1, 0));
        result[0][0] = A[0][0] * B[0][0];
        return result;
    }

    // Split matrices into four submatrices
    int halfSize = n / 2;
    std::vector<std::vector<int>> A11(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> A12(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> A21(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> A22(halfSize, std::vector<int>(halfSize));

    std::vector<std::vector<int>> B11(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> B12(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> B21(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> B22(halfSize, std::vector<int>(halfSize));

    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
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

    // Calculate seven products required for Strassen's formula
    std::vector<std::vector<int>> M1 = strassenMatrixMultiplication(addMatrices(A11, A22), addMatrices(B11, B22));
    std::vector<std::vector<int>> M2 = strassenMatrixMultiplication(addMatrices(A21, A22), B11);
    std::vector<std::vector<int>> M3 = strassenMatrixMultiplication(A11, subtractMatrices(B12, B22));
    std::vector<std::vector<int>> M4 = strassenMatrixMultiplication(A22, subtractMatrices(B21, B11));
    std::vector<std::vector<int>> M5 = strassenMatrixMultiplication(addMatrices(A11, A12), B22);
    std::vector<std::vector<int>> M6 = strassenMatrixMultiplication(subtractMatrices(A21, A11), addMatrices(B11, B12));
    std::vector<std::vector<int>> M7 = strassenMatrixMultiplication(subtractMatrices(A12, A22), addMatrices(B21, B22));

    // Calculate the four quadrants of the result matrix
    std::vector<std::vector<int>> C11 = addMatrices(subtractMatrices(addMatrices(M1, M4), M5), M7);
    std::vector<std::vector<int>> C12 = addMatrices(M3, M5);
    std::vector<std::vector<int>> C21 = addMatrices(M2, M4);
    std::vector<std::vector<int>> C22 = addMatrices(subtractMatrices(addMatrices(M1, M3), M2), M6);

    // Combine the four quadrants to form the result matrix
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + halfSize] = C12[i][j];
            result[i + halfSize][j] = C21[i][j];
            result[i + halfSize][j + halfSize] = C22[i][j];
        }
    }

    return result;
}

// Function to print a matrix
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // Example usage
    std::vector<std::vector<int>> A = {{1, 2}, {3, 4}};
    std::vector<std::vector<int>> B = {{5, 6}, {7, 8}};

    std::cout << "Matrix A:" << std::endl;
    printMatrix(A);
    std::cout << "Matrix B:" << std::endl;
    printMatrix(B);

    std::vector<std::vector<int>> result = strassenMatrixMultiplication(A, B);

    std::cout << "Matrix A * B:" << std::endl;
    printMatrix(result);

    return 0 ;
}    
