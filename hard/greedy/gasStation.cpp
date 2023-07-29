#include <iostream>
#include <vector>

int canCompleteCircuit(const std::vector<int>& gas, const std::vector<int>& cost) {
    int n = gas.size();
    int totalGas = 0;
    int totalCost = 0;
    int tank = 0;
    int startStation = 0;

    for (int i = 0; i < n; ++i) {
        totalGas += gas[i];
        totalCost += cost[i];
        tank += gas[i] - cost[i];

        if (tank < 0) {
            // Cannot reach the next station from the current start station
            // Move to the next station as the new start station
            tank = 0;
            startStation = i + 1;
        }
    }

    // If the total gas is greater than or equal to the total cost,
    // it means we can complete the entire circular route
    return (totalGas >= totalCost) ? startStation : -1;
}

int main() {
    // Example usage
    std::vector<int> gas = {4, 3, 5, 1, 2};
    std::vector<int> cost = {3, 2, 4, 5, 1};

    int startStation = canCompleteCircuit(gas, cost);

    if (startStation != -1) {
        std::cout << "Start station: " << startStation << std::endl;
    } else {
        std::cout << "Cannot complete the circular route." << std::endl;
    }

    return 0;
}
