#include <iostream>
#include <vector>
#include <queue>

const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

bool isValid(int x, int y, const std::vector<std::vector<int>>& maze) {
    return (x >= 0 && x < maze.size() && y >= 0 && y < maze[0].size() && maze[x][y] == 0);
}

int shortestPath(const std::vector<std::vector<int>>& maze) {
    int rows = maze.size();
    int cols = maze[0].size();
    std::vector<std::vector<int>> distance(rows, std::vector<int>(cols, INT_MAX));

    std::queue<std::pair<int, int>> q;
    q.push({0, 0});
    distance[0][0] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; ++i) {
            int newX = x + dx[i];
            int newY = y + dy[i];

            if (isValid(newX, newY, maze) && distance[newX][newY] == INT_MAX) {
                distance[newX][newY] = distance[x][y] + 1;
                q.push({newX, newY});
            }
        }
    }

    return distance[rows - 1][cols - 1] == INT_MAX ? -1 : distance[rows - 1][cols - 1];
}

int main() {
    std::vector<std::vector<int>> maze = {
        {0, 1, 0, 0, 0},
        {0, 0, 0, 1, 0},
        {1, 1, 0, 1, 0},
        {1, 1, 0, 0, 0},
        {1, 1, 0, 1, 0},
        {0, 0, 0, 1, 0}
    };

    int result = shortestPath(maze);
    std::cout << "Length of shortest path: " << result << std::endl;

    return 0;
}
