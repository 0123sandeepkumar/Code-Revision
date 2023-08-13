#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include<algorithm>
using namespace std;

struct CompareFrequency {
    bool operator()(const std::pair<int, int>& a, const std::pair<int, int>& b) {
        return a.second < b.second;
    }
};

std::vector<int> topKFrequentElements(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> frequencyMap;
    for (int num : nums) {
        frequencyMap[num]++;
    }
    
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, CompareFrequency> maxHeap;
    
    for (const auto& entry : frequencyMap) {
        maxHeap.push(entry);
        if (maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    
    std::vector<int> result;
    while (!maxHeap.empty()) {
        result.push_back(maxHeap.top().first);
        maxHeap.pop();
    }
    
    std::reverse(result.begin(), result.end());
    return result;
}

int main() {
    std::vector<int> nums = {1, 1, 1, 2, 2, 3};
    int k = 2;
    
    std::vector<int> topKFrequent = topKFrequentElements(nums, k);
    std::cout << "Top " << k << " frequent elements: ";
    for (int num : topKFrequent) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
