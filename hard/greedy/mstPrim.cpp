#include <iostream>
#include <vector>
#include <queue>

struct Edge {
    int dest, weight;
};

struct CompareEdges {
    bool operator()(const Edge& edge1, const Edge& edge2) const {
        return edge1.weight > edge2.weight;
    }
};

std::vector<Edge> primMST(int V, const std::vector<std::vector<Edge>>& adjList) {
    std::vector<Edge> mst;
    std::vector<bool> visited(V, false);
    std::priority_queue<Edge, std::vector<Edge>, CompareEdges> pq;
    int edgesAdded = 0;

    visited[0] = true;
    for (const Edge& edge : adjList[0]) {
        pq.push(edge);
    }

    while (!pq.empty() && edgesAdded < V - 1) {
        Edge currEdge = pq.top();
        pq.pop();

        if (!visited[currEdge.dest]) {
            mst.push_back(currEdge);
            visited[currEdge.dest] = true;
            edgesAdded++;

            for (const Edge& edge : adjList[currEdge.dest]) {
                if (!visited[edge.dest]) {
                    pq.push(edge);
                }
            }
        }
    }

    return mst;
}

int main() {
    // Example usage
    int V = 4; // Number of vertices
    std::vector<std::vector<Edge>> adjList(V);

    adjList[0].push_back({1, 10});
    adjList[0].push_back({2, 6});
    adjList[0].push_back({3, 5});
    adjList[1].push_back({0, 10});
    adjList[1].push_back({3, 15});
    adjList[2].push_back({0, 6});
    adjList[2].push_back({3, 4});
    adjList[3].push_back({0, 5});
    adjList[3].push_back({1, 15});
    adjList[3].push_back({2, 4});

    std::vector<Edge> mst = primMST(V, adjList);

    std::cout << "Minimum Spanning Tree (MST) Edges:" << std::endl;
    for (const Edge& edge : mst) {
        std::cout << "0 -- " << edge.dest << " Weight: " << edge.weight << std::endl;
    }

    return 0;
}
