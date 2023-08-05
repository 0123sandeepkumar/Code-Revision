#include <iostream>
#include <vector>
#include <stack>

std::vector<int> nextGreaterElements(const std::vector<int>& nums) {
    int n = nums.size();
    std::vector<int> result(n, -1); // Initialize the result array with -1.
    std::stack<int> indicesStack;

    for (int i = 0; i < n * 2; ++i) {
        int index = i % n;
        
        while (!indicesStack.empty() && nums[index] > nums[indicesStack.top()]) {
            // If the current element is greater than the element at the top of the stack,
            // update the result for the element at the top of the stack and pop it.
            result[indicesStack.top()] = nums[index];
            indicesStack.pop();
        }
        
        // Push the current index onto the stack.
        indicesStack.push(index);
    }

    return result;
}

int main() {
    std::vector<int> nums = {4, 5, 2, 25, 10, 7};
    std::vector<int> result = nextGreaterElements(nums);

    std::cout << "Next Greater Elements: ";
    for (int num : result) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
