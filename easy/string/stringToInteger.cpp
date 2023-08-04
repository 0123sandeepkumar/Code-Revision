#include <iostream>
#include <climits>

int atoi(const std::string& str) {
    int sign = 1;
    int i = 0;
    int n = str.length();

    // Skip leading whitespaces
    while (i < n && str[i] == ' ') {
        i++;
    }

    // Handle the sign if present
    if (i < n && (str[i] == '+' || str[i] == '-')) {
        sign = (str[i++] == '-') ? -1 : 1;
    }

    // Convert the digits to an integer until non-digit character is encountered
    int result = 0;
    while (i < n && std::isdigit(str[i])) {
        // Check for overflow
        if (result > INT_MAX / 10 || (result == INT_MAX / 10 && (str[i] - '0') > INT_MAX % 10)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }

        result = result * 10 + (str[i++] - '0');
    }

    return sign * result;
}

int main() {
    std::string inputString = "   -42";
    int convertedInt = atoi(inputString);
    std::cout << "Converted Integer: " << convertedInt << std::endl;
    return 0;
}
