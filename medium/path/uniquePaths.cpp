#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    
    // Initialize the base cases
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }
    
    // Fill in the DP table
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
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
    
    int paths = uniquePaths(m, n);
    std::cout << "Number of unique paths: " << paths << std::endl;
    
    return 0;
}
