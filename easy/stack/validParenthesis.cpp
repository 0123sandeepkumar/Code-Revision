#include <iostream>
#include <stack>
#include <string>

bool isValidParentheses(const std::string& s) {
    std::stack<char> parenthesesStack;
    
    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            // If an opening parenthesis is found, push it onto the stack.
            parenthesesStack.push(c);
        } else {
            // If a closing parenthesis is found and the stack is empty, it's unbalanced.
            if (parenthesesStack.empty()) {
                return false;
            }
            
            char top = parenthesesStack.top();
            parenthesesStack.pop();
            
            // Check if the closing parenthesis matches the corresponding opening parenthesis.
            if ((c == ')' && top != '(') || (c == ']' && top != '[') || (c == '}' && top != '{')) {
                return false;
            }
        }
    }
    
    // If the stack is not empty, some opening parentheses are not closed.
    return parenthesesStack.empty();
}

int main() {
    std::string input;
    std::cout << "Enter a string containing parentheses: ";
    std::cin >> input;

    if (isValidParentheses(input)) {
        std::cout << "Valid parentheses and properly balanced." << std::endl;
    } else {
        std::cout << "Invalid parentheses or not properly balanced." << std::endl;
    }

    return 0;
}
