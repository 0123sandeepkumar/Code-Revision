#include <iostream>
#include <vector>
#include <string>

bool isPalindrome(const std::string& s, int start, int end) {
    while (start < end) {
        if (s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

int minCut(std::string s) {
    int n = s.length();
    std::vector<int> dp(n, 0);
    std::vector<std::vector<bool>> isPalindromeDP(n, std::vector<bool>(n, false));

    for (int end = 0; end < n; ++end) {
        dp[end] = end; // Maximum possible cuts for worst case: each character is a palindrome

        for (int start = 0; start <= end; ++start) {
            if (s[start] == s[end] && (end - start <= 1 || isPalindromeDP[start + 1][end - 1])) {
                isPalindromeDP[start][end] = true;

                if (start == 0) {
                    dp[end] = 0; // The whole string is a palindrome
                } else {
                    dp[end] = std::min(dp[end], dp[start - 1] + 1);
                }
            }
        }
    }

    return dp[n - 1];
}

int main() {
    std::string input;
    std::cout << "Enter the input string: ";
    std::cin >> input;

    int minCuts = minCut(input);
    std::cout << "Minimum number of cuts to form palindrome substrings: " << minCuts << std::endl;

    return 0;
}
