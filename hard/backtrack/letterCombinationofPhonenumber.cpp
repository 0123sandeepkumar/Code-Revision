#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> phoneKeys = {
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};

void backtrack(string& digits, string& current, int index, vector<string>& result) {
    if (index == digits.length()) {
        result.push_back(current);
        return;
    }

    char digit = digits[index];
    string letters = phoneKeys[digit];
    for (char letter : letters) {
        current.push_back(letter);
        backtrack(digits, current, index + 1, result);
        current.pop_back(); // Backtrack to explore other letter combinations
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) {
        return result;
    }

    string current;
    backtrack(digits, current, 0, result);
    return result;
}

int main() {
    string digits = "23"; // Change the input to test with different digits
    vector<string> combinations = letterCombinations(digits);
    
    cout << "Letter Combinations for " << digits << ":" << endl;
    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
