#include <iostream>
#include <vector>
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

// Depth-First Search (DFS) to traverse the connected component and mark visited nodes
void dfs(int node, vector<bool>& visited, vector<int>& component) {
    visited[node] = true;
    component.push_back(node);

    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, visited, component);
        }
    }
}

// Find the number of connected components and identify nodes in each connected component
vector<vector<int>> findConnectedComponents() {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    vector<vector<int>> connectedComponents;

    for (int node = 0; node < numNodes; ++node) {
        if (!visited[node]) {
            vector<int> component;
            dfs(node, visited, component);
            connectedComponents.push_back(component);
        }
    }

    return connectedComponents;
}

int main() {
    vector<vector<int>> connectedComponents = findConnectedComponents();

    cout << "Number of connected components: " << connectedComponents.size() << endl;

    cout << "Nodes in each connected component:" << endl;
    for (int i = 0; i < connectedComponents.size(); ++i) {
        cout << "Component " << i + 1 << ": ";
        for (int node : connectedComponents[i]) {
            cout << node << " ";
        }
        cout << endl;
    }

    return 0;
}
