#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateParentheses(int openCount, int closeCount, int n, string& current, vector<string>& result) {
    if (current.length() == 2 * n) {
        result.push_back(current);
        return;
    }

    if (openCount < n) {
        current.push_back('(');
        generateParentheses(openCount + 1, closeCount, n, current, result);
        current.pop_back();
    }

    if (closeCount < openCount) {
        current.push_back(')');
        generateParentheses(openCount, closeCount + 1, n, current, result);
        current.pop_back();
    }
}

vector<string> generateParenthesis(int n) {
    vector<string> result;
    if (n <= 0) {
        return result;
    }

    string current;
    generateParentheses(0, 0, n, current, result);
    return result;
}

int main() {
    int n = 3; // Change the value of n to generate different combinations
    vector<string> combinations = generateParenthesis(n);

    cout << "Valid Parentheses Combinations for n=" << n << ":" << endl;
    for (const string& combination : combinations) {
        cout << combination << endl;
    }

    return 0;
}
