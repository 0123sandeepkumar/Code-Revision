#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Sample graph represented as an adjacency list
vector<vector<int>> graph = {
    {1, 2},     // Node 0 is connected to nodes 1 and 2
    {0, 3},     // Node 1 is connected to nodes 0 and 3
    {0, 3},     // Node 2 is connected to nodes 0 and 3
    {1, 2}      // Node 3 is connected to nodes 1 and 2
};

bool isBipartite() {
    int numNodes = graph.size();
    vector<int> colors(numNodes, -1); // Initialize all colors as -1 (unassigned)
    queue<int> q;

    for (int startNode = 0; startNode < numNodes; ++startNode) {
        if (colors[startNode] != -1) // Skip nodes that are already colored
            continue;

        colors[startNode] = 0;
        q.push(startNode);

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (int neighbor : graph[node]) {
                if (colors[neighbor] == -1) {
                    colors[neighbor] = 1 - colors[node]; // Assign the opposite color
                    q.push(neighbor);
                } else if (colors[neighbor] == colors[node]) {
                    return false; // The graph is not bipartite
                }
            }
        }
    }

    return true; // The graph is bipartite
}

int main() {
    if (isBipartite()) {
        cout << "The graph is bipartite." << endl;
    } else {
        cout << "The graph is not bipartite." << endl;
    }

    return 0;
}
