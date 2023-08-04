#include <iostream>
#include <stack>
#include <unordered_map>

bool isValidParentheses(const std::string& s) {
    std::stack<char> parenStack;
    std::unordered_map<char, char> parenPairs = {
        {')', '('},
        {']', '['},
        {'}', '{'}
    };

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            parenStack.push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (parenStack.empty() || parenStack.top() != parenPairs[c]) {
                return false;
            }
            parenStack.pop();
        }
    }

    return parenStack.empty();
}

int main() {
    std::string parentheses = "{[()]}";
    if (isValidParentheses(parentheses)) {
        std::cout << "The parentheses are valid and properly balanced." << std::endl;
    } else {
        std::cout << "The parentheses are not valid or properly balanced." << std::endl;
    }
    return 0;
}
