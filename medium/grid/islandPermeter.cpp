#include <iostream>
#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        int perimeter = 0;
        
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    perimeter += 4;  // Start with the initial perimeter value
                    
                    // Check neighboring cells
                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter -= 2;  // Deduct for the shared edge
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter -= 2;  // Deduct for the shared edge
                    }
                }
            }
        }
        
        return perimeter;
    }
};

int main() {
    Solution solution;
    
    std::vector<std::vector<int>> grid = {
        {0, 1, 0, 0},
        {1, 1, 1, 0},
        {0, 1, 0, 0},
        {1, 1, 0, 0}
    };
    
    int perimeter = solution.islandPerimeter(grid);
    std::cout << "Perimeter of the island: " << perimeter << std::endl;
    
    return 0;
}
