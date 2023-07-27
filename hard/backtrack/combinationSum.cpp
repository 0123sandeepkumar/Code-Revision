#include <iostream>
#include <vector>

using namespace std;

void findCombinations(vector<int>& candidates, int target, vector<int>& current, int start, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], current, i, result);
            current.pop_back(); // Backtrack if the current candidate leads to a dead-end
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    findCombinations(candidates, target, current, 0, result);
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;

    vector<vector<int>> result = combinationSum(candidates, target);
    for (const auto& combination : result) {
        cout << "Combination: ";
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
