#include <iostream>
#include <vector>

int binarySearch(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    // Example usage
    std::vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15, 17};
    int target = 9;

    int index = binarySearch(sortedArray, target);

    if (index != -1) {
        std::cout << "Target element " << target << " found at index: " << index << std::endl;
    } else {
        std::cout << "Target element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
