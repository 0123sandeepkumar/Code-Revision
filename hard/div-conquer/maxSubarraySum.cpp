#include <iostream>
#include <vector>
#include <limits>

struct SubarrayInfo {
    int maxSum;
    int leftIndex;
    int rightIndex;
};

SubarrayInfo findMaxCrossingSubarray(const std::vector<int>& arr, int left, int mid, int right) {
    int leftSum = std::numeric_limits<int>::min();
    int rightSum = std::numeric_limits<int>::min();

    int sum = 0;
    int leftIndex = mid;
    for (int i = mid; i >= left; --i) {
        sum += arr[i];
        if (sum > leftSum) {
            leftSum = sum;
            leftIndex = i;
        }
    }

    sum = 0;
    int rightIndex = mid + 1;
    for (int j = mid + 1; j <= right; ++j) {
        sum += arr[j];
        if (sum > rightSum) {
            rightSum = sum;
            rightIndex = j;
        }
    }

    return {leftSum + rightSum, leftIndex, rightIndex};
}

SubarrayInfo findMaximumSubarray(const std::vector<int>& arr, int left, int right) {
    if (left == right) {
        return {arr[left], left, right};
    }

    int mid = left + (right - left) / 2;

    SubarrayInfo leftSubarray = findMaximumSubarray(arr, left, mid);
    SubarrayInfo rightSubarray = findMaximumSubarray(arr, mid + 1, right);
    SubarrayInfo crossingSubarray = findMaxCrossingSubarray(arr, left, mid, right);

    if (leftSubarray.maxSum >= rightSubarray.maxSum && leftSubarray.maxSum >= crossingSubarray.maxSum) {
        return leftSubarray;
    } else if (rightSubarray.maxSum >= leftSubarray.maxSum && rightSubarray.maxSum >= crossingSubarray.maxSum) {
        return rightSubarray;
    } else {
        return crossingSubarray;
    }
}

int main() {
    // Example usage
    std::vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};

    SubarrayInfo result = findMaximumSubarray(arr, 0, arr.size() - 1);

    std::cout << "Maximum Subarray Sum: " << result.maxSum << std::endl;
    std::cout << "Subarray indices: [" << result.leftIndex << ", " << result.rightIndex << "]" << std::endl;

    return 0;
}
