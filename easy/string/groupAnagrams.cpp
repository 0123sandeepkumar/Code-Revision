#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(const std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

    // Group words by their sorted versions (anagrams will have the same sorted version)
    for (const std::string& word : strs) {
        std::string sortedWord = word;
        std::sort(sortedWord.begin(), sortedWord.end());
        anagramGroups[sortedWord].push_back(word);
    }

    // Convert the hash map values to the result vector
    std::vector<std::vector<std::string>> result;
    for (const auto& entry : anagramGroups) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};
    std::vector<std::vector<std::string>> anagramGroups = groupAnagrams(words);

    // Output the grouped anagrams
    for (const auto& group : anagramGroups) {
        for (const std::string& word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
