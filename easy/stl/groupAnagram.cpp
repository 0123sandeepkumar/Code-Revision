#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
    std::unordered_map<std::string, std::vector<std::string>> anagramGroups;

    for (const std::string& str : strs) {
        std::string sortedStr = str;
        std::sort(sortedStr.begin(), sortedStr.end());

        anagramGroups[sortedStr].push_back(str);
    }

    std::vector<std::vector<std::string>> result;
    for (const auto& entry : anagramGroups) {
        result.push_back(entry.second);
    }

    return result;
}

int main() {
    std::vector<std::string> words = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::vector<std::vector<std::string>> anagramGroups = groupAnagrams(words);

    std::cout << "Anagram Groups:\n";
    for (const auto& group : anagramGroups) {
        for (const std::string& word : group) {
            std::cout << word << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
