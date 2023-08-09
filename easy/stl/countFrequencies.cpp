#include <iostream>
#include <map>
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 3, 2, 4, 1, 5, 2, 3, 1};

    std::map<int, int> frequencyMap;

    // Count the frequency of each element
    for (int num : arr) {
        frequencyMap[num]++;
    }

    // Display the frequency map
    std::cout << "Frequency map:\n";
    for (const auto& pair : frequencyMap) {
        std::cout << pair.first << ": " << pair.second << " times\n";
    }

    return 0;
}
