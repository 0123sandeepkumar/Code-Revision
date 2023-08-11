#include <iostream>
#include <vector>
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
    for (const auto& group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;
}

int main() {
    std::vector<std::string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    std::vector<std::vector<std::string>> anagramGroups = groupAnagrams(strs);

    for (const auto& group : anagramGroups) {
        std::cout << "[";
        for (const std::string& str : group) {
            std::cout << str << " ";
        }
        std::cout << "]" << std::endl;
    }

    return 0;
}
