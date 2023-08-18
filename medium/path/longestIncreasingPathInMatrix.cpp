#include <iostream>
#include <vector>

const int dx[4] = {-1, 1, 0, 0}; // Directions: up, down, left, right
const int dy[4] = {0, 0, -1, 1};

int longestIncreasingPathUtil(int x, int y, int prevVal, const std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& cache) {
    if (x < 0 || x >= matrix.size() || y < 0 || y >= matrix[0].size() || matrix[x][y] <= prevVal) {
        return 0;
    }

    if (cache[x][y] != -1) {
        return cache[x][y];
    }

    int maxLength = 0;
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];
        maxLength = std::max(maxLength, longestIncreasingPathUtil(newX, newY, matrix[x][y], matrix, cache));
    }

    cache[x][y] = maxLength + 1;
    return cache[x][y];
}

int longestIncreasingPath(const std::vector<std::vector<int>>& matrix) {
    if (matrix.empty()) {
        return 0;
    }

    int rows = matrix.size();
    int cols = matrix[0].size();
    std::vector<std::vector<int>> cache(rows, std::vector<int>(cols, -1));
    
    int maxLength = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            maxLength = std::max(maxLength, longestIncreasingPathUtil(i, j, INT_MIN, matrix, cache));
        }
    }

    return maxLength;
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {9, 9, 4},
        {6, 6, 8},
        {2, 1, 1}
    };

    int result = longestIncreasingPath(matrix);
    std::cout << "Length of longest increasing path: " << result << std::endl;

    return 0;
}
