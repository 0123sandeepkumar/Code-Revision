#include <iostream>
#include <vector>
#include <queue>

int kthLargestElement(std::vector<int>& nums, int k) {
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k) {
            minHeap.pop();
        }
    }
    
    return minHeap.top();
}

int main() {
    std::vector<int> nums = {3, 2, 1, 5, 4};
    int k = 2;
    
    int kthLargest = kthLargestElement(nums, k);
    std::cout << "The " << k << "th largest element is: " << kthLargest << std::endl;
    
    return 0;
}
