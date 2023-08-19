#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        std::queue<std::pair<int, int>> rottenQueue;  // Queue to store rotten oranges
        
        int freshCount = 0;  // Count of fresh oranges
        
        // Add initially rotten oranges to the queue and count fresh oranges
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 2) {
                    rottenQueue.push({i, j});
                } else if (grid[i][j] == 1) {
                    ++freshCount;
                }
            }
        }
        
        int minutes = 0;
        
        static constexpr int directions[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        // Perform BFS to simulate rotting process
        while (!rottenQueue.empty() && freshCount > 0) {
            int currentLevelSize = rottenQueue.size();
            
            for (int i = 0; i < currentLevelSize; ++i) {
                int row = rottenQueue.front().first;
                int col = rottenQueue.front().second;
                rottenQueue.pop();
                
                for (const auto& direction : directions) {
                    int newRow = row + direction[0];
                    int newCol = col + direction[1];
                    
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && grid[newRow][newCol] == 1) {
                        grid[newRow][newCol] = 2;  // Update the fresh orange to be rotten
                        rottenQueue.push({newRow, newCol});
                        --freshCount;
                    }
                }
            }
            
            ++minutes;
        }
        
        return freshCount == 0 ? minutes : -1;  // Return -1 if not all oranges can be rotten
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> grid = {
        {2, 1, 1},
        {1, 1, 0},
        {0, 1, 1}
    };
    
    int minutes = solution.orangesRotting(grid);
    std::cout << "Minutes required to rot all oranges: " << minutes << std::endl;
    
    return 0;
}
