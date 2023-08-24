#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void generateUniquePermutations(vector<int>& nums, int index, vector<vector<int>>& permutations) {
    if (index == nums.size()) {
        permutations.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i) {
        if (i > index && nums[i] == nums[index]) {
            continue; // Skip duplicates to avoid duplicate permutations
        }

        swap(nums[index], nums[i]);
        generateUniquePermutations(nums, index + 1, permutations);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> result;
    sort(nums.begin(), nums.end()); // Sort the input to handle duplicates
    generateUniquePermutations(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1, 1, 2}; // Replace with your set of elements
    vector<vector<int>> result = permuteUnique(nums);

    cout << "All unique permutations:" << endl;
    for (const auto& permutation : result) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
