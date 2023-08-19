#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }

        int rows = matrix.size();
        int cols = matrix[0].size();

        std::vector<std::vector<bool>> canReachPacific(rows, std::vector<bool>(cols, false));
        std::vector<std::vector<bool>> canReachAtlantic(rows, std::vector<bool>(cols, false));

        // Perform DFS from the borders to mark cells that can be reached by water
        for (int i = 0; i < rows; ++i) {
            dfs(matrix, canReachPacific, i, 0);
            dfs(matrix, canReachAtlantic, i, cols - 1);
        }

        for (int j = 0; j < cols; ++j) {
            dfs(matrix, canReachPacific, 0, j);
            dfs(matrix, canReachAtlantic, rows - 1, j);
        }

        // Collect cells that can reach both oceans
        std::vector<std::vector<int>> result;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (canReachPacific[i][j] && canReachAtlantic[i][j]) {
                    result.push_back({i, j});
                }
            }
        }

        return result;
    }

private:
    void dfs(const std::vector<std::vector<int>>& matrix, std::vector<std::vector<bool>>& canReachOcean, int row, int col) {
        if (row < 0 || row >= matrix.size() || col < 0 || col >= matrix[0].size() || canReachOcean[row][col]) {
            return;
        }

        canReachOcean[row][col] = true;

        static constexpr int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        for (const auto& direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];

            if (newRow >= 0 && newRow < matrix.size() && newCol >= 0 && newCol < matrix[0].size() && matrix[newRow][newCol] >= matrix[row][col]) {
                dfs(matrix, canReachOcean, newRow, newCol);
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> matrix = {
        {1, 2, 2, 3, 5},
        {3, 2, 3, 4, 4},
        {2, 4, 5, 3, 1},
        {6, 7, 1, 4, 5},
        {5, 1, 1, 2, 4}
    };

    std::vector<std::vector<int>> result = solution.pacificAtlantic(matrix);

    std::cout << "Positions from which water can flow to both oceans:" << std::endl;
    for (const auto& pos : result) {
        std::cout << "(" << pos[0] << ", " << pos[1] << ") ";
    }
    std::cout << std::endl;

    return 0;
}
