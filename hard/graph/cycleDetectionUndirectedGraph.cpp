#include <iostream>
#include <vector>

using namespace std;

// Sample undirected graph represented as an adjacency list
vector<vector<int>> graph = {
    {1, 2},     // Node 0 is connected to nodes 1 and 2
    {3},        // Node 1 is connected to node 3
    {4},        // Node 2 is connected to node 4
    {0},        // Node 3 is connected to node 0 (forming a cycle)
    {}          // Node 4 has no outgoing edges
};

bool dfsHasCycleUndirected(int node, int parent, vector<int>& visited) {
    visited[node] = 1;  // Mark node as visited

    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            if (dfsHasCycleUndirected(neighbor, node, visited))
                return true;
        } else if (neighbor != parent) {
            // If the neighbor is already visited and not the immediate parent, then there's a cycle
            return true;
        }
    }

    return false;
}

bool containsCycleUndirected() {
    int numNodes = graph.size();
    vector<int> visited(numNodes, 0);

    for (int node = 0; node < numNodes; ++node) {
        if (visited[node] == 0) {
            if (dfsHasCycleUndirected(node, -1, visited))
                return true;
        }
    }

    return false;
}

int main() {
    if (containsCycleUndirected()) {
        cout << "The undirected graph contains a cycle." << endl;
    } else {
        cout << "The undirected graph does not contain a cycle." << endl;
    }

    return 0;
}
