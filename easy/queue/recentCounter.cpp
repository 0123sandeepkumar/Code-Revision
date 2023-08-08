#include <iostream>
#include <queue>

class RecentCounter {
private:
    std::queue<int> requests;

public:
    RecentCounter() {
    }
    
    int ping(int t) {
        requests.push(t);
        
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }
        
        return requests.size();
    }
};

int main() {
    RecentCounter counter;
    
    int timestamps[] = {1, 100, 3001, 3002};
    for (int timestamp : timestamps) {
        int count = counter.ping(timestamp);
        std::cout << "Number of recent requests: " << count << "\n";
    }

    return 0;
}
