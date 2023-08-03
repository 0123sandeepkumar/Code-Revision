#include <iostream>
#include <vector>

int uniquePaths(int m, int n) {
    // Create a 2D DP array to store the number of unique paths at each cell
    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));

    // Base case: there is only one unique path to reach any cell in the first row or first column
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }

    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }

    // Fill in the DP array
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            // The number of unique paths to reach cell (i, j) is the sum of the paths from the cell above and the cell to the left
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }

    // The bottom-right cell contains the number of unique paths to reach the bottom-right corner
    return dp[m - 1][n - 1];
}

int main() {
    int m, n;
    std::cout << "Enter the number of rows (m): ";
    std::cin >> m;

    std::cout << "Enter the number of columns (n): ";
    std::cin >> n;

    int numPaths = uniquePaths(m, n);
    std::cout << "Number of unique paths: " << numPaths << std::endl;

    return 0;
}
