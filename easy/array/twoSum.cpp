#include <iostream>
#include <unordered_map>
#include <vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_map; // Hash table to store element-value and index pairs

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i}; // Return indices of the two numbers
        }
        num_map[nums[i]] = i;
    }

    return {}; // If no pair is found, return an empty vector
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices of the two numbers that add up to the target: "
                  << result[0] << " and " << result[1] << std::endl;
        std::cout << "The numbers are: " << nums[result[0]] << " and " << nums[result[1]] << std::endl;
    } else {
        std::cout << "No pair found." << std::endl;
    }

    return 0;
}
