#include <iostream>
#include <vector>

long long merge(std::vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    for (int i = 0; i < n1; ++i)
        leftArr[i] = arr[left + i];
    for (int j = 0; j < n2; ++j)
        rightArr[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    long long inversionCount = 0;

    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        } else {
            arr[k] = rightArr[j];
            ++j;
            inversionCount += (n1 - i); // Count the inversions when an element from rightArr is smaller
        }
        ++k;
    }

    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
    }

    return inversionCount;
}

long long mergeSortAndCountInversions(std::vector<int>& arr, int left, int right) {
    long long inversionCount = 0;

    if (left < right) {
        int mid = left + (right - left) / 2;

        inversionCount += mergeSortAndCountInversions(arr, left, mid);
        inversionCount += mergeSortAndCountInversions(arr, mid + 1, right);
        inversionCount += merge(arr, left, mid, right);
    }

    return inversionCount;
}

int main() {
    // Example usage
    std::vector<int> arr = {8, 4, 2, 1};

    std::cout << "Original array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    long long inversionCount = mergeSortAndCountInversions(arr, 0, arr.size() - 1);

    std::cout << "Number of inversions: " << inversionCount << std::endl;

    return 0;
}
