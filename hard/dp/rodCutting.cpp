#include <iostream>
#include <vector>
#include <algorithm>

int maxProfit(std::vector<int>& prices, int n) {
    std::vector<int> dp(n + 1, 0);

    for (int i = 1; i <= n; ++i) {
        int maxProfit = 0;
        for (int j = 1; j <= i; ++j) {
            maxProfit = std::max(maxProfit, prices[j] + dp[i - j]);
        }
        dp[i] = maxProfit;
    }

    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter the length of the rod: ";
    std::cin >> n;

    std::vector<int> prices(n + 1, 0);
    std::cout << "Enter the prices for each rod piece of different lengths:\n";
    for (int i = 1; i <= n; ++i) {
        std::cin >> prices[i];
    }

    int maxProfitValue = maxProfit(prices, n);
    std::cout << "Maximum value obtained by cutting the rod: " << maxProfitValue << std::endl;

    return 0;
}
