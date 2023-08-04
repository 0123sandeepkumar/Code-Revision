#include <iostream>
#include <cctype>

bool isPalindrome(const std::string& s) {
    // Step 1: Remove non-alphanumeric characters and convert to lowercase
    std::string cleanedString;
    for (char c : s) {
        if (std::isalnum(c)) {
            cleanedString.push_back(std::tolower(c));
        }
    }

    // Step 2: Check if the cleaned string is a palindrome
    int left = 0;
    int right = cleanedString.length() - 1;
    while (left < right) {
        if (cleanedString[left] != cleanedString[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    std::string inputString = "A man, a plan, a canal, Panama!";
    if (isPalindrome(inputString)) {
        std::cout << "The string is a valid palindrome." << std::endl;
    } else {
        std::cout << "The string is not a valid palindrome." << std::endl;
    }
    return 0;
}
