#include <iostream>
#include <vector>
#include <queue>

std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::priority_queue<std::pair<int, int>> maxHeap;  // Pair: (element, index)
    
    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements that are out of the current window
        while (!maxHeap.empty() && maxHeap.top().second <= i - k) {
            maxHeap.pop();
        }
        
        maxHeap.push({nums[i], i});
        
        if (i >= k - 1) {
            result.push_back(maxHeap.top().first);
        }
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    
    std::vector<int> maxInSlidingWindow = maxSlidingWindow(nums, k);
    std::cout << "Maximum elements in sliding windows of size " << k << ": ";
    for (int num : maxInSlidingWindow) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
