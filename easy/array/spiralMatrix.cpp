#include <iostream>
#include <vector>

std::vector<int> spiral_order(std::vector<std::vector<int>>& matrix) {
    std::vector<int> result;

    if (matrix.empty() || matrix[0].empty()) {
        return result;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        // Traverse right
        for (int col = left; col <= right; ++col) {
            result.push_back(matrix[top][col]);
        }
        top++;

        // Traverse down
        for (int row = top; row <= bottom; ++row) {
            result.push_back(matrix[row][right]);
        }
        right--;

        // Check if top <= bottom to avoid duplicate traversal of last row
        if (top <= bottom) {
            // Traverse left
            for (int col = right; col >= left; --col) {
                result.push_back(matrix[bottom][col]);
            }
            bottom--;
        }

        // Check if left <= right to avoid duplicate traversal of last column
        if (left <= right) {
            // Traverse up
            for (int row = bottom; row >= top; --row) {
                result.push_back(matrix[row][left]);
            }
            left++;
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<int> result = spiral_order(matrix);

    std::cout << "Elements in spiral order: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: 1 2 3 6 9 8 7 4 5

    return 0;
}
