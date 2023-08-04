#include <iostream>
#include <vector>
#include <algorithm>

int max_subarray_sum(std::vector<int>& nums) {
    int max_sum = INT_MIN;  // Initialize max_sum to negative infinity
    int current_sum = 0;    // Initialize current_sum to zero

    for (int num : nums) {
        // Check whether adding the current number to the current_sum is beneficial or not
        current_sum = std::max(num, current_sum + num);
        // Update max_sum if the current_sum is greater
        max_sum = std::max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    std::vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int result = max_subarray_sum(nums);
    std::cout << "Maximum subarray sum: " << result << std::endl; // Output: 6
    return 0;
}
