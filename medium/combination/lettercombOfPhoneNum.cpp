#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<char, string> phoneMapping = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    {'8', "tuv"}, {'9', "wxyz"}
};

void generateCombinations(string digits, int index, string current, vector<string>& result) {
    if (index == digits.size()) {
        result.push_back(current);
        return;
    }
    
    char digit = digits[index];
    string letters = phoneMapping[digit];
    
    for (char letter : letters) {
        generateCombinations(digits, index + 1, current + letter, result);
    }
}

vector<string> letterCombinations(string digits) {
    vector<string> result;
    if (digits.empty()) {
        return result;
    }
    
    generateCombinations(digits, 0, "", result);
    
    return result;
}

int main() {
    string digits = "23";

    vector<string> combinations = letterCombinations(digits);

    for (const string& combination : combinations) {
        cout << combination << " ";
    }
    cout << endl;

    return 0;
}
