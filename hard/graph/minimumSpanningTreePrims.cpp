#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Sample graph represented as an adjacency list with weighted edges
vector<vector<pair<int, int>>> graph = {
    {{1, 10}, {2, 5}},          // Node 0 is connected to nodes 1 (weight 10) and 2 (weight 5)
    {{0, 10}, {3, 1}},          // Node 1 is connected to nodes 0 (weight 10) and 3 (weight 1)
    {{0, 5}, {3, 9}, {4, 2}},   // Node 2 is connected to nodes 0 (weight 5), 3 (weight 9), and 4 (weight 2)
    {{1, 1}, {2, 9}, {4, 6}},   // Node 3 is connected to nodes 1 (weight 1), 2 (weight 9), and 4 (weight 6)
    {{2, 2}, {3, 6}}            // Node 4 is connected to nodes 2 (weight 2) and 3 (weight 6)
};

int primMST() {
    int numNodes = graph.size();
    vector<bool> visited(numNodes, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int mstWeight = 0;

    // Start with node 0 (you can choose any starting node)
    pq.push({0, 0});

    while (!pq.empty()) {
        int node = pq.top().second;
        int weight = pq.top().first;
        pq.pop();

        if (visited[node])
            continue;

        visited[node] = true;
        mstWeight += weight;

        for (const auto& edge : graph[node]) {
            int neighbor = edge.first;
            int edgeWeight = edge.second;
            if (!visited[neighbor]) {
                pq.push({edgeWeight, neighbor});
            }
        }
    }

    return mstWeight;
}

int main() {
    int mstWeight = primMST();

    cout << "Minimum Spanning Tree (MST) weight: " << mstWeight << endl;

    return 0;
}
