#include <iostream>
#include <unordered_map>

int lengthOfLongestSubstring(const std::string& s) {
    int n = s.length();
    int maxLength = 0;
    std::unordered_map<char, int> charIndexMap; // Map to store characters and their last seen index

    // Sliding window boundaries
    int left = 0;
    int right = 0;

    while (right < n) {
        char currentChar = s[right];

        // If the character is already present in the window,
        // update the left boundary to skip the repeated character
        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
            left = charIndexMap[currentChar] + 1;
        }

        // Update the character's last seen index in the map
        charIndexMap[currentChar] = right;

        // Update the maximum length of the non-repeating substring
        maxLength = std::max(maxLength, right - left + 1);

        // Move the right boundary of the window
        right++;
    }

    return maxLength;
}

int main() {
    std::string inputString = "abcabcbb";
    int longestLength = lengthOfLongestSubstring(inputString);
    std::cout << "The length of the longest substring without repeating characters: " << longestLength << std::endl;
    return 0;
}
