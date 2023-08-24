#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& subsets) {
    if (index == nums.size()) {
        subsets.push_back(current);
        return;
    }

    // Exclude the current number
    generateSubsets(nums, index + 1, current, subsets);

    // Include the current number
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, subsets);

    current.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(nums, 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3}; // Replace with your set of distinct integers
    vector<vector<int>> result = subsets(nums);

    cout << "All possible subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
