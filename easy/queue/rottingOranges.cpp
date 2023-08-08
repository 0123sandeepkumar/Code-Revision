#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int minutes = 0;
        
        std::vector<std::pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        std::queue<std::pair<int, int>> rottenQueue;
        
        // Enqueue all initially rotten oranges
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                }
            }
        }
        
        // Perform BFS to simulate rotting
        while (!rottenQueue.empty()) {
            int size = rottenQueue.size();
            bool hasRotten = false;
            
            for (int i = 0; i < size; ++i) {
                int row = rottenQueue.front().first;
                int col = rottenQueue.front().second;
                rottenQueue.pop();
                
                for (const auto& direction : directions) {
                    int newRow = row + direction.first;
                    int newCol = col + direction.second;
                    
                    if (newRow >= 0 && newRow < numRows && newCol >= 0 && newCol < numCols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;
                        rottenQueue.push({newRow, newCol});
                        hasRotten = true;
                    }
                }
            }
            
            if (hasRotten) {
                ++minutes;
            }
        }
        
        // Check if there are any fresh oranges left
        for (int i = 0; i < numRows; ++i) {
            for (int j = 0; j < numCols; ++j) {
                if (grid[i][j] == 1) {
                    return -1; // Some oranges cannot be rotten
                }
            }
        }
        
        return minutes;
    }
};

int main() {
    std::vector<std::vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };

    Solution solution;
    int minutes = solution.orangesRotting(grid);
    
    if (minutes != -1) {
        std::cout << "Minimum minutes to rot all oranges: " << minutes << std::endl;
    } else {
        std::cout << "Some oranges cannot be rotten." << std::endl;
    }

    return 0;
}
