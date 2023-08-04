#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

std::string reverseWords(const std::string& s) {
    std::istringstream iss(s);
    std::string word;
    std::string reversedString;

    while (iss >> word) {
        std::reverse(word.begin(), word.end());
        reversedString += word + " ";
    }

    // Remove the trailing whitespace
    if (!reversedString.empty()) {
        reversedString.pop_back();
    }

    return reversedString;
}

int main() {
    std::string inputString = "Hello, World!";
    std::string reversedString = reverseWords(inputString);
    std::cout << "Reversed Words: " << reversedString << std::endl;
    return 0;
}
