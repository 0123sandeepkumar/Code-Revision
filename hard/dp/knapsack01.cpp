#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

int knapsack(int capacity, const std::vector<Item>& items) {
    int n = items.size();
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w <= capacity; ++w) {
            if (items[i - 1].weight > w) {
                dp[i][w] = dp[i - 1][w];
            } else {
                dp[i][w] = std::max(dp[i - 1][w], items[i - 1].value + dp[i - 1][w - items[i - 1].weight]);
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int n, capacity;
    std::cout << "Enter the number of items: ";
    std::cin >> n;

    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Enter weight and value for item " << i + 1 << ": ";
        std::cin >> items[i].weight >> items[i].value;
    }

    std::cout << "Enter the capacity of the knapsack: ";
    std::cin >> capacity;

    int maxValue = knapsack(capacity, items);
    std::cout << "The maximum value that can be obtained is: " << maxValue << std::endl;

    return 0;
}
