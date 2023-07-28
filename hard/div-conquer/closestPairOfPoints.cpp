#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <limits>

struct Point {
    int x, y;
};

bool compareX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool compareY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

double distance(const Point& p1, const Point& p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return std::sqrt(dx * dx + dy * dy);
}

double bruteForceClosestPair(const std::vector<Point>& points, int left, int right) {
    double minDistance = std::numeric_limits<double>::max();

    for (int i = left; i <= right; ++i) {
        for (int j = i + 1; j <= right; ++j) {
            minDistance = std::min(minDistance, distance(points[i], points[j]));
        }
    }

    return minDistance;
}

double closestPairRecursive(std::vector<Point>& points, int left, int right) {
    if (right - left <= 2) {
        return bruteForceClosestPair(points, left, right);
    }

    int mid = left + (right - left) / 2;
    double leftMinDist = closestPairRecursive(points, left, mid);
    double rightMinDist = closestPairRecursive(points, mid + 1, right);
    double minDist = std::min(leftMinDist, rightMinDist);

    std::vector<Point> strip;
    for (int i = left; i <= right; ++i) {
        if (std::abs(points[i].x - points[mid].x) < minDist) {
            strip.push_back(points[i]);
        }
    }

    std::sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); ++i) {
        for (size_t j = i + 1; j < strip.size() && strip[j].y - strip[i].y < minDist; ++j) {
            minDist = std::min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

double closestPair(std::vector<Point>& points) {
    std::sort(points.begin(), points.end(), compareX);
    return closestPairRecursive(points, 0, points.size() - 1);
}

int main() {
    // Example usage
    std::vector<Point> points = {{1, 2}, {3, 7}, {9, 4}, {5, 6}, {2, 8}};

    double minDistance = closestPair(points);

    std::cout << "Minimum Euclidean distance between two points: " << minDistance << std::endl;

    return 0;
}
