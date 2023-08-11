#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
    std::vector<std::vector<int>> result;
    int n = nums.size();
    
    if (n < 4)
        return result;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < n - 3; ++i) {
        if (i > 0 && nums[i] == nums[i - 1])
            continue;

        for (int j = i + 1; j < n - 2; ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            std::unordered_map<int, int> numIndexMap;
            int currTarget = target - nums[i] - nums[j];

            for (int k = j + 1; k < n; ++k) {
                int complement = currTarget - nums[k];
                if (numIndexMap.find(complement) != numIndexMap.end()) {
                    result.push_back({nums[i], nums[j], complement, nums[k]});
                    while (k + 1 < n && nums[k] == nums[k + 1])
                        ++k;
                }
                numIndexMap[nums[k]] = k;
            }
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    std::vector<std::vector<int>> result = fourSum(nums, target);

    for (const auto& quad : result) {
        std::cout << "[";
        for (int num : quad) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
