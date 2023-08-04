#include <iostream>
#include <vector>

int find_missing_number(std::vector<int>& nums) {
    int n = nums.size();
    int xor_all = 0;
    int xor_nums = 0;

    // XOR all the numbers from 0 to n
    for (int i = 0; i <= n; ++i) {
        xor_all ^= i;
    }

    // XOR all the elements in the array
    for (int num : nums) {
        xor_nums ^= num;
    }

    // The missing number will be the XOR of the two XORs
    return xor_all ^ xor_nums;
}

int main() {
    std::vector<int> nums = {3, 0, 1, 4, 2, 6, 5};
    int missing_number = find_missing_number(nums);

    std::cout << "The missing number is: " << missing_number << std::endl; // Output: 7

    return 0;
}
