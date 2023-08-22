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
        if (candidates[i] <= target) {
            current.push_back(candidates[i]);
            findCombinations(candidates, target - candidates[i], i, current, result);
            current.pop_back();
        }
    }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> result;
    vector<int> current;
    
    sort(candidates.begin(), candidates.end()); // Sort the candidates for optimization
    findCombinations(candidates, target, 0, current, result);
    
    return result;
}

int main() {
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    
    vector<vector<int>> combinations = combinationSum(candidates, target);
    
    cout << "Combinations that sum up to " << target << ":" << endl;
    for (const vector<int>& combo : combinations) {
        cout << "[ ";
        for (int num : combo) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }
    
    return 0;
}
