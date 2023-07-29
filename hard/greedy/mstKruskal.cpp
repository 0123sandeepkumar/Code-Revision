#include <iostream>
#include <vector>
#include <algorithm>

struct Edge {
    int src, dest, weight;
};

bool compareEdges(const Edge& edge1, const Edge& edge2) {
    return edge1.weight < edge2.weight;
}

class DisjointSet {
public:
    DisjointSet(int n) : parent(n), rank(n, 0) {
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);

        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY]) {
                parent[rootX] = rootY;
            } else if (rank[rootX] > rank[rootY]) {
                parent[rootY] = rootX;
            } else {
                parent[rootY] = rootX;
                rank[rootX]++;
            }
        }
    }

private:
    std::vector<int> parent;
    std::vector<int> rank;
};

std::vector<Edge> kruskalMST(int V, const std::vector<Edge>& edges) {
    std::vector<Edge> mst;
    DisjointSet ds(V);
    int edgesAdded = 0;

    std::vector<Edge> sortedEdges = edges;
    std::sort(sortedEdges.begin(), sortedEdges.end(), compareEdges);

    for (const Edge& edge : sortedEdges) {
        if (edgesAdded == V - 1) {
            break;
        }

        int srcRoot = ds.find(edge.src);
        int destRoot = ds.find(edge.dest);

        if (srcRoot != destRoot) {
            mst.push_back(edge);
            ds.unionSets(srcRoot, destRoot);
            edgesAdded++;
        }
    }

    return mst;
}

int main() {
    // Example usage
    int V = 4; // Number of vertices
    std::vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    std::vector<Edge> mst = kruskalMST(V, edges);

    std::cout << "Minimum Spanning Tree (MST) Edges:" << std::endl;
    for (const Edge& edge : mst) {
        std::cout << edge.src << " -- " << edge.dest << " Weight: " << edge.weight << std::endl;
    }

    return 0;
}
