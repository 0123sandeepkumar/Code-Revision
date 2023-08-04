#include <iostream>
#include <unordered_set>

bool isPalindrome(const std::string& s, int left, int right) {
    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int countPalindromicSubstrings(const std::string& s) {
    int n = s.length();
    std::unordered_set<std::string> palindromes;

    for (int i = 0; i < n; i++) {
        // Odd length palindromic substrings centered at index i
        for (int j = 0; i - j >= 0 && i + j < n; j++) {
            if (s[i - j] == s[i + j]) {
                palindromes.insert(s.substr(i - j, 2 * j + 1));
            } else {
                break;
            }
        }

        // Even length palindromic substrings centered between i and i+1
        for (int j = 0; i - j >= 0 && i + 1 + j < n; j++) {
            if (s[i - j] == s[i + 1 + j]) {
                palindromes.insert(s.substr(i - j, 2 * j + 2));
            } else {
                break;
            }
        }
    }

    return palindromes.size();
}

int main() {
    std::string inputString = "abaaa";
    int numPalindromes = countPalindromicSubstrings(inputString);
    std::cout << "Number of distinct palindromic substrings: " << numPalindromes << std::endl;
    return 0;
}
