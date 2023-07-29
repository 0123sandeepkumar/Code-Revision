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

int intervalScheduling(const std::vector<Interval>& intervals) {
    int n = intervals.size();
    if (n == 0) {
        return 0;
    }

    std::vector<Interval> sortedIntervals = intervals;
    std::sort(sortedIntervals.begin(), sortedIntervals.end(), compareIntervals);

    int maxNonOverlapping = 1;
    int lastEnd = sortedIntervals[0].end;

    for (int i = 1; i < n; ++i) {
        if (sortedIntervals[i].start >= lastEnd) {
            ++maxNonOverlapping;
            lastEnd = sortedIntervals[i].end;
        }
    }

    return maxNonOverlapping;
}

int main() {
    // Example usage
    std::vector<Interval> intervals = {{1, 5}, {2, 6}, {5, 8}, {7, 10}, {9, 12}};

    int maxNonOverlapping = intervalScheduling(intervals);

    std::cout << "Maximum number of non-overlapping intervals: " << maxNonOverlapping << std::endl;

    return 0;
}
