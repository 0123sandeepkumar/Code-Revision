#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>

std::string rearrangeString(const std::string& str) {
    // Count the frequency of each character
    std::unordered_map<char, int> frequencyMap;
    for (char ch : str) {
        frequencyMap[ch]++;
    }

    // Create a max-heap (priority queue) based on character frequencies
    auto compare = [&](char a, char b) {
        return frequencyMap[a] < frequencyMap[b];
    };
    std::priority_queue<char, std::vector<char>, decltype(compare)> maxHeap(compare);
    for (const auto& entry : frequencyMap) {
        maxHeap.push(entry.first);
    }

    // Rearrange the string by alternating characters from the max-heap
    std::string result;
    while (!maxHeap.empty()) {
        char current = maxHeap.top();
        maxHeap.pop();

        if (!result.empty() && result.back() == current) {
            // Move the next character to the front of the heap
            char next = maxHeap.top();
            maxHeap.pop();
            result += next;
            maxHeap.push(current);
        } else {
            result += current;
        }
        
        frequencyMap[current]--;
        if (frequencyMap[current] > 0) {
            maxHeap.push(current);
        }
    }

    return result;
}

int main() {
    std::string input = "aaabbc";
    std::string rearranged = rearrangeString(input);
    
    std::cout << "Original string: " << input << std::endl;
    std::cout << "Rearranged string: " << rearranged << std::endl;

    return 0;
}
