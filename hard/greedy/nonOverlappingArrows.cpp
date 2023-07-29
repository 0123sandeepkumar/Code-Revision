#include <iostream>
#include <vector>
#include <algorithm>

struct Interval {
    int start;
    int end;
};

bool compareIntervals(const Interval& interval1, const Interval& interval2) {
    return interval1.end < interval2.end;
}

int eraseOverlapIntervals(const std::vector<Interval>& intervals) {
    int n = intervals.size();
    if (n <= 1) {
        return 0;
    }

    std::vector<Interval> sortedIntervals = intervals;
    std::sort(sortedIntervals.begin(), sortedIntervals.end(), compareIntervals);

    int countNonOverlapping = 1;
    int lastEnd = sortedIntervals[0].end;

    for (int i = 1; i < n; ++i) {
        if (sortedIntervals[i].start >= lastEnd) {
            // The current interval does not overlap with the last interval
            ++countNonOverlapping;
            lastEnd = sortedIntervals[i].end;
        }
    }

    // The number of intervals to remove = total intervals - count of non-overlapping intervals
    return n - countNonOverlapping;
}

int main() {
    // Example usage
    std::vector<Interval> intervals = {{1, 2}, {2, 3}, {3, 4}, {1, 3}};

    int minRemovals = eraseOverlapIntervals(intervals);

    std::cout << "Minimum number of intervals to remove: " << minRemovals << std::endl;

    return 0;
}
