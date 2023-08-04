#include <iostream>
#include <vector>
#include <algorithm>

int max_area(std::vector<int>& height) {
    int left = 0;
    int right = height.size() - 1;
    int max_area = 0;

    while (left < right) {
        int area = (right - left) * std::min(height[left], height[right]);
        max_area = std::max(max_area, area);

        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }

    return max_area;
}

int main() {
    std::vector<int> heights = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int max_container_area = max_area(heights);
    std::cout << "Maximum container area: " << max_container_area << std::endl; // Output: 49

    return 0;
}
