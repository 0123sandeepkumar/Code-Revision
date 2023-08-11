#include <iostream>
#include <vector>
#include <unordered_set>

int longestConsecutive(std::vector<int>& nums) {
    if (nums.empty()) return 0;

    std::unordered_set<int> numSet(nums.begin(), nums.end());
    int longestStreak = 0;

    for (int num : numSet) {
        if (numSet.find(num - 1) == numSet.end()) { // If num is the start of a streak
            int currentNum = num;
            int currentStreak = 1;

            while (numSet.find(currentNum + 1) != numSet.end()) {
                currentNum += 1;
                currentStreak += 1;
            }

            longestStreak = std::max(longestStreak, currentStreak);
        }
    }

    return longestStreak;
}

int main() {
    std::vector<int> nums = {100, 4, 200, 1, 3, 2};

    int longest = longestConsecutive(nums);

    std::cout << "Longest consecutive sequence length: " << longest << std::endl;

    return 0;
}
