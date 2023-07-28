#include <iostream>
#include <vector>

int findMajorityElement(const std::vector<int>& nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else {
            count += (candidate == num) ? 1 : -1;
        }
    }

    // At this point, the candidate should be the majority element.
    // But to be sure, let's verify its count in the array.
    int majorityCount = 0;
    for (int num : nums) {
        if (num == candidate) {
            ++majorityCount;
        }
    }

    int n = nums.size();
    if (majorityCount > n / 2) {
        return candidate;
    }

    // If the majority element does not exist, return a value indicating an error.
    return -1;
}

int main() {
    // Example usage
    std::vector<int> nums = {2, 2, 2, 3, 3, 4, 2, 2, 2};

    int majorityElement = findMajorityElement(nums);

    if (majorityElement != -1) {
        std::cout << "The majority element is: " << majorityElement << std::endl;
    } else {
        std::cout << "No majority element found." << std::endl;
    }

    return 0;
}
