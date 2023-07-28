#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start;
    int finish;
};

bool compareActivities(const Activity& a1, const Activity& a2) {
    return a1.finish < a2.finish;
}

int activitySelection(const std::vector<Activity>& activities) {
    int n = activities.size();
    if (n == 0) {
        return 0;
    }

    std::vector<Activity> sortedActivities = activities;
    std::sort(sortedActivities.begin(), sortedActivities.end(), compareActivities);

    int maxActivities = 1;
    int lastFinishTime = sortedActivities[0].finish;

    for (int i = 1; i < n; ++i) {
        if (sortedActivities[i].start >= lastFinishTime) {
            ++maxActivities;
            lastFinishTime = sortedActivities[i].finish;
        }
    }

    return maxActivities;
}

int main() {
    // Example usage
    std::vector<Activity> activities = {
        {1, 4}, {3, 5}, {0, 6}, {5, 7}, {3, 8}, {5, 9},
        {6, 10}, {8, 11}, {8, 12}, {2, 13}, {12, 14}
    };

    int maxActivities = activitySelection(activities);

    std::cout << "Maximum number of non-overlapping activities: " << maxActivities << std::endl;

    return 0;
}
