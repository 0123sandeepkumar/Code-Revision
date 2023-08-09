#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include<vector>

bool compare(const std::pair<char, int>& a, const std::pair<char, int>& b) {
    return a.second > b.second;
}

std::string frequencySort(const std::string& str) {
    std::unordered_map<char, int> frequencyMap;
    for (char ch : str) {
        frequencyMap[ch]++;
    }

    std::vector<std::pair<char, int>> charFrequencyPairs;
    for (const auto& entry : frequencyMap) {
        charFrequencyPairs.push_back(entry);
    }

    std::sort(charFrequencyPairs.begin(), charFrequencyPairs.end(), compare);

    std::string result;
    for (const auto& pair : charFrequencyPairs) {
        result += std::string(pair.second, pair.first);
    }

    return result;
}

int main() {
    std::string input = "tree";
    std::string sorted = frequencySort(input);

    std::cout << "Original string: " << input << std::endl;
    std::cout << "Sorted string by frequency: " << sorted << std::endl;

    return 0;
}
