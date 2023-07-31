#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int src, dest, weight;
};

// Sample graph represented as a list of edges with weights
vector<Edge> edges = {
    {0, 1, 10},    // Edge from node 0 to node 1 with weight 10
    {0, 2, 5},     // Edge from node 0 to node 2 with weight 5
    {1, 3, 1},     // Edge from node 1 to node 3 with weight 1
    {2, 3, 9},     // Edge from node 2 to node 3 with weight 9
    {2, 4, 2},     // Edge from node 2 to node 4 with weight 2
    {3, 4, 6}      // Edge from node 3 to node 4 with weight 6
};

struct DSU {
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int u) {
        if (parent[u] != u)
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int u, int v) {
        u = find(u);
        v = find(v);
        if (rank[u] < rank[v])
            parent[u] = v;
        else if (rank[v] < rank[u])
            parent[v] = u;
        else {
            parent[u] = v;
            rank[v]++;
        }
    }
};

int kruskalMST(int numNodes) {
    sort(edges.begin(), edges.end(), [](const Edge& a, const Edge& b) {
        return a.weight < b.weight;
    });

    DSU dsu(numNodes);
    int mstWeight = 0;

    for (const Edge& edge : edges) {
        if (dsu.find(edge.src) != dsu.find(edge.dest)) {
            mstWeight += edge.weight;
            dsu.merge(edge.src, edge.dest);
        }
    }

    return mstWeight;
}

int main() {
    int numNodes = 5; // Update this value based on the number of nodes in your graph

    int mstWeight = kruskalMST(numNodes);

    cout << "Minimum Spanning Tree (MST) weight: " << mstWeight << endl;

    return 0;
}
