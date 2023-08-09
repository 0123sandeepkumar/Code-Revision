#include <iostream>
#include <vector>
#include <algorithm>

int findKthLargest(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::nth_element(nums.begin(), nums.begin() + n - k, nums.end());
    return nums[n - k];
}

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 4};
    int k = 2;

    int kthLargest = findKthLargest(nums, k);
    
    std::cout << "Kth largest element (k=" << k << "): " << kthLargest << std::endl;

    return 0;
}
