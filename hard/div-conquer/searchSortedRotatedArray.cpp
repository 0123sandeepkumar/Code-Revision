#include <iostream>
#include <vector>

int searchInRotatedArray(const std::vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        // Check if the left half is sorted
        if (arr[left] <= arr[mid]) {
            if (arr[left] <= target && target < arr[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else { // Right half is sorted
            if (arr[mid] < target && target <= arr[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }

    return -1; // Element not found
}

int main() {
    // Example usage
    std::vector<int> rotatedArray = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;

    int index = searchInRotatedArray(rotatedArray, target);

    if (index != -1) {
        std::cout << "Target element " << target << " found at index: " << index << std::endl;
    } else {
        std::cout << "Target element " << target << " not found in the array." << std::endl;
    }

    return 0;
}
