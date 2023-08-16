#include <iostream>
#include <vector>
#include <algorithm>

int minPathSum(std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    
    // Initialize the DP table
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    dp[0][0] = grid[0][0];
    
    // Fill in the first row and first column
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    
    // Fill in the rest of the DP table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = grid[i][j] + std::min(dp[i-1][j], dp[i][j-1]);
        }
    }
    
    return dp[m-1][n-1];
}

int main() {
    int m, n;
    std::cout << "Enter the number of rows (m): ";
    std::cin >> m;
    std::cout << "Enter the number of columns (n): ";
    std::cin >> n;
    
    std::vector<std::vector<int>> grid(m, std::vector<int>(n));
    std::cout << "Enter the grid elements:" << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grid[i][j];
        }
    }
    
    int minSum = minPathSum(grid);
    std::cout << "Minimum sum path: " << minSum << std::endl;
    
    return 0;
}
