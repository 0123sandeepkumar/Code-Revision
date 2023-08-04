#include <iostream>
#include <vector>

void reverse(std::vector<int>& nums, int start, int end) {
    while (start < end) {
        std::swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

void rotate_array(std::vector<int>& nums, int k) {
    int n = nums.size();
    k %= n; // Handle the case when k is larger than the array size

    // Reverse the entire array
    reverse(nums, 0, n - 1);

    // Reverse the first k elements
    reverse(nums, 0, k - 1);

    // Reverse the remaining elements after k
    reverse(nums, k, n - 1);
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    int k = 3;

    rotate_array(nums, k);

    std::cout << "Rotated array: ";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: 5 6 7 1 2 3 4

    return 0;
}
