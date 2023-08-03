#include <iostream>
#include <vector>
#include <algorithm>

int minDistance(std::string word1, std::string word2) {
    int m = word1.length();
    int n = word2.length();

    // Create a 2D DP table of size (m+1) x (n+1)
    std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));

    // Initialize the base cases
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;
    }

    for (int j = 0; j <= n; ++j) {
        dp[0][j] = j;
    }

    // Fill in the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (word1[i - 1] == word2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = 1 + std::min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
            }
        }
    }

    return dp[m][n];
}

int main() {
    std::string word1, word2;
    std::cout << "Enter the first string: ";
    std::cin >> word1;

    std::cout << "Enter the second string: ";
    std::cin >> word2;

    int minOperations = minDistance(word1, word2);
    std::cout << "Minimum number of operations required: " << minOperations << std::endl;

    return 0;
}
