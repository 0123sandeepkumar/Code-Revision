#include <iostream>
#include <vector>

using namespace std;

void countArrangements(int pos, vector<bool>& used, int& count, int n) {
    if (pos > n) {
        count++;
        return;
    }

    for (int i = 1; i <= n; ++i) {
        if (!used[i] && (i % pos == 0 || pos % i == 0)) {
            used[i] = true;
            countArrangements(pos + 1, used, count, n);
            used[i] = false;
        }
    }
}

int countArrangement(int n) {
    vector<bool> used(n + 1, false); // To keep track of used numbers
    int count = 0;
    countArrangements(1, used, count, n);
    return count;
}

int main() {
    int n = 3; // Replace with the desired value of n
    int result = countArrangement(n);
    cout << "Number of beautiful arrangements for n = " << n << ": " << result << endl;

    return 0;
}
