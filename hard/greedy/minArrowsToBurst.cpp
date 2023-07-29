#include <iostream>
#include <vector>
#include <algorithm>

struct Balloon {
    int start;
    int end;
};

bool compareBalloons(const Balloon& balloon1, const Balloon& balloon2) {
    return balloon1.end < balloon2.end;
}

int minArrowsBurstBalloons(const std::vector<Balloon>& balloons) {
    int n = balloons.size();
    if (n == 0) {
        return 0;
    }

    std::vector<Balloon> sortedBalloons = balloons;
    std::sort(sortedBalloons.begin(), sortedBalloons.end(), compareBalloons);

    int arrows = 1;
    int lastEnd = sortedBalloons[0].end;

    for (int i = 1; i < n; ++i) {
        if (sortedBalloons[i].start > lastEnd) {
            // The current balloon cannot be burst with the same arrow, so we need a new arrow
            ++arrows;
            lastEnd = sortedBalloons[i].end;
        }
    }

    return arrows;
}

int main() {
    // Example usage
    std::vector<Balloon> balloons = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};

    int minArrows = minArrowsBurstBalloons(balloons);

    std::cout << "Minimum number of arrows required: " << minArrows << std::endl;

    return 0;
}
