#include <iostream>
#include <vector>
#include <climits>

int minCoinsRequired(std::vector<int>& coins, int target) {
    int n = coins.size();
    std::vector<int> dp(target + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i <= target; ++i) {
        for (int j = 0; j < n; ++j) {
            if (coins[j] <= i && dp[i - coins[j]] != INT_MAX) {
                dp[i] = std::min(dp[i], dp[i - coins[j]] + 1);
            }
        }
    }

    return dp[target] == INT_MAX ? -1 : dp[target];
}

int main() {
    int target, numCoins;
    std::cout << "Enter the target amount: ";
    std::cin >> target;

    std::cout << "Enter the number of coin denominations: ";
    std::cin >> numCoins;

    std::vector<int> coins(numCoins);
    std::cout << "Enter the coin denominations: ";
    for (int i = 0; i < numCoins; ++i) {
        std::cin >> coins[i];
    }

    int minCoins = minCoinsRequired(coins, target);
    if (minCoins == -1) {
        std::cout << "It is not possible to make up the target amount using the given coins.\n";
    } else {
        std::cout << "Minimum number of coins required: " << minCoins << std::endl;
    }

    return 0;
}
