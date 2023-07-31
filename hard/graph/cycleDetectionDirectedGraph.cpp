#include <iostream>
#include <vector>

using namespace std;

// Sample directed graph represented as an adjacency list
vector<vector<int>> graph = {
    {1, 2},     // Node 0 has edges to nodes 1 and 2
    {3},        // Node 1 has an edge to node 3
    {4},        // Node 2 has an edge to node 4
    {0},        // Node 3 has an edge to node 0 (forming a cycle)
    {}          // Node 4 has no outgoing edges
};

bool dfsHasCycleDirected(int node, vector<int>& visited, vector<int>& recursionStack) {
    visited[node] = 1;  // Mark node as visited
    recursionStack[node] = 1; // Add the node to the recursion stack

    for (int neighbor : graph[node]) {
        if (visited[neighbor] == 0) {
            if (dfsHasCycleDirected(neighbor, visited, recursionStack))
                return true;
        } else if (recursionStack[neighbor] == 1) {
            // If the neighbor is already in the recursion stack, then there's a cycle
            return true;
        }
    }

    recursionStack[node] = 0; // Remove the node from the recursion stack after exploring its neighbors
    return false;
}

bool containsCycleDirected() {
    int numNodes = graph.size();
    vector<int> visited(numNodes, 0);
    vector<int> recursionStack(numNodes, 0);

    for (int node = 0; node < numNodes; ++node) {
        if (visited[node] == 0) {
            if (dfsHasCycleDirected(node, visited, recursionStack))
                return true;
        }
    }

    return false;
}

int main() {
    if (containsCycleDirected()) {
        cout << "The directed graph contains a cycle." << endl;
    } else {
        cout << "The directed graph does not contain a cycle." << endl;
    }

    return 0;
}
