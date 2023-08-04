#include <iostream>
#include <vector>
#include <algorithm>

void next_permutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first index i such that nums[i] < nums[i+1]
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Find the smallest number greater than nums[i] in the suffix
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            j--;
        }

        // Swap nums[i] and nums[j]
        std::swap(nums[i], nums[j]);
    }

    // Reverse the suffix from i+1 to the end
    std::reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    next_permutation(nums);

    std::cout << "Next permutation: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: 1 3 2

    return 0;
}
