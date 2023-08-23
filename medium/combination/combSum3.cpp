#include <iostream>
#include <vector>

using namespace std;

void findCombinations(int k, int n, int start, vector<int>& current, vector<vector<int>>& result) {
    if (k == 0 && n == 0) {
        result.push_back(current);
        return;
    }

    for (int i = start; i <= 9; ++i) {
        if (i > n)
            break;

        current.push_back(i);
        findCombinations(k - 1, n - i, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> current;
    
    findCombinations(k, n, 1, current, result);
    
    return result;
}

int main() {
    int k = 3;
    int n = 9;

    vector<vector<int>> combinations = combinationSum3(k, n);

    for (const auto& combination : combinations) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
