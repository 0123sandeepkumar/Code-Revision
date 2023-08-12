#include <iostream>
#include <unordered_map>
#include <string>

bool areIsomorphic(std::string s, std::string t) {
    if (s.length() != t.length()) {
        return false;
    }

    std::unordered_map<char, char> sToT; // Mapping from characters of s to characters of t
    std::unordered_map<char, char> tToS; // Mapping from characters of t to characters of s

    for (int i = 0; i < s.length(); ++i) {
        char charS = s[i];
        char charT = t[i];

        // Check if the mapping from s to t already exists
        if (sToT.find(charS) != sToT.end()) {
            if (sToT[charS] != charT) {
                return false; // Invalid mapping
            }
        } else {
            // Create the mapping from s to t
            sToT[charS] = charT;
        }

        // Check if the mapping from t to s already exists
        if (tToS.find(charT) != tToS.end()) {
            if (tToS[charT] != charS) {
                return false; // Invalid mapping
            }
        } else {
            // Create the mapping from t to s
            tToS[charT] = charS;
        }
    }

    return true;
}

int main() {
    std::string s = "egg";
    std::string t = "add";
    
    bool result = areIsomorphic(s, t);
    if (result) {
        std::cout << "The strings are isomorphic." << std::endl;
    } else {
        std::cout << "The strings are not isomorphic." << std::endl;
    }
    
    return 0;
}
