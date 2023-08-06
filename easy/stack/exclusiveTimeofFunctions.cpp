#include <iostream>
#include <sstream>
#include <stack>
#include <vector>

struct Log {
    int function_id;
    std::string event;
    int timestamp;
};

std::vector<int> exclusiveTime(int n, std::vector<Log>& logs) {
    std::vector<int> exclusive_times(n, 0);
    std::stack<int> active_functions;
    int prev_timestamp = 0;

    for (const auto& log : logs) {
        if (log.event == "start") {
            if (!active_functions.empty()) {
                // Update the exclusive time for the previously active function
                exclusive_times[active_functions.top()] += log.timestamp - prev_timestamp;
            }
            active_functions.push(log.function_id);
            prev_timestamp = log.timestamp;
        } else {
            // "end" event
            int function_id = active_functions.top();
            active_functions.pop();
            exclusive_times[function_id] += log.timestamp - prev_timestamp + 1;
            prev_timestamp = log.timestamp + 1;
        }
    }

    return exclusive_times;
}

int main() {
    // Example logs: {function_id, event ("start" or "end"), timestamp}
    std::vector<Log> logs = {
        {0, "start", 0},
        {1, "start", 2},
        {1, "end", 5},
        {0, "end", 6}
    };

    int n = 2; // Number of functions
    std::vector<int> exclusive_times = exclusiveTime(n, logs);

    std::cout << "Exclusive Times:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << "Function " << i << ": " << exclusive_times[i] << std::endl;
    }

    return 0;
}
