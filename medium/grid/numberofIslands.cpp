#include <iostream>
#include <vector>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int numIslands = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    ++numIslands;
                }
            }
        }
        
        return numIslands;
    }
    
private:
    void dfs(std::vector<std::vector<char>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0') {
            return;
        }
        
        grid[row][col] = '0';  // Mark the cell as visited
        
        static constexpr int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (const auto& direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            
            dfs(grid, newRow, newCol);
        }
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    
    int numIslands = solution.numIslands(grid);
    std::cout << "Number of islands: " << numIslands << std::endl;
    
    return 0;
}
