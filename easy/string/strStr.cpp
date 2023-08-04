#include <iostream>

int strStr(const std::string& haystack, const std::string& needle) {
    int m = haystack.length();
    int n = needle.length();

    // Return 0 if the needle is an empty string
    if (n == 0) {
        return 0;
    }

    // If the needle is longer than the haystack, return -1
    if (m < n) {
        return -1;
    }

    // Sliding window loop
    for (int i = 0; i <= m - n; i++) {
        int j;
        // Check if the current window matches the needle
        for (j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }

        // If the entire needle is found in the haystack, return the starting index
        if (j == n) {
            return i;
        }
    }

    return -1; // Needle not found in haystack
}

int main() {
    std::string haystack = "hello, world";
    std::string needle = "world";
    
    int index = strStr(haystack, needle);
    if (index != -1) {
        std::cout << "Needle found at index: " << index << std::endl;
    } else {
        std::cout << "Needle not found in haystack." << std::endl;
    }
    
    return 0;
}
