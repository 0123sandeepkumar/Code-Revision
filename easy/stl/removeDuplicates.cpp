#include <iostream>
#include <algorithm>
#include <vector>

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 2, 3, 5, 6, 1};

    // Step 1: Sort the array
    std::sort(arr.begin(), arr.end());

    // Step 2: Remove duplicates using std::unique
    arr.erase(std::unique(arr.begin(), arr.end()), arr.end());

    // Display the array after removing duplicates
    std::cout << "Array after removing duplicates: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
