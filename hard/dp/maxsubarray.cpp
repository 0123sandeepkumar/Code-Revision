#include <iostream>
#include <vector>
#include <algorithm>

int maxSubArray(std::vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    // Create a 1D DP array to store the maximum sum ending at each index
    std::vector<int> dp(n, 0);

    // Base case: the first element has the maximum sum so far
    dp[0] = nums[0];
    
    // Fill in the DP array
    for (int i = 1; i < n; ++i) {
        // The maximum sum ending at index i is either the current element (nums[i])
        // or the current element plus the maximum sum ending at index (i-1)
        dp[i] = std::max(nums[i], nums[i] + dp[i - 1]);
    }

    // Find the maximum sum in the DP array
    int maxSum = dp[0];
    for (int i = 1; i < n; ++i) {
        if (dp[i] > maxSum) {
            maxSum = dp[i];
        }
    }

    return maxSum;
}

int main() {
    int n;
    std::cout << "Enter the number of elements in the array: ";
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> nums[i];
    }

    int maxSum = maxSubArray(nums);
    std::cout << "Maximum sum of a contiguous subarray: " << maxSum << std::endl;

    return 0;
}
