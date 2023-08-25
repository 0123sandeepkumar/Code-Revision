#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& nums, int startIndex, vector<vector<int>>& result) {
    if (startIndex == nums.size() - 1) {
        result.push_back(nums);
        return;
    }

    for (int i = startIndex; i < nums.size(); ++i) {
        swap(nums[startIndex], nums[i]);
        generatePermutations(nums, startIndex + 1, result);
        swap(nums[startIndex], nums[i]); // Backtrack
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    generatePermutations(nums, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = permute(nums);

    for (const vector<int>& perm : permutations) {
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
