#include <iostream>
#include <vector>

long long fibonacci(int n) {
    if (n <= 0)
        return 0;
    else if (n == 1)
        return 1;

    std::vector<long long> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

int main() {
    int n;
    std::cout << "Enter the value of n to calculate the nth Fibonacci number: ";
    std::cin >> n;

    long long result = fibonacci(n);
    std::cout << "The " << n << "th Fibonacci number is: " << result << std::endl;

    return 0;
}
