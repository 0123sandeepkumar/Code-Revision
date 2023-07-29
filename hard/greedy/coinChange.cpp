#include <iostream>
#include <vector>
#include <climits>

int coinChange(const std::vector<int>& coins, int target) {
    std::vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= target; ++i) {
        for (int coin : coins) {
            if (i - coin >= 0 && dp[i - coin] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return dp[target] == INT_MAX ? -1 : dp[target];
}

int main() {
    // Example usage
    std::vector<int> coins = {1, 2, 5};
    int target = 11;

    int minCoins = coinChange(coins, target);

    std::cout << "Minimum number of coins needed: " << minCoins << std::endl;

    return 0;
}
