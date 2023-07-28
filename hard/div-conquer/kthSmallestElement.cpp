#include <iostream>
#include <vector>
#include <algorithm>

int partition(std::vector<int>& arr, int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; ++j) {
        if (arr[j] <= pivot) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[right]);
    return i + 1;
}

int quickSelect(std::vector<int>& arr, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right);

        if (pivotIndex == k - 1) {
            return arr[pivotIndex];
        } else if (pivotIndex > k - 1) {
            return quickSelect(arr, left, pivotIndex - 1, k);
        } else {
            return quickSelect(arr, pivotIndex + 1, right, k);
        }
    }

    // Kth smallest element not found (should not reach this point for a valid input)
    return -1;
}

int main() {
    // Example usage
    std::vector<int> arr = {7, 10, 4, 3, 20, 15};
    int k = 3; // Find the 3rd smallest element

    int kthSmallest = quickSelect(arr, 0, arr.size() - 1, k);

    std::cout << "The " << k << "th smallest element is: " << kthSmallest << std::endl;

    return 0;
}
