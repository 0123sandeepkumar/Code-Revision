#include <iostream>
#include <string>
#include <unordered_map>
#include <deque>

char firstUniqChar(const std::string& str) {
    std::unordered_map<char, int> freqMap;
    std::deque<char> charQueue;

    for (char ch : str) {
        freqMap[ch]++;
        charQueue.push_back(ch);
    }

    for (char ch : charQueue) {
        if (freqMap[ch] == 1) {
            return ch;
        }
    }

    return '\0'; // No non-repeating character found
}

int main() {
    std::string input = "leetcode";

    char firstUnique = firstUniqChar(input);

    if (firstUnique != '\0') {
        std::cout << "First non-repeating character: " << firstUnique << std::endl;
    } else {
        std::cout << "No non-repeating character found." << std::endl;
    }

    return 0;
}
