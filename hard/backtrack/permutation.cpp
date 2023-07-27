#include <iostream>
#include <vector>

using namespace std;

void generatePermutations(vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result) {
    if (current.size() == nums.size()) {
        result.push_back(current);
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        if (!used[i]) {
            current.push_back(nums[i]);
            used[i] = true;
            generatePermutations(nums, current, used, result);
            current.pop_back(); // Backtrack to explore other permutations
            used[i] = false;
        }
    }
}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    vector<bool> used(nums.size(), false); // To keep track of used elements
    generatePermutations(nums, current, used, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> permutations = permute(nums);
    for (const auto& perm : permutations) {
        cout << "Permutation: ";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
