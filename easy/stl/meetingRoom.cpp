#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
    Interval(int s, int e) : start(s), end(e) {}
};

bool canAttendMeetings(std::vector<Interval>& intervals) {
    if (intervals.empty()) {
        return true; // No meetings to attend
    }

    // Sort intervals based on start times
    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    // Check for overlapping intervals
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i].start < intervals[i - 1].end) {
            return false; // Overlapping meetings
        }
    }

    return true; // No overlapping meetings
}

int main() {
    std::vector<Interval> meetings = {{0, 5}, {5, 10}, {15, 20}};

    bool canAttend = canAttendMeetings(meetings);
    
    if (canAttend) {
        std::cout << "The person can attend all meetings." << std::endl;
    } else {
        std::cout << "The person cannot attend all meetings." << std::endl;
    }

    return 0;
}
