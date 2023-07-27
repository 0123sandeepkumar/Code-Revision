#include <iostream>
#include <vector>

using namespace std;

bool isPalindrome(string& str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

void backtrack(string& str, int start, vector<string>& current, vector<vector<string>>& result) {
    if (start == str.length()) {
        result.push_back(current);
        return;
    }

    for (int end = start; end < str.length(); ++end) {
        if (isPalindrome(str, start, end)) {
            current.push_back(str.substr(start, end - start + 1));
            backtrack(str, end + 1, current, result);
            current.pop_back(); // Backtrack to explore other partitions
        }
    }
}

vector<vector<string>> partition(string str) {
    vector<vector<string>> result;
    if (str.empty()) {
        return result;
    }

    vector<string> current;
    backtrack(str, 0, current, result);
    return result;
}

int main() {
    string str = "aab";
    vector<vector<string>> partitions = partition(str);

    cout << "Palindrome partitions for \"" << str << "\":" << endl;
    for (const auto& partition : partitions) {
        for (const string& palindrome : partition) {
            cout << palindrome << " ";
        }
        cout << endl;
    }

    return 0;
}
