#include <iostream>
#include <string>

std::string countAndSay(int n) {
    if (n <= 0) {
        return "";
    }

    std::string prev = "1"; // The first term is "1"

    for (int i = 2; i <= n; i++) {
        std::string current;
        int count = 1;
        char digit = prev[0];

        for (int j = 1; j < prev.length(); j++) {
            if (prev[j] == digit) {
                count++;
            } else {
                current += std::to_string(count) + digit;
                count = 1;
                digit = prev[j];
            }
        }

        current += std::to_string(count) + digit; // Append the last group
        prev = current;
    }

    return prev;
}

int main() {
    int n = 6; // Generate the 6th term of the "Count and Say" sequence
    std::string nthTerm = countAndSay(n);
    std::cout << "The " << n << "th term of the \"Count and Say\" sequence: " << nthTerm << std::endl;
    return 0;
}
