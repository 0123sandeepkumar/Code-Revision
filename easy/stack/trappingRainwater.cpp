#include <iostream>
#include <stack>
#include <vector>

int trapRainwater(std::vector<int>& height) {
    int n = height.size();
    int totalWater = 0;
    std::stack<int> stack;

    for (int i = 0; i < n; ++i) {
        while (!stack.empty() && height[i] > height[stack.top()]) {
            int topBar = stack.top();
            stack.pop();

            if (stack.empty()) {
                break;
            }

            int distance = i - stack.top() - 1;
            int boundedHeight = std::min(height[i], height[stack.top()]) - height[topBar];
            totalWater += distance * boundedHeight;
        }

        stack.push(i);
    }

    return totalWater;
}

int main() {
    std::vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int trappedWater = trapRainwater(height);
    std::cout << "Total trapped rainwater: " << trappedWater << std::endl;
    return 0;
}
