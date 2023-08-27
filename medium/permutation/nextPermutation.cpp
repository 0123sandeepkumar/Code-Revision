#include <iostream>
#include <algorithm>
#include <vector>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first decreasing element starting from the right
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        i--;
    }

    if (i >= 0) {
        // Find the smallest element to the right of nums[i] that is larger than nums[i]
        int j = n - 1;
        while (nums[j] <= nums[i]) {
            j--;
        }

        // Swap nums[i] and nums[j]
        std::swap(nums[i], nums[j]);
    }

    // Reverse the elements after index i
    std::reverse(nums.begin() + i + 1, nums.end());
}

int main()  {
    std::vector<int> nums = {1, 2, 3};

    nextPermutation(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }

    return 0;
}
