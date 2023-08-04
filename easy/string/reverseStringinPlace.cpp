#include <iostream>
#include <string>

void reverseStringInPlace(std::string& s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        std::swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    std::string inputString = "Hello, World!";
    std::cout << "Original String: " << inputString << std::endl;

    reverseStringInPlace(inputString);

    std::cout << "Reversed String: " << inputString << std::endl;
    return 0;
}
