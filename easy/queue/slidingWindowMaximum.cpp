#include <iostream>
#include <vector>
#include <deque>

std::vector<int> maxSlidingWindow(const std::vector<int>& nums, int k) {
    std::vector<int> result;
    std::deque<int> dq;

    for (int i = 0; i < nums.size(); ++i) {
        // Remove elements that are out of the current window
        while (!dq.empty() && dq.front() < i - k + 1) {
            dq.pop_front();
        }

        // Remove smaller elements as they are no longer candidates for maximum
        while (!dq.empty() && nums[dq.back()] < nums[i]) {
            dq.pop_back();
        }

        dq.push_back(i);

        // The front of the deque contains the index of the maximum element
        // for the current window
        if (i >= k - 1) {
            result.push_back(nums[dq.front()]);
        }
    }

    return result;
}

int main() {
    std::vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;

    std::vector<int> result = maxSlidingWindow(nums, k);

    std::cout << "Maximum elements in sliding windows of size " << k << ":\n";
    for (int val : result) {
        std::cout << val << " ";
    }

    return 0;
}
