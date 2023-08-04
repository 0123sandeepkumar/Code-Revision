#include <iostream>
#include <vector>
#include <algorithm>

// Interval structure with a start and end point
struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

// Function to merge overlapping intervals
std::vector<Interval> merge_intervals(std::vector<Interval>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    // Sort the intervals based on their starting points
    std::sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
        return a.start < b.start;
    });

    std::vector<Interval> merged_intervals;
    merged_intervals.push_back(intervals[0]);

    for (const Interval& interval : intervals) {
        if (interval.start <= merged_intervals.back().end) {
            // Overlapping intervals, merge them
            merged_intervals.back().end = std::max(merged_intervals.back().end, interval.end);
        } else {
            // Non-overlapping interval, add it to the result
            merged_intervals.push_back(interval);
        }
    }

    return merged_intervals;
}

int main() {
    std::vector<Interval> intervals = {Interval(1, 3), Interval(2, 6), Interval(8, 10), Interval(15, 18)};
    std::vector<Interval> merged = merge_intervals(intervals);

    std::cout << "Merged intervals: ";
    for (const Interval& interval : merged) {
        std::cout << "[" << interval.start << ", " << interval.end << "] ";
    }
    std::cout << std::endl; // Output: [1, 6] [8, 10] [15, 18]

    return 0;
}
