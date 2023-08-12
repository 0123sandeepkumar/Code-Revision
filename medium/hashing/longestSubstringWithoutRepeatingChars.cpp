#include <iostream>
#include <unordered_map>
#include <string>

int lengthOfLongestSubstring(std::string s) {
    int maxLength = 0;
    int start = 0; // Start of the current window
    std::unordered_map<char, int> charIndex; // Stores character positions

    for (int end = 0; end < s.length(); ++end) {
        if (charIndex.find(s[end]) != charIndex.end()) {
            // Update the start of the window to the next character of the repeating character
            start = std::max(start, charIndex[s[end]] + 1);
        }
        // Update the character's position in the hash map
        charIndex[s[end]] = end;
        // Calculate the length of the current substring
        int currentLength = end - start + 1;
        // Update the maximum length if necessary
        maxLength = std::max(maxLength, currentLength);
    }

    return maxLength;
}

int main() {
    std::string s = "abcabcbb";
    int result = lengthOfLongestSubstring(s);
    std::cout << "Length of the longest substring without repeating characters: " << result << std::endl;
    return 0;
}
