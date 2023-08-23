#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void findCombinations(vector<int>& candidates, int target, int start, vector<int>& current, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i < candidates.size(); ++i) {
        if (i > start && candidates[i] == candidates[i - 1])  // Skip duplicates
            continue;

        if (candidates[i] > target)
            break;

        current.push_back(candidates[i]);
        findCombinations(candidates, target - candidates[i], i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    
    sort(candidates.begin(), candidates.end()); // Sort candidates to handle duplicates
    
    findCombinations(candidates, target, 0, current, result);
    
    return result;
}

int main() {
    vector<int> candidates = {10, 1, 2, 7, 6, 5};
    int target = 8;

    vector<vector<int>> combinations = combinationSum2(candidates, target);

    for (const auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
