#include <iostream>
#include <vector>
#include <string>

std::string commonPrefix(const std::string& str1, const std::string& str2) {
    int minLength = std::min(str1.length(), str2.length());

    int i = 0;
    while (i < minLength && str1[i] == str2[i]) {
        ++i;
    }

    return str1.substr(0, i);
}

std::string divideAndConquer(const std::vector<std::string>& strs, int left, int right) {
    if (left == right) {
        return strs[left];
    }

    int mid = left + (right - left) / 2;

    std::string leftPrefix = divideAndConquer(strs, left, mid);
    std::string rightPrefix = divideAndConquer(strs, mid + 1, right);

    return commonPrefix(leftPrefix, rightPrefix);
}

std::string longestCommonPrefix(const std::vector<std::string>& strs) {
    if (strs.empty()) {
        return "";
    }

    return divideAndConquer(strs, 0, strs.size() - 1);
}

int main() {
    // Example usage
    std::vector<std::string> strings = {"apple", "apricot", "appetizer", "apex"};

    std::string commonPrefix = longestCommonPrefix(strings);

    if (!commonPrefix.empty()) {
        std::cout << "Longest common prefix: " << commonPrefix << std::endl;
    } else {
        std::cout << "No common prefix found." << std::endl;
    }

    return 0;
}
