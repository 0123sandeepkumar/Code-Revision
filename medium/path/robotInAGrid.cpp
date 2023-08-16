#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> findPath(const std::vector<std::vector<int>>& grid) {
    int m = grid.size();
    int n = grid[0].size();

    std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0));
    std::vector<std::vector<int>> path(m, std::vector<int>(n, 0));

    dp[0][0] = (grid[0][0] == 0) ? 1 : 0;

    for (int i = 1; i < m; ++i) {
        if (grid[i][0] == 0) {
            dp[i][0] = dp[i - 1][0];
            path[i][0] = 1;
        }
    }

    for (int j = 1; j < n; ++j) {
        if (grid[0][j] == 0) {
            dp[0][j] = dp[0][j - 1];
            path[0][j] = 2;
        }
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (grid[i][j] == 0) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                if (dp[i - 1][j] > dp[i][j - 1]) {
                    path[i][j] = 1;
                } else {
                    path[i][j] = 2;
                }
            }
        }
    }

    std::vector<std::vector<int>> robotPath;

    if (dp[m - 1][n - 1] == 0) {
        return robotPath; // No path found
    }

    int i = m - 1, j = n - 1;
    while (i >= 0 && j >= 0) {
        robotPath.push_back({i, j});
        if (path[i][j] == 1) {
            i--;
        } else {
            j--;
        }
    }

    std::reverse(robotPath.begin(), robotPath.end());
    return robotPath;
}

int main() {
    int m, n;
    std::cout << "Enter the number of rows (m): ";
    std::cin >> m;
    std::cout << "Enter the number of columns (n): ";
    std::cin >> n;

    std::vector<std::vector<int>> grid(m, std::vector<int>(n));
    std::cout << "Enter the grid (0 for empty, 1 for obstacle):" << std::endl;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> grid[i][j];
        }
    }

    std::vector<std::vector<int>> robotPath = findPath(grid);

    if (robotPath.empty()) {
        std::cout << "No valid path found!" << std::endl;
    } else {
        std::cout << "Robot path:" << std::endl;
        for (const auto& point : robotPath) {
            std::cout << "(" << point[0] << ", " << point[1] << ")" << std::endl;
        }
    }

    return 0;
}
