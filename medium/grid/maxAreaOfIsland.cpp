#include <iostream>
#include <vector>

class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int maxArea = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    maxArea = std::max(maxArea, dfs(grid, i, j));
                }
            }
        }
        
        return maxArea;
    }
    
private:
    int dfs(std::vector<std::vector<int>>& grid, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0) {
            return 0;
        }
        
        grid[row][col] = 0;  // Mark the cell as visited
        
        int area = 1;
        
        static constexpr int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        for (const auto& direction : directions) {
            int newRow = row + direction[0];
            int newCol = col + direction[1];
            
            area += dfs(grid, newRow, newCol);
        }
        
        return area;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {
        {1, 1, 0, 0, 0},
        {1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1},
        {0, 0, 0, 1, 1}
    };
    
    int maxArea = solution.maxAreaOfIsland(grid);
    std::cout << "Maximum area of an island: " << maxArea << std::endl;
    
    return 0;
}
