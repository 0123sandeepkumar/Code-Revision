#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> numIndexMap;
    std::vector<int> result;

    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (numIndexMap.find(complement) != numIndexMap.end()) {
            result.push_back(numIndexMap[complement]);
            result.push_back(i);
            break;
        }
        numIndexMap[nums[i]] = i;
    }

    return result;
}

int main() {
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    std::vector<int> result = twoSum(nums, target);

    if (result.size() == 2) {
        std::cout << "Indices of the two numbers that add up to the target: " << result[0] << " and " << result[1] << std::endl;
        std::cout << "Numbers: " << nums[result[0]] << " and " << nums[result[1]] << std::endl;
    } else {
        std::cout << "No solution found." << std::endl;
    }

    return 0;
}
