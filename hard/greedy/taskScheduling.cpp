#include <iostream>
#include <vector>
#include <algorithm>

struct Task {
    int duration;
    int deadline;
};

bool compareTasks(const Task& task1, const Task& task2) {
    return task1.deadline < task2.deadline;
}

int minMaxLateness(const std::vector<Task>& tasks) {
    int n = tasks.size();
    if (n == 0) {
        return 0;
    }

    std::vector<Task> sortedTasks = tasks;
    std::sort(sortedTasks.begin(), sortedTasks.end(), compareTasks);

    int current_time = 0;
    int max_lateness = 0;

    for (const Task& task : sortedTasks) {
        current_time += task.duration;
        int lateness = std::max(0, current_time - task.deadline);
        max_lateness = std::max(max_lateness, lateness);
    }

    return max_lateness;
}

int main() {
    // Example usage
    std::vector<Task> tasks = {{2, 4}, {3, 5}, {1, 3}, {5, 8}};

    int max_lateness = minMaxLateness(tasks);

    std::cout << "Minimum maximum lateness: " << max_lateness << std::endl;

    return 0;
}
