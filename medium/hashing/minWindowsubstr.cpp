#include <iostream>
#include <string>
#include <unordered_map>

std::string minWindowSubstring(std::string s, std::string t) {
    std::unordered_map<char, int> patternFreq; // Frequency of characters in the pattern
    std::unordered_map<char, int> windowFreq;  // Frequency of characters in the current window

    // Initialize patternFreq with character frequencies from the pattern
    for (char c : t) {
        patternFreq[c]++;
    }

    int requiredChars = patternFreq.size(); // Number of unique characters in the pattern
    int formedChars = 0; // Number of unique characters formed in the current window
    int left = 0, right = 0; // Pointers for the sliding window
    int minLen = INT_MAX; // Minimum window length
    std::string minWindow = "";

    while (right < s.length()) {
        char currentChar = s[right];

        // Update windowFreq with the character from the right pointer
        windowFreq[currentChar]++;

        // If the character frequency in windowFreq matches or exceeds its frequency in patternFreq, increment formedChars
        if (patternFreq.find(currentChar) != patternFreq.end() && windowFreq[currentChar] == patternFreq[currentChar]) {
            formedChars++;
        }

        // Try to minimize the window by moving the left pointer
        while (left <= right && formedChars == requiredChars) {
            // Update the minimum window if the current window length is smaller
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minWindow = s.substr(left, minLen);
            }

            char leftChar = s[left];
            // Decrement the frequency of the character at the left pointer
            windowFreq[leftChar]--;

            // If the character frequency becomes less than the required frequency, decrement formedChars
            if (patternFreq.find(leftChar) != patternFreq.end() && windowFreq[leftChar] < patternFreq[leftChar]) {
                formedChars--;
            }

            left++; // Move the left pointer to the right
        }

        right++; // Move the right pointer to the right
    }

    return minWindow;
}

int main() {
    std::string s = "ADOBECODEBANC";
    std::string t = "ABC";
    
    std::string result = minWindowSubstring(s, t);
    std::cout << "Minimum window substring: " << result << std::endl;
    
    return 0;
}
