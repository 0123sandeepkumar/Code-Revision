#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        if (grid.empty()) {
            return 0;
        }
        
        int numRows = grid.size();
        int numCols = grid[0].size();
        int numIslands = 0;
        
        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == '1') {
                    ++numIslands;
                    grid[i][j] = '0';  // Mark the current cell as visited
                    std::queue<std::pair<int, int>> bfsQueue;
                    bfsQueue.push({i, j});
                    
                    while (!bfsQueue.empty()) {
                        std::pair<int, int> current = bfsQueue.front();
                        bfsQueue.pop();
                        
                        for (const auto& direction : directions) {
                            int newRow = current.first + direction.first;
                            int newCol = current.second + direction.second;
                            
                            if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && grid[newRow][newCol] == '1') {
                                grid[newRow][newCol] = '0';  // Mark the adjacent cell as visited
                                bfsQueue.push({newRow, newCol});
                            }
                        }
                    }
                }
            }
        }
        
        return numIslands;
    }
};

int main() {
    std::vector<std::vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    Solution solution;
    int numIslands = solution.numIslands(grid);
    
    std::cout << "Number of islands: " << numIslands << std::endl;

    return 0;
}
