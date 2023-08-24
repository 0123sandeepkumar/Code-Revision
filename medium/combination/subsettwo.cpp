#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateUniqueSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& subsets) {
    subsets.push_back(current);

    for (int i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[i - 1]) {
            continue; // Skip duplicates to avoid duplicate combinations
        }
        
        current.push_back(nums[i]);
        generateUniqueSubsets(nums, i + 1, current, subsets);
        current.pop_back();
    }
}

vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    
    sort(nums.begin(), nums.end()); // Sort the input to handle duplicates
    
    generateUniqueSubsets(nums, 0, current, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 2}; // Replace with your set of integers
    vector<vector<int>> result = subsetsWithDup(nums);

    cout << "All unique subsets:" << endl;
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
