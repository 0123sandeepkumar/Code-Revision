#include <iostream>
#include <unordered_map>
#include <queue>

class FirstUnique {
private:
    std::unordered_map<char, int> freqMap;
    std::queue<char> uniqueQueue;

public:
    void addCharacter(char ch) {
        freqMap[ch]++;
        uniqueQueue.push(ch);
    }

    char getFirstUnique() {
        while (!uniqueQueue.empty() && freqMap[uniqueQueue.front()] > 1) {
            uniqueQueue.pop();
        }
        
        if (uniqueQueue.empty()) {
            return '#'; // No unique character found
        }
        
        return uniqueQueue.front();
    }
};

int main() {
    FirstUnique firstUnique;

    char stream[] = "aabbcddeeff";
    for (char ch : stream) {
        firstUnique.addCharacter(ch);
        std::cout << "First unique character: " << firstUnique.getFirstUnique() << "\n";
    }

    return 0;
}
