#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

struct CompareFrequency {
    bool operator()(const std::pair<char, int>& a, const std::pair<char, int>& b) {
        return a.second < b.second;
    }
};

std::string frequencySort(std::string s) {
    std::unordered_map<char, int> frequencyMap;
    for (char c : s) {
        frequencyMap[c]++;
    }
    
    std::priority_queue<std::pair<char, int>, std::vector<std::pair<char, int>>, CompareFrequency> maxHeap;
    
    for (const auto& entry : frequencyMap) {
        maxHeap.push(entry);
    }
    
    std::string result;
    while (!maxHeap.empty()) {
        char c = maxHeap.top().first;
        int freq = maxHeap.top().second;
        maxHeap.pop();
        
        result.append(freq, c);
    }
    
    return result;
}

int main() {
    std::string s = "tree";
    std::string sortedString = frequencySort(s);
    
    std::cout << "Sorted characters by frequency: " << sortedString << std::endl;
    
    return 0;
}
