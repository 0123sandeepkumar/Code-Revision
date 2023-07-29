#include <iostream>
#include <vector>

bool canJump(const std::vector<int>& nums) {
    int maxReachable = 0;
    int n = nums.size();

    for (int i = 0; i < n; ++i) {
        if (i > maxReachable) {
            // If the current index cannot be reached, return false
            return false;
        }

        maxReachable = std::max(maxReachable, i + nums[i]);

        if (maxReachable >= n - 1) {
            // If the last index can be reached, return true
            return true;
        }
    }

    return false;
}

int main() {
    // Example usage
    std::vector<int> nums = {2, 3, 1, 1, 4};

    bool result = canJump(nums);

    if (result) {
        std::cout << "It is possible to reach the last index." << std::endl;
    } else {
        std::cout << "It is not possible to reach the last index." << std::endl;
    }

    return 0;
}
