#include <iostream>
#include <vector>

using namespace std;

// Sample graph represented as an adjacency list
vector<vector<int>> graph = {
    {1, 2},     // Node 0 is adjacent to nodes 1 and 2
    {0, 2},     // Node 1 is adjacent to nodes 0 and 2
    {0, 1}      // Node 2 is adjacent to nodes 0 and 1
};

bool isSafeToColor(int node, int color, vector<int>& colors) {
    for (int neighbor : graph[node]) {
        if (colors[neighbor] == color)
            return false;
    }
    return true;
}

bool graphColoringUtil(int numColors, int node, vector<int>& colors) {
    if (node == graph.size())
        return true;

    for (int color = 1; color <= numColors; ++color) {
        if (isSafeToColor(node, color, colors)) {
            colors[node] = color;

            if (graphColoringUtil(numColors, node + 1, colors))
                return true;

            colors[node] = 0; // Backtrack
        }
    }

    return false;
}

bool graphColoring(int numColors) {
    vector<int> colors(graph.size(), 0); // Initialize all colors as 0

    if (graphColoringUtil(numColors, 0, colors)) {
        cout << "The graph can be colored with " << numColors << " colors as follows:" << endl;
        for (int i = 0; i < graph.size(); ++i) {
            cout << "Node " << i << ": Color " << colors[i] << endl;
        }
        return true;
    } else {
        cout << "The graph cannot be colored with " << numColors << " colors." << endl;
        return false;
    }
}

int main() {
    int numColors = 3; // Change this value to the desired number of colors
    graphColoring(numColors);

    return 0;
}
