#include <iostream>
#include <vector>

int trap_rainwater(std::vector<int>& height) {
    int n = height.size();
    if (n <= 2) {
        return 0; // No bars or only two bars cannot trap water
    }

    int left = 0;
    int right = n - 1;
    int left_max = height[left];
    int right_max = height[right];
    int trapped_water = 0;

    while (left < right) {
        if (height[left] <= height[right]) {
            // Process the left pointer
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                trapped_water += left_max - height[left];
            }
            left++;
        } else {
            // Process the right pointer
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                trapped_water += right_max - height[right];
            }
            right--;
        }
    }

    return trapped_water;
}

int main() {
    std::vector<int> heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int total_trapped_water = trap_rainwater(heights);
    std::cout << "Total trapped water: " << total_trapped_water << std::endl; // Output: 6

    return 0;
}
