#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(vector<int>& nums, int index, vector<vector<int>>& permutations) {
    if (index == nums.size()) {
        permutations.push_back(nums);
        return;
    }

    for (int i = index; i < nums.size(); ++i) {
        swap(nums[index], nums[i]);
        generatePermutations(nums, index + 1, permutations);
        swap(nums[index], nums[i]);
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3}; // Replace with your set of elements
    vector<vector<int>> result = permute(nums);

    cout << "All possible permutations:" << endl;
    for (const auto& permutation : result) {
        cout << "[ ";
        for (int num : permutation) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
