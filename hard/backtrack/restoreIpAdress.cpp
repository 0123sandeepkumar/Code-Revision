#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isValidIPComponent(string str) {
    if (str.empty() || (str.length() > 1 && str[0] == '0')) {
        return false; // Invalid if empty or has leading zeros
    }

    int num = stoi(str);
    return num >= 0 && num <= 255;
}

void backtrack(string& s, int index, int part, vector<string>& current, vector<string>& result) {
    if (part == 4) {
        if (index == s.length()) {
            result.push_back(current[0] + "." + current[1] + "." + current[2] + "." + current[3]);
        }
        return;
    }

    for (int len = 1; len <= 3 && index + len <= s.length(); ++len) {
        string str = s.substr(index, len);
        if (isValidIPComponent(str)) {
            current.push_back(str);
            backtrack(s, index + len, part + 1, current, result);
            current.pop_back(); // Backtrack to explore other combinations
        }
    }
}

vector<string> restoreIpAddresses(string s) {
    vector<string> result;
    if (s.empty() || s.length() > 12) {
        return result;
    }

    vector<string> current;
    backtrack(s, 0, 0, current, result);
    return result;
}

int main() {
    string s = "25525511135"; // Change the input to test with different digits
    vector<string> ipAddresses = restoreIpAddresses(s);

    cout << "Valid IP Addresses for \"" << s << "\":" << endl;
    for (const string& ipAddress : ipAddresses) {
        cout << ipAddress << endl;
    }

    return 0;
}
