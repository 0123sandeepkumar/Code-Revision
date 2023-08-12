#include <iostream>
#include <unordered_map>
#include <vector>

int subarraySum(std::vector<int>& nums, int k) {
    int count = 0;
    int sum = 0;
    std::unordered_map<int, int> sumFreq; // Stores cumulative sum frequencies

    sumFreq[0] = 1; // Initialize with frequency of 0 sum

    for (int num : nums) {
        sum += num;
        // Check if (sum - k) exists in the hash map
        if (sumFreq.find(sum - k) != sumFreq.end()) {
            count += sumFreq[sum - k];
        }
        // Update the hash map with the current cumulative sum frequency
        sumFreq[sum]++;
    }

    return count;
}

int main() {
    std::vector<int> nums = {1, 1, 1};
    int k = 2;
    int result = subarraySum(nums, k);
    std::cout << "Total subarrays with sum " << k << ": " << result << std::endl;
    return 0;
}
