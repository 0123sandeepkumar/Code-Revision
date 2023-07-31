#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Sample DAG represented as an adjacency list
vector<vector<int>> graph = {
    {1, 2},     // Node 0 has edges to nodes 1 and 2
    {3, 4},     // Node 1 has edges to nodes 3 and 4
    {4},        // Node 2 has an edge to node 4
    {5},        // Node 3 has an edge to node 5
    {5},        // Node 4 has an edge to node 5
    {},         // Node 5 has no outgoing edges
};

// Depth-First Search (DFS) to perform topological sorting
void dfs(int node, vector<bool>& visited, stack<int>& result) {
    visited[node] = true;

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, result);
        }
    }

    result.push(node);
}

// Topological sorting function
vector<int> topologicalSort() {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    stack<int> result;

    for (int node = 0; node < numNodes; ++node) {
        if (!visited[node]) {
            dfs(node, visited, result);
        }
    }

    vector<int> sortedNodes;
    while (!result.empty()) {
        sortedNodes.push_back(result.top());
        result.pop();
    }

    return sortedNodes;
}

int main() {
    vector<int> sortedNodes = topologicalSort();

    cout << "Topological Sorting: ";
    for (int node : sortedNodes) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
