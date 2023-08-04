#include <iostream>
#include <vector>

std::vector<int> product_except_self(std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> left_products(n, 1);
    std::vector<int> right_products(n, 1);

    // Calculate products of all elements to the left of each index
    int left_product = 1;
    for (int i = 1; i < n; ++i) {
        left_product *= nums[i - 1];
        left_products[i] = left_product;
    }

    // Calculate products of all elements to the right of each index
    int right_product = 1;
    for (int i = n - 2; i >= 0; --i) {
        right_product *= nums[i + 1];
        right_products[i] = right_product;
    }

    // Calculate the final product except self for each index
    std::vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        result[i] = left_products[i] * right_products[i];
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 2, 3, 4};
    std::vector<int> result = product_except_self(nums);
    
    std::cout << "Product of all elements except self: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: 24 12 8 6

    return 0;
}
