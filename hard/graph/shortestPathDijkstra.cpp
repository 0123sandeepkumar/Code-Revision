#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Sample graph represented as an adjacency list with weighted edges
vector<vector<pair<int, int>>> graph = {
    {{1, 10}, {2, 5}},          // Node 0 is connected to nodes 1 (weight 10) and 2 (weight 5)
    {{3, 1}},                   // Node 1 is connected to node 3 (weight 1)
    {{1, 3}, {3, 9}},           // Node 2 is connected to nodes 1 (weight 3) and 3 (weight 9)
    {{0, 2}, {2, 2}}            // Node 3 is connected to nodes 0 (weight 2) and 2 (weight 2)
};

vector<int> dijkstra(int source, int numNodes) {
    vector<int> distance(numNodes, INF);
    distance[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        if (dist > distance[node])
            continue;

        for (const auto& edge : graph[node]) {
            int neighbor = edge.first;
            int weight = edge.second;

            if (distance[node] + weight < distance[neighbor]) {
                distance[neighbor] = distance[node] + weight;
                pq.push({distance[neighbor], neighbor});
            }
        }
    }

    return distance;
}

int main() {
    int source = 0;
    int destination = 3;
    int numNodes = graph.size();

    vector<int> shortestDistances = dijkstra(source, numNodes);

    cout << "Shortest distance from node " << source << " to all other nodes:" << endl;
    for (int i = 0; i < numNodes; ++i) {
        cout << "Node " << i << ": " << shortestDistances[i] << endl;
    }

    cout << "Shortest distance from node " << source << " to node " << destination << ": " << shortestDistances[destination] << endl;

    return 0;
}
