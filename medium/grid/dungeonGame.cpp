#include <iostream>
#include <vector>
#include <algorithm>

int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
    int rows = dungeon.size();
    int cols = dungeon[0].size();

    // Create a 2D DP array to store the minimum initial health needed
    std::vector<std::vector<int>> dp(rows, std::vector<int>(cols, 0));

    // Start from the bottom-right corner
    dp[rows - 1][cols - 1] = std::max(1, 1 - dungeon[rows - 1][cols - 1]);

    // Fill the last row and last column
    for (int i = rows - 2; i >= 0; --i) {
        dp[i][cols - 1] = std::max(dp[i + 1][cols - 1] - dungeon[i][cols - 1], 1);
    }
    for (int j = cols - 2; j >= 0; --j) {
        dp[rows - 1][j] = std::max(dp[rows - 1][j + 1] - dungeon[rows - 1][j], 1);
    }

    // Fill the rest of the DP array
    for (int i = rows - 2; i >= 0; --i) {
        for (int j = cols - 2; j >= 0; --j) {
            int minRequiredHealthOnExit = std::min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j] = std::max(minRequiredHealthOnExit - dungeon[i][j], 1);
        }
    }

    return dp[0][0];
}

int main() {
    std::vector<std::vector<int>> dungeon = {
        {-2, -3, 3},
        {-5, -10, 1},
        {10, 30, -5}
    };

    int minInitialHealth = calculateMinimumHP(dungeon);
    std::cout << "Minimum initial health needed: " << minInitialHealth << std::endl;

    return 0;
}
