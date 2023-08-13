#include <iostream>
#include <vector>
#include <queue>

class MedianFinder {
public:
    /** Initialize your data structure here. */
    MedianFinder() {}
    
    void addNum(int num) {
        if (maxHeap.empty() || num <= maxHeap.top()) {
            maxHeap.push(num);
        } else {
            minHeap.push(num);
        }
        
        // Balance the heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if (maxHeap.size() == minHeap.size()) {
            return (maxHeap.top() + minHeap.top()) / 2.0;
        } else {
            return maxHeap.top();
        }
    }
    
private:
    std::priority_queue<int> maxHeap; // Stores the smaller half of elements
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Stores the larger half of elements
};

int main() {
    MedianFinder medianFinder;
    
    medianFinder.addNum(1);
    medianFinder.addNum(2);
    std::cout << "Median: " << medianFinder.findMedian() << std::endl; // Output: 1.5
    
    medianFinder.addNum(3);
    std::cout << "Median: " << medianFinder.findMedian() << std::endl; // Output: 2.0
    
    return 0;
}
