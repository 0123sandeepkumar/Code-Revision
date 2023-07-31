#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

Node* cloneGraphUtil(Node* node, unordered_map<Node*, Node*>& visited) {
    if (!node)
        return nullptr;

    if (visited.find(node) != visited.end())
        return visited[node];

    Node* newNode = new Node(node->val);
    visited[node] = newNode;

    for (Node* neighbor : node->neighbors) {
        newNode->neighbors.push_back(cloneGraphUtil(neighbor, visited));
    }

    return newNode;
}

Node* cloneGraph(Node* node) {
    unordered_map<Node*, Node*> visited;
    return cloneGraphUtil(node, visited);
}

// Helper function to print the graph
void printGraph(Node* node, unordered_map<Node*, bool>& visited) {
    if (!node || visited[node])
        return;

    visited[node] = true;
    cout << "Node " << node->val << " -> ";

    for (Node* neighbor : node->neighbors) {
        cout << neighbor->val << " ";
    }
    cout << endl;

    for (Node* neighbor : node->neighbors) {
        printGraph(neighbor, visited);
    }
}

int main() {
    // Sample graph represented as an adjacency list
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->neighbors.push_back(node2);
    node1->neighbors.push_back(node4);
    node2->neighbors.push_back(node1);
    node2->neighbors.push_back(node3);
    node3->neighbors.push_back(node2);
    node3->neighbors.push_back(node4);
    node4->neighbors.push_back(node1);
    node4->neighbors.push_back(node3);

    Node* clonedGraph = cloneGraph(node1);

    cout << "Original Graph:" << endl;
    unordered_map<Node*, bool> visited;
    printGraph(node1, visited);

    cout << "Cloned Graph:" << endl;
    visited.clear();
    printGraph(clonedGraph, visited);

    return 0;
}
