#include <iostream>
#include <string>
#include <unordered_map>
#include <sstream>

bool wordPattern(std::string pattern, std::string str) {
    std::unordered_map<char, std::string> patternToWord;
    std::unordered_map<std::string, char> wordToPattern;
    
    std::istringstream ss(str);
    std::string word;
    int i = 0; // Index for iterating through the pattern
    
    while (ss >> word) {
        if (i >= pattern.size()) {
            return false; // More words in the string than the pattern
        }
        
        char pChar = pattern[i];
        
        if (patternToWord.find(pChar) == patternToWord.end() && wordToPattern.find(word) == wordToPattern.end()) {
            // Both mappings are not present, create them
            patternToWord[pChar] = word;
            wordToPattern[word] = pChar;
        } else if (patternToWord[pChar] != word || wordToPattern[word] != pChar) {
            // Mismatch in mappings
            return false;
        }
        
        i++;
    }
    
    // Check if there are remaining characters in the pattern
    return i == pattern.size();
}

int main() {
    std::string pattern = "abba";
    std::string str = "dog cat cat dog";
    
    bool result = wordPattern(pattern, str);
    if (result) {
        std::cout << "The string follows the pattern." << std::endl;
    } else {
        std::cout << "The string does not follow the pattern." << std::endl;
    }
    
    return 0;
}
