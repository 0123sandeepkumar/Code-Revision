#include <iostream>
#include <vector>

using namespace std;

int uniquePaths(int m, int n) {
    // Create a 2D DP array to store the number of unique paths
    vector<vector<int>> dp(m, vector<int>(n, 0));
    
    // Initialize the base cases
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1; // Only one way to reach any cell in the leftmost column
    }
    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1; // Only one way to reach any cell in the top row
    }
    
    // Fill in the DP array using the recurrence relation
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
    
    return dp[m - 1][n - 1]; // Number of unique paths to bottom-right corner
}

int main() {
    int m = 3; // Number of rows
    int n = 7; // Number of columns
    
    int paths = uniquePaths(m, n);
    
    cout << "Number of unique paths: " << paths << endl;
    
    return 0;
}
