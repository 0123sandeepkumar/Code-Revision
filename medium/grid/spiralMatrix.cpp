#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateSpiralMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    
    int num = 1;  // Starting number
    
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    
    while (top <= bottom && left <= right) {
        // Traverse top row
        for (int j = left; j <= right; ++j) {
            matrix[top][j] = num++;
        }
        ++top;
        
        // Traverse right column
        for (int i = top; i <= bottom; ++i) {
            matrix[i][right] = num++;
        }
        --right;
        
        // Traverse bottom row
        if (top <= bottom) {
            for (int j = right; j >= left; --j) {
                matrix[bottom][j] = num++;
            }
            --bottom;
        }
        
        // Traverse left column
        if (left <= right) {
            for (int i = bottom; i >= top; --i) {
                matrix[i][left] = num++;
            }
            ++left;
        }
    }
    
    return matrix;
}

int main() {
    int n = 4;  // Change n to the desired value
    
    std::vector<std::vector<int>> spiralMatrix = generateSpiralMatrix(n);
    
    std::cout << "Spiral Matrix:" << std::endl;
    for (const auto& row : spiralMatrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    
    return 0;
}
