#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

// Sample graph represented as an adjacency list
vector<vector<int>> graph = {
    {1, 2},     // Node 0 is connected to nodes 1 and 2
    {0, 3, 4},  // Node 1 is connected to nodes 0, 3, and 4
    {0, 5, 6},  // Node 2 is connected to nodes 0, 5, and 6
    {1},        // Node 3 is connected to node 1
    {1},        // Node 4 is connected to node 1
    {2},        // Node 5 is connected to node 2
    {2}         // Node 6 is connected to node 2
};

// Depth-First Search (DFS)
void dfs(int node, vector<bool>& visited) {
    cout << node << " ";
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited);
        }
    }
}

// Breadth-First Search (BFS)
void bfs(int start) {
    vector<bool> visited(graph.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        cout << node << " ";

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    cout << "DFS Traversal: ";
    vector<bool> visited(graph.size(), false);
    dfs(0, visited);  // Starting from node 0
    cout << endl;

    cout << "BFS Traversal: ";
    bfs(0);           // Starting from node 0
    cout << endl;

    return 0;
}
