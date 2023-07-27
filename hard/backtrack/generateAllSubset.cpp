#include <iostream>
#include <vector>

using namespace std;

void generateSubsets(vector<int>& nums, vector<int>& current, int start, vector<vector<int>>& result) {
    result.push_back(current);

    for (int i = start; i < nums.size(); ++i) {
        current.push_back(nums[i]);
        generateSubsets(nums, current, i + 1, result);
        current.pop_back(); // Backtrack to explore other subsets
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> current;
    generateSubsets(nums, current, 0, result);
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> allSubsets = subsets(nums);
    for (const auto& subset : allSubsets) {
        cout << "Subset: ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
