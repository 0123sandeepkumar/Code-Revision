#include <iostream>
#include <vector>

void dfs(int node, const std::vector<std::vector<int>>& graph, std::vector<int>& currentPath, std::vector<std::vector<int>>& allPaths) {
    currentPath.push_back(node);
    
    if (node == graph.size() - 1) {
        allPaths.push_back(currentPath);
    } else {
        for (int nextNode : graph[node]) {
            dfs(nextNode, graph, currentPath, allPaths);
        }
    }
    
    currentPath.pop_back();
}

std::vector<std::vector<int>> allPathsSourceTarget(const std::vector<std::vector<int>>& graph) {
    std::vector<std::vector<int>> allPaths;
    std::vector<int> currentPath;

    dfs(0, graph, currentPath, allPaths);

    return allPaths;
}

int main() {
    std::vector<std::vector<int>> graph = {
        {1, 2},
        {3},
        {3},
        {}
    };

    std::vector<std::vector<int>> paths = allPathsSourceTarget(graph);

    std::cout << "All possible paths from source to target:" << std::endl;
    for (const auto& path : paths) {
        for (int node : path) {
            std::cout << node << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
