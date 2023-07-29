#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
};

bool compareItems(const Item& item1, const Item& item2) {
    // Calculate the value per unit weight (value-to-weight ratio) for each item
    double valuePerUnitWeight1 = static_cast<double>(item1.value) / item1.weight;
    double valuePerUnitWeight2 = static_cast<double>(item2.value) / item2.weight;
    return valuePerUnitWeight1 > valuePerUnitWeight2;
}

double fractionalKnapsack(int knapsackCapacity, const std::vector<Item>& items) {
    std::vector<Item> sortedItems = items;
    std::sort(sortedItems.begin(), sortedItems.end(), compareItems);

    double totalValue = 0.0;
    int currentWeight = 0;

    for (const Item& item : sortedItems) {
        if (currentWeight + item.weight <= knapsackCapacity) {
            // Take the whole item
            totalValue += item.value;
            currentWeight += item.weight;
        } else {
            // Take a fraction of the item to fill the remaining capacity
            int remainingCapacity = knapsackCapacity - currentWeight;
            totalValue += static_cast<double>(remainingCapacity) / item.weight * item.value;
            break; // The knapsack is now full
        }
    }

    return totalValue;
}

int main() {
    // Example usage
    int knapsackCapacity = 50;
    std::vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};

    double maxValue = fractionalKnapsack(knapsackCapacity, items);

    std::cout << "Maximum value in the knapsack: " << maxValue << std::endl;

    return 0;
}
