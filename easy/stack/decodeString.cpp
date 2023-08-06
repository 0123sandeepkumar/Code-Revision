#include <iostream>
#include <stack>
#include <string>

std::string decodeString(std::string s) {
    std::stack<int> countStack;
    std::stack<std::string> resultStack;
    std::string currentResult = "";
    int currentCount = 0;

    for (char ch : s) {
        if (isdigit(ch)) {
            currentCount = currentCount * 10 + (ch - '0');
        } else if (ch == '[') {
            countStack.push(currentCount);
            resultStack.push(currentResult);
            currentCount = 0;
            currentResult = "";
        } else if (ch == ']') {
            int count = countStack.top();
            countStack.pop();
            std::string prevResult = resultStack.top();
            resultStack.pop();
            std::string tempResult;
            for (int i = 0; i < count; ++i) {
                tempResult += currentResult;
            }
            currentResult = prevResult + tempResult;
        } else {
            currentResult += ch;
        }
    }

    return currentResult;
}

int main() {
    std::string encodedString = "3[a2[bc]]";
    std::string decodedString = decodeString(encodedString);
    std::cout << "Decoded String: " << decodedString << std::endl;
    return 0;
}
